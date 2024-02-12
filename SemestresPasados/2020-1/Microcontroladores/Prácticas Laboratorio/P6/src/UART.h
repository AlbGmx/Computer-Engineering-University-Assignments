// Prototypes
// Initialization
void UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop);

// Send
void UART_puts(uint8_t com, char *str);
void UART_putchar(uint8_t com, char data);

// Received
char UART_getchar(uint8_t com );

// Escape sequences
void UART_clrscr( uint8_t com );
void UART_gotoxy(uint8_t com, uint8_t x, uint8_t y);


// Utils
void itoa(uint32_t number, char* str, uint8_t base); 
uint16_t atoi(char *str);
