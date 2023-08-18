
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "myUart.h"
#include "sdkconfig.h"

// UART 0
#define PC_UART_PORT   (0)
#define PC_UART_RX_PIN (3)
#define PC_UART_TX_PIN (1)
// UART 1
#define UART1_PORT   (1)
#define UART1_RX_PIN (18)
#define UART1_TX_PIN (19)
// UART 2
#define UART2_PORT   (2)
#define UART2_RX_PIN (16)
#define UART2_TX_PIN (17)

#define UARTS_BAUD_RATE (115200)
#define TASK_STACK_SIZE (1048)
#define READ_BUF_SIZE   (1024)

/**
 * @brief Configure and install the default UART, then, connect it to the
 * console UART.
 */


void uartInit(uint8_t com, uint16_t baudrate, uint8_t size, uint8_t parity, uint8_t stop) {
   uint8_t txPin, rxPin;

   switch (parity) {
      case 0:
         parity = UART_PARITY_DISABLE;
         break;
      case 1:
         parity = UART_PARITY_ODD;
         break;
      case 2:
         parity = UART_PARITY_EVEN;
         break;
      default:
         parity = UART_PARITY_DISABLE;
   }
   switch (com) {
      case 0:
         txPin = PC_UART_TX_PIN;
         rxPin = PC_UART_RX_PIN;
         break;
      case 1:
         txPin = UART1_TX_PIN;
         rxPin = UART1_RX_PIN;
         break;
      case 2:
         txPin = UART2_TX_PIN;
         rxPin = UART2_RX_PIN;
         break;
      default:
         txPin = PC_UART_TX_PIN;
         rxPin = PC_UART_RX_PIN;
   }

   switch(size){
      case 5:
         size = UART_DATA_5_BITS;
         break;
      case 6:
         size = UART_DATA_6_BITS;
         break;
      case 7:
         size = UART_DATA_7_BITS;
         break;
      case 8:
         size = UART_DATA_8_BITS;
         break;
      default:
         size = UART_DATA_8_BITS;
   }
   uart_config_t uart_config = {
       .baud_rate  = UARTS_BAUD_RATE,
       .data_bits  = size,
       .parity     = parity,
       .stop_bits  = (stop >= 1 && stop <= 2) ? stop : UART_STOP_BITS_1,
       .flow_ctrl  = UART_HW_FLOWCTRL_DISABLE,
       .source_clk = UART_SCLK_APB,
   };
   ESP_ERROR_CHECK(uart_driver_install(com, READ_BUF_SIZE, READ_BUF_SIZE, 0, NULL, 0));
   ESP_ERROR_CHECK(uart_param_config(com, &uart_config));
   ESP_ERROR_CHECK(uart_set_pin(com, txPin, rxPin, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
}
void uartSetColor(uart_port_t com, uint8_t color) {
   char esc_seq[10];
   switch (color) {
      case YELLOW:
         sprintf(esc_seq, "\033[33m");
         break;
      case GREEN:
         sprintf(esc_seq, "\033[32m");
         break;
      case BLUE:
         sprintf(esc_seq, "\033[34m");
         break;
      default:
         sprintf(esc_seq, "\033[0m");
         break;
   }
   uartPuts(com, esc_seq);
}

void uartGotoxy(uart_port_t com, uint8_t x, uint8_t y) {
   char escape_seq[16];
   sprintf(escape_seq, "\033[%d;%dH", y, x);
   uartPuts(com, escape_seq);
}

void delayMs(uint16_t ms) { vTaskDelay(ms / portTICK_PERIOD_MS); }

void uartClrScr(uart_port_t uart_num) {
   // Uso "const" para sugerir que el contenido del arreglo lo coloque en Flash
   // y no en RAM
   const char caClearScr[] = "\e[2J";
   uart_write_bytes(uart_num, caClearScr, sizeof(caClearScr));
}

void uartGoto11(uart_port_t uart_num) {
   // Limpie un poco el arreglo de caracteres, los siguientes tres son
   // equivalentes:
   // "\e[1;1H" == "\x1B[1;1H" == {27,'[','1',';','1','H'}
   const char caGoto11[] = "\e[1;1H";
   uart_write_bytes(uart_num, caGoto11, sizeof(caGoto11));
}

bool uartKbhit(uart_port_t uart_num) {
   uint8_t length;
   uart_get_buffered_data_len(uart_num, (size_t *)&length);
   return (length > 0);
}

void uartPutchar(uart_port_t uart_num, char c) { uart_write_bytes(uart_num, &c, sizeof(c)); }

char uartGetchar(uart_port_t uart_num) {
   char c;
   // Wait for a received byte
   while (!uartKbhit(uart_num)) {
      delayMs(10);
   }
   // read byte, no wait
   uart_read_bytes(uart_num, &c, sizeof(c), 0);

   return c;
}

void uartPuts(uint8_t com, char *str) {
   while (*str) {
      uartPutchar(com, *str++);
   }
}
void uartGets(uint8_t com, char *str) {
   char c;
   int i = 0;

   while (i < READ_BUF_SIZE - 1) {
      if (uartKbhit(com)) {
         c = uartGetchar(com);
         if (c == '\r' || c == '\n') {
            str[i] = '\0';
            return;
         } else if (c == '\b') {
            if (i > 0) {
               str[i] = '\0';
               i--;
               str[i] = '\0';
               uart_write_bytes(com, "\b \b", 3);
            }
         } else {
            str[i++] = c;
            if (str[i] != '\0') str[i] = '\0';
            uart_write_bytes(com, &c, 1);
         }
         if ((i > 20)) {
            str[i] = '\0';
            i--;
            str[i] = '\0';
            uart_write_bytes(com, "\b \b", 3);
         }
      }
      delayMs(10);
   }

   str[i] = '\0';
}

void myItoa(uint16_t number, char *str, uint8_t base) {
   // Tabla de caracteres para conversiones en bases mayores a 10
   const char digits[] = "0123456789ABCDEF";

   uint16_t temp = number;
   int digit, i = 0;

   // Convertir número a cadena en la base especificada
   do {
      digit    = temp % base;
      str[i++] = digits[digit];
      temp /= base;
   } while (temp > 0);

   // Agregar el carácter nulo al final de la cadena
   str[i] = '\0';

   // Invertir la cadena
   for (int j = 0, k = i - 1; j < k; j++, k--) {
      char temp = str[j];
      str[j]    = str[k];
      str[k]    = temp;
   }
}

uint16_t myAtoi(char *str) {
   uint16_t res = 0;

   // Iterar a través de cada carácter de la cadena hasta encontrar el final de
   // la cadena o un carácter no numérico
   while (*str != '\0' && (*str >= '0' && *str <= '9')) {
      // Multiplicar el resultado actual por 10 y sumar el valor numérico del
      // carácter actual
      res = res * 10 + (*str - '0');
      str++;
   }

   return res;
}

void app_main(void) {
   char cad[20];
   char cadUart[20];
   uint16_t num;

   uartInit(PC_UART_PORT, 57600, 8, 1, 2);
   uartInit(UART1_PORT, 12345, 8, 0, 1);
   uartInit(UART2_PORT, 12345, 8, 0, 1);
   while (1) {
      uartPuts(PC_UART_PORT, "\n\nPress any key to continue...");
      uartGetchar(0);
      uartClrScr(0);

      uartGotoxy(0, 2, 2);
      uartSetColor(0, YELLOW);
      uartPuts(0, "Introduce un número: ");

      uartGotoxy(0, 22, 2);
      uartSetColor(0, GREEN);
      uartGets(0, cad);
      // For the following code to work, TX2 must be physically
      // connected with a jumper wire to RX1
      // -------------------------------------------
      // Cycle through UART2->UART1
      uartPuts(2, cad);
      uartPuts(2, "\r");
      uartGets(1, cadUart);
      uartGotoxy(0, 5, 3);
      uartPuts(0, cadUart);
      // -------------------------------------------
      num = myAtoi(cad);
      myItoa(num, cad, 16);

      uartGotoxy(0, 5, 4);
      uartSetColor(0, BLUE);
      uartPuts(0, "Hex: ");
      uartPuts(0, cad);
      myItoa(num, cad, 2);

      uartGotoxy(0, 5, 5);
      uartPuts(0, "Bin: ");
      uartPuts(0, cad);
   }
}