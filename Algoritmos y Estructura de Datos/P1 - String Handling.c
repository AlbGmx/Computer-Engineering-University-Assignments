/*
    Algortimos y Estructura de Datos
    Práctica 1. Manejo de cadenas
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 28 de septiembre a las 13:00

    Actividad: Elaborar un programa de encriptacion basado en funciones que,
    al introducir una frase este devuelva la palabra encriptada (criptograma) 
    El metodo de encriptacion es el siguiente: 
        Cadena a encriptar: "Hola Mundo"
    Se divide el mensaje en dos bloques, en el primer bloque se colocan los simbolos 
    que se encuentren en una posicion par y los impares en el segundo:
        Bloque 1: Hlmno     Bloque 2: oaud
    Por ultimo, para obtener el criptograma se concatenan ambos bloques (primero bloque 1):
        Criptograma: Hlmnooaud    
    
    REQUISITOS DEL PROGRAMA:
    § El usuario debe proporcionar la frase para encriptar
    § El programa debe calcular el tamaño de la frase al momento de capturar
    § El tamaño máximo de la frase estará definido por el programador
    § El programa debe repetirse N veces hasta elegir la opción de salida.
    § No utilice la biblioteca string para las operaciones de cadena.
    § Debe presentarse en pantalla el progreso del proceso de separación de caracteres.
    § Debe presentarse en pantalla la frase a encriptar
    § Debe presentarse en pantalla el criptograma
    § La función encriptadora debe regresar el criptograma cadena
*/

#include <stdio.h>
#define SIZE 10

void encryptionLoop();
void clearSpaces(char[]);
int getSize(char[]);
int checkSize(int);
void fillStr(char[], int, char);
void encryption(char[], int, char[]);
void concatenateBlocks(char[], char[], char[]);

void main(){
    char flag = ' ';
    do{
        encryptionLoop();
        printf("\n\nDesea encriptar otra frase? Y/N ");
        scanf("%c", &flag);
        fflush(stdin);  //Limpiar buffer
    } while (flag == 'y' || flag == 'Y');
}
void encryptionLoop(){
    char phrase[SIZE] = ""; 
    char encrypted[SIZE] = "";
    int size = 0;
    printf("\n%d caracteres es el tama%co maximo predefinido\nInserte frase a encriptar: ", SIZE, 164);
    clearSpaces(gets(phrase)); //Elimina los espacios de la cadena, ya que estos no son utilizados al encriptar
    size = getSize(phrase);
    if(checkSize(size)) printf("\nEl tama%co de la frase a encriptar supera el limite establecido por el programa", 164);
    else{
        printf("\nFrase a encriptar: \"%s\"", phrase);
        encryption(phrase, size, encrypted);
        printf("\n\nCriptograma: \"%s\"", encrypted);
    }
}
int getSize(char phrase[SIZE]){
    int i=0;
    while(phrase[i]) i++;
    return i;
}
int checkSize(int size){
    return (size < SIZE) ?  0 : 1;
}

//Llena la cadena hasta la posicion indicada por el usuario con el simbolo especificado
void fillStr(char str[SIZE], int size, char sym){
    int i=0;
    for(i=0; i<size; i++){
        str[i]=sym;
    }
    str[i] = '\0'; //Coloca el caracter de terminacion al final de la cadena
}
void clearSpaces(char phrase[SIZE]){
    int i=0, j=0, size=0;
    char aux = '\0';
    size = getSize(phrase);
    while(phrase[i]){
        if(phrase[i] == ' '){
            j = i;
            while ( j < size ){ //Recorrer los espacios hacia la derecha
                aux = phrase[j];
                phrase[j] = phrase[j+1];
                phrase[j+1] = aux;
                j++;
            }
        }else i++;
    }
}
void encryption(char phrase[SIZE], int size, char encrypted[SIZE]){
    int i=0, j=0;
    char block_1[SIZE] = " ";
    char block_2[SIZE] = " ";

    //Llena ambos bloques de cadenas, si el tamaño es impar agrega un caracter extra al bloque 1
    if( !(size%2) ) fillStr(block_1, (size/2), '_');
    else fillStr(block_1, (size/2)+1, '_');
    fillStr(block_2, (size/2), '_');

    while(phrase[i]){
        if( !(i%2) ){
            block_1[j] = phrase[i];
            printf("\nBloque 1: %s", block_1);
        }
        else{
            block_2[j] = phrase[i];
            printf("\t   Bloque 2: %s", block_2);
            j++;
        }
    i++;
    }
    concatenateBlocks(block_1, block_2, encrypted);

}
void concatenateBlocks(char block_1[SIZE/2], char block_2[SIZE/2], char encrypted[SIZE]){
    int i = 0;
    int size = getSize(block_1);

    for(i=0; i<size*2; i++){
        if(i<size){
            encrypted[i] = block_1[i]; 
        }
        else encrypted[i] = block_2[i-size];
    }
}