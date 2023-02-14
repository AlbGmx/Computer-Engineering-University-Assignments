/*
  practica 10 Programación Estructurada							Gómez Cárdenas Emmanuel Alberto
  28/11/2019																		                          Grupo 531
  
  En estas practica se realizó una biblioteca para la manipulacion a nivel bit de 
  enteros y caracteres, se hicieron funciones de rotacion, manipulacion a nivel bit
  como la obtencion, el apagar o encender un bit especificado dependiendo de su estado
  y entre otras cosas.
  
*/
#include "bits.h"


int main(){
  system("cls");
  unsigned char r=0xaf, clave=0xa2;
  unsigned int z=0x76543210;
  char msg[20];
  strcpy(msg, "MENSAJE SECRETO");
  printf("Entero a manipular => ");  display(z,UNSIGNED_INT_SIZE);
  printf("Caracter a manipular => ");  display(r,UNSIGNED_CHAR_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Apagar el bit numero 2 de 10101111 => "); display(r=valor_clearbit(r,2), UNSIGNED_CHAR_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Encender el bit numero 5 de 10101101 => "); display(r=valor_setbit(r,5), UNSIGNED_CHAR_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Obtener el bit numero 3 de 10111101 => "); display(getbit(r,3), 1);
  puts("-------------------------------------------------------------------------\n");
  printf("Alternar el bit numero 3 de 10111101 => "); display(r=togglebit(r,3), UNSIGNED_CHAR_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Rotar 16 bits a la izquierda el entero \n01110110 01010100 00110010 00010000\n"); display(z=introtleft(z,16), UNSIGNED_INT_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Rotar 24 bits a la derecha el entero \n00110010 00010000 01110110 01010100\n"); display(z=introtright(z,24), UNSIGNED_INT_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Rotar 6 bits a la derecha el byte 10111001 => "); display(r=byterotright(r,6), UNSIGNED_CHAR_SIZE);
  puts("-------------------------------------------------------------------------\n");
  printf("Obtener el byte en el que se encuentra ubicado el noveno bit del entero \n00010000 01110110 01010100 00110010\n"); display(getbyte(z,9), UNSIGNED_CHAR_SIZE);
  puts("-------------------------------------------------------------------------\n");
  puts(msg);
  encryptMsg(msg, clave);
  printf("Mensaje encriptado: %s\n", msg);
  encryptMsg(msg, clave);
  printf("Mensaje des-encriptado: %s\n", msg);
  puts("-------------------------------------------------------------------------\n");
  
  return 0;
}