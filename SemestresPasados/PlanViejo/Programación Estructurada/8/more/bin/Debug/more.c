#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]){
  FILE *fileptr;
  int i=0;
  char c,txt[100];
  if(arg<2){
    printf("Falta nombre de archivo");
    exit(-1);
  }
  if(fileptr = fopen(argv[1],"r")){
    printf("Error al abrir el archivo");
    exit(-1);
  }
  c=fgetc(fileptr);
  do{
    printf("%c", c);
    c=fgetc(fileptr);
   }while(c!=EOF);

  fclose(fileptr);
  return 0;
}
