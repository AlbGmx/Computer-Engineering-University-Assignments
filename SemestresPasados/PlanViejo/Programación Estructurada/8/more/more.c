#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]){
  FILE *fileptr=NULL;
  int b=1, i=0, ren=15;
  char cad[100];
  if((arg<2)){
    printf("Falta nombre de archivo");
    exit(-1);
  }
  fileptr = fopen(argv[1],"r");
  if(!fileptr){
    printf("Error al abrir el archivo");
    exit(-1);
  }
  do{
    fgets(cad, 100, fileptr);
    printf("%s", cad);
    i++;
    if(i>=ren){
      ren=10;
      if (getchar()!=10) {
        b=0;
      }
      i=0;    
     
    }
  }while(b!=0 && !feof(fileptr));
  fclose(fileptr);
  return 0;
}