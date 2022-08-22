#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "VECT.h"

void getVect(Vect_t *a, int num){ //Obtener vector
  printf("\nVector %d\n", num);
  printf("\nIntroduce el componente i...");
  scanf("%f", &a->i);
  printf("\nIntroduce el componente j...");
  scanf("%f", &a->j);  
  printf("\nIntroduce el componente k...");
  scanf("%f", &a->k);
}
void printVect(Vect_t a){ //Imprimir vector
  printf("\n\n Vector = %.2fi %+.2fj %+.2fk\n", a.i, a.j, a.k);
}
float modVect(Vect_t a){  //Sacar modulo del vector
  float mod;
  mod = sqrt((a.i*a.i)+(a.j*a.j)+(a.k*a.k));
  return mod;  
}
void sumVect(Vect_t a, Vect_t b, Vect_t *c){ //Sumar dos vectores y guardar el resultado en el tercero
  c->i=(a.i+b.i);
  c->j=(a.j+b.j);
  c->k=(a.k+b.k); 
}
void resVect(Vect_t a, Vect_t b, Vect_t *c){ //Restar dos vectores y guardar el resultado en el tercero
  c->i=(a.i-b.i);
  c->j=(a.j-b.j);
  c->k=(a.k-b.k); 
}
float escVect(Vect_t a, Vect_t b){  //Producto escalar de dos vectores (Producto punto)
  float i,j,k;
  i=(a.i*b.i);
  j=(a.j*b.j);
  k=(a.k*b.k); 
  return (i+j+k);
}
void escXvect(Vect_t *a, float esc){  //Producto de un vector por un escalar
  a->i*=esc;
  a->j*=esc;
  a->k*=esc;  
}
void vectVect(Vect_t a, Vect_t b, Vect_t *c){  //Producto vectorial de dos vectores (Producto cruz)
  c->i = ((a.j*b.k)-(a.k*b.j));
  c->j =((-1)*((a.i*b.k)-(a.k*b.i)));
  c->k = ((a.i*b.j)-(a.j*b.i)); 
}



























