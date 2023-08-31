#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
 system("color 0a");
 system("cls");
  FILE *origen=NULL, *destino=NULL;
  char c, cad[25];
  int a,d;
  if(argc<3){
    printf("Falta nombre de archivo a leer");
    exit(-1);
  }
  origen=fopen(argv[1], "r");
  destino=fopen(argv[2], "w");
  if (!(origen||destino)){
    printf("Fallo al abrir");
    exit(-1);
  }
  printf("Cargando archivos");
  for(a=0; a<10000; a++) for(d=0; d<20000; d++){}
  printf(".");
  for(a=0; a<10000; a++) for(d=0; d<20000; d++){}
  printf(".");
  for(a=0; a<10000; a++) for(d=0; d<20000; d++){}
  printf(".");
  for(a=0; a<10000; a++) for(d=0; d<20000; d++){}
  printf("\nArchivos cargados\n");
  c=fgetc(origen);
  while(c!=EOF){
    fprintf(destino,"%c",c);
    printf("%c", c);
    c=fgetc(origen);
    for(a=0; a<10000; a++) for(d=0; d<300; d++){}
  }
  fclose(origen);
  fclose(destino);
  return 0;
}
