#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include <string.h>

#define BUF_SIZE (1024)
#define UART_RX_PIN (3)
#define UART_TX_PIN (1)

#define UART_RX_PIN_2 (16)
#define UART_TX_PIN_2 (17)

#define ONE_BYTE 1
#define ASCII_PRINTABLE_START 32
#define ASCII_PRINTABLE_END 126
#define NEWLINE '\n'
#define CARRIAGE_RETURN '\r'
#define NULL_TERMINATOR '\0'

static void UART_init(void *arg) {
	uart_config_t uart_config = {
		 .baud_rate	 = 115200,
		 .data_bits	 = UART_DATA_8_BITS,
		 .parity		 = UART_PARITY_DISABLE,
		 .stop_bits	 = UART_STOP_BITS_1,
		 .flow_ctrl	 = UART_HW_FLOWCTRL_DISABLE,
		 .source_clk = UART_SCLK_DEFAULT,
	};
	// Configure UART parameters
	ESP_ERROR_CHECK(uart_param_config(UART_NUM_0, &uart_config));
	ESP_ERROR_CHECK(uart_param_config(UART_NUM_2, &uart_config));

	// Set UART pins
	ESP_ERROR_CHECK(uart_set_pin(UART_NUM_0, UART_TX_PIN, UART_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
	ESP_ERROR_CHECK(uart_set_pin(UART_NUM_2, UART_TX_PIN_2, UART_RX_PIN_2, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));

	// Setup UART buffered IO with event queue
	QueueHandle_t uart_queue;
	// Install UART driver using an event queue here
	ESP_ERROR_CHECK(uart_driver_install(UART_NUM_0, BUF_SIZE * 2, BUF_SIZE * 2, 10, &uart_queue, 0));

	ESP_ERROR_CHECK(uart_driver_install(UART_NUM_2, BUF_SIZE * 2, BUF_SIZE * 2, 10, &uart_queue, 0));
}

bool UART_kbhit(void) {
	if (uart_get_buffered_data_len(UART_NUM_0) > 0) return true;
}

char UART_getchar(void) {
	uint8_t data;
	int len = uart_read_bytes(UART_NUM_0, &data, ONE_BYTE, 20 / portTICK_PERIOD_MS);
	return data;
}

void UART_putchar(char c) { uart_write_bytes(UART_NUM_0, &c, ONE_BYTE); }

void UART_puts(char *str) {
	while (*str != '\0')
		UART_putchar(*str++);
}

void UART_gets(char *str) {
	size_t i = 0;
	char c;

	while (uart_read_bytes(UART_NUM_0, (uint8_t *)&c, 1, portMAX_DELAY) != CARRIAGE_RETURN) {
		if (c >= ASCII_PRINTABLE_START && c <= ASCII_PRINTABLE_END && i < BUF_SIZE - 1) str[i++] = c;
	}
	str[i] = NULL_TERMINATOR;
}
