#include <stdio.h>
#ifndef MTX
#define MTX

typedef struct{
  float **mtx;
  int ren;  
  int col;
} Mtx_t;

void fillMtx_t(FILE*, Mtx_t*, int); 
void getSizeMtx(FILE*, int*, int*);
void mtxMalloc(Mtx_t*);
void fillFromFile(FILE*, Mtx_t*);
void transponer(Mtx_t, Mtx_t*);
void printM2F(Mtx_t, FILE*);
Mtx_t hadamard(Mtx_t, Mtx_t);
Mtx_t prodPunto(Mtx_t, Mtx_t);

#endif