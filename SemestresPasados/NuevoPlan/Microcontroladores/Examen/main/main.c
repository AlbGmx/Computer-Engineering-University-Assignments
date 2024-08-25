/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 21/02/2023
 * Descripcion: Practica 1, Configuracion de ambiente de desarrollo
 * Laboratorio de la clase Microcontroladores
 */


#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_2
#define DOT 300
#define DASH (DOT * 3)
#define PAUSE 1
#define BREAK (DOT * 5)
#define END 0

uint16_t mA[] = {DOT, DASH, END};
uint16_t mE[] = {DOT, END};
uint16_t mL[] = {DOT, DASH, DOT, DOT, END};
uint16_t mM[] = {DASH, DASH, END};
uint16_t mN[] = {DASH, DOT, END};
uint16_t mU[] = {DOT, DOT, DASH, END};
uint16_t mEND[] = {END};
uint16_t *name[] = {mE, mM, mM, mA, mN, mU, mE, mL, mEND};

void app_main() {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    printf("Hello world!\n");

    while (1){
        printf("printing EMMANUEL\n");
        sendMorse(name);
        printf("\n\n");
    }
}

void delayMs(uint16_t ms) { vTaskDelay(ms / portTICK_PERIOD_MS); }

void sendMorse(uint16_t *data[]) {
    while (*data != mEND) {
        sendLetter(*data);
        data++;
    }
}

void sendLetter(uint16_t *data) {
    //Se utiliza fflush(stdout) para que la salida se imprima en la consola inmediatamente
    while (*data != END) {
        if (*data == DOT) {
            printf(". ");
            fflush(stdout);
            gpio_set_level(LED_GPIO, 1);
            delayMs(DOT);
            gpio_set_level(LED_GPIO, 0);
            delayMs(DOT);
        }
        else if (*data == DASH) {
            printf("- ");
            fflush(stdout);
            gpio_set_level(LED_GPIO, 1);
            delayMs(DASH);
            gpio_set_level(LED_GPIO, 0);
            delayMs(DOT);
        }
        data++;
    }
    delayMs(BREAK);
    printf("\n");
}