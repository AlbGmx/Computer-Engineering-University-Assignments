#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#define TAG "ParkingMachine"
#define PARKING_PRICE 15
#define LED_DELAY_ON 500
#define LED_DELAY_OFF LED_DELAY_ON / 2
#define PRINTING_DELAY 2000
#define BUTTON_BOUNCE_TIME 150
#define RELEASED 0
#define PRESSED 1

// LEDS
#define LED_CHANGE_1_PESO GPIO_NUM_26
#define LED_CHANGE_5_PESOS GPIO_NUM_27
#define LED_CHANGE_10_PESOS GPIO_NUM_14
#define LED_PRINTING_RECEIPT GPIO_NUM_12
#define LED_DEBUG GPIO_NUM_2

// BUTTONS
#define BUTTON_1_PESO GPIO_NUM_17
#define BUTTON_5_PESOS GPIO_NUM_22
#define BUTTON_10_PESOS GPIO_NUM_18
#define BUTTON_20_PESOS GPIO_NUM_19

typedef enum {
   STATE_INITIAL = 0,
   STATE_RECEIVING_MONEY,
   STATE_RETURNING_CHANGE,
   STATE_WAITING_CHANGE,
   STATE_RECEIPT,
} states_t;

// Global variables
states_t currentState = STATE_INITIAL;
uint8_t change = 0;
uint8_t totalAmount = 0;
int32_t lastStateChange = 0;
QueueHandle_t buttonQueueHandler;
uint32_t currentTime = 0;
bool areInterruptsAttached = false;
bool giveChange = false;
bool changeGiven = false;
bool isPressed = false;

void delayMillis(int millis) { vTaskDelay(millis / portTICK_PERIOD_MS); }

void configGPIOs() {
   gpio_config_t io_conf;

   io_conf.intr_type = GPIO_INTR_DISABLE;
   io_conf.mode = GPIO_MODE_OUTPUT;
   io_conf.pin_bit_mask = (1 << LED_CHANGE_1_PESO) | (1 << LED_CHANGE_5_PESOS) | (1 << LED_CHANGE_10_PESOS) |
                          (1 << LED_PRINTING_RECEIPT) | (1 << LED_DEBUG);
   io_conf.pull_down_en = 0;
   io_conf.pull_up_en = 0;
   gpio_config(&io_conf);

   io_conf.intr_type = GPIO_INTR_NEGEDGE;
   io_conf.mode = GPIO_MODE_INPUT;
   io_conf.pin_bit_mask =
       (1 << BUTTON_1_PESO) | (1 << BUTTON_5_PESOS) | (1 << BUTTON_10_PESOS) | (1 << BUTTON_20_PESOS);
   io_conf.pull_down_en = 1;
   io_conf.pull_up_en = 0;
   gpio_config(&io_conf);
}

static void IRAM_ATTR buttonInterruptHandler(void *args) {
   uint32_t buttonActioned = (uint32_t)args;
   bool buttonAction = gpio_get_level(buttonActioned);

   currentTime = xTaskGetTickCount() * portTICK_PERIOD_MS;

   if (currentTime - lastStateChange < BUTTON_BOUNCE_TIME) {
      return;
   }
   // if (buttonAction == RELEASED) {
   gpio_set_level(LED_DEBUG, buttonAction);
   lastStateChange = currentTime;
   xQueueSendFromISR(buttonQueueHandler, &buttonActioned, NULL);
   // }
}

void detachAllInterrupts() {
   if (areInterruptsAttached) {
      gpio_isr_handler_remove(BUTTON_1_PESO);
      gpio_isr_handler_remove(BUTTON_5_PESOS);
      gpio_isr_handler_remove(BUTTON_10_PESOS);
      gpio_isr_handler_remove(BUTTON_20_PESOS);
      areInterruptsAttached = false;
   }
}

void attachInterrupts() {
   if (!areInterruptsAttached) {
      gpio_isr_handler_add(BUTTON_1_PESO, buttonInterruptHandler, (void *)BUTTON_1_PESO);
      gpio_isr_handler_add(BUTTON_5_PESOS, buttonInterruptHandler, (void *)BUTTON_5_PESOS);
      gpio_isr_handler_add(BUTTON_10_PESOS, buttonInterruptHandler, (void *)BUTTON_10_PESOS);
      gpio_isr_handler_add(BUTTON_20_PESOS, buttonInterruptHandler, (void *)BUTTON_20_PESOS);
      areInterruptsAttached = true;
   }
}

