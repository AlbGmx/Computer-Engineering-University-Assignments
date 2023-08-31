#include<stdio.h>
#include<stdlib.h> //funcion qsort

float max(int*, int);
float min(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);

//EXTRA 10pts
//float desviacion(int*, int);

int main(int argc, char* argv[])
{
    int size, i, tam;
    //Crear un arreglo de tipo entero de 50 elementos de forma aleatoria
    
    /*srand (time(NULL));//Establecer semilla para valores aleatorios
     *rand()%numero; //rand() regresa un valor entero de gran tamaño, para acortar el valor se aplica modulo del valor como limite maximo
     */
    int arreglo[] = {-1,2,6,8,4,1,5,6,8,7,3,10,-50,-3};
    tam = sizeof(arreglo)/sizeof(arreglo[0]);
    
    //arreglo de apuntadores a funciones
    float (*funciones[])(int*, int) = {max, min, media, mediana, moda };
    char* nombres[] = {"maximo", "minimo", "media", "mediana", "moda"};
    
    size = sizeof(funciones)/sizeof(funciones[0]);
    for(i=0; i<size; i++)
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tam));
    
    return 0;
}

float max(int* array, int size)
{
    return 0;
}

float min(int* array, int size)
{
    return 1;
}

float media(int* array, int size)
{
    return 2;
}

//Se requiere datos ordenados
float mediana(int* array, int size)
{
    //usar funcion qsort se stdlib.h para ordenamiento de datos
    return 3;
}

float moda(int* array, int size)
{
    return 4;
}
