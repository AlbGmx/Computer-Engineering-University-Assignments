#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "MTRX.h"

void start(int calif[][PRAC], int col, int row){
  srand(time(NULL));
  initMtrx(calif, ALUM, PRAC);
  system("cls");
  system("color 0a");
}
void initMtrx(int calif[][PRAC], int row, int col){
  int i;
  for(i=0; i<col*row; i++)  calif[0][i]=1+rand()%10;
}
int showOpc(int calif[][PRAC], int row, int col){
  int opc;
  printf("\n\n\t");
  printf("\n \t (1) Mostrar tabla de calificaciones");
  printf("\n \t (2) Mostrar calificaciones de un solo alumno");
  printf("\n \t (3) Mostrar calificaciones de una practica");
  printf("\n \t (4) Mostrar moda, mediana y media");
  printf("\n \t (5) Salir\n");
  printf("\n\t\t\250Qu\x82 desea realizar? \n\n\tCapture su eleccion...  ");
  scanf("%d", &opc);
  return opc;
}
void printAlumCalif(int calif[][PRAC], int row, int col, int select){
  int i, id;
  if(select){
    while(getchar()!='\n'); 
    printf("\n\nIngrese el ID del alumno... ");
    scanf("%d", &id); 
    if(id>=row) printf("\n\n\tValor introducido no valido");
    else{
      printf("\n           ");
      for (i=0; i<col; i++) printf("Prac %d\263", i);
      printf("Promedio  prac\263");
      printf("\nAlumno %d  ", id);
      if(id<9) printf(" ");
      for (i=0; i<col; i++){
        if(i>9) printf("%4d   \263", calif[id][i]); //Para mantener el formato, se agrega un espacio  si "i" es mayor que 9 
        else printf("%4d  \263", calif[id][i]);
      }
      printf("     %.2f     \263", avgAlum(calif, row,col, id));
    }
  }
  else {
    printf("\n           ");
    for (i=0; i<col; i++) printf("Prac %d\263", i);
    printf("Promedio  prac\263");
    for(id=0; id<row; id++){
      printf("\nAlumno %d  ", id);
      if(id<=9) printf(" ");
      for (i=0; i<col; i++) {
        if(i>9) printf("%4d   \263", calif[id][i]);
        else printf("%4d  \263", calif[id][i]);
      }
      printf("     %.2f     \263", avgAlum(calif, row,col, id));
    }   
    printf("\nPromedio   ");
    for (i=0; i<col; i++){
      if (i>9) printf(" %.2f  \263", avgPrac(calif, row,col, i));  
      else printf(" %.2f \263", avgPrac(calif, row,col, i));
    }
  }
}
void printAvgPrac(int calif[][PRAC], int row, int col){
  int i, id;
  while(getchar()!='\n'); 
  printf("\n\nIngrese el ID de la practica... ");
  scanf("%d", &id); 
  if(id>=col) printf("\n\n\tValor introducido no valido"); //Si piden una numero de practica mas grande que el numero de practicas,  el valor no es valido
  else{
    printf("\n            \263Practica %d\263", id);
    for (i=0; i<row; i++){
      printf("\nAlumno %d   ", i);
      if(i<10) printf(" \263");
      else printf("\263"); 
      if(id>=10) printf("%6d     \263", calif[i][id]);
      else printf("%6d    \263", calif[i][id]);    
    }
    printf("\nProm Total  ");
    if(id>=10) printf("\263   %.2f    \263", avgPrac(calif, row,col, id));
    else printf("\263   %.2f   \263", avgPrac(calif, row,col, id));
  }
}
float avgAlum(int calif[][PRAC], int row, int col, int id){
  int i;
  float avg=0;
  for(i=0; i<col; i++) avg+=calif[id][i]; //Promedio de calificaciones
  return avg/i;
}
float avgPrac(int calif[][PRAC], int row, int col, int id){
  int i;
  float avg=0;
  for(i=0; i<row; i++){  //Promedio de practicas
    avg+=calif[i][id];
  }
  return avg/i;
}
void medidas(int calif[][PRAC], int row, int col){
  int auxcal[row][col];
  copyM(calif, row, col, auxcal);
  sort(auxcal, row, col);  
  printf("\n\n\t ");
  moda(auxcal, row, col);
  printf("\n\n\t La media es   = %.2f", media(auxcal, row, col));
  printf("\n\n\t La mediana es = %.2f", mediana(auxcal, row, col)); 
}void copyM(int calif[][PRAC], int row, int col, int auxcal[][PRAC]){ //Copiar matriz de calificaciones a una matriz aux
  int i;
  for(i=0; i<row*col; i++)  auxcal[0][i]=calif[0][i];  
}
void sort(int M[][PRAC], int row, int col){//Algoritmo ​ ​ de ​ ​ ordenamiento ​ ​ por ​ ​ Burbuja

  int i, n, tmp, j=0, swapped=1; 
  n=row*col;
  while(swapped){
    swapped=0;
    j++;
    for(i=0; i<n-j; i++){
      if(M[0][i]>M[0][i+1]){
        tmp=M[0][i];
        M[0][i]=M[0][i+1];
        M[0][i+1]=tmp;
        swapped=1;     
      }
    }    
  }
}
void moda(int auxcal[][PRAC], int row, int col){
  int freqTbl[10]={0}, i, mayor, aux=-1;
  fillFreqTbl(freqTbl, row, col, auxcal);  //Se crea una tablade frecuencias con las calif de 1 a 10
  for(i=0; i<10; i++)  if(freqTbl[i]>aux){ //Se revisa la tabla de frecuencias en busca de la calif que se repite mas veces
    mayor=i+1; 
    aux=freqTbl[i];
  }
  printf("\n\t Moda(s)\t\263 %d \263", mayor);
  freqTbl[mayor-1]=0;  //Esa moda que ya se imprimió es eliminada
  for(i=0; i<10; i++)  if(freqTbl[i]==aux){ //Se vuelve a buscar por si existe algun otro numero con las misma frecuencia (moda)
    printf("  %d \263", i+1);  //en caso de haber otra moda, simplemente se imprime
  }
}
void fillFreqTbl(int freqTbl[10], int row, int col, int auxcal[][PRAC]){
  int i;
  for(i=0; i<row*col; i++) freqTbl[auxcal[0][i]-1]++; //Se llena la tabla de frecuencias
}
float mediana(int auxcal[][PRAC], int row, int col){
  float mediana=0;
  if((row*col)%2) mediana=auxcal[0][(row*col)/2];  //Existen dos casos para sacar la mediana, si se tiene un conjunto par e impar
  else mediana=(auxcal[0][(row*col)/2]+auxcal[0][((row*col)/2)+1])/2; //Par
  return mediana;
}
float media(int auxcal[][PRAC], int row, int col){
  int i;
  float media=0;
  for(i=0; i<row*col; i++) media+=auxcal[0][i];  //Promedio
  return (media/i);
}
void end(){ 
  printf("\n\n\t");
  system("cls");
  system("color 07");
}

