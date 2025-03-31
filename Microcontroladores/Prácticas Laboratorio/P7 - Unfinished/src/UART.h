// Prototypes
// Initialization
void UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop);

// Send
void UART0_puts(char *str);
void UART0_putchar(char data);

// Received
char UART0_getchar(void);
void UART0_gets(char *str);

// Escape sequences
void clrscr();
void gotoxy(uint8_t x, uint8_t y);


// Utils
void itoa(uint32_t number, char* str, uint8_t base); 
uint16_t atoi(char *str);
