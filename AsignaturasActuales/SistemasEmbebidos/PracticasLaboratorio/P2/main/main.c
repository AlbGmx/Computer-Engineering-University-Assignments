#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"
#include <math.h>
#include "driver/gpio.h"

// Adc
#define ADC_UNIT ADC_UNIT_1
#define SENSOR_TEMP_CHANNEL ADC_CHANNEL_4
#define SENSOR_ILUM_CHANNEL ADC_CHANNEL_5
// Button
#define BUTTON_SELECT GPIO_NUM_13
#define BUTTON_SELECT_MASK (1ULL << BUTTON_SELECT)
#define ESP_INTR_FLAG_DEFAULT 0
// Leds
#define LIGHT_0 GPIO_NUM_26
#define LIGHT_1 GPIO_NUM_27
#define LIGHT_2 GPIO_NUM_14
#define LIGHT_3 GPIO_NUM_12
#define HEATER_LED GPIO_NUM_25
#define LEDS_MASK (1ULL << LIGHT_0 | 1ULL << LIGHT_1 | 1ULL << LIGHT_2 | 1ULL << LIGHT_3 | 1ULL << HEATER_LED)

// Parameters used by Wowki components
#define SENSORS_BITWIDTH ADC_BITWIDTH_10
#define SENSOR_ATTENUATION ADC_ATTEN_DB_11
#define MAX_LUMINOSITY 100000
#define SINGLE_LED_VALUE MAX_LUMINOSITY / 4
#define V_REF 5.0

// LDR sensor parameters
#define RL10 50	// LDR resistance @ 10lux (in kilo-ohms)
#define GAMMA 0.7 // Slope of the log(R) / log(lux) graph
// This sensor ranges from 0.1 to 1000 lux

// NTC temperature parameters
#define BETA 3975 // The beta coefficient of the thermistor
// This sensor ranges from -28 to 80 degrees Celsius

// Pre computed values (update when modifying the sensor parameters!)
#define INV_GAMMA 1.428571			 // 1 / GAMMA
#define RL10_KGAMMA 250593.616813 // RL10 * 1e3 * pow(10, GAMMA)

float getTemperature();
float getIlumination();
void logStateChange(uint8_t lastState);
void setLightsState(float iluminationValue, float iluminationTreshold);

// ISR routines
static void selectButtonInterrupt(void *);
static void selectButtonHandler(void *);

// Global variables
bool heater				= false;
uint8_t lights			= 0;
static uint64_t ms	= 0;
uint8_t selectedRoom = 0;
gpio_config_t io_conf;
static QueueHandle_t gpio_evt_queue = NULL;
// ADC variables
static int adcRawValue;
static float sensorValues[2];
adc_oneshot_unit_handle_t sensorHandle;
adc_oneshot_unit_init_cfg_t sensorConfig	 = {.unit_id = ADC_UNIT};
adc_oneshot_chan_cfg_t sensorChannelConfig = {.atten = SENSOR_ATTENUATION, .bitwidth = SENSORS_BITWIDTH};

// Enums
enum ROOM { eBedroom = 0, eLivingroom, eKitchen, eRoomMAX };
enum SENSORS { eIlumination, eTemperature, eSensorMAX };
enum LIGHTS { eAllOff = 0, eOneLight, eTwoLights = 3, eThreeLights = 7, eAllLights = 15, eTresholdExceeded };

typedef struct {
	float iluminationTreshold;
	float temperatureTreshold;
} tresholds_t;

tresholds_t roomTresholds[3] = {
	 {MAX_LUMINOSITY + MAX_LUMINOSITY / 10, 40}, // Bedroom
	 {60000, -10},											// Livingroom
	 {30000, 0},											// Kitchen
};

void updateLights() {
	gpio_set_level(LIGHT_0, lights & 1);
	gpio_set_level(LIGHT_1, lights & 2);
	gpio_set_level(LIGHT_2, lights & 4);
	gpio_set_level(LIGHT_3, lights & 8);
	gpio_set_level(HEATER_LED, heater);
}

void gpioInit() {
	// Input button, set isr service and handler
	io_conf.pin_bit_mask = BUTTON_SELECT_MASK;
	io_conf.mode			= GPIO_MODE_INPUT;
	io_conf.intr_type		= GPIO_INTR_ANYEDGE;
	io_conf.pull_up_en	= 1;
	gpio_config(&io_conf);
	gpio_set_intr_type(BUTTON_SELECT, GPIO_INTR_ANYEDGE);
	gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
	xTaskCreate(selectButtonInterrupt, "selectButtonInterrupt", 2048, NULL, 10, NULL);
	gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
	gpio_isr_handler_add(BUTTON_SELECT, selectButtonHandler, (void *)BUTTON_SELECT);

	// Output lights
	io_conf.pin_bit_mask = LEDS_MASK;
	io_conf.mode			= GPIO_MODE_OUTPUT;
	io_conf.pull_up_en	= 0;
	gpio_config(&io_conf);
}

