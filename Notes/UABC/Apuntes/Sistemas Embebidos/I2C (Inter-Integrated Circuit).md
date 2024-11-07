Especificación Original

- Direcciones de 7 bits
- 112 Máximo número de dispositivos
- Transmisión a 100KHz

Especificación de 1992

- Direcciones de 10 bits
- Fast-mode de 400KHz
  - High Speed mode a 3.4MHz,
  - Ultra speed mode a 5MHz
  - Fast-Mode plus a 1MHz

Solo dos lineas para intercambiar información

SDA: Serial DAta line

SCL: Serial CLock line

Bus bidireccional

# Jerarquía Controlador - Periférico

Controlador

- Dirige el reloj del bus
- Direcciona a los periféricos
- Lee y escribe datos de los registros de los periféricos

Periférico

- Responden al controlador
- No pueden iniciar la transacción
- Se conectan al bus con pines con colector o de drenaje abierto las cuales ponen la linea en bajo

**Cuando no se transmiten datos las lineas están en alto**

# Condiciones Inicio - Fin

## Inicio

- Ocurre al inicio de la transmisión
- Es iniciada por el controlador para despertar a los periféricos en el bus del estado inactivo
  - Es una transición de la línea SDA de estado alto a bajo
    - Es una de las dos ocasiones donde se permite que SDA cambie de estado cuando SCL está en alto

## Fin

- Ocurre al final de la transmisión
- Es generada por el controlador para indicar a los periféricos que deben regresar al esadi inactivo, liberar la línea SDA y no enviar mas datos en el bus
- Es una transición de la línea SDA de estado bajo a alto
  - Es una de las dos ocasiones donde se permite que SDA cambie de estado cuando SCL está en alto

En el resto de las condiciones, la línea SDA solo cambia cuando SCL está en bajo

# Tipos de Frame

## Frame de Dirección

- Es siempre el primero en cualquier secuencia de comunicación
- Para direcciones de 7 bits, la dirección es envia empezando del MSB
- La dirección es seguida de un bit que indica la operación
  - 1: Lectura
  - 0: Escritura
- El noveno bit es NACK/ACK de parte del periférico
  - NACK: Bus en Alto (No hubo respuesta)
  - ACK: El periférico pone el bus en bajo
- Una vez que el octavo bit ha sido enviado, el dispositivo receptor toma control de SDA
- Si el receptor no coloca a SDA en bajo antes del noveno pulso de reloj, se infiere que el receptor no recibió los datos o no supo como procesar el mensaje
- En este caso, el intercambio de información no se detiene y depende del controlador decidir como se procede

## Frame de Datos

- Después de enviar la dirección, inicia la transmisión de datos
- El controlador genera pulsos de reloj a intervalo regular
- Los datos son colocados en SDA por el controlador o el periférico dependiendo de la operación indicada
- Los datos se transmiten en bloques de 8 bits, iniciando por el MSB
- Despues de una lectura, el controlador debe indicar con un ACK si quiere seguir leyendo
- No hay límite de bytes a mandar
- Los bloques de datos siempre serán de 8 bits
- Los bits de SDA solo puede cambiar cuando la linea SCL está en alto
- Cada byte debe ser seguido ded un ACK generado por el receptor

## ACK / NACK

- Después de cada byte transmitido, el receptor envía un bit de ACK/NACK
- Un ACK denota que un byte se recibió exitosamente
- Un NACK indica que ocurrió un error en la transmisión de datos

- El controlador usa un nack después del último byte que quiere leer del perifériico para indicarle al periférico que debe de terminar la transmisión
- El receptor genera el ACK al poner la línea SDA en bajo
- Se genera un NACK cuando el receptor deja a SDA en alto y no responde de ninguna manera

## ESP32

- 2 Puertos I2C: I2C0 - I2C1
- Default:
  - SDA: GPIO 21
  - SCL: GPIO 22

## Master Config

```C
\#include <stdio.h>
\#include <string.h>
\#include "esp_log.h"
\#include "driver/i2c.h"

static const char *TAG = "master";

\#define I2C_MASTER_SCL 22
\#define I2C_MASTER_SDA 21
\#define I2C_SLAVE_ADDRESS 0x1C
\#define ACK_CHECK_EN 0x1

esp_err_t i2c_master_init(void) {
	i2c_config_t = i2c_master_conf = {
		.mode = I2C_MODE_MASTER,
		.sda_io_num = I2_MASTER_SDA,
		.sda_pullup_en = GPIO_PULLUP_EN,
		.scl_io_num = I2_MASTER_SCL,
		.scl_pullup_en = GPIO_PULLUP_EN,
		.master_clk_speed = 400000,
	}
	esp_err_t error = i2c_param_config(I2C_NUM_O, &i2c_master_init);
	if (error == ){
		return ;
	}
	i2c_driver_install(I2C_NUM_O, i2c_master_init.mode, 0, 0, 0);
}

esp_err_t i2c_master_send(char *data, int len) {
	esp_err res;
	i2c_cmd_handle_t cmd_handle = i2c_cmd_link_create();
	i2c_master_start(cmd_handle);
	i2c_master_write_byte(cmd_handle, I2C_SLAVE_ADDRESS << 1 | I2C_MASTER_WRITE, ACK_CHECK_EN);
	i2c_master_write(cmd_handle, data, len, ACK_CHECK_EN);
	i2c_master_stop(cmd_handle);

	res = i2c_master_cmd_begin(I2C_NUM_0, cmd_handle, 1000 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd_handle);
	return res;
}

void app_main(void) {
	ESP_ERROR_CHECK(i2c_master_init());

	while() {
		i2c_master_send(led_on, sizeof(led_on));
		ESP_LOGI(TAG, "LED on request");
		vTaskDelay(500 / portTICK_PERIOD_MS);
		i2c_master_send(led_off, sizeof(led_on));
		ESP_LOGI(TAG, "LED off request");
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}

}
```

## Slave Config
