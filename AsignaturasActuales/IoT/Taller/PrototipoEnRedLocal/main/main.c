#include <lwip/netdb.h>
#include <string.h>
#include <sys/param.h>

#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "regex.h"
#include "driver/gpio.h"

#define PORT 12345
#define SSID "ESP_NET"
#define PASS "ESP_NET_IOT"
#define LED GPIO_NUM_2
#define ADC GPIO_NUM_34

static const char *TAG = "Prototipo en Red Local";

bool wifi_connected = false;
int retry_num = 0;

void gpio_init() {
   esp_rom_gpio_pad_select_gpio(LED);
   gpio_set_direction(LED, GPIO_MODE_OUTPUT);
   esp_rom_gpio_pad_select_gpio(ADC);
   gpio_set_direction(ADC, GPIO_MODE_INPUT);

   gpio_set_level(LED, 1);
}

static void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id,
                               void *event_data) {
   if (event_id == WIFI_EVENT_STA_START) {
      ESP_LOGI(TAG, "WIFI CONNECTING...\n");
   } else if (event_id == WIFI_EVENT_STA_CONNECTED) {
      ESP_LOGI(TAG, "WIFI CONNECTED\n");
   } else if (event_id == WIFI_EVENT_STA_DISCONNECTED) {
      ESP_LOGE(TAG, "WIFI LOST CONNECTION\n");
      if (retry_num < 5) {
         esp_wifi_connect();
         retry_num++;
         ESP_LOGE(TAG, "RETRYING CONNECTION...\n");
      }
   } else if (event_id == IP_EVENT_STA_GOT_IP) {
      ESP_LOGI(TAG, "CONNECTED WITH IP %s\n", ip4addr_ntoa(&((ip_event_got_ip_t *)event_data)->ip_info.ip));
      wifi_connected = true;
   }
}

void wifi_connection() {
   esp_netif_init();
   esp_event_loop_create_default();
   esp_netif_create_default_wifi_sta();
   wifi_init_config_t wifi_initiation = WIFI_INIT_CONFIG_DEFAULT();
   esp_wifi_init(&wifi_initiation);
   esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
   esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);
   wifi_config_t wifi_configuration = {.sta = {
                                           .ssid = SSID,
                                           .password = PASS,
                                       }};
   esp_log_write(ESP_LOG_INFO, "Kconfig", "SSID=%s, PASS=%s", SSID, PASS);
   esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_configuration);
   esp_wifi_start();
   esp_wifi_set_mode(WIFI_MODE_STA);
   esp_wifi_connect();
   ESP_LOGE(TAG, "wifi_init_softap finished. SSID:%s  password:%s", SSID, PASS);
}

// Función para procesar el comando usando regex
char *process_command(char *command) {
   regex_t regex;
   char *response = (char *)malloc(128);
   regmatch_t matches[5];
   const char *pattern = "^UABC:([WR]):L(:[01])?(:.*)?$";

   // Compilar la expresión regular
   int ret = regcomp(&regex, pattern, REG_EXTENDED);
   if (ret) {
      strcpy(response, "NACK");
      return response;
   }

   // Ejecutar la expresión regular en el comando
   ret = regexec(&regex, command, 5, matches, 0);
   if (!ret) {
      char operation[2], value[2], comment[128];

      // Extraer la operación (W o R)
      snprintf(operation, matches[1].rm_eo - matches[1].rm_so + 1, "%s", &command[matches[1].rm_so]);

      // Extraer el valor si es una operación de escritura
      if (matches[2].rm_so != -1) {
         snprintf(value, matches[2].rm_eo - matches[2].rm_so + 1, "%s", &command[matches[2].rm_so + 1]);
      }

      // Extraer el comentario si existe
      if (matches[3].rm_so != -1) {
         snprintf(comment, matches[3].rm_eo - matches[3].rm_so + 1, "%s", &command[matches[3].rm_so + 1]);
      } else {
         comment[0] = '\0';
      }

      // Procesar la operación
      if (strcmp(operation, "W") == 0) {
         // Operación de escritura: se espera un valor de 1 o 0
         if (strcmp(value, "1") == 0 || strcmp(value, "0") == 0) {
            sprintf(response, "ACK:LED state set to %d", atoi(value));
            gpio_set_level(LED, atoi(value));
         } else {
            strcpy(response, "NACK");
         }
      } else if (strcmp(operation, "R") == 0) {
         // Operación de lectura: devolver el estado del LED
         sprintf(response, "ACK:LED state is %d", gpio_get_level(LED));
      } else {
         strcpy(response, "NACK");
      }

      regfree(&regex);  // Liberar la memoria del regex
   } else {
      // Si no coincide con el patrón, devolver NACK
      strcpy(response, "NACK");
      regfree(&regex);  // Liberar la memoria del regex
   }
   return response;
}

