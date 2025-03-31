// Prototypes
// Initialization
void UART_Ini(uint8_t, uint8_t, uint8_t, uint8_t);
void UART_AutoBaudRate(void);

// Send
void UART_puts(char *str);
void UART_putchar(char data);

// Received
char UART_getchar();

// Escape sequences
void UART_clrscr();
void UART_gotoxy(uint8_t, uint8_t);
void UART_forwardsX(uint8_t);
void UART_backwardsX(uint8_t);
void UART_color(uint8_t);
void UART_resetColor();

// Utils
void itoa(uint16_t, char *);
uint16_t atoi(char *);
void justifyRight(char[], uint8_t);
void justifyRightNoZeros(char[], uint8_t);
