#include <avr/io.h>
#include <inttypes.h>

#define LEFT_BTN PD2
#define RIGHT_BTN PD3
#define LED_ON_DELAY 300
#define LED_OFF_DELAY 50
#define WALKING_ZEROS_DELAY 500
#define SPEED_UP 20
#define WALKING_ZEROS 0 

extern void Delay(uint8_t); /* Prototipo de la función Delay */

typedef enum eDirection_tag { 
   eGoingLeft = 1, 
   eGoingRight = -1 
} eDirection_t;

enum {
   leftBtnIndex = 0,
   rightBtnIndex,
   walkingZerosIndex,
   gameOnIndex,
   blinkEndIndex,
};

enum {
   AllLEDsOff = 0,
   LED1,
   LED2,
   LED3,
   LED4,
   LED5,
   LED6,
   LED7,
};

// Enumerations
typedef enum ButtonState_tag {
   eBtnUndefined = 0,
   eBtnShortPressed, // if duration is lower than 999mS, its a short press
   eBtnLongPressed   // else if > 1000ms its a long Press
} eButtonState_t;

typedef enum PlayerInputState_tag {
   eWaiting = 0,
   eCorrect,
   eIncorrect
} ePlayerInputState_t;

typedef enum ButtonId_tag{
	eLeftButton = 0, // This enum must follow btnArray
	eRightButton,
	eMaxButtonId
} eButtonId_t;

typedef enum GameState_tag {
   eGameRestart = 0,
   eWaitForStart,
   eOngoingGame,
   eEnd
} eGameState_t;

// Global variables;
uint32_t startTime[] = {0, 0, 0, 0, 0};
uint32_t _millis=0;
uint32_t ledDelay = LED_ON_DELAY;
uint8_t score;
uint8_t state;
eDirection_t direction = eGoingLeft;

void setLEDsAsInput() {
   PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB5));
   DDRB  &= ~((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB5));
}

static void initIO(void) {
   DDRD &= ~((1 << LEFT_BTN) | (1 << RIGHT_BTN));
   PORTD |= ((1 << LEFT_BTN) | (1 << RIGHT_BTN));
   setLEDsAsInput();
}

void updateLedArray(uint8_t status) {
   setLEDsAsInput();
   switch (status) {
      case LED1:
         DDRB |= (1 << PB0) | (1 << PB1);
         PORTB &= ~(1 << PB1);
         PORTB |= (1 << PB0);
      break;
      case LED2:
         DDRB |= (1 << PB0) | (1 << PB1);
         PORTB &= ~(1 << PB0);
         PORTB |= (1 << PB1);
      break;
      case LED3:
         DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB5);
         PORTB &= ~(1 << PB2);
         PORTB |= (1 << PB1) | (1 << PB5);
      break;
      case LED4:
         DDRB |= (1 << PB1) | (1 << PB2);
         PORTB &= ~(1 << PB1);
         PORTB |= (1 << PB2);
      break;
      case LED5:
         DDRB |= (1 << PB0) | (1 << PB2);
         PORTB &= ~(1 << PB2);
         PORTB |= (1 << PB0);
      break;
      case LED6:
         DDRB |= (1 << PB0) | (1 << PB2);
         PORTB &= ~(1 << PB0);
         PORTB |= (1 << PB2);
      break;
      case LED7:
         DDRB |= (1 << PB0) | (1 << PB3);
         PORTB &= ~(1 << PB3);
         PORTB |= (1 << PB0);
      break;
   case AllLEDsOff:
   default:
      DDRB |= (1<<PB5);
      PORTB |= (1<<PB5);
      break;
   }
}

void walkingZeros() {
   static uint8_t walkingZerosState = 0;
   if(startTime[walkingZerosIndex] == 0) {
      startTime[walkingZerosIndex] = _millis;
      walkingZerosState = 8;
   } else {
      if (_millis - startTime[walkingZerosIndex] >= WALKING_ZEROS_DELAY) {
         startTime[walkingZerosIndex] = _millis;
         walkingZerosState--;
         if (walkingZerosState<1) {
            walkingZerosState = 7;
         }
      }
   }
   state = 1 + (_millis % 7);
   if (state == walkingZerosState) {
      state++;
   }
}

void blinkEnd(uint8_t score) {
   static uint8_t blinkEndState = 0;
   if(startTime[blinkEndIndex] == 0) {
      startTime[blinkEndIndex] = _millis;
      blinkEndState = 0;
   } else {
      if (blinkEndState == 0) {
         ledDelay = LED_ON_DELAY;
      } else {
         ledDelay = LED_OFF_DELAY;
      }
      if (_millis - startTime[blinkEndIndex] >= ledDelay) {
         startTime[blinkEndIndex] = _millis;
         blinkEndState++;
         if (blinkEndState>1) {
            blinkEndState = 0;
         }
      }
   }
   state = (blinkEndState == 0) ? score : AllLEDsOff;
}

