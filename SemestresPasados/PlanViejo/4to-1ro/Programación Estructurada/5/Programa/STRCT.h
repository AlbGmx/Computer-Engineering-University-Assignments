#ifndef STRCT
#define STRCT
#define PRAC 10  //Usar 10 como maximo numero de practicas
#define ALUM 10  //Usar 10 como maximo numero de alumnos

typedef struct{
  int ID, year, period, status, calif;
  char name[20], mail[20], gender;
  float avg;
} Alumno_t;

typedef struct{
  int ID;
  char title[30], comment[20];
  float avg;
} Prac_t;

void initMtrx(int[][PRAC], int, int);
void fillAVG(int[][PRAC], int, int, Alumno_t[ALUM], Prac_t[PRAC]);
float avgAlum(int[][PRAC], int, int, int); 
float avgPrac(int[][PRAC], int, int, int); 
void printAlumCalif(int[][PRAC], int, int, Alumno_t[ALUM]); 
void printAvgPrac(int[][PRAC], int, int, Alumno_t[ALUM]); 
void start(int[][PRAC], int, int, Alumno_t[ALUM], Prac_t[PRAC]);
void tableList(int);
void tableListPracs(int);
void generatePracs(Prac_t prac[PRAC]);
void tableCalif(int);
void tableAlumInfo(int);
void tablePracInfo(int);
void generateNames(Alumno_t[ALUM]);
void printAlumList(Alumno_t[ALUM]);
void printPracList(Prac_t[PRAC]);
void printAlumInfo(Alumno_t[ALUM]);
void printPracInfo(Prac_t[PRAC]);
void printBestAvg(Alumno_t[ALUM]);
void printLowerAvgs(Alumno_t[ALUM]);
void printLowerPracAvgs(Prac_t[PRAC]);
void sadmessage();
int showOpc();
void cpyStruct(Alumno_t[ALUM], Alumno_t[ALUM]);
void end();

#endif