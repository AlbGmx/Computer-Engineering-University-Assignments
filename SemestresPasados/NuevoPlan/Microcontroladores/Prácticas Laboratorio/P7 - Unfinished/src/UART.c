#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

#define F_OSC (uint32_t)16000000
#define UCSZ_OFFSET 5
#define BUFFER_SIZE 64

volatile uint8_t *regUBRRH[4] = {&UBRR0H, &UBRR1H, &UBRR2H, &UBRR3H};
volatile uint8_t *regUBRRL[4] = {&UBRR0L, &UBRR1L, &UBRR2L, &UBRR3L};
volatile uint8_t *regUSCRA[4] = {&UCSR0A, &UCSR1A, &UCSR2A, &UCSR3A};
volatile uint8_t *regUCSRB[4] = {&UCSR0B, &UCSR1B, &UCSR2B, &UCSR3B};
volatile uint8_t *regUCSRC[4] = {&UCSR0C, &UCSR1C, &UCSR2C, &UCSR3C};
volatile uint8_t *regUDR[4] = {&UDR0, &UDR1, &UDR2, &UDR3};

typedef struct {
   char buffer[BUFFER_SIZE];        /* Espacio Reservado */
   volatile unsigned char in_idx;   /* Indice de entrada */
   volatile unsigned char out_idx;  /* Indice de salida  */
} ring_buffer_t;

static ring_buffer_t ringBuffer;  

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

   //Init ring buffer
   ringBuffer.in_idx = 0;
   ringBuffer.out_idx = 0;
   sei();
}

uint8_t UART0_available(void) {
   return (ringBuffer.in_idx - ringBuffer.out_idx) % BUFFER_SIZE;
}

// Places a char on the ring queue
void UART0_putchar(char data) {
   while (UART0_available() == BUFFER_SIZE - 1);
   
   ringBuffer.buffer[ringBuffer.in_idx] = data;
   ringBuffer.in_idx = (ringBuffer.in_idx + 1) % BUFFER_SIZE;
}

// Reads the corresponging char from the ring queue
char UART0_getchar(void){
   while (!UART0_available());

   char received = ringBuffer.buffer[ringBuffer.out_idx];
   ringBuffer.out_idx = (ringBuffer.out_idx + 1) % BUFFER_SIZE;
   
   return received;
}

void UART0_gets(char *str) {
   char c;
   while ((c = UART0_getchar()) != '\n') *str++ = c;
   *str = '\0';
}

void UART0_puts(char *str) {
   while (*str) UART0_putchar(*str++);
}

// Escape sequences
void clrscr() {
   UART0_puts("\033[2J");
}

void gotoxy(uint8_t x, uint8_t y) {
   char str[4];
   itoa(y, str, 10);
   UART0_putchar('\033');
   UART0_putchar('[');
   UART0_puts(str);
   UART0_putchar(';');
   itoa(x, str, 10);
   UART0_puts(str);
   UART0_putchar('H');
}

ISR(USART0_UDRE_vect) {
   if (ringBuffer.in_idx != ringBuffer.out_idx) {
      UDR0 = ringBuffer.buffer[ringBuffer.out_idx];
      ringBuffer.out_idx = (ringBuffer.out_idx + 1) % BUFFER_SIZE;
   } else {
      *regUCSRB[0] &= ~(1 << UDRIE0);
   }
}

ISR(USART0_RX_vect) {
   char received = UDR0;
   unsigned char next_idx = (ringBuffer.in_idx + 1) % BUFFER_SIZE;
   if (next_idx != ringBuffer.out_idx) {
      ringBuffer.buffer[ringBuffer.in_idx] = received;
      ringBuffer.in_idx = next_idx;
   }
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