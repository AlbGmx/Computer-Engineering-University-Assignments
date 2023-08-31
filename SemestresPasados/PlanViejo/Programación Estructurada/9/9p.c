#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mtx.h"

int main(int arg, char *argv[]){
  FILE *maPtr=NULL, *mbPtr=NULL, *mrPtr=NULL;
  Mtx_t a, b, r;
  int flag=0;
  system("Color 07");  
  switch(arg){
    case 1:   
    case 2:  printf("Faltan argumentos");
             exit(-1); 
    break;  
    case 3:  if(!(maPtr=fopen(argv[2], "r"))){
               printf("No se pudo abrir el archivo %5s", argv[2]); 
               exit(-1); 
             }
    break;
    case 4:  if(!(maPtr=fopen(argv[2], "r"))){
               printf("No se pudo abrir el archivo %5s", argv[2]); 
               exit(-1); 
             }
             if(!strcmp(argv[1],"transponer")){
               if(!(mbPtr=fopen(argv[3], "w"))){
                 printf("No se pudo abrir el archivo %5s", argv[3]); 
                 exit(-1);  
               }
             }
             else {
               if(!(mbPtr=fopen(argv[3], "r"))){
                 printf("No se pudo abrir el archivo %5s", argv[3]); 
                 exit(-1);  
               }
             }
             fillMtx_t(maPtr, &a, 1);
             fillMtx_t(mbPtr, &b, 1);
             flag=1;  
    break;
    default: if(!(maPtr=fopen(argv[2], "r"))){
               printf("No se pudo abrir el archivo %5s", argv[2]); 
               exit(-1); 
             }
             if(!(mbPtr=fopen(argv[3], "r"))){
               printf("No se pudo abrir el archivo %5s", argv[3]); 
               exit(-1);  
             }
             if(!(mrPtr=fopen(argv[4], "w"))){
               printf("No se pudo abrir el archivo %5s", argv[4]); 
               exit(-1);  
             }
             fillMtx_t(maPtr, &a, 1);
             
             fillMtx_t(mbPtr, &b, 1);
             flag=2;
    break;
  }
  if(!strcmp("transpuesta",argv[1])){
    fillMtx_t(maPtr,&a, 1);
    if(flag){
      printf("%p", mbPtr);
      transponer(a,&b);
      printf("\nMatriz de %d renglones x %d columnas\n", b.ren, b.col);
      printM2F(b, mbPtr);
    }  
    else  {
      transponer(a,&b);
      printf("\nMatriz de %d renglones x %d columnas\n", b.ren, b.col);
      printM2F(b, stdout);
    }
  }
  else if(!strcmp("prodPunto",argv[1]) && flag>0){
    if(a.col!=b.ren){
      printf("\nEl numero de columnas de la matriz A\ndebe coincidir con el numero de renglones de la matriz B\n");
      printf("col A=%d != ren B=%d\n", a.col, b.ren);
      exit(-1);
    }
    if(flag==1){
      printf("\nMatriz de %d renglones x %d columnas\n", a.ren, a.col);
      printM2F(prodPunto(a, b), stdout);
      }  
    else{
        printM2F(prodPunto(a, b), mrPtr);
    }
  }
  else if(!strcmp("hadamard",argv[1]) && flag>0){
    if(a.ren!=b.ren || a.col!=b.col){
      printf("\nEl numero de renglones y columnas de la matriz A y B deben coincidir\n");
      exit(-1);
    }
    if(flag==1){
      printf("\nMatriz de %d renglones x %d columnas\n", a.ren, a.col);
      printM2F(hadamard(a, b), stdout);
      }  
    else{
        printM2F(hadamard(a, b), mrPtr);
    }
  } 
  else{
    printf("\n\n%s *%s* %s\n\n\t%s \n%s\t%s\t%s\n\n", "Operacion",argv[1],"incorrecta", "Operaciones Validas:", "transpuesta", "prodPunto", "hadamard");
  }
  return 0;  
}