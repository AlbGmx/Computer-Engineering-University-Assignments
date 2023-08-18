/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 12/06/2023
 */

#include <stdio.h>

#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_spi_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

#define DUTY100PERCENT  8191
#define DUTY1PERCENT    82
#define UARTS_BAUD_RATE (115200)
#define TASK_STACK_SIZE (1048)
#define READ_BUF_SIZE   (1024)
// UART 0
#define PC_UART_PORT   (0)
#define PC_UART_RX_PIN (3)
#define PC_UART_TX_PIN (1)

#define INTERNAL_LED         GPIO_NUM_2
#define BUTTON_UP            GPIO_NUM_26
#define BUTTON_DOWN          GPIO_NUM_27
#define TIMG0_T0CONFIG_REG   0x3FF5F000
#define TIMG0_T0LO_REG       0x3FF5F004
#define TIMG0_T0HI_REG       0x3FF5F008
#define TIMG0_T0UPDATE_REG   0x3FF5F00C
#define TIMG0_T0LOADLO_REG   0x3FF5F018
#define TIMG0_T0LOADHI_REG   0x3FF5F01C
#define TIMG0_T0LOAD_REG     0x3FF5F020
#define TIMG0_T0ALARMLO_REG  0x3FF5F010
#define TIMG0_T0ALARMHI_REG  0x3FF5F014
#define LED_HSCH0_CONF0_REG  0x3FF59000
#define LED_HSCH0_DUTY_REG   0x3FF59008
#define LED_HSCH0_DUTY_R_REG 0x3FF59010
#define LED_CONF_REG         0x3FF59190
#define FREQUENCY            1000

/*
void uartInit(uart_port_t uart_num, uint32_t baudrate, uint8_t size,
              uint8_t parity, uint8_t stop, uint8_t txPin, uint8_t rxPin) {

   uart_config_t uart_config = {
       .baud_rate  = UARTS_BAUD_RATE,
       .data_bits  = UART_DATA_8_BITS,
       .parity     = UART_PARITY_DISABLE,
       .stop_bits  = UART_STOP_BITS_1,
       .flow_ctrl  = UART_HW_FLOWCTRL_DISABLE,
       .source_clk = UART_SCLK_APB,
   };

   ESP_ERROR_CHECK(
       uart_driver_install(uart_num, READ_BUF_SIZE, READ_BUF_SIZE, 0, NULL, 0));
   ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
   ESP_ERROR_CHECK(uart_set_pin(uart_num, txPin, rxPin, UART_PIN_NO_CHANGE,
                                UART_PIN_NO_CHANGE));
}
*/

void initTimer(int div) {
   /* Setup the timers registers */
   uint32_t *configurationRegister = (uint32_t *)TIMG0_T0CONFIG_REG;
   uint32_t *loadLowToRegister     = (uint32_t *)TIMG0_T0LOADLO_REG;
   uint32_t *loadHighToRegister    = (uint32_t *)TIMG0_T0LOADHI_REG;
   uint32_t *loadRegisters         = (uint32_t *)TIMG0_T0LOAD_REG;
   uint32_t *updateValueRegister   = (uint32_t *)TIMG0_T0UPDATE_REG;
   uint32_t *loadAlarmLowRegister  = (uint32_t *)TIMG0_T0ALARMLO_REG;
   uint32_t *loadAlarmHighRegister = (uint32_t *)TIMG0_T0ALARMHI_REG;

   *configurationRegister &= ~((1 << 31) | (1 << 10));
   *configurationRegister |= 1 << 30;
   *configurationRegister &= ~(0xFFFF << 29);
   *configurationRegister |= 8000 << 13;
   *configurationRegister &= ~(1 << 29);
   *loadLowToRegister  = 0;
   *loadHighToRegister = 0;
   *loadRegisters      = 0;

   // Enable the timer (31st bit) and the alarm (10th bit)
   *configurationRegister |= (1 << 31);
   *updateValueRegister = 1;
}

void initGPIO() {
   esp_rom_gpio_pad_select_gpio(INTERNAL_LED);
   esp_rom_gpio_pad_select_gpio(BUTTON_UP);
   esp_rom_gpio_pad_select_gpio(BUTTON_DOWN);
   gpio_set_direction(INTERNAL_LED, GPIO_MODE_OUTPUT);
   gpio_set_direction(BUTTON_UP, GPIO_MODE_INPUT);
   gpio_set_direction(BUTTON_DOWN, GPIO_MODE_INPUT);
   gpio_pullup_en(BUTTON_UP);
   gpio_pullup_en(BUTTON_DOWN);
   gpio_reset_pin(INTERNAL_LED);
}

void initPWM(int gpio, int channel, int freq, int resolution) {
   ledc_timer_config_t ledc_timer = {.duty_resolution = resolution,
                                     .freq_hz         = freq,
                                     .speed_mode      = LEDC_HIGH_SPEED_MODE,
                                     .timer_num       = LEDC_TIMER_0,
                                     .clk_cfg         = LEDC_AUTO_CLK};

   ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

   ledc_channel_config_t ledc_channel = {.speed_mode = LEDC_HIGH_SPEED_MODE,
                                         .channel    = LEDC_CHANNEL_0,
                                         .timer_sel  = LEDC_TIMER_0,
                                         .intr_type  = LEDC_INTR_DISABLE,
                                         .gpio_num   = gpio,
                                         .duty       = 0,  // Set duty to 0%
                                         .hpoint     = 0};

   ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

void enablePWM(int enable) {}

void delayMs(int ms) { vTaskDelay(ms / portTICK_PERIOD_MS); }

void writeGPIO(int gpio, int level) { gpio_set_level(gpio, level); }

bool readGPIO(int gpio) { return gpio_get_level(gpio); }

void printValues(int buttonUp, int buttonDown, uint32_t duty) {
   printf("UP: %d DOWN: %d, duty: %ld\n", !(BUTTON_UP), !readGPIO(BUTTON_DOWN), duty);
}

int app_main(void) {
   initGPIO();
   initPWM(INTERNAL_LED, LEDC_CHANNEL_0, FREQUENCY, LEDC_TIMER_13_BIT);
   writeGPIO(INTERNAL_LED, 0);

   uint32_t duty = 0;

   while (1) {
      if (!readGPIO(BUTTON_UP) /*| uartGetchar(PC_UART_PORT) == '8'*/) {
         printValues(BUTTON_UP, BUTTON_DOWN, duty);
         if (duty >= DUTY100PERCENT - DUTY1PERCENT)
            duty = DUTY100PERCENT;
         else
            duty += DUTY1PERCENT;
      } else if (!readGPIO(BUTTON_DOWN) /*| uartGetchar(PC_UART_PORT) == '2'*/) {
         if (duty <= DUTY1PERCENT)
            duty = 0;
         else
            duty -= DUTY1PERCENT;
         printValues(BUTTON_UP, BUTTON_DOWN, duty);
      }

      ESP_ERROR_CHECK(ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty));
      ESP_ERROR_CHECK(ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0));

      fflush(stdout);
      delayMs(1);
   }
}