void gameOn() {
   if(startTime[gameOnIndex] == 0) {
      startTime[gameOnIndex] = _millis;
      direction = eGoingLeft;
      state = LED1;
   } else {
      if (_millis - startTime[gameOnIndex] >= ledDelay) {
         startTime[gameOnIndex] = _millis;
         state += direction;
      }
   }
}

void playSequence(eGameState_t gameState) {
   switch (gameState) {
      case eWaitForStart:
         walkingZeros();
         break;
      case eOngoingGame:
         gameOn();
         break;
      case eEnd:
         blinkEnd(score/2);
         break;
      case eGameRestart:
      default:
         break;
   }
}

ePlayerInputState_t checkPlayerInput(eButtonState_t buttonState, eButtonId_t buttonId) {
   if (buttonState == eBtnShortPressed) {
      if (buttonId == eLeftButton) return (direction == eGoingLeft && (state == LED7 || state == LED6)) ? eCorrect : eIncorrect;
      if (buttonId == eRightButton) return (direction == eGoingRight && (state == LED1 || state == LED2)) ? eCorrect : eIncorrect;
   }
   if (state == AllLEDsOff || state > LED7) return eIncorrect;
   return eWaiting;
}

eButtonState_t checkButtons(eButtonId_t *buttonId) {
   if ((PIND & (1 << LEFT_BTN)) == 0) {
      if (startTime[leftBtnIndex] == 0) {
         startTime[leftBtnIndex] = _millis;
         return eBtnUndefined;
      } 
   }else {
      if(startTime[leftBtnIndex] != 0){
         if (_millis - startTime[leftBtnIndex] < 100) {
            startTime[leftBtnIndex] = 0;
            return eBtnUndefined;
         } else if (_millis - startTime[leftBtnIndex] < 1000) {
            *buttonId = leftBtnIndex;
            startTime[leftBtnIndex] = 0;
            return eBtnShortPressed;
         } else {
            *buttonId = leftBtnIndex;
            startTime[leftBtnIndex] = 0;
            return eBtnLongPressed;
         }
      }
   }
   if ((PIND & (1 << RIGHT_BTN)) == 0) {
      if (startTime[rightBtnIndex] == 0) {
         startTime[rightBtnIndex] = _millis;
         return eBtnUndefined;
      }
   }else {
      if(startTime[rightBtnIndex] != 0){
         if (_millis - startTime[rightBtnIndex] < 100) {
            startTime[rightBtnIndex] = 0;
            return eBtnUndefined;
         } else if (_millis - startTime[rightBtnIndex] < 1000) {
            *buttonId = rightBtnIndex;
            startTime[rightBtnIndex] = 0;
            return eBtnShortPressed;
         } else {
            *buttonId = rightBtnIndex;
            startTime[rightBtnIndex] = 0;
            return eBtnLongPressed;
         }
      }
   }
      
   return eBtnUndefined;
}

int main(void) {
 	eGameState_t  currentGameState = eGameRestart;
	ePlayerInputState_t playerInputState;
	eButtonState_t buttonState;
   eButtonId_t buttonId;
	initIO();

   while(1) {
      buttonState = checkButtons(&buttonId);
      if (buttonState == eBtnLongPressed) currentGameState = eGameRestart;

		switch(currentGameState){
			case eGameRestart:
            startTime[walkingZerosIndex] = 0;
            startTime[gameOnIndex] = 0;
            startTime[blinkEndIndex] = 0;
            startTime[leftBtnIndex] = 0;
            startTime[rightBtnIndex] = 0;
            score = 0;
            state = AllLEDsOff;
            currentGameState = eWaitForStart;
            direction = eGoingLeft;
            ledDelay = LED_ON_DELAY;
			break;

			case eWaitForStart:
			   playSequence(eWaitForStart);
			   if (buttonState == eBtnShortPressed) {
               currentGameState++;
               state = LED1;
            }
			break;

			case eOngoingGame:
			   playSequence(eOngoingGame);
			   playerInputState = checkPlayerInput(buttonState, buttonId);
			   if (playerInputState == eCorrect) {
               direction = (direction == eGoingLeft) ? eGoingRight : eGoingLeft;
			   	score++;
               ledDelay -= SPEED_UP;
			   } else if (playerInputState == eIncorrect) currentGameState = eEnd;
			break;
         
			case eEnd:
			   playSequence(eEnd);
			break;
      }
      updateLedArray(state);
      _millis++;
      Delay(1);
   }
}