#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    system("color 0a");
    char c, cad[25];
    printf("Introduzca nombre ");
    scanf("%s", cad);
    //fflush(stdin); No esta definido para buffer de entrada
    printf("Introduzca genero ");
    setbuf(stdin, 0);
    scanf("%c", &c);

    printf("Nombre:-%s-\n", cad);
    printf("Genero:-%c-\n", c);
    return 0;
}

int main(){
  FILE *ptr;
  if(ptr = fopen("a.txt","w")) printf("No se pudo :(");
  else fprintf(ptr,"HOLA MUNDO :)");

  fclose(ptr);
return 0;
}


int main(int argc, char* argv[]){

  FILE *fileptr=NULL;
  char c;
  int a,d;
  if(argc<2){
    printf("Falta nombre de archivo a leer");
    exit(-1);
  }
  fileptr=fopen(argv[1], "r");
  if (!fileptr){
    printf("Fallo al abrir");
    exit(-1);
  }
  c=fgetc(fileptr);
  while(c=fgetc(fileptr)!=EOF){
    for ( a = 1 ; a <= 32767 ; a++ )
       for ( d = 1 ; d <= 32767 ; d++)
        printf("%c", c);

  }
  fclose(fileptr);
  return 0;
}
*/


int main12(int argc, char* argv[]){

  FILE *fileptr=NULL;
  char c, cad[25];
  int a,d;
  if(argc<2){
    printf("Falta nombre de archivo a leer");
    exit(-1);
  }
  fileptr=fopen(argv[1], "r");
  if (!fileptr){
    printf("Fallo al abrir");
    exit(-1);
  }
  fscanf(fileptr, "%s", cad);
  while(!feof(fileptr)){
    printf("\n%s",cad);
    fscanf(fileptr, "%s", cad);
    for(a=0; a<10000; a++) for(d=0; d<10000; d++){}
  }
  fclose(fileptr);
  return 0;
}




