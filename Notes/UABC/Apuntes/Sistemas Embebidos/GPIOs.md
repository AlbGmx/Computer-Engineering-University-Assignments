[Documentación](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html)

> [!NOTE]
> Los pines RTC se pueden usar como fuente para despertar al ESP32 cuando está en modo deep sleep.

The ESP32 chip features 34 physical GPIO pins (GPIO0 ~ GPIO19, GPIO21 ~ GPIO23, GPIO25 ~ GPIO27, and GPIO32 ~ GPIO39). Each pin can be used as a general-purpose I/O, or be connected to an internal peripheral signal.

![[image.png]]

- GPI: GPIO34-39 can only be set as input mode and do not have software-enabled pullup or pulldown functions.
- SPI0/1: GPIO6-11 and GPIO16-17 are usually connected to the SPI flash and PSRAM integrated on the module and therefore should not be used for other purposes.
- ADC2: ADC2 pins cannot be used when Wi-Fi is used.
- TXD & RXD are usually used for flashing and debugging.
- Do not use the interrupt of GPIO36 and GPIO39 when using ADC or Wi-Fi and Bluetooth with sleep mode enabled.

# Funciones de Configuracíon

```C
//Resetear GPIO
esp_err_t gpio_reset_pin(gpio_num_t gpio_num)

//Configurar GPIO como Entrada/Salida
esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode)

//Enum for direction mode

- GPIO_MODE_DISABLE_GPIO: disable input and output
- GPIO_MODE_INPUT_GPIO mode: input only
- GPIO_MODE_OUTPUT_GPIO mode: output only mode
- GPIO_MODE_OUTPUT_OD_GPIO mode: output only with open-drain mode
- GPIO_MODE_INPUT_OUTPUT_OD_GPIO mode: output and input with open-drain mode
- GPIO_MODE_INPUT_OUTPUT_GPIO mode: output and input mode

//Ajustar el GPIO a un valor cuando es un GPIO de salida
esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)

//Leer GPIO
int gpio_get_level(gpio_num_t gpio_num)

//Función principal, no es el main de arranque
//Do not rely on the default configurations values in the Technical Reference Manual,
//    because it may be changed in the bootloader or application startup code before app_main.
void app_main() {
	//Aqui se ejecuta nuestro código
}
```

# Ejemplo GPIO

https://github.com/espressif/esp-idf/blob/dbce23f8a449eb436b0b574726fe6ce9a6df67cc/examples/peripherals/gpio/generic_gpio/main/gpio_example_main.c

```C
\#include <stdio.h>
\#include "freertos/FreeRTOS.h"

\#define LED_PIN GPIO_NUM_2

void app_main() {
	printf("cnt: %d\n", cnt++);
	vTaskDelay(1000 / portTICK_PERIOD_MS);
	gpio_set_level(GPIO_OUTPUT_IO_0, cnt % 2);
}
```

# Pull-Up/Pull-Down

```C
//Activar/Desactivar Pull-Up
esp_err_t gpio_pullup_en(gpio_num_t gpio_num)
esp_err_t gpio_pullup_dis(gpio_num_t gpio_num)

//Activar/Desactivar Pull-Down
esp_err_t gpio_pulldown_en(gpio_num_t gpio_num)
esp_err_t gpio_pulldown_dis(gpio_num_t gpio_num)

//Configurar las resistencias Pull-Up/Dn del GPIO
esp_err_t gpio_set_pull_mode(gpio_num_t gpio_num, gpio_pull_mode_t pull)
//Las resistencias de los GPIOS del 34-39 no pueden ser configuradas por software

//Enum for pull up/dn config:
- GPIO_PULLUP_ONLY
- GPIO_PULLDOWN_ONLY
- GPIO_PULLUP_PULLDOWN_ONLY
- GPIO_FLOATING
```

# Interrupciones

```C
//Setar el tipo de interrupción
esp_err_t gpio_set_intr_type(gpio_num_t gpio_num, gpio_int_type_t intr_type)

//Enums for Interrupts
- GPIO_INTR_DISABLE: Disable GPIO interrupt
- GPIO_INTR_POSEDGE: rising edge
- GPIO_INTR_NEGEDGE: falling edge
- GPIO_INTR_ANYEDGE: both rising and falling edge
- GPIO_INTR_LOW_LEVEL: input low level trigger
- GPIO_INTR_HIGH_LEVEL: input high level trigger
- GPIO_INTR_MAX

//Habilitar TODAS las interrupciones del GPIO
esp_err_t gpio_install_isr_service(int intr_alloc_flags)

//Deshabilitar las interrupciones
void gpio_uninstall_isr_service(void)

//Agregar una handler de una interrupción
esp_err_t gpio_isr_handler_add(gpio_num_t gpio_num, gpio_isr_t isr_handler, void *args)
```

# Cargar ISR en RAM

# Tareas

La cola es FIFO
