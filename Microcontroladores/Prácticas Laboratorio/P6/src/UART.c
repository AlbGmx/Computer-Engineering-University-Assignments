#include <avr/io.h>
#include "UART.h"
#include <stdio.h>

#define F_OSC (uint32_t)16000000
#define UCSZ_OFFSET 5

volatile uint8_t *regUBRRH[4] = {&UBRR0H, &UBRR1H, &UBRR2H, &UBRR3H};
volatile uint8_t *regUBRRL[4] = {&UBRR0L, &UBRR1L, &UBRR2L, &UBRR3L};
volatile uint8_t *regUSCRA[4] = {&UCSR0A, &UCSR1A, &UCSR2A, &UCSR3A};
volatile uint8_t *regUCSRB[4] = {&UCSR0B, &UCSR1B, &UCSR2B, &UCSR3B};
volatile uint8_t *regUCSRC[4] = {&UCSR0C, &UCSR1C, &UCSR2C, &UCSR3C};
volatile uint8_t *regUDR[4]   = {&UDR0, &UDR1, &UDR2, &UDR3};

// Prototypes
// Initialization

// Consider:
// 1. The COM port (0 to 3)
// 2. The baudrate, may be non standard
// 3. The size of the data (5 to 8 bits)
// 4. The parity (0: Disabled, 1: Odd, 2: Even)
// 5. The number of stop bits (1 or 2)
void UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop) {
   if (com <= 3) {
      // UBRR Formula => UBRRH:UBRRL = (F_OSC / (16 * baudrate)) - 1
      uint32_t ubrrValue = F_OSC / ((uint32_t)16 *  baudrate) - 1;
      uint8_t paritySize[3] = {0, (1 << UPM01) | (1 << UPM00), (1 << UPM01)};

      *regUBRRH[com] = (uint8_t) (ubrrValue >> 8);
      *regUBRRL[com] = (uint8_t) ubrrValue;
      *regUCSRC[com] &= ~(3 << UCSZ00); 
      *regUCSRC[com] |= (size - UCSZ_OFFSET) << UCSZ00; // Using UCSZ_OFFSET to map the size (5 - 8) to the UCSZ0 bits (0 - 3)
      *regUCSRC[com] &= ~(3 << UPM00);  
      *regUCSRC[com] |= paritySize[parity]; 
      *regUCSRC[com] = (stop == 1) ? (*regUCSRC[com] & ~(1 << USBS0)) : (*regUCSRC[com] | (1 << USBS0));
      *regUCSRB[com] |= (1 << TXEN0) | (1 << RXEN0);
   }
}

// Send
void UART_puts(uint8_t com, char *str) {
   while (*str) UART_putchar(com, *str++);
}

void UART_putchar(uint8_t com, char data) {
   while (!(*regUSCRA[com] & (1 << UDRE0)));
   *regUDR[com] = data;
}

// Received
char UART_getchar(uint8_t com){
   while (!(*regUSCRA[com] & (1 << RXC0)));
   return *regUDR[com];
}

// Escape sequences
void UART_clrscr( uint8_t com) {
   UART_puts(com, "\033[2J");
}

void UART_gotoxy(uint8_t com, uint8_t x, uint8_t y) {
   char str[4];
   itoa(y, str, 10);
   UART_putchar(com, '\033');
   UART_putchar(com, '[');
   UART_puts(com, str);
   UART_putchar(com, ';');
   itoa(x, str, 10);
   UART_puts(com, str);
   UART_putchar(com, 'H');
}


// Utils
void itoa(uint32_t number, char* str, uint8_t base) {
   uint8_t index = 0;
   uint8_t remainder = 0;
   if (number != 0) {
      while (number != 0) {
         remainder = number % base;
         str[index++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
         number = number / base;
      }
      str[index] = '\0';
      uint8_t j = 0;
      index--;
      while (j < index) {
         char temp = str[j];
         str[j++] = str[index];
         str[index--] = temp;
      } 
   } else {
      str[0] = '0';
      str[1] = '\0';
   }
}

uint16_t atoi(char *str){
   uint16_t number = 0;
   while (*str) {
      number = number * 10 + (*str++ - '0');
   }
   return number;
}