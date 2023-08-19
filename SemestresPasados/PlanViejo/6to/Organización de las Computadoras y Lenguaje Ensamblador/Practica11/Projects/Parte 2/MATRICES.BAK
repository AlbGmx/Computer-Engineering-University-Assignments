#include<stdio.h>
extern void mulMat3x3(char[], char[], char[]);
void printMat(unsigned char[], int);
void main(){
    //Uso de chars, ya que el codigo en asm esta hecho para 8 bits
    char matA[9] = {1,2,3,4,5,6,7,8,9};
    char matB[9] = {9,8,7,6,5,4,3,2,1};
    char matR[9] = {0};
    printf("\nMatriz A:\n");
    printMat(matA,9);
    printf("\nMatriz B:\n");
    printMat(matB,9);
    //Matrices enviadas a ensamblador a multiplicarse
    mulMat3x3(matA, matB, matR);
    printf("\nMatriz Resultante:\n");
    printMat(matR,9);
    getchar();
}

void printMat(unsigned char mat[9], int size){
    int i,j;
    for (i = 0; i < size/3; i++){
	for (j = 0; j < size/3; j++) printf("\t%d", mat[i*3+j]);
	printf("\n");
    }
}