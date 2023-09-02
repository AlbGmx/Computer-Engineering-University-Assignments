/*  practica5 Programación Estructurada						                    	Gómez Cárdenas Emmanuel Alberto
    27/09/2019																		                                            Grupo 531
    Programa que muestra un menú al usuario de varias acciones para manipular las calificaciones de los
    estudiantes de la clase de Programacion Estructurada del grupo 531, teniendo las opciones de:
      Mostrar​ ​tabla​ ​de​ ​calificaciones. 
      Mostrar​ ​toda​ ​la​ ​información​ ​de​ ​un​ ​alumno​ ​indicado​ ​por​ ​el​ ​usuario​.
      Mostrar​ ​toda​ ​la​ ​información​ ​de​ ​una​ ​práctica​ ​indicada​ ​por​ ​el​ ​usuario​. 
      Mostrar​ ​lista​ ​de​ ​alumnos​.
      Mostrar​ ​lista​ ​de​ ​prácticas​.
      Mostrar​ ​al​ ​alumno​ ​(o​ ​alumnos)​ ​con​ ​el​ ​más​ ​alto​ ​promedio. 
      Mostrar​ ​a​ ​todos​ ​los​ ​alumnos​ ​que​ ​tienen​ ​calificación​ ​reprobatoria. 
      Mostrar​ ​las​ ​prácticas​ ​con​ ​promedio​ ​menor​ ​a​ 6.   
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "STRCT.h"

int main(){
  Alumno_t alum[ALUM];
  Prac_t prac[PRAC];
  int calif[ALUM][PRAC], flag=1;
  start(calif, ALUM, PRAC, alum, prac);
  do{ //Hacer mientras el usuario lo desea 
    switch(showOpc()){
      case 1:  printAlumCalif(calif, ALUM, PRAC, alum);  break;
      case 2:  printAlumInfo(alum);   break;  
      case 3:  printPracInfo(prac);   break;  
      case 4:  printAlumList(alum);   break;  
      case 5:  printPracList(prac);   break;  
      case 6:  printBestAvg(alum);    break;
      case 7:  printLowerAvgs(alum);  break;
      case 8:  printLowerPracAvgs(prac); break;
      case 9:
      case 0:
      default:  flag=0; //Salir del ciclo
    }  
  }while(flag!=0);
  
  
  end();
  return 0;
}