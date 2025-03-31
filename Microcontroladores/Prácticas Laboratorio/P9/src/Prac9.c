#include <avr/io.h>
#include "Timer0.h"
#include "Timer2.h"
#include "UART.h"
extern void Delay(uint8_t); /* Prototipo de la función Delay */

void Clock_Update(void);
void Clock_Display(void);
void Clock_Ini(uint8_t, uint8_t, uint8_t);

static uint8_t seconds		= 0;
static uint8_t minutes		= 0;
static uint8_t hours			= 0;
static uint32_t aux_millis = 0;

void IO_init(void) {
	DDRB |= (1 << DDB7);
	PORTB &= ~(1 << PORTB7);
}

int main() {
	IO_init();
   // To modify the baudrate on platformio edit the file platformio.ini
	UART_AutoBaudRate();
	UART_Ini(0, 8, 0, 1);
	UART_clrscr();
	Timer2_Ini(1);
	Timer0_Ini();
	Clock_Ini(23, 50, 50);
	char str[10];

	PORTB |= (1 << PORTB7);

	while (1) {
		if (millis() - aux_millis >= 1000) {
			UART_clrscr();
			aux_millis = millis();
			Clock_Update();
			UART_gotoxy(5, 2);
			Clock_Display();
			UART_gotoxy(5, 3);
			UART_puts("millis =");
			/* itoa solo convertirá los 16bits menos significativos */
			itoa(millis(), str);
			justifyRightNoZeros(str, 5);
			UART_puts(str);
		}
	}
	return 0;
}

void Clock_Update(void) {
	seconds++;
	if (seconds == 60) {
		seconds = 0;
		minutes++;
		if (minutes == 60) {
			minutes = 0;
			hours++;
			if (hours == 24) {
				hours = 0;
			}
		}
	}
}

void Clock_Display(void) {
	char str[10];
	itoa(hours, str);
	justifyRight(str, 2);
	UART_puts(str);
	UART_puts(":");
	itoa(minutes, str);
	justifyRight(str, 2);
	UART_puts(str);
	UART_puts(":");
	itoa(seconds, str);
	justifyRight(str, 2);
	UART_puts(str);
}

void Clock_Ini(uint8_t h, uint8_t m, uint8_t s) {
	hours	  = h;
	minutes = m;
	seconds = s;
}