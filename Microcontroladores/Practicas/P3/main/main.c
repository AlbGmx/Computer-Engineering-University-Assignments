/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 18/03/2023
 * Descripcion: Practica 3, Implementacion del juego de pong en 1D
 * Laboratorio de la clase Microcontroladores
 * 
 * 
 * For use with the Wokwi ESP32 online simulator (https://wokwi.com/projects/new/esp32)
 * change "sketch.ino" to "main.c" and upload the "diagram.json" file to the projec
 */

#include <stdio.h>

#include "driver/gpio.h"
#include "esp_spi_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

#define LED_GPIO GPIO_NUM_2
#define BTN_GPIO GPIO_NUM_4
#define NUM_LEDS sizeof(ledArray)
#define NUM_BTNS sizeof(btnArray)
#define LEFT_BTN GPIO_NUM_19
#define RIGHT_BTN GPIO_NUM_18
#define LED_ON_DELAY 300
#define LED_OFF_DELAY 50
#define SPEED_UP 20

uint8_t ledArray[] = {
    GPIO_NUM_32,  // Leftmost LED
    GPIO_NUM_33,
    GPIO_NUM_25,
    GPIO_NUM_26,
    GPIO_NUM_27,
    GPIO_NUM_14,
    GPIO_NUM_12  // Rightmost LED
};

uint8_t btnArray[] = {
    GPIO_NUM_19,  // Left Btn
    GPIO_NUM_18   // Right Btn
};

typedef enum eDirection_tag {
   eGoingLeft = -1,
   eGoingRight = 1
} eDirection_t;

// Enumerations
typedef enum ButtonState_tag {
   eBtnUndefined = 0,
   eBtnShortPressed,
   eBtnLongPressed
} eButtonState_t;

typedef enum PlayerInputState_tag {
   eWaiting = 0,
   eCorrect,
   eIncorrect
} ePlayerInputState_t;

typedef enum ButtonId_tag {
   eLeftButton = 0,  // This enum must follow btnArray
   eRightButton,
   eMaxButtonId
} eButtonId_t;

typedef enum GameState_tag {
   eGameRestart = 0,
   eWaitForStart,
   eOngoingGame,
   eEnd
} eGameState_t;

// Global variable;
uint32_t startTime[3] = {0, 0, 0};
uint32_t _millis;
uint32_t ledDelay = 300;
uint8_t score;
uint8_t state = 64;
bool isBtnPressed[NUM_BTNS];
bool stateFlag = 0;
eDirection_t direction = eGoingLeft;

void updateLedArray(uint8_t status) {
   for (int i = 0; i < NUM_LEDS; i++) {
      if ((status >> i) & 1) {
         gpio_set_level(ledArray[i], 1);
      } else {
         gpio_set_level(ledArray[i], 0);
      }
   }
}

void delayMs(uint16_t ms) {
   vTaskDelay(ms / portTICK_PERIOD_MS);
}

static void initIO(void) {
   for (int i = 0; i < NUM_LEDS; i++) {
      gpio_reset_pin(ledArray[i]);
      gpio_set_direction(ledArray[i], GPIO_MODE_OUTPUT);
   }
   for (int i = 0; i < eMaxButtonId; i++) {
      gpio_reset_pin(btnArray[i]);
      gpio_set_direction(btnArray[i], GPIO_MODE_INPUT);
      gpio_pullup_en(btnArray[i]);
   }
}

void rotateSevenBitsOnce(eDirection_t direction) {
   if (direction == eGoingLeft) {
      state <<= 1;
      state |= 1;
   } else {
      state >>= 1;
      state |= 1 << 6;
   }
}

void playSequence(eGameState_t gameState) {
   switch (gameState) {
      case eWaitForStart:
         if (!stateFlag) {
            stateFlag = 1;
            startTime[0] = _millis;
            state = 0xFE;
            direction = eGoingLeft;
         } else {
            if (_millis - startTime[0] > 500) {
               startTime[0] = _millis;
               rotateSevenBitsOnce(direction);
               if (state == 0x7E || state == 0xBF) direction = (direction == eGoingLeft) ? eGoingRight : eGoingLeft;
            }
         }
         break;

      case eOngoingGame:
         if (!stateFlag) {
            stateFlag = 1;
            startTime[0] = _millis;
            state = 1;
            ledDelay = 300;
            direction = eGoingRight;
         }
         if (_millis - startTime[0] > ledDelay) {
            startTime[0] = _millis;
            state = (direction == eGoingRight) ? (state << 1) : (state >> 1);
            if (state == 1 || state == 64) ledDelay -= SPEED_UP;
         }
         break;

      case eEnd:
         if (!stateFlag) {
            score = 1 << ((score / 2) - 1);
            state = score;
            stateFlag = 1;
            startTime[0] = _millis;
            updateLedArray(state);
         } else {
            if (_millis - startTime[0] > LED_ON_DELAY && state == 0) {
               startTime[0] = _millis;
               state = score;
               updateLedArray(state);
            } else if (_millis - startTime[0] > LED_ON_DELAY && state) {
               startTime[0] = _millis;
               state = 0;
               updateLedArray(state);
            }
         }
      default:
         break;
   }

   updateLedArray(state);
}

eButtonState_t checkButtons(eButtonId_t *buttonNumber) {
   for (int i = 0; i < eMaxButtonId; i++) {
      if (gpio_get_level(btnArray[i]) == 0 && startTime[i + 1] == 0) startTime[i + 1] = _millis;
      if (gpio_get_level(btnArray[i]) && startTime[i + 1] > 0) {
         if (_millis - startTime[i + 1] > 50 && _millis - startTime[i + 1] < 1000) {
            *buttonNumber = i;
            startTime[i + 1] = 0;
            return eBtnShortPressed;
         } else if (_millis - startTime[i + 1] > 1000) {
            *buttonNumber = i;
            startTime[i + 1] = 0;
            return eBtnLongPressed;
         } else
            startTime[i + 1] = 0;
      }
   }
   return eBtnUndefined;
}

ePlayerInputState_t checkPlayerInput(eButtonState_t buttonState, eButtonId_t buttonId) {
   if (buttonState == eBtnShortPressed) {
      if (buttonId == eLeftButton) {
         if (direction == eGoingLeft && (state == 1 || state == 2)) {
            return eCorrect;
         } else
            return eIncorrect;
      }
      if (buttonId == eRightButton) {
         if (direction == eGoingRight && (state == 64 || state == 32))
            return eCorrect;
         else
            return eIncorrect;
      }
   }
   if (!state) return eIncorrect;
   return eWaiting;
}

int app_main(void) {
   eGameState_t currentGameState = eGameRestart;
   eGameState_t lastGameState = currentGameState;
   ePlayerInputState_t playerInputState;
   eButtonId_t buttonId;
   eButtonState_t buttonState;

   initIO();

   while (1) {
      buttonState = checkButtons(&buttonId);
      if (buttonState == eBtnLongPressed) {
         currentGameState = eGameRestart;
      }
      switch (currentGameState) {
         case eGameRestart:
            state = 1;
            score = 0;
            _millis = 0;
            ledDelay = 300;
            currentGameState++;
            direction = eGoingRight;
            break;

         case eWaitForStart:
            if (buttonState == eBtnShortPressed) {
               state = 1;
               _millis = 0;
               currentGameState++;
            }
            playSequence(eWaitForStart);
            break;

         case eOngoingGame:
            playerInputState = checkPlayerInput(buttonState, buttonId);
            if (playerInputState == eCorrect) {
               score++;
               ledDelay -= 20;
               direction = (direction == eGoingLeft) ? eGoingRight : eGoingLeft;
            } else if (playerInputState == eIncorrect)
               currentGameState = eEnd;
            playSequence(eOngoingGame);
            break;

         case eEnd:
            playSequence(eEnd);
            break;
      }
      if (lastGameState != currentGameState) {
         stateFlag = false;
         lastGameState = currentGameState;
      }
      delayMs(1);
      _millis++;
      fflush(stdout);
   }
}