void adcInit() {
	ESP_ERROR_CHECK(adc_oneshot_new_unit(&sensorConfig, &sensorHandle));
	ESP_ERROR_CHECK(adc_oneshot_config_channel(sensorHandle, SENSOR_TEMP_CHANNEL, &sensorChannelConfig));
	ESP_ERROR_CHECK(adc_oneshot_config_channel(sensorHandle, SENSOR_ILUM_CHANNEL, &sensorChannelConfig));
}

void app_main() {
	gpioInit();
	adcInit();
	uint8_t lastState = 0;
	printf("\n\n\nSelected room: %d\n Ilumination treshold has been set to: %f\n Temperature treshold has been set "
			 "to: %f\n\n",
			 selectedRoom, roomTresholds[selectedRoom].iluminationTreshold,
			 roomTresholds[selectedRoom].temperatureTreshold);

	while (1) {
		printf("\nikimunaction = %0.2f", sensorValues[eIlumination]);
		sensorValues[eIlumination] = getIlumination();
		sensorValues[eTemperature] = getTemperature();

		setLightsState(sensorValues[eIlumination], roomTresholds[selectedRoom].iluminationTreshold);
		logStateChange(lastState);
		lastState = lights;

		if (sensorValues[eTemperature] < roomTresholds[selectedRoom].temperatureTreshold && !heater) {
			printf("Temperature treshold has been reached, turning on the heater\n");
			heater = true;
		} else if (sensorValues[eTemperature] > roomTresholds[selectedRoom].temperatureTreshold && heater) {
			printf("Temperature treshold has been reached, turning off the heater\n");
			heater = false;
		}
		ms++;
		updateLights();
		vTaskDelay(1 / portTICK_PERIOD_MS);
	}
}

void setLightsState(float iluminationValue, float iluminationTreshold) {
	if (iluminationValue < iluminationTreshold) {
		switch ((uint64_t)iluminationValue) {
			case 0 ... SINGLE_LED_VALUE - 1:
				lights = eAllLights;
				break;
			case SINGLE_LED_VALUE ... SINGLE_LED_VALUE * 2 - 1:
				lights = eThreeLights;
				break;
			case SINGLE_LED_VALUE * 2 ... SINGLE_LED_VALUE * 3 - 1:
				lights = eTwoLights;
				break;
			case SINGLE_LED_VALUE * 3 ... SINGLE_LED_VALUE * 4 - 1:
				lights = eOneLight;
				break;
			case MAX_LUMINOSITY:
			default:
				lights = eAllOff;
				break;
		}
	} else if (sensorValues[eIlumination] > roomTresholds[selectedRoom].iluminationTreshold) {
		lights = eTresholdExceeded;
	}
}

void logStateChange(uint8_t lastState) {
	if (lights != lastState) {
		switch (lights) {
			case eAllOff:
				printf("Light is very high, turning off the lights\n");
				break;
			case eOneLight:
				printf("Light is high, turning on 1 light\n");
				break;
			case eTwoLights:
				printf("Light is medium, turning on 2 lights\n");
				break;
			case eThreeLights:
				printf("Light is low, turning on 3 lights\n");
				break;
			case eAllLights:
				printf("Light is very low, turning on all the lights\n");
				break;
			case eTresholdExceeded:
				printf("Ilumination treshold has been exceeded, turning off all the lights\n");
				break;
		}
	}
}

static void IRAM_ATTR selectButtonHandler(void *arg) {
	uint32_t gpio_num = (uint32_t)arg;
	xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}

static void selectButtonInterrupt(void *arg) {
	static bool isPressed = 1;
	uint32_t io_num;
	for (;;) {
		if (xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
			isPressed = !isPressed;
			if (!isPressed) {
				selectedRoom = (selectedRoom + 1) % eRoomMAX;
				printf("Selected room: %d\n Ilumination treshold has been set to: %f\n Temperature treshold has been set "
						 "to: %f\n\n",
						 selectedRoom, roomTresholds[selectedRoom].iluminationTreshold,
						 roomTresholds[selectedRoom].temperatureTreshold);
			}
		}
	}
}

// Functions used by Wowki components
// NTC temperature sensor https://docs.wokwi.com/parts/wokwi-ntc-temperature-sensor#attributes
float getTemperature() {
	ESP_ERROR_CHECK(adc_oneshot_read(sensorHandle, SENSOR_TEMP_CHANNEL, &adcRawValue));
	return (BETA / (log(1 / ((1023. / adcRawValue) - 1)) + 13.3322)) - 273.15;
}

// LDR sensor https://docs.wokwi.com/parts/wokwi-photoresistor-sensor#attributes
float getIlumination() {
	ESP_ERROR_CHECK(adc_oneshot_read(sensorHandle, SENSOR_ILUM_CHANNEL, &adcRawValue));
	float voltage	  = adcRawValue / 1024. * V_REF;
	float resistance = 2000 * voltage / (1 - voltage / V_REF);
	// pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA)) is the formula to calculate the lux
	return pow(RL10_KGAMMA / resistance, INV_GAMMA);
}