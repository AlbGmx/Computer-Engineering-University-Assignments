#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CMPLX.h"

void  getcmplx(Cmplx_t *a, int num){  //Capturar un numero complejo en su forma rectangular -> a + bi
  printf("\n\nNumero imaginario %d", num);
  printf("\nIntroduce la parte real... ");
  scanf("%f", &a->r);
  printf("\nIntroduce la parte imaginaria... ");
  scanf("%f", &a->bi);
}  
void  printRec(Cmplx_t a){  //Imprimir un numero complejo
  printf("\n\nNumero imaginario (forma rectangular) = %.2f %+ .2fi\n", a.r, a.bi);
}
void  printPol(Cmplx_t a){  //Imprimir un numero complejo en su forma polar -> r(cosθ + isinθ)
  float r=0, theta=0;
  r=(sqrt((a.r*a.r)*(a.bi*a.bi)));
  theta=((atan(a.bi/a.r)));
  printf("\n\nNumero imaginario (forma polar) = (%.2f)(Cos(%.2f) + isin(%.2f))\n", r, theta, theta);
}
void  sumCmplx(Cmplx_t a, Cmplx_t b, Cmplx_t *c){  //Sumar dos numeros complejos y guardar el resultado en un tercer numero complejo
  c->r = a.r + b.r;                             
  c->bi = a.bi + b.bi;                          
}                                               
void  resCmplx(Cmplx_t a, Cmplx_t b, Cmplx_t *c){  //Sumar dos numeros complejos y guardar el resultado en un tercer numero complejo
  c->r = a.r - b.r;  
  c->bi = a.bi - b.bi;
}
void  multComplx(Cmplx_t a, Cmplx_t b, Cmplx_t *c){  //Multiplicar dos numeros complejos y guardar el resultado en un tercer numero
  c->r = ((a.r*b.r)-(a.bi*b.bi));
  c->bi = ((a.r*b.bi)+(a.bi*b.r));
}
void  divComplx(Cmplx_t a, Cmplx_t b, Cmplx_t *c){  //Dividir dos numeros complejos y guardar el resultado en un tercer numero
  Cmplx_t conjugate, aux1, aux2;
  conjugate.r = b.r;
  conjugate.bi = ((-1)*b.bi);
  multComplx(a,conjugate, &aux1);
  multComplx(b,conjugate, &aux2);  
  c->r = (aux1.r/aux2.r);
  c->bi = (aux1.bi/aux2.r); 
}