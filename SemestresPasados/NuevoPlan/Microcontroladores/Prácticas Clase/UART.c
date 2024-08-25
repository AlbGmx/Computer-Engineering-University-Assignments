// 1000000, 5, EVEN, 2
void UART3_Init(void) {
   UBRR3 = (F_CPU / (16 * 1000000)) - 1;
}