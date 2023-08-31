#include <stdio.h>
#include <stdlib.h>
#include "FRACC.h"

void getFracc(Fracc_t *a, int num){  //Capturar un numero racional
  printf("\n\nNumero racional %d... ", num);
  printf("\n\n\tIntroduce el numerador... ");
  scanf(" %d", &a->num);  
  printf("\n\n\tIntroduce el denominador... "); 
  scanf(" %d", &a->den);  
  redFracc(a);
}
void printFracc(Fracc_t a){  //Imprimir un numero racional
  if(a.num==a.den) printf("\n\nNumero racional = 1");
  else if(a.den==1) printf("\n\nNumero Racional = %d", a.num);
  else printf("\n\nNumero racional = %d/%d", a.num, a.den);  
}
void sumFracc(Fracc_t a, Fracc_t b, Fracc_t *c){  //Sumar dos numeros racionales 
  c->num = ((a.num*b.den)+(a.den*b.num));
  c->den = (a.den*b.den);
  redFracc(c);  
}
void resFracc(Fracc_t a, Fracc_t b, Fracc_t *c){  //Restar dos numeros racionales
  c->num = ((a.num*b.den)-(a.den*b.num));
  c->den = (a.den*b.den);
  redFracc(c);  
}
void multFracc(Fracc_t a, Fracc_t b, Fracc_t *c){  //Multiplicar dos numeros racionales
  c->num = (a.num * b.num);  
  c->den = (a.den * b.den);
  redFracc(c);
}
void divFracc(Fracc_t a, Fracc_t b, Fracc_t *c){  //Dividir dos numeros racionales
  c->num = (a.num * b.den);  
  c->den = (a.den * b.num);
  redFracc(c);
}
int mcd(Fracc_t c){  //Obtener el maximo comun divisor de un numero racional
  int u=abs(c.num);
  int v=abs(c.den);
  if(v==0){
    return u;
  }
  int r;
  while(v!=0){
    r=u%v;
    u=v;
    v=r;
  }
  return u;
  } 
void redFracc(Fracc_t *c){  //Reducir a su minima expresion un numero racional
  int dividir=mcd(*c);
  c->num/=dividir;
  c->den/=dividir;
}