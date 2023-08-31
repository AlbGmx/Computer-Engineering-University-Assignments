#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]){
  FILE *orignPtr=NULL, *destnPtr=NULL;
  char c;
  int b=0;
  if((arg<2)){
    printf("Falta nombre de archivo");
    exit(-1);
  }
  orignPtr = fopen(argv[1],"r");
  if(!orignPtr){
    printf("Error al abrir el archivo %s", argv[1]);
    exit(-1);
  }
  if (arg==3){
    destnPtr = fopen(argv[2],"w");
    b=1;
    if(!destnPtr){
      printf("Error al abrir el archivo %s", argv[2]);
      exit(-1);
    } 
  }
  do{
    c=fgetc(orignPtr);
    if (c>64 && c<91) c+=32;
    else if (c>96 && c<123) c-=32; 
    if(b) fprintf(destnPtr, "%c", c);
    else  printf("%c", c);
  }while(c!=EOF);
  fclose(orignPtr); 
  fclose(destnPtr);
  return 0;  
}
