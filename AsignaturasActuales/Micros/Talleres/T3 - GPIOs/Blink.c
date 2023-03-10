/* Blink Example */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define LED_GPIO 2

void app_main(){
   /* Configure the peripheral according to the LED type */
   gpio_reset_pin(LED_GPIO);
   /* Set the GPIO as a push/pull output */  
   gpio_set_direction( LED_GPIO, GPIO_MODE_INPUT_OUTPUT );

   
   volatile uint32_t * GPIO_OUT = (uint32_t) 0x3FF44004;
   volatile uint32_t * GPIO_IN = (uint32_t) 0x3FF4403C;

   while(1){
      gpio_set_level(LED_GPIO, 0);
      printf("Value of GPIO Input Register at address %p when OFF: 0x%08xh\n", GPIO_IN, *GPIO_IN);
      printf("Value of GPIO Output Register at address %p when OFF: 0x%08xh\n", GPIO_IN, *GPIO_IN);
      vTaskDelay(1000 / portTICK_PERIOD_MS);

      gpio_set_level(LED_GPIO, 1);
      printf("Value of GPIO Input Register at address %p when ON: 0x%08xh\n", GPIO_IN, *GPIO_IN);
      printf("Value of GPIO Output Register at address %p when ON: 0x%08xh\n", GPIO_IN, *GPIO_IN);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
}