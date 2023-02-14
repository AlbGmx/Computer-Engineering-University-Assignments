#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "STRCT.h"
void start(int calif[][PRAC], int row, int col, Alumno_t alum[ALUM], Prac_t prac[PRAC]){
  int i;
  srand(time(NULL));
  generateNames(alum);
  generatePracs(prac);
  initMtrx(calif, row, col);
  fillAVG(calif, row, col, alum, prac);
  system("color 0a"); 
  system("cls");
}
void initMtrx(int calif[][PRAC], int row, int col){
  int i;
  for(i=0; i<col*row; i++)  calif[0][i]=1+rand()%10;
}
void generatePracs(Prac_t prac[PRAC]){
  prac[0].ID=0;
  strcpy(prac[0].title,  "Hello World         ");
  strcpy(prac[0].comment,"Introduccion printf ");
  
  prac[1].ID=1;
  strcpy(prac[1].title,  "Variables           ");
  strcpy(prac[1].comment,"Tipos de datos      ");
  
  prac[2].ID=2;
  strcpy(prac[2].title,  "Estructura iterativa");
  strcpy(prac[2].comment,"For, do y while     ");
  
  prac[3].ID=3;
  strcpy(prac[3].title,  "Procedimientos      ");
  strcpy(prac[3].comment,"Funciones void      ");
  
  prac[4].ID=4;
  strcpy(prac[4].title,  "Funciones           ");
  strcpy(prac[4].comment,"Devolucion valores  ");
  
  prac[5].ID=5;
  strcpy(prac[5].title,  "Vectores            ");
  strcpy(prac[5].comment,"Introd. a vectores  ");
  
  prac[6].ID=6;
  strcpy(prac[6].title,  "Matrices            ");
  strcpy(prac[6].comment,"Introd. a matrices  ");
  
  prac[7].ID=7;
  strcpy(prac[7].title,  "Estructuras         ");
  strcpy(prac[7].comment,"Uso de estructuras  ");
  
  prac[8].ID=8;
  strcpy(prac[8].title,  "Apuntadores         ");
  strcpy(prac[8].comment,"Introd. al apuntador");
  
  prac[9].ID=9;
  strcpy(prac[9].title,  "Proyecto final      ");
  strcpy(prac[9].comment,"Uso de lo aprendido ");
} 
void generateNames(Alumno_t alum[ALUM]){
  alum[0].ID=0;
  alum[0].year=2018;
  alum[0].period=2;
  alum[0].gender='M';
  alum[0].calif=1+rand()%10;
  strcpy(alum[0].name,"Raul   ");
  strcpy(alum[0].mail,"raul@uabc.edu.mx ");

  alum[1].ID=1;
  alum[1].year=2018;
  alum[1].period=2;
  alum[1].gender='M';
  alum[1].calif=1+rand()%10;
  strcpy(alum[1].name,"Adlai  ");
  strcpy(alum[1].mail,"adlai@uabc.edu.mx");

  alum[2].ID=2;
  alum[2].year=2018;
  alum[2].period=2;
  alum[2].gender='F';
  alum[2].calif=1+rand()%10;
  strcpy(alum[2].name,"Cris   ");
  strcpy(alum[2].mail,"cris@uabc.edu.mx ");

  alum[3].ID=3;
  alum[3].year=2013;
  alum[3].period=1;
  alum[3].gender='M';
  alum[3].calif=1+rand()%10;
  strcpy(alum[3].name,"Eros   ");
  strcpy(alum[3].mail,"eros@uabc.edu.mx ");

  alum[4].ID=4;
  alum[4].year=2019;
  alum[4].period=2;
  alum[4].gender='M';
  alum[4].calif=1+rand()%10;
  strcpy(alum[4].name,"Luis   ");
  strcpy(alum[4].mail,"luis@uabc.edu.mx ");

  alum[5].ID=5;
  alum[5].year=2018;
  alum[5].period=2;
  alum[5].gender='M';
  alum[5].calif=1+rand()%10;
  strcpy(alum[5].name,"Roge   ");
  strcpy(alum[5].mail,"roge@uabc.edu.mx ");

  alum[6].ID=6;
  alum[6].year=2018;
  alum[6].period=2;
  alum[6].gender='M';
  alum[6].calif=1+rand()%10;
  strcpy(alum[6].name,"Rojo   ");
  strcpy(alum[6].mail,"rojo@uabc.edu.mx ");

  alum[7].ID=7;
  alum[7].year=2019;
  alum[7].period=2;
  alum[7].gender='F';
  alum[7].calif=1+rand()%10;
  strcpy(alum[7].name,"Luisa  ");
  strcpy(alum[7].mail,"luisa@uabc.edu.mx");

  alum[8].ID=8;
  alum[8].year=2012;
  alum[8].period=1;
  alum[8].gender='M';
  alum[8].calif=1+rand()%10;
  strcpy(alum[8].name,"Carl   ");
  strcpy(alum[8].mail,"carl@uabc.edu.mx ");

  alum[9].ID=9;
  alum[9].year=2014;
  alum[9].period=1;
  alum[9].gender='F';
  alum[9].calif=1+rand()%10;
  strcpy(alum[9].name,"Azul   ");
  strcpy(alum[9].mail,"azul@uabc.edu.mx ");
}
int showOpc(){
  int opc;
  printf("\n\n\t");
  printf("\n \t(1) Mostrar tabla de calificaciones");
  printf("\n \t(2) Mostrar toda la informacion de un alumno");
  printf("\n \t(3) Mostrar toda la informacion de una practica");
  printf("\n \t(4) Mostrar lista de alumnos");
  printf("\n \t(5) Mostrar lista de practicas");  
  printf("\n \t(6) Mostrar al(los) alumno(s) con el(los) mas alto(s) promedio(s)");
  printf("\n \t(7) Mostrar a todos los alumnos que tienen calificacion reprobatoria");
  printf("\n \t(8) Mostrar las practicas con promedio menor a 6");
  printf("\n \t(9) Salir\n");
  printf("\n\t\t\250Qu\x82 desea realizar? \n\n\tCapture su eleccion...  ");
  scanf("%d", &opc);
  return opc;
}
void fillAVG(int calif[][PRAC], int row, int col, Alumno_t alum[ALUM], Prac_t prac[PRAC]){
  int i, aux;
  for(aux=0; aux<2; aux++) {
    if(aux) for (i=0; i<row; i++) alum[i].avg=avgAlum(calif, row, col, alum[i].ID);  
    else for (i=0; i<col; i++) prac[i].avg=avgPrac(calif, row, col, prac[i].ID);
  }

}
void printAlumCalif(int calif[][PRAC], int row, int col, Alumno_t alum[ALUM]){
  int i, id;
  tableCalif(1);
  printf("\n\263ID \263  Nombre  \263");
  for (i=0; i<col; i++) printf("Prac %d\263", i);
  printf("Promedio  prac\263");
  for(id=0; id<row; id++){
    printf("\n\263%2d \263  %s \263",alum[id].ID, alum[id].name);
    for (i=0; i<col; i++) {
      printf("%4d  \263", calif[id][i]);
    }
    printf("     %.2f     \263", alum[id].avg);
    if (alum[id].avg>=6) printf("    A   ");
    else printf("    N   ");
  }   
  printf("\n\263Promedio Calif\263");
  for (i=0; i<col; i++){
    printf(" %.2f \263", avgPrac(calif, row,col, i));
  }    
  printf("\260\260\260\260\260\260\260\260\260\260\260\260\260\260\263");
  tableCalif(0);
}
void printAvgPrac(int calif[][PRAC], int row, int col, Alumno_t alum[PRAC]){
  int i, id;
  while(getchar()!='\n'); 
  printf("\n\nIngrese el ID de la practica... ");
  scanf(" %d", &id); 
  if(id>=col)  printf("\n\n\tPractica no encontrada");
  else if(id<0)  printf("\n\n\tValor introducido no valido");
  else{
    printf("\n ID\263 Nombre \263 Prom Practica %d \263", id);
    for (i=0; i<row; i++){
      printf("\n %2d\263 %6s\263", alum[i].ID, alum[i].name);
      printf(" %9d       \263", calif[i][id]);    
    }
    printf("\nProm Total  ");
    printf("\263       %.2f      \263", avgPrac(calif, row,col, id));
  }
}
float avgAlum(int calif[][PRAC], int row, int col, int id){
  int i;
  float avg=0;
  for(i=0; i<row; i++) avg+=calif[id][i]; //Promedio de calificaciones
  return avg/i;
}
float avgPrac(int calif[][PRAC], int row, int col, int id){
  int i;
  float avg=0;
  for(i=0; i<col; i++) avg+=calif[i][id]; //Promedio de practicas
  return avg/i;
}
void printNames(Alumno_t alum[ALUM]){
  int i;
  for(i=ALUM-1; i>=0; i--) printf("Id = %d\t Name = %s\t Mail = %s\t Gender = %c\n", alum[i].ID, alum[i].name, alum[i].mail, alum[i].gender);
}
void printAlumList(Alumno_t alum[ALUM]){
  int i;
  printf("\n\t\t LISTA DE ALUMNOS PROGRAMACION ESTRUCTURADA GRUPO 531\n");
  tableList(1);
  for(i=0; i<ALUM; i++)  printf("\t\263 %2d \263 %6s\263 %6s\263 %7c      \263   2019-%d \263    %.2f   \263\n", alum[i].ID, alum[i].name, alum[i].mail, alum[i].gender, alum[i].period, alum[i].avg);
  tableList(0);
}
void printPracList(Prac_t prac[PRAC]){
  int i;
  printf("\n\t\t LISTA DE PRACTICAS PROGRAMACION ESTRUCTURADA GRUPO 531\n");
  tableListPracs(1);
  for(i=0; i<PRAC; i++)  printf("\t\263 %2d \263 %6s\263 %6s\263    %.2f   \263\n", prac[i].ID, prac[i].title, prac[i].comment, prac[i].avg);
  tableListPracs(0);
}
void tableList(int i){
  if (i){
    printf("\n\t\332\304\304\304\304\302\304\304\304\304\304\304\304\304\302");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\302");  
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\302");
    printf("\304\304\304\304\304\304\304\304\304\304\302");
    printf("\304\304\304\304\304\304\304\304\304\304\304\277");
    printf("\n\t\263 ID \263 Nombre \263      Correo      \263  Genero(M/F) \263  Periodo \263  Promedio \263\n");    
  }
  else {
    printf("\t\300\304\304\304\304\301\304\304\304\304\304\304\304\304\301");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\301");  
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\301");
    printf("\304\304\304\304\304\304\304\304\304\304\301");
    printf("\304\304\304\304\304\304\304\304\304\304\304\331");    
  }
}
void tableListPracs(int i){
  if (i){
    printf("\n\t\332\304\304\304\304\302\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\302");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\302");  
    printf("\304\304\304\304\304\304\304\304\304\304\304\277");
    printf("\n\t\263 ID \263 Titulo              \263 Comentario          \263  Promedio \263\n");    
  }
  else {
    printf("\t\300\304\304\304\304\301\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\301");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\301");  
    printf("\304\304\304\304\304\304\304\304\304\304\304\331");    
  }
}
void printAlumInfo(Alumno_t alum[ALUM]){
  int i=0;
  printf("\n\n\tIngrese el ID del alumno...");
  scanf(" %d", &i); 
  if(i>=ALUM)  printf("\n\n\tAlumno no encontrado");
  else if(i<0)  printf("\n\n\tValor introducido no valido");
  else{
    tableAlumInfo(1);
    printf("\n\t\263 ID        \263 %10d          \263" , alum[i].ID);
    printf("\n\t\263 Nombre    \263        %6s      \263" , alum[i].name);
    printf("\n\t\263 Correo    \263  %7s  \263" , alum[i].mail);
    printf("\n\t\263 Genero    \263 %10c          \263" , alum[i].gender);
    printf("\n\t\263 Ingreso   \263     %7d         \263" , alum[i].year);
    printf("\n\t\263 Periodo   \263 %10d-%d        \263" , alum[i].year, alum[i].period);
    printf("\n\t\263 Promedio  \263        %.3f        \263", alum[i].avg); 
    tableAlumInfo(0);
  }
}
void printPracInfo(Prac_t prac[PRAC]){
  int i=0;
  printf("\n\n\tIngrese el ID de la practica...");
  scanf("%d", &i); 
  if(i>=PRAC)  printf("\n\n\tPractica no encontrada");
  else if(i<0)  printf("\n\n\tValor introducido no valido");
  else{
    tablePracInfo(1);
    printf("\n\t\263 ID          \263 %10d          \263" ,     prac[i].ID);
    printf("\n\t\263 Titulo      \263 %s\263" ,                prac[i].title);
    printf("\n\t\263 Comentario  \263 %s\263" ,                prac[i].comment);
    printf("\n\t\263 Promedio    \263        %.3f        \263", prac[i].avg); 
    tablePracInfo(0);
  }
}
void tableAlumInfo(int i){
  if(i)  printf("\n\t\332\304\304\304\304\304\304\304\304\304\304\304\302\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
  else  printf("\n\t\300\304\304\304\304\304\304\304\304\304\304\304\301\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331");
}
void tablePracInfo(int i){
  if(i)  printf("\n\t\332\304\304\304\304\304\304\304\304\304\304\304\304\304\302\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
  else  printf("\n\t\300\304\304\304\304\304\304\304\304\304\304\304\304\304\301\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331");
}
void tableCalif(int i){
  int j;
  if (i){
    printf("\n\332\304\304\304\302\304\304\304\304\304\304\304\304\304\304\302");
    for(j=0; j<ALUM; j++) printf("\304\304\304\304\304\304\302");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
  }else{
    printf("\n\300\304\304\304\304\304\304\304\304\304\304\304\304\304\304\301");
    for(j=0; j<ALUM; j++) printf("\304\304\304\304\304\304\301");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331");
  }
}
void printLowerAvgs(Alumno_t alum[ALUM]){
  int i, b=0;
  for(i=0; i<ALUM; i++) if(alum[i].avg>=6) b=1;
  if(b){
    printf("\n\t\t LISTA DE ALUMNOS CON CALIFICACION REPROBATORIA\n");
    tableList(1);
    for(i=0; i<ALUM; i++) if(alum[i].avg<6)  printf("\t\263 %2d \263 %6s\263 %6s\263 %7c      \263   2019-%d \263    %.2f   \263\n", alum[i].ID, alum[i].name, alum[i].mail, alum[i].gender, alum[i].period, alum[i].avg);
    tableList(0);
  }
  else sadmessage(1);
}
void sadmessage(int i){
  printf("\n\t\t\332\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
  if(i)printf("\n\t\t\263 NO HAY ALUMNOS CON CALIFICACION REPROBATORIA\263\n");
  else printf("\n\t\t\263 NO HAY PRACTICAS CON PROMEDIO MENOR A 6\263\n");
  printf("\t\t\300\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331");
}
void printLowerPracAvgs(Prac_t prac[PRAC]){
  int i, b=0;
  for(i=0; i<PRAC; i++) if(prac[i].avg>=6) b=1;
  if(b){
    printf("\n\t\t LISTA DE PRACTICAS CON PROMEDIO MENOR A 6\n");
    tableListPracs(1);
    for(i=0; i<PRAC; i++) if(prac[i].avg<6)  printf("\t\263 %2d \263 %6s\263 %6s\263    %.2f   \263\n", prac[i].ID, prac[i].title, prac[i].comment, prac[i].avg);
    tableListPracs(0);
  }
  else sadmessage(0);
}
void printBestAvg(Alumno_t alum[ALUM]){
  int i,b=0, best;
  float max=-1;
  Alumno_t aux[ALUM];
  cpyStruct(alum, aux);
  printf("\n\t\t ALUMNO(S) CON MEJOR PROMEDIO \n");
  tableList(1);
  for(i=0; i<ALUM; i++) if(aux[i].avg>max){
    max=aux[i].avg;
    best=i;
  }
  printf("\t\263 %2d \263 %6s\263 %6s\263 %7c      \263   2019-%d \263    %.2f   \263\n", aux[best].ID, aux[best].name, aux[best].mail, aux[best].gender, aux[best].period, aux[best].avg);    
  aux[best].avg=0;
  do{
    b=0;
    for(i=0; i<ALUM; i++) if(aux[i].avg==max){
      printf("\t\263 %2d \263 %6s\263 %6s\263 %7c      \263   2019-%d \263    %.2f   \263\n", aux[i].ID, aux[i].name, aux[i].mail, aux[i].gender, aux[i].period, aux[i].avg);
      aux[i].avg=0;
      b=1;
    }
  }while(b!=0);
  tableList(0);
}
void cpyStruct(Alumno_t alum[ALUM], Alumno_t aux[ALUM]){
  int i;
  for(i=0; i<ALUM; i++) aux[i]=alum[i];
}
void end(){ 
  printf("\n\n\t");
  system("cls");
  system("color 07");
}