#include <avr/io.h>
#include "UART.h"

void printName(char *name, int numberOfLetters);

int main( void ) {
   UART_Ini(0, 20000, 8, 0, 1);
   char name[] = "EmmanuelAlbertoGomezCardenas";

   while (1){
      UART_clrscr(0);
      UART_gotoxy(0, 5, 20);
      UART_puts(0, "Presione un numero del 1 al 9 para imprimir el nombre: ");
      printName(name, UART_getchar(0) - '0');
      UART_getchar(0);
  }
}

void printName(char *name, int numberOfLetters) {
   if (numberOfLetters < 10) {
      char *temp = name; 
      while(numberOfLetters-- != 0 && *temp != '\0') {
         UART_putchar(0, *temp++);
      }
   } else {
      UART_clrscr(0);
      UART_gotoxy(0, 0, 0);
      UART_puts(0, "Ha introducido un valor invalido...\n");
   }
}
