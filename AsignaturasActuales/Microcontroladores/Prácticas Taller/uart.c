#include <avr/io.h>
// Configure UART0
// 177000 Bauds, 6 bits, paridad even, 2 stop bits
// UBRR = 11.29 - 1 = 10.29 = 10

void uart_Init() {
   UCSR0A = 1 << U2X0;                                    // Double Speed
   UCSR0B = (1 << TXEN0) | (1 << RXEN0);                  // Enable Pins
   UCSR0C = (2 << UPM00) | (1 << USBS0) | (1 << UCSZ00);  // Parity Even, 2 Stop Bits, 6 bits
   UBRR0  = 10;                                           // 177000 Bauds
}

// Configure UART0
// 177000 Bauds, 9 bits, paridad even, 2 stop bits
// UBRR = 11.29 - 1 = 10.29 = 10

void Uart_InitNineBits(void) {
   UCSR0A = 1 << U2X0;                                    // Double Speed
   UCSR0B = (1 << TXEN0) | (1 << RXEN0) | (1 << UCSZ02);  // Enable Pins
   UCSR0C = (2 << UPM00) | (1 << USBS0) | (3 << UCSZ00);  // Parity Even, 2 Stop Bits, 9 bits
   UBRR0  = 10;                                           // 177000 Bauds
}

void uart0_putchar(char data) {
   while (!(UCSR0A & (1 << UDRE0)))
      ;          // Wait until buffer is empty
   UDR0 = data;  // Send character
}

void uart0_puts(char* str) {
   while (*str) uart0_putchar(*str++);
}

void uart0_getchar() {
   while (!(UCSR0A & (1 << RXC0)))
      ;          // Wait until data is received
   return UDR0;  // Return received data
}

uint8_t uart0_dataAvailable() {
   return (UCSR0A >> RXC0) & 1;  // Return 1 if data is available
}

int main() {
   uart_Init();
   uart0_puts("Hello World!\n");
   return 0;
}