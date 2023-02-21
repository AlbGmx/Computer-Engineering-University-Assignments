#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_2
#define BTN_GPIO GPIO_NUM_4

void delayMs(uint16_t ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}

static void update_led(int led)
{
    /* Set the GPIO level according to the button state (LOW or HIGH)
       Inverting button as the button will read '0' when pressed,
       and we want the LED to turn on when the button is pressed. */
    gpio_set_level(LED_GPIO, led); 
}

static void configure_led(void)
{
    gpio_reset_pin(LED_GPIO);
    gpio_reset_pin(BTN_GPIO);
    /* Set LED GPIO as a push/pull output */
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    /* Set LED GPIO as a push/pull output */
    gpio_set_direction(BTN_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(BTN_GPIO);
}

void app_main(void)
{
    printf("Hello world!\n");
    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());


    /* GPIO example */
    configure_led();
    char morse[][26]={".-", "-...", "-.-.", "-..",".","..-.", "--.","....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    char *nombre= "cristina marlen torres gastelum";
    //char *nombre= "sos";
    int time = 200; ///tiempo que dura el punto
    update_led(0);

    for(int i=0;i<strlen(nombre);i++){
        printf("letra: %c\n", nombre[i]);

        if(nombre[i]!=' '){
            for(int j=0; j< strlen(morse[(int)nombre[i]-97]);j++){

                if(morse[(int)nombre[i]-97][j] =='.'){
                    printf(".\n");
                    update_led(1); 
                    delayMs(time); //tiempo del punto
                }
                else{
                    printf("-\n");
                    update_led(1);
                    delayMs(time*3); //raya es 3 veces el punto
                }
                 update_led(0);
                 delayMs(time); ///entre cada . y - es el punto
            }

            printf("Siguiente letra\n");
            update_led(0);
            delayMs(time*2); //entre cada letra 3 veces el punto
        }
        else{
            update_led(0);
            delayMs(time*2); //espacios son 2 veces el punto
        }
    }
    update_led(0); //apagar led
    
}