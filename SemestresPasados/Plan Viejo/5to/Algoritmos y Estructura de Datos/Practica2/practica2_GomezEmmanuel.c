/*
    Algortimos y Estructura de Datos
    Práctica 2. Análisis de Algortimos Empirico
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 5 de octubre a las 13:00

    Diseñe e implemente un algoritmo que codifique
    una frase cualquiera proporcionada por el usuario, 
    con un desplazamiento variable proporcionado también 
    por el usuario y determine el tiempo que tarda en 
    codificarse una palabra. Considere que las letras 
    que no están en el alfabeto permanecen iguales.

*/
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 6000

void fillStr(char[], int, char);
void encryption(char[], int);
void encryptionLoop();


void main(){
    char flag = ' ';
    do{
        encryptionLoop();
        printf("\n\nDesea encriptar otra frase? (Y/N) :");
        scanf("%c", &flag);
        fflush(stdin);  //Limpiar buffer
    } while (flag == 'y' || flag == 'Y');
}
void encryptionLoop(){
    char phrase[SIZE]="";
    int shifts = 0, i=0;
    double executionTime = 0;
    clock_t end, begin;
    printf("\nIntroduzca la frase a codificar: ");
    gets(phrase);
    printf("\nIntroduzca el n%cmero de dezplazamientos: ", 163);
    scanf("%d", &shifts);
    fflush(stdin);

    printf("\nFrase a codificar: \"%s\"", phrase);

    begin = clock();
    encryption(phrase, shifts);
    end = clock();
    
    executionTime = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nFrase codificada: \"%s\"", phrase);
    printf("\nEl tiempo de ejecuci%cn fu%c: %lf", 162, 130, executionTime);
}

void encryption(char phrase[SIZE], int shifts){
    int i=0;
    if(shifts < 0) shifts = shifts % 26 + 26; //Modulo de un número negativo
    while(phrase[i]){
        if(phrase[i]>='A' && phrase[i]<='Z') 
            phrase[i] = 'A'+ ( ( phrase[i] + shifts - 'A') %26);
        else if(phrase[i]>='a' && phrase[i]<='z') 
            phrase[i] = 'a'+ ( ( phrase[i] + shifts - 'a') %26);
        i++;
    }
}