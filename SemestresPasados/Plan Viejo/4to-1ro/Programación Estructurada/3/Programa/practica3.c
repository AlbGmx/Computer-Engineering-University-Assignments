/*
  practica3 Programación Estructurada							Gómez Cárdenas Emmanuel Alberto
  01/09/2019																		  Grupo 531
  Este programa cuenta con 6 funciones, de las cuales 5 son utilizables por el usuario, la 6ta
  solo se usa para fines del programa, cuenta con las funciones rev(reversa), sum(suma), dgts(digitos)  
  prfct(perfecto) y frnds(amigos), la funcion puede ser llamada por como esta escrita en el parentesis
  
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pp3.h"

void informacion_error();
void detener_pantalla(char *mensaje);

int main(int argc, char* argv[]){
  system("cls");
  system("color 0A");
  int num,num2;
  char auxString[15];
  //Imprime los argumentos introducidos
  printf("\n\n  FUNCION    VALOR(ES):");
  if (argc==3)  printf("\n  %s       %s\n\n", argv[1], argv[2]); 
  else if (argc==4)  printf("\n  %s     %s  %s\n\n", argv[1], argv[2], argv[3]);
  
  if (argc<3){
    informacion_error();
	detener_pantalla("\n\n\t Presione ENTER para salir");
	return 1;
  }
  else{
    num=atoi(argv[2]);
    if(!strcmp("suma",argv[1]))      printf("\n    La suma de los digitos de %d es %d",num, sum(num));
    else if(!strcmp("digitos",argv[1])) printf("\n    El numero %d tiene %d digitos",num,dgts(num));
    else if(!strcmp("reversa",argv[1])){
	  rev(num, auxString);
	  printf("\n    El numero %d en reversa es %s",num, auxString);
    }
	else if(!strcmp("perfecto",argv[1])){
		if(prfct(num)) printf("\n    El numero %d si es perfecto", num);
		else printf("\n    El numero %d no es perfecto", num);
	}
	else if(!strcmp("amigos",argv[1])){
      if(argc ==  4){
        num2=atoi(argv[3]);
        if(frnds(num,num2)){
          printf("\n    El numero %d y %d son amigos",num,num2);
		}
		else printf("\n    El numero %d y %d no son amigos",num,num2);
	  }
	} 
    else informacion_error();
  }  
  detener_pantalla("\n\n\t Presione ENTER para salir");
  return 0;
}

void informacion_error(){
  printf("\n    El programa debe recibir como minimo dos parametros");
  printf("\n    [1] Instruccion a completar  reversa, amigos, suma, digitos o perfecto");
  printf("\n    [2] Valor a utilizar");
  printf("\n    [3] en caso de utilizar la operacion amigos \n     se necesita el segundo numero a comparar");
  printf("\n\n    Ejemplo: p3 amigos 12 3");
}
void detener_pantalla(char *mensaje){
  printf("\n%s\n", mensaje);
  setbuf(stdin, NULL);
  getchar();
  system("color 07");
  system("cls");
}