#ifndef MTRX
#define MTRX

#define PRAC 10
#define ALUM 20

void start();
void initMtrx(int[][PRAC], int, int);
int showOpc(int[][PRAC], int, int);
void fillFreqTbl(int[], int, int, int[][PRAC]);
void medidas(int[][PRAC], int, int);
void moda(int[][PRAC], int, int);
float mediana(int[][PRAC], int, int);
float media(int[][PRAC], int, int);
float avgAlum(int[][PRAC], int, int, int); 
float avgPrac(int[][PRAC], int, int, int); 
void printAlumCalif(int[][PRAC], int, int, int); 
void printAvgPrac(int[][PRAC], int, int); 
void copyM(int[][PRAC], int, int, int[][PRAC]);
void end();
void sort(int [][PRAC], int, int);



#endif