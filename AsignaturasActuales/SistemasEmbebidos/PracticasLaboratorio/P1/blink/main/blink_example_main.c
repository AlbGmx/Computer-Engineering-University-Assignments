#include <stdio.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BASEANIMATIONSPEED 128

#define DIPSWITCHSIZE 8
#define DIPSWITCH1 GPIO_NUM_21
#define DIPSWITCH2 GPIO_NUM_19
#define DIPSWITCH3 GPIO_NUM_18
#define DIPSWITCH4 GPIO_NUM_5
#define DIPSWITCH5 GPIO_NUM_17
#define DIPSWITCH6 GPIO_NUM_16
#define DIPSWITCH7 GPIO_NUM_4
#define DIPSWITCH8 GPIO_NUM_2

#define LEDSIZE 5
#define LED5 GPIO_NUM_13
#define LED4 GPIO_NUM_12
#define LED3 GPIO_NUM_14
#define LED2 GPIO_NUM_27
#define LED1 GPIO_NUM_26

#define MAX_LED_STATE 1 << LEDSIZE
#define RESET_LED_STATE 1 << (LEDSIZE - 1)

typedef enum eDirection { eGoingLeft = 1, eGoingRight = -1 } eDirection;

bool playingAnimation					  = false;
uint8_t ledState							  = 0;
uint8_t dipswitchState					  = 0;
uint8_t ledArray[LEDSIZE]				  = {LED1, LED2, LED3, LED4, LED5};
uint8_t dipswitchArray[DIPSWITCHSIZE] = {DIPSWITCH1, DIPSWITCH2, DIPSWITCH3, DIPSWITCH4,
													  DIPSWITCH5, DIPSWITCH6, DIPSWITCH7, DIPSWITCH8};
uint64_t animationSpeed					  = 0;
uint64_t startTime						  = 0;
uint64_t milis								  = 0;
eDirection direction						  = eGoingRight;

void setupPins() {
	for (int i = 0; i < LEDSIZE; i++)
		gpio_set_direction(ledArray[i], GPIO_MODE_OUTPUT);

	for (int i = 0; i < DIPSWITCHSIZE; i++) {
		gpio_set_direction(dipswitchArray[i], GPIO_MODE_INPUT);
		gpio_set_pull_mode(dipswitchArray[i], GPIO_PULLDOWN_ONLY);
	}
}

void readDIPSwitch() {
	dipswitchState = 0;
	for (int i = 0; i < DIPSWITCHSIZE; i++)
		dipswitchState |= gpio_get_level(dipswitchArray[i]) << i;
}

void updateLEDS() {
	for (int i = 0; i < LEDSIZE; i++)
		gpio_set_level(ledArray[i], ledState & (1 << i));
}

void reset() {
	milis				  = 0;
	direction		  = eGoingLeft;
	ledState			  = 0;
	dipswitchState	  = 0;
	playingAnimation = false;
}

void getAnimationInfo() {
	readDIPSwitch();
	direction = dipswitchState & (1 << (DIPSWITCHSIZE - 1)) ? eGoingRight : eGoingLeft;
	if (dipswitchState & ~(1 << (DIPSWITCHSIZE - 1)))
		animationSpeed = BASEANIMATIONSPEED / (dipswitchState & ~(1 << (DIPSWITCHSIZE - 1)));
	else
		animationSpeed = 0;
      printf("animationSpeed: %lld\n", animationSpeed);
}

void playAnimation() {
	getAnimationInfo();
	if (animationSpeed == 0) {
		playingAnimation = false;
	} else {
		if (!playingAnimation) {
			startTime		  = milis;
			playingAnimation = true;
		} else if (milis - startTime >= animationSpeed) {
			startTime = milis;
			if (direction == eGoingLeft) {
				ledState <<= 1;
				if ((ledState >= MAX_LED_STATE) | (ledState == 0)) ledState = 1;

			} else {
				ledState >>= 1;
				if ((ledState == 0) | (ledState >= RESET_LED_STATE)) ledState = RESET_LED_STATE;
			}
		}
	}
}

int app_main() {
	setupPins();
	reset();
	while (1) {
		playAnimation();
		updateLEDS();
		milis++;
		vTaskDelay(1);
	}
}
