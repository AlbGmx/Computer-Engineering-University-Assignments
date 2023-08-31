/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 14/02/2023
 * Descripcion: Taller 2, Aplicacion
 * Taller de la clase Microcontroladores
 * Analizar, diseñar e implemengtar un programa
 * para simular la funcionalidad de una licuadora
 * acorde a la especificación dada
 */

#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>

#define ON 1
#define OFF 0

void printGuide();

int main(){
   char tecla=0;
   int estado=0;
   int led = 0;
   int exit = 0;

   printGuide();

   while (!exit){
      if (kbhit()){
         tecla = getch();
         switch (tecla){
         case '0':
            printf("\n\n-----------------------------------------------------\n");
            printf("Apagando");
            estado = OFF;
            led = OFF;
            delay(1000);
            clrscr();
            printf("\nApagado");
            printGuide();
            break;
         case '1':
            printf("\n\n-----------------------------------------------------\n");
            printf("Encendiendo motor a velocidad 1");
            estado = 1;
            printf("\nEncendiendo LED");
            led = ON;
            break;
         case '2':
            printf("\n\n-----------------------------------------------------\n");
            printf("Encendiendo motor a velocidad 2");
            estado = 2;
            printf("\nEncendiendo LED");
            led = ON;
            break;
         case '3':
            printf("\n\n-----------------------------------------------------\n");
            printf("Encendiendo motor a velocidad 3");
            estado = 3;
            printf("\nEncendiendo LED");
            led = ON;
            break;
         case 'P':
         case 'p':
            printf("\n\n-----------------------------------------------------\n");
            printf("Encendiendo motor a velocidad 3 en modo pulsado");
            estado = 4;
            printf("\nEncendiendo LED");
            led = ON;
            break;
         case 'x':
         case 'X':
            exit = 1;
            break;
         }
      }
      if (exit) printf("\n\nSaliendo...");

      else if (estado == OFF) delay(1000);
      
      else if (estado != 4){
         printf("\n\nModo ON a velocidad %d", estado);
         led = !led;
         printf("\nLED %s", led ? "encendido" : "apagado");
         delay(1000 / pow(2, estado));
      }
      else{
         if (led) printf("\n\nModo ON a velocidad %d\nLED encendido", estado - 1);
         else printf("\n\nModo OFF\nLED apagado");
         led = !led;
         delay(1000);
      }
   }
   return 0;
}

void printGuide()
{
   printf("\n\nBotones de control:");
   printf("\n\t- 0: Apagar");
   printf("\n\t- 1: Encender a velocidad 1");
   printf("\n\t- 2: Encender a velocidad 2");
   printf("\n\t- 3: Encender a velocidad 3");
   printf("\n\t- P: Encender a modo pulsado");
   printf("\n\t- X: Salir");
   printf("\n\t");
}