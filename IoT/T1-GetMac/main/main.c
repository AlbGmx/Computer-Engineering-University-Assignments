#include "esp_log.h"
#include "esp_mac.h"

char* TAG = "GetMac";

void app_main(void) {
   uint8_t mac[6] = {0};

   if (esp_read_mac(mac, ESP_MAC_WIFI_STA) == ESP_FAIL) {
      ESP_LOGE(TAG, "Failed to read MAC address");
      return;
   }
   ESP_LOGI(TAG, "ESP_MAC_WIFI_STA: %02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}
