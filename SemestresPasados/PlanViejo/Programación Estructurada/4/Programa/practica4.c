/*
  practica4 Programación Estructurada							Gómez Cárdenas Emmanuel Alberto
  12/09/2019																		  Grupo 531
  Generar una matriz de para administrar las calificaciones de las practicas
  del grupo 532, el cual debe visuualizarse en formato de tabla, como se indicó
  donde las columnas representan las practicas y las filas corresponden a los
  alumnos. La tabla deberá ser de 20 alumnos por 10 practicas, pero flexible a 
  modificacion, con las calificaciones siendo generadas de forma aleatoria en 
  un rango de 1 a 10. Realizar funcion para calcular el promedio por alumno, por
  practica, para calcula la moda, media y mediana
  
*/

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "MTRX.h"

int main(){
  
  int flag=1, calif[ALUM][PRAC];
  start(calif, ALUM, PRAC); //Inicializar (srand, matriz, cambio de colores)
  do{ //Hacer mientras el usuario lo desea 
    switch(showOpc(calif, ALUM, PRAC)){
      case 1:  printAlumCalif(calif, ALUM, PRAC, 0);  break;
      case 2:  printAlumCalif(calif, ALUM, PRAC, 1); break;  
      case 3:  printAvgPrac(calif, ALUM, PRAC);  break;  
      case 4:  medidas(calif, ALUM, PRAC);  break;  
//    case 5:  initMtrx(calif, ALUM, PRAC);  break; //Genera matrices diferentes para testear
      default:  flag=0; //Salir del ciclo
    }  
  }while(flag!=0);
  end();
  return 0;
}