static void udp_server_task(void *pvParameters) {
   char rx_buffer[128];
   char addr_str[128];
   int addr_family = (int)pvParameters;
   int ip_protocol = 0;
   struct sockaddr_in6 dest_addr;

   while (1) {
      if (addr_family == AF_INET) {
         struct sockaddr_in *dest_addr_ip4 = (struct sockaddr_in *)&dest_addr;
         dest_addr_ip4->sin_addr.s_addr = htonl(INADDR_ANY);
         dest_addr_ip4->sin_family = AF_INET;
         dest_addr_ip4->sin_port = htons(PORT);
         ip_protocol = IPPROTO_IP;
      } else if (addr_family == AF_INET6) {
         bzero(&dest_addr.sin6_addr.un, sizeof(dest_addr.sin6_addr.un));
         dest_addr.sin6_family = AF_INET6;
         dest_addr.sin6_port = htons(PORT);
         ip_protocol = IPPROTO_IPV6;
      }

      int sock = socket(addr_family, SOCK_DGRAM, ip_protocol);
      if (sock < 0) {
         ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
         break;
      }
      ESP_LOGI(TAG, "Socket created");

      int err = bind(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
      if (err < 0) {
         ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
      }
      ESP_LOGI(TAG, "Socket bound, port %d", PORT);

      struct sockaddr_storage source_addr;
      socklen_t socklen = sizeof(source_addr);

      while (1) {
         ESP_LOGI(TAG, "Waiting for data");

         int len = recvfrom(sock, rx_buffer, sizeof(rx_buffer) - 1, 0, (struct sockaddr *)&source_addr, &socklen);

         if (len < 0) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
               ESP_LOGE(TAG, "recvfrom failed: errno %d", errno);
               break;
            }
         } else {
            if (source_addr.ss_family == PF_INET) {
               inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr, addr_str, sizeof(addr_str) - 1);

            } else if (source_addr.ss_family == PF_INET6) {
               inet6_ntoa_r(((struct sockaddr_in6 *)&source_addr)->sin6_addr, addr_str, sizeof(addr_str) - 1);
            }

            rx_buffer[len] = 0;
            ESP_LOGW(TAG, "Received %d bytes from %s:", len, addr_str);
            ESP_LOGW(TAG, "%s", rx_buffer);

            char * answer = process_command(rx_buffer);


            int err = sendto(sock, answer, strlen(answer), 0, (struct sockaddr *)&source_addr, sizeof(source_addr));
            if (err < 0) {
               ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
               break;
            }
         }
      }

      if (sock != -1) {
         ESP_LOGE(TAG, "Shutting down socket and restarting...");
         shutdown(sock, 0);
         close(sock);
      }
   }
   vTaskDelete(NULL);
}

void app_main(void) {
   gpio_init();
   ESP_ERROR_CHECK(nvs_flash_init());
   wifi_connection();
   while (!wifi_connected) {
      printf("Waiting for connection...\n");
      fflush(stdout);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
   xTaskCreate(udp_server_task, "udp_server", 4096, (void *)AF_INET, 5, NULL);
}
