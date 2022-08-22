/*  practica6 Programación Estructurada						                    	Gómez Cárdenas Emmanuel Alberto
    28/09/2019																		                                            Grupo 531
    Programa para resolver las siguientes problematicas, para cada ejercicio crear una biblioteca que 
    contenga las funciones que se requieren en cada uno de ellos.
    1.- Crear una biblioteca para manipulacion de numeros complejos.
    2.- Crear una biblioteca para manipulaion de numeros racionales.
    3.- Crear una biblioteca para manipulacion de vectores en R3.

*/

#include <stdio.h>
#include <stdlib.h>
#include "CMPLX.h"
#include "VECT.h"
#include "FRACC.h"

int main(){
  Cmplx_t a,b,c;
  Fracc_t x,y,z;
  Vect_t i, j, k;
   
    printf("\n\n\n----------Numeros Complejos----------\n\n");
    getcmplx(&a,0);  
    getcmplx(&b,1);
    printRec(a);
    printPol(a);
    sumCmplx(a, b, &c);
    printRec(c);
    resCmplx(a, b, &c) ;
    printRec(c);
    multComplx(a, b, &c);
    printRec(c);
    divComplx(a, b, &c); 
    printRec(c);
    printf("\n\n\n----------Numeros Complejos----------\n\n\n");
   
   
    printf("\n\n\n----------Numeros Racionales----------\n\n");
    getFracc(&x,1);
    getFracc(&y,2);
    printFracc(x);
    sumFracc(x, y, &z); 
    printFracc(z);
    resFracc(x, y, &z); 
    printFracc(z);
    multFracc(x, y, &z);
    printFracc(z);
    divFracc(x, y, &z);
    printFracc(z);    
    printf("\n\n\n----------Numeros Racionales----------\n\n\n");

    

    printf("\n\n\n----------Manipulacion de Vectores----------\n\n"); 
    getVect(&i,0); 
    getVect(&j,1);
    printVect(i);
    printf("\n\n modulo = %.2f", modVect(i));
    sumVect(i, j, &k);
    printVect(k);
    resVect(i, j, &k);
    printVect(k);
    printf("\n\n Producto vectorial %.2f",escVect(i, j));
    vectVect(i, j, &k);  
    printVect(k);
    escXvect(&i, 12);
    printVect(i);
    printf("\n\n\n----------Manipulacion de vectores----------\n\n\n");
  getchar();
  return 0;
}
