#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cifra_cadena(char*, char*, char*);

int main(){
  char original[100], clave[100], resultado[100];
  strcpy(original,  "hola");
  puts("ingresar clave");
  gets(clave);
  cifra_cadena (original, clave, resultado);
  puts("Original antes de encriptar");
  puts(original);
  puts("Original encriptado");
  puts(resultado);

  cifra_cadena (resultado, clave, original);
  puts("Original encriptado");
  puts(resultado);
  puts("Original desencriptado");
  puts(original);
  return 0;
}

void cifra_cadena (char *str_in, char *clave, char *str_out){
  int i=0;
  while(i < strlen(str_in)){
    str_out[i]=str_in[i]^clave[(i%(1+strlen(clave)))];
    i++;
  }
  str_out[i]='\x0';
}