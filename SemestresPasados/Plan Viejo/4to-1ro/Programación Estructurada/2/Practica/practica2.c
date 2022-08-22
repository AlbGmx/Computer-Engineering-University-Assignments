/*practica2 Programacion Estructurada*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"dec2base.h"

//Indicar que hace define
#define MAX 10

void detener_pantalla(char* mensaje);
void informacion_err();

int main(int argc, char* argv[])
{
    //declaracion de variables a utilizar
    int num = 0;
    //Indicar por que se declara en el main la cadena a mostrar
    char binchar[MAX];

    //comprobacion de numero de parametros ingresados por consola
    if(argc<3)
    {
        //Por defecto el programa recibe un argumento, el nombre del archivo (ej. practica2.c).
        informacion_err();
        detener_pantalla("\n\tPresione ENTER para salir");
        return 1;
    }
    else
    {
        num = atoi(argv[2]);
        if(strcmp("bin", argv[1])==0)
        {
          //Indicar de que forma se envia el arreglo binchar y por que?
          dec2binchar(num, binchar, MAX);
          printf("\nEl numero: %d, en binario es: %s\n",num,binchar);
        }
        else if(strcmp("hex", argv[1])==0)
        {
          dec2hex(num, binchar, MAX);
          printf("\nEl numero: %d, en hexadecimal es: %s",num,binchar);
        }
        else if(strcmp("oct", argv[1])==0)
        {
          printf("\nEl numero: %d, en octal es: %d",num,dec2oct(num));
        }
        else
        {
            informacion_err();
            detener_pantalla("\n\tPresione ENTER para salir");
            return 1;
        }
    }

    detener_pantalla("\n\tPresione ENTER para salir");
    return 0;
}


void detener_pantalla (char* mensaje)
{
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

void informacion_err()
{
    printf("El programa debe recibir dos parametros");
    printf("\n   [1] Base a convertir el valor entero: \"bin\", \"hex\", \"oct\"");
    printf("\n   [2] Valor entero decimal");
    printf("\n\nEjemplo:\nprac2.exe bin 5");
}

