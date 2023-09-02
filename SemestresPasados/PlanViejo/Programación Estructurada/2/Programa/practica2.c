/*  
    practica2 Programacion Estructurada							Gómez Cárdenas Emmanuel Alberto
  	28/08/2019													         			  Grupo 531
  	Este programa convierte valores decimales a valores binarios, hexadecimales y octodecimales
    utilizando cadenas, enteros, módulos, parámetros en main, entre otros.
    He hecho varios cambios a la biblioteca dec2base.h, he agregado y modificado los parametros 
    para poder utilizar las 4 funciones que serían bin, oct, hex y binchar	
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"dec2base.h"

void detener_pantalla(char* mensaje);
void informacion_err(int bin);

//define indica al compilador que debe cambiar todas las palabras "MAX" a 15
#define MAX 15

int main(int argc, char* argv[]){
  system("cls");
  system("color 0a");
  //declaracion de variables a utilizar
  int num=0, dec=0, bin=0;
  char auxString[MAX]; //La cadena es declarada en el main para que pueda ser mandada a cualquiera de las funciones
  auxString[0]='\0'; 
  if(argc<3){ //comprobacion de numero de parametros ingresados por consola
    informacion_err(bin);
    detener_pantalla("\n\tPresione ENTER para salir");
    return 1;
  }
    else{
      num = atoi(argv[2]);
	  if(strcmp("bin", argv[1])==0){
	    if (num>1023){
		  bin=1;
   		  informacion_err(bin);
        }
		else  printf("\nEl numero: %d, en binario es: %d",num, dec2bin(num));  
	  }
      else if(strcmp("binchar", argv[1])==0){
//        El arreglo auxString se envía como "paso por referencia"
//        aunque en realidad solo envía la dirección en la que se encuentra
//        para así evitar enviar toda una copia de cada valor de la cadena
//        lo que lo hace mas eficiente
		  printf("\nEl numero: %d, en binario es: %s",dec2binchar(num, auxString), auxString);
		}
      else if(strcmp("hex", argv[1])==0){
          dec=dec2hex(num, auxString);
		  printf("\nEl numero: %d, en hexadecimal es: %s",dec, auxString);
		}
      else if(strcmp("oct", argv[1])==0){
		  printf("\nEl numero: %d, en octal es: %d",num,dec2oct(num));
		}
      else{
          informacion_err(bin);
          detener_pantalla("\n\tPresione ENTER para salir");
          return 1;
        }
	}
    detener_pantalla("\n\tPresione ENTER para salir");
    return 0;
}

void detener_pantalla (char* mensaje){
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
    system("color 07");
    system("cls");

}

void informacion_err(int bin){
  if(bin) printf("\n\n\n   Usar valores menores de 1024 al utilizar la conversion bin");
  else {
    printf("\nEl programa debe recibir dos parametros");
    printf("\n   [1] Base a convertir el valor entero: \"bin\", \"binchar\", \"hex\", \"oct\"");
    printf("\n   [2] Valor entero decimal");
    printf("\n\nEjemplo:\nprac2.exe bin 5");
  }
}

