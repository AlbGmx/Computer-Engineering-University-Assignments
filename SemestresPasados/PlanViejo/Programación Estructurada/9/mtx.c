#include <stdlib.h>
#include <stdio.h>
#include "mtx.h"

void fillMtx_t(FILE *mtxPtr, Mtx_t *a, int flag){
  getSizeMtx(mtxPtr, &a->ren, &a->col);
  mtxMalloc(a);
  if(flag) fillFromFile(mtxPtr, a);
}
void getSizeMtx(FILE *mtxPtr, int *ren, int *col){
  char c;
  int i=0;
  if(!mtxPtr && ren==0 &&   col==0 ){
    printf("\nMatriz no dimensionada\n");
    exit(-1);
  }
  *col=1;
  *ren=1;
  do{
    i++;
    c=fgetc(mtxPtr);
    if(c==32) *col+=1;
    else if(c==10 || c==13) *ren+=1;
  }while(c!=EOF);
  *col+=*ren-1;
  *col/=*ren;
  if ((i%2)) printf("\nPrecaucion: puede que la matriz tenga un error de escritura o se muestre incorrectamente, favor de revisar el archivo.\n");
  rewind(mtxPtr);
}
void mtxMalloc (Mtx_t *a){
  int i,j;
  //a.ren <- renglones 
  //a.col <- columnas
  if(a->ren>100 || a->col>100){
    printf("\tdimensiones excedentes");
    exit(-1);
  }
  a->mtx =((float**) (malloc(sizeof(float*)*a->ren)));
  if(!a->mtx) exit (-1);
  for (i=0; i<a->ren; i++) a->mtx[i]=((float*)(malloc(sizeof(float)*a->col)));
   for(i=0; i<a->ren; i++){
    for(j=0; j<a->col; j++){
      a->mtx[i][j]=0;        
    //  printf("//%p--%p//    ", &a.mtx[i][j], &a.mtx[0][i*3+j]);
    }      
  }
}
void fillFromFile(FILE *mtxPtr, Mtx_t *a){
  int i,j;
  for(i=0; i<a->ren; i++){
    for(j=0; j<a->col; j++){
      fscanf(mtxPtr, "%f", &a->mtx[i][j]);
    } 
  }
    
  rewind(mtxPtr);
}
void transponer(Mtx_t a, Mtx_t *r){
  int i, j;
  r->ren=a.col;
  r->col=a.ren;
  mtxMalloc(r);
  for(i=0; i<a.ren; i++){ 
    for(j=0; j<a.col; j++){
      r->mtx[j][i]=a.mtx[i][j];
    }
  }
}
void printM2F(Mtx_t a, FILE* fPtr){
  int i,j; 
  if (fPtr==stdout){
    for(i=0; i<a.ren; i++){
      for(j=0; j<a.col; j++){
        fprintf(fPtr, "%7.2f ", a.mtx[i][j]);
      }
      fprintf(fPtr, "\n");  
    }
  }else{
    for(i=0; i<a.ren; i++){
      for(j=0; j<a.col; j++){
        fprintf(fPtr, "%.2f", a.mtx[i][j]);
          if(j+1!=a.col) fprintf(fPtr," ");  
      }
      if(i+1!=a.ren) fprintf(fPtr, "\n");  
    }
  }
}
Mtx_t hadamard(Mtx_t a, Mtx_t b){
  Mtx_t r;
  r.ren=a.ren;
  r.col=b.col;
  mtxMalloc(&r);
  int i,j; 
  for(i=0; i<a.ren; i++)
    for(j=0; j<a.col; j++)
      r.mtx[i][j]=((a.mtx[i][j]) * (b.mtx[i][j]));
  return r;
}
Mtx_t prodPunto(Mtx_t a, Mtx_t b){
	int i, j, k;
  Mtx_t r;
  r.ren=a.ren;
  r.col=b.col;
	mtxMalloc(&r);
	for(i=0; i<a.ren; i++){
    for(j=0; j<b.col; j++){
			for(k=0; k<b.ren; k++){
				r.mtx[i][j]= ((a.mtx[i][k]) * (b.mtx[k][j]));
      }
    }
  }
  return r;
}


