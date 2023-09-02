#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    FILE* file;
    char buffer[20];
    char c;

    if(!(argc>1))
    {
        printf("Error en los parametros por consola.\nRequiere nombre de archivo a leer.");
        exit(-1);
    }

    file = fopen(argv[1], "r");
    if(!file)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    while(!((c=fgetc(file))==EOF))
        printf("%c",c);
    
    /*
    c = fgetc(file);
    while(!feof(file))
    {
        c = fgetc(file);
        printf("%c",c);
    }
    */

    /*
    fscanf(file, "%s", buffer);
    while(!feof(file))
    {
        printf("%s\n",buffer);
        fscanf(file, "%s", buffer);
    }
    */

    fclose(file);

    return EXIT_SUCCESS;
}