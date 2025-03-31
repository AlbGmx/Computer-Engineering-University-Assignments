#include <stdio.h>
/*
    Algoritmos y Estructura de Datos
    Práctica 6. Recursividad 
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 1 de noviembre a las 13:00

    Desarrollar un programa basado en un algoritmo recursivo 
    cuya funcion sea devolver el numero de #'s alrededor de 
    una celda de una matriz ROWSxCOLS.
 
*/

#define ROWS 5 
#define COLS 9
#define QUANTITY 15 
    void main(){
        char matrix[ROWS][COLS];
        int intMtx[ROWS][COLS];
        initializeMtx(matrix);
        instertInMtx(matrix);
        checkSorrounds(matrix, intMtx, 0, 0);
    }

    void initializeMtx(char matrix[ROWS][COLS]){
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                matrix[i][j] = " ";
    }
    void instertInMtx(char matrix[ROWS][COLS]){
        int remaining = 15;
        int i = 0;
        while(remaining>0){
            if() {
                matrix[0][i] = "#";
                i++;
                remaining--;
            }
            if(i>=5) i = 0;
        }
    }
    int checkSorrounds(char matrix[ROWS][COLS], int intMtx[ROWS][COLS], int ren, int col){
        if(col > COLS ) ren++;
        if(ren > ROWS ) return 0; //Caso Base

        return 0;
    }
}