void parkingMachineTask(void *args) {
   int pinNumber;
   while (true) {
      if (xQueueReceive(buttonQueueHandler, &pinNumber, portMAX_DELAY)) {
         ESP_LOGI(TAG, "Button %d actioned, current state: %d", pinNumber, gpio_get_level(pinNumber));
         if (gpio_get_level(pinNumber) == RELEASED) {
            switch (currentState) {
               case STATE_INITIAL:
                  currentState = STATE_RECEIVING_MONEY;
               case STATE_RECEIVING_MONEY:
                  switch (pinNumber) {
                     case BUTTON_1_PESO:
                        totalAmount += 1;
                        printf("Se han depositado 1 peso, total: %d\n", totalAmount);
                        break;
                     case BUTTON_5_PESOS:
                        totalAmount += 5;
                        printf("Se han depositado 5 pesos, total: %d\n", totalAmount);
                        break;
                     case BUTTON_10_PESOS:
                        totalAmount += 10;
                        printf("Se han depositado 10 pesos, total: %d\n", totalAmount);
                        break;
                     case BUTTON_20_PESOS:
                        totalAmount += 20;
                        printf("Se han depositado 20 pesos, total: %d\n", totalAmount);
                        break;
                     default:
                        printf("Botón no reconocido\n");
                        break;
                  }
                  if (totalAmount >= PARKING_PRICE) {
                     currentState = STATE_RETURNING_CHANGE;
                     detachAllInterrupts();
                  }
                  break;
               case STATE_WAITING_CHANGE:
               case STATE_RETURNING_CHANGE:
               case STATE_RECEIPT:
                  printf("No se pueden recibir más depósitos\n");
                  return;
            }
         }
      }
      delayMillis(10);
   }
}

void showAmountOnLedsTask() {
   while (true) {
      if (currentState == STATE_RECEIVING_MONEY) {
         gpio_set_level(LED_CHANGE_1_PESO, totalAmount & 1);
         gpio_set_level(LED_CHANGE_5_PESOS, totalAmount & 2);
         gpio_set_level(LED_CHANGE_10_PESOS, totalAmount & 4);
         gpio_set_level(LED_PRINTING_RECEIPT, totalAmount & 8);
         gpio_set_level(LED_DEBUG, totalAmount & 16);
      }
      delayMillis(10);
   }
}

void configInterruptions() {
   buttonQueueHandler = xQueueCreate(10, sizeof(uint32_t));
   xTaskCreate(parkingMachineTask, "ParkingMachineTask", 2048, NULL, 1, NULL);

   gpio_install_isr_service(0);
   attachInterrupts();
}

void indicateReturnWithLedsTask(void *param) {
   while (true) {
      if (giveChange == true) {
         gpio_set_level(LED_CHANGE_1_PESO, 0);
         gpio_set_level(LED_CHANGE_5_PESOS, 0);
         gpio_set_level(LED_CHANGE_10_PESOS, 0);
         gpio_set_level(LED_PRINTING_RECEIPT, 0);
         while (change > 0) {
            if (change >= 10) {
               gpio_set_level(LED_CHANGE_10_PESOS, 1);
               delayMillis(LED_DELAY_ON);
               gpio_set_level(LED_CHANGE_10_PESOS, 0);
               delayMillis(LED_DELAY_OFF);
               change -= 10;
            } else if (change >= 5) {
               gpio_set_level(LED_CHANGE_5_PESOS, 1);
               delayMillis(LED_DELAY_ON);
               gpio_set_level(LED_CHANGE_5_PESOS, 0);
               delayMillis(LED_DELAY_OFF);
               change -= 5;
            } else if (change >= 1) {
               gpio_set_level(LED_CHANGE_1_PESO, 1);
               delayMillis(LED_DELAY_ON);
               gpio_set_level(LED_CHANGE_1_PESO, 0);
               delayMillis(LED_DELAY_OFF);
               change -= 1;
            }
         }
         ESP_LOGI(TAG, "Change given");
         giveChange = false;
         changeGiven = true;
      }
      delayMillis(10);
   }
}

void printReceivedReceipt() {
   gpio_set_level(LED_PRINTING_RECEIPT, 1);
   delayMillis(LED_DELAY_ON);
   gpio_set_level(LED_PRINTING_RECEIPT, 0);
   delayMillis(LED_DELAY_OFF);
}

void app_main() {
   configGPIOs();
   configInterruptions();
   xTaskCreate(indicateReturnWithLedsTask, "IndicateReturnWithLedsTask", 2048, NULL, 1, NULL);
   xTaskCreate(showAmountOnLedsTask, "ShowAmountOnLedsTask", 2048, NULL, 1, NULL);
   printf("Parking Machine started\n");

   while (true) {
      switch (currentState) {
         case STATE_INITIAL:
            if (totalAmount == (uint8_t)-1) {
               totalAmount = 0;
               printf("Parking Machine started\n");
            }
            attachInterrupts();
            break;
         case STATE_RECEIVING_MONEY:
            break;
         case STATE_RETURNING_CHANGE:
            detachAllInterrupts();
            change = totalAmount - PARKING_PRICE;
            giveChange = true;
            currentState = STATE_WAITING_CHANGE;
            break;
         case STATE_WAITING_CHANGE:
            if (changeGiven) {
               currentState = STATE_RECEIPT;
               changeGiven = false;
            }
            break;
         case STATE_RECEIPT:
            printf("Imprimiendo recibo\n");
            printReceivedReceipt();
            totalAmount = -1;
            currentState = STATE_INITIAL;
            break;
         default:
            break;
      }

      delayMillis(10);
      currentTime = xTaskGetTickCount() * portTICK_PERIOD_MS;
   }
}