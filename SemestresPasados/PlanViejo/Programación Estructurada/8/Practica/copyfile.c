#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    FILE *file, *dest;
    char c;

    if(!(argc>2))
    {
        printf("Error en los parametros por consola.\nRequiere nombre de archivo a leer y nombre del archivo copia.");
        exit(-1);
    }

    file = fopen(argv[1], "r");
    if(!file)
    {
        printf("Error al abrir flujo de archivo: %s.", argv[1]);
        exit(-1);
    }
    
    dest = fopen(argv[2], "w");
    if(!dest)
    {
        printf("Error al abrir flujo de archivo: %s.", argv[2]);
        exit(-1);
    }

    c = fgetc(file);
    while(!feof(file))
    {
        printf("%c",c);
        fputc(c,dest);
        c = fgetc(file);
    }
    

    fclose(file);
    fclose(dest);

    return EXIT_SUCCESS;
}