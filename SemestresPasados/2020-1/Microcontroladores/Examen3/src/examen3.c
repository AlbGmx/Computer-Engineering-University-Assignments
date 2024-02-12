#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

// Definitions
#define F_OSC (uint32_t)16000000
#define UCSZ_OFFSET 5

// Prototypes
void delay(void);
void GPIO_Init(void);
void Timer2_Ini(uint8_t baseT);
uint8_t Timer2_Flag(void);
uint64_t counterT2(void);
uint64_t millis(void);
void UART_Ini(uint8_t, uint32_t, uint8_t, uint8_t, uint8_t);
void UART_puts(char *);
void UART_putchar(char);
char UART_getchar();
void UART_clrscr();
void UART_gotoxy(uint8_t x, uint8_t y);
void UART_forwardsX(uint8_t x);
void UART_backwardsX(uint8_t x);
void UART_color(uint8_t color);
void UART_resetColor();
void itoa(uint32_t number, char *str);
uint16_t atoi(char *str);
void Adc9_Init();
uint16_t Adc9_Read();

// Global variables
static uint8_t Flag;
static volatile uint64_t counter;
volatile uint8_t *regUBRRH[4] = {&UBRR0H, &UBRR1H, &UBRR2H, &UBRR3H};
volatile uint8_t *regUBRRL[4] = {&UBRR0L, &UBRR1L, &UBRR2L, &UBRR3L};
volatile uint8_t *regUSCRA[4] = {&UCSR0A, &UCSR1A, &UCSR2A, &UCSR3A};
volatile uint8_t *regUCSRB[4] = {&UCSR0B, &UCSR1B, &UCSR2B, &UCSR3B};
volatile uint8_t *regUCSRC[4] = {&UCSR0C, &UCSR1C, &UCSR2C, &UCSR3C};
volatile uint8_t *regUDR[4]	= {&UDR0, &UDR1, &UDR2, &UDR3};

/********************* MAIN **********************/

int main(void) {
	GPIO_Init();
	UART_Ini(0, 9600, 8, 0, 1);
	Adc9_Init();
	uint16_t adc = 0;
	char str[4];

	while (1) {
		adc = Adc9_Read();
		adc = (adc * (uint32_t)100) / 1023;

		switch (adc) {
			case 0 ... 24:
				PORTB &= ~(1 << PB4);
				UART_puts("Nivel 1 - 0%"); // PWM 0%
				break;

			case 25 ... 49:
				PORTB |= (1 << PB4);
				UART_puts("Nivel 2 - 25%"); // PWM 25%
				break;

			case 50 ... 74:
				PORTB &= ~(1 << PB4);
				UART_puts("Nivel 3 - 50%"); // PWM 50%
				break;

			case 75 ... 99:
				PORTB |= (1 << PB4);
				UART_puts("Nivel 4 - 75%"); // PWM 75%
				break;

			case 100 ... 124:
				PORTB &= ~(1 << PB4);
				UART_puts("Nivel 5 - 100%"); // PWM 100%
				break;

			default:
				break;
		}

		UART_forwardsX(10);
		UART_puts("ADC% = ");
		itoa(adc, str);
		UART_puts(str);
		UART_puts("\n\r");
	}
}
/********************* END MAIN **********************/

void delay(void) {
	volatile uint16_t counter = 0xFFFF;
	while (--counter)
		;
}

void GPIO_Init() {
	DDRB |= (1 << PB4);
	PORTB |= (1 << PB4);
}

void Adc9_Init() {
	ADMUX	 = (1 << REFS0) | (1 << MUX0); // Internal Clock, ADC9 -> ADMUX 100001
	ADCSRB = (1 << MUX5);					 // ADC9
	ADCSRA = (1 << ADEN) | (7 << ADPS2);
	DIDR0	 = (1 << ADC5D);
}

uint16_t Adc9_Read() {
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC))
		;
	return (ADCL | ADCH << 8);
}

// Usar PB4
void Timer2_Ini(uint8_t baseT) {
	TIMSK2 = 0;
	TCNT2	 = 0x00;							 /* Initialize value for Timer0 */
	TCCR2A = (1 << WGM01);				 /* Initialize Timer0 in CTC mode */
	OCR2A	 = (0.001 * 32768) * baseT; /* Set the compare register */
	TCCR2B = (1 << CS20);				 // Initialize with external oscilator and no prescaler
	TIFR2	 = 0;
	TIMSK2 = (1 << OCIE2A);
	sei();
}

uint8_t Timer2_Flag(void) {
	if (Flag) {
		Flag = 0;
		return 1;
	} else {
		return 0;
	}
}

ISR(TIMER2_COMPA_vect) {
	counter++;
	if (counter % 1000 == 0) {
		Flag = 1;
	}
}

uint64_t counterT2(void) { return counter; }

void UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop) {
	if (com <= 3) {
		// UBRR Formula => UBRRH:UBRRL = (F_OSC / (16 * baudrate)) - 1
		uint32_t ubrrValue	 = F_OSC / ((uint32_t)16 * baudrate) - 1;
		uint8_t paritySize[3] = {0, (1 << UPM01) | (1 << UPM00), (1 << UPM01)};

		*regUBRRH[com] = (uint8_t)(ubrrValue >> 8);
		*regUBRRL[com] = (uint8_t)ubrrValue;
		*regUCSRC[com] &= ~(3 << UCSZ00);
		*regUCSRC[com] |= (size - UCSZ_OFFSET)
								<< UCSZ00; // Using UCSZ_OFFSET to map the size (5 - 8) to the UCSZ0 bits (0 - 3)
		*regUCSRC[com] &= ~(3 << UPM00);
		*regUCSRC[com] |= paritySize[parity];
		*regUCSRC[com] = (stop == 1) ? (*regUCSRC[com] & ~(1 << USBS0)) : (*regUCSRC[com] | (1 << USBS0));
		*regUCSRB[com] |= (1 << TXEN0) | (1 << RXEN0);
	}
}

// Send
void UART_puts(char *str) {
	while (*str)
		UART_putchar(*str++);
}

void UART_putchar(char data) {
	while (!(*regUSCRA[0] & (1 << UDRE0)))
		;
	*regUDR[0] = data;
}

// Received
char UART_getchar() {
	while (!(*regUSCRA[0] & (1 << RXC0)))
		;
	return *regUDR[0];
}

// Escape sequences
void UART_clrscr() { UART_puts("\033[2J"); }

void UART_gotoxy(uint8_t x, uint8_t y) {
	char str[4];
	itoa(y, str);
	UART_putchar('\033');
	UART_putchar('[');
	UART_puts(str);
	UART_putchar(';');
	itoa(x, str);
	UART_puts(str);
	UART_putchar('H');
}
void UART_forwardsX(uint8_t x) {
	char str[4];
	UART_putchar('\033');
	UART_putchar('[');
	itoa(x, str);
	UART_puts(str);
	UART_putchar('C');
}

void UART_backwardsX(uint8_t x) {
	char str[4];
	UART_putchar('\033');
	UART_putchar('[');
	itoa(x, str);
	UART_puts(str);
	UART_putchar('D');
}

void UART_color(uint8_t color) {
	char temp[4];
	UART_putchar('\033');
	UART_putchar('[');
	itoa(color, temp);
	UART_puts(temp);
	UART_putchar('m');
}

void UART_resetColor() { UART_puts("\033[39m\033[49m"); }

// Utils
void itoa(uint32_t number, char *str) {
	uint8_t index		 = 0;
	uint32_t remainder = 0;
	if (number != 0) {
		while (number != 0) {
			remainder	 = number % 10;
			str[index++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
			number /= 10;
		}
		str[index] = '\0';
		uint8_t i  = 0;
		index--;
		while (i < index) {
			char temp	 = str[i];
			str[i++]		 = str[index];
			str[index--] = temp;
		}
	} else {
		str[0] = '0';
		str[1] = '\0';
	}
}

uint16_t atoi(char *str) {
	uint16_t number = 0;
	while (*str) {
		number = (number * 10) + (*str++ - '0');
	}
	return number;
}