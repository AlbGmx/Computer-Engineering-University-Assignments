/// Pedraza Gonzalez Eros Abdael    01263161    Practica 11: Listas circulares


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 50

struct nodo {
    char autor[MAX];
    char titulo[MAX];
    int duracion;
    struct nodo * sig;
};

struct nodo * crearNodo (char autor[], char titulo[], int duracion);
void insertar(struct nodo *inicio, struct nodo **fin, char autor[], char titulo[], int duracion);
void reproducir_Lista(struct nodo *inicio);
void eliminarCancion(struct nodo **inicio, struct nodo **fin, char autor[], char titulo[]);
void Menu_capturar_Listas(struct nodo **L1_I,struct nodo **L1_F, struct nodo **L2_I,struct nodo **L2_F, struct nodo **L3_I,struct nodo **L3_F);
void menu_eliminar(struct nodo **L1_I,struct nodo **L1_F, struct nodo **L2_I,struct nodo **L2_F, struct nodo **L3_I,struct nodo **L3_F);
void menu_reproducir(struct nodo **L1_I,struct nodo **L1_F, struct nodo **L2_I,struct nodo **L2_F, struct nodo **L3_I,struct nodo **L3_F);


int main()
{
    struct nodo *L1_I = NULL, *L1_F = NULL;
    struct nodo *L2_I = NULL, *L2_F = NULL;
    struct nodo *L3_I = NULL, *L3_F = NULL;
    char respuesta;

    printf("--BIENVENIDO--\n ");
    do{
        printf("\n(1)Insertar una cancion");
        printf("\n(2)borrar una cancion");
        printf("\n(3)Reproducir Lista");
        printf("\n(4)Salir");
        printf("\n\n Elige la opcion deseada: ");
        scanf("%c", &respuesta);
        fflush(stdin);

        switch(respuesta){
            case '1': Menu_capturar_Listas(&L1_I,&L1_F, &L2_I,&L2_F, &L3_I,&L3_F);
                      break;
            case '2': menu_eliminar(&L1_I,&L1_F, &L2_I,&L2_F, &L3_I,&L3_F);
                      break;
            case '3': menu_reproducir(&L1_I,&L1_F, &L2_I,&L2_F, &L3_I,&L3_F);
                      break;
            case '4': printf("\n\n Cerrando programa.");
                      break;
        }

    }while(respuesta != '4' );

    return 0;
}

struct nodo *crearNodo (char autor[], char titulo[], int duracion)
{
    struct nodo * p;
    p = (struct nodo *) malloc (sizeof (struct nodo));
    strcpy(p->autor,autor);
    strcpy(p->titulo,titulo);
    p-> duracion = duracion;
    p-> sig = NULL;
    return (p);
}

void insertar(struct nodo *inicio, struct nodo **fin, char autor[], char titulo[], int duracion)
{
    printf("uh");
    struct nodo * nuevo;
    nuevo = crearNodo(autor, titulo, duracion);
    nuevo->sig = inicio;
    (*fin)->sig = nuevo;
    *fin = nuevo;
}

void reproducir_Lista(struct nodo * inicio)
{
    struct nodo * aux;
    int tiempo;
    if (inicio == NULL)
        printf ("\n Esta lista esta vacia");
    else
    {
        aux = inicio;
        do
        {
            printf ("\n -> REPRODUCIENDO autor: %s - \"%s\" \n", aux->autor, aux->titulo);
            tiempo = 0;
            while(tiempo <= aux->duracion)
            {
                printf("\rTiempo de reproduccion |> %d / %d ", tiempo,aux->duracion);
                Sleep(1000);
                tiempo++;
            }
            printf("\n");
            aux = aux->sig;

        } while(aux != NULL && aux != inicio);


    printf("\n < Fin de la reproduccion >\n ");
    }
}

void eliminarCancion(struct nodo **inicio, struct nodo **fin, char autor[], char titulo[])
{
    struct nodo *p;
    struct nodo *q = NULL;
    int bandera = 0;

    p = *inicio;
    while(q != *fin && bandera == 0) /// el for se repite la cantidad de k mas las posiciones que haya avanzado en la eliminacion anterior
    {
        if(strcmp(p->autor,autor) == 0 && strcmp(p->titulo,titulo) == 0)
        {
            bandera++;
        }
        else
        {
            q = p;
            p = p->sig;
        }
    }

    if(*inicio == *fin)
    {
        *inicio = NULL;
        *fin=NULL;
        printf("\n ULTIMA CANCION");
        printf ("\n|> se elimino la cancion de: autor:%s - %s (%d segundos)", p->autor,p->titulo,p->duracion);
        free(p);
    }
    else if(q == NULL && bandera==1) ///si se elimina el nodo del inicio...
    {
        (*inicio)= (*inicio)->sig;
        (*fin)->sig = *inicio;
        printf ("\n|> se elimino la cancion de: autor:%s - %s (%d segundos)", p->autor,p->titulo,p->duracion);
        free(p);
    }
    else if(bandera == 1 && p == *fin)
    {
        (*fin)= q;
        q->sig = *inicio;
        printf ("\n|> se elimino la cancion de: autor:%s - %s (%d segundos)", p->autor,p->titulo,p->duracion);
        free(p);
    }
    else if(bandera == 1)
    {
        printf ("\n|> se elimino la cancion de: autor:%s - %s (%d segundos)", p->autor,p->titulo,p->duracion);
        q->sig = p->sig;
        free(p);
    }
    else if(bandera == 0)
    {
        printf("no se encontro nara :( \n");
    }

}

void Menu_capturar_Listas(struct nodo **L1_I,struct nodo **L1_F, struct nodo **L2_I,struct nodo **L2_F, struct nodo **L3_I,struct nodo **L3_F)
{
    char autor[MAX];
    char titulo[MAX];
    int duracion;
    char respuesta;
    printf("\nselecciona la lista para AGRAGAR una cancion ");
    printf("\n(1)Lista 1");
    printf("\n(2)Lista 2");
    printf("\n(3)Lista 3");
    printf("\n(4)Cancelar");
    printf("\n Elige la opcion deseada: ");
    scanf("%c", &respuesta);
    fflush(stdin);

    switch(respuesta){
        case '1': do{
                      printf("\n\n--|Lista 1|--");
                      printf("\nIntroduzca el nombre del autor: ");
                      gets(autor);
                      printf("\nIntroduzca el titulo de la cancion: ");
                      gets(titulo);
                      printf("\nDuracion de la cancion: ");
                      scanf("%d", &duracion);
                      fflush(stdin);
                      if( !(*L1_I) )
                      {
                          *L1_I = crearNodo(autor, titulo, duracion);
                          *L1_F = *L1_I;
                          (*L1_I)->sig = *L1_F;
                          (*L1_F)->sig = *L1_I;
                          printf("cjhde");
                      }
                      else insertar(*L1_I, L1_F, autor, titulo, duracion);

                      printf("\n Capturar otra cancion de esta lista? (s/n) : ");
                      scanf("%c", &respuesta);
                      fflush(stdin);

                    }while(respuesta == 's' || respuesta == 'S');
                  break;
        case '2': do{
                      printf("\n\n--|Lista 2|--");
                      printf("\nIntroduzca el nombre del autor: ");
                      gets(autor);
                      printf("\nIntroduzca el titulo de la cancion: ");
                      gets(titulo);
                      printf("\nDuracion de la cancion: ");
                      scanf("%d", &duracion);
                      fflush(stdin);
                      if( !(*L2_I) )
                      {
                          *L2_I = crearNodo(autor, titulo, duracion);
                          *L2_F = *L2_I;
                          (*L2_I)->sig = *L2_F;
                          (*L2_F)->sig = *L2_I;
                      }
                      else insertar(*L2_I, L2_F, autor, titulo, duracion);

                      printf("\n Capturar otra cancion de esta lista? (s/n) : ");
                      scanf("%c", &respuesta);
                      fflush(stdin);

                    }while(respuesta == 's' || respuesta == 'S');
                  break;
        case '3': do{
                      printf("\n\n--|Lista 3|--");
                      printf("\nIntroduzca el nombre del autor: ");
                      gets(autor);
                      printf("\nIntroduzca el titulo de la cancion: ");
                      gets(titulo);
                      printf("\nDuracion de la cancion: ");
                      scanf("%d", &duracion);
                      fflush(stdin);
                      if( !(*L3_I) )
                      {
                          *L3_I = crearNodo(autor, titulo, duracion);
                          *L3_F = *L3_I;
                          (*L3_I)->sig = *L3_F;
                          (*L3_F)->sig = *L3_I;
                      }
                      else insertar(*L3_I, L3_F, autor, titulo, duracion);

                      printf("\n Capturar otra cancion de esta lista? (s/n) : ");
                      scanf("%c", &respuesta);
                      fflush(stdin);

                    }while(respuesta == 's' || respuesta == 'S');
                  break;
    }

}

void menu_eliminar(struct nodo **L1_I,struct nodo **L1_F, struct nodo **L2_I,struct nodo **L2_F, struct nodo **L3_I,struct nodo **L3_F)
{
    char autor[MAX];
    char titulo[MAX];
    char respuesta;
    printf("\nselecciona la lista para ELIMINAR la cancion ");
    printf("\n(1)Lista 1");
    printf("\n(2)Lista 2");
    printf("\n(3)Lista 3");
    printf("\n(4)Cancelar");
    printf("\n Elige la opcion deseada: ");
    scanf("%c", &respuesta);
    fflush(stdin);

    switch(respuesta){
        case '1': do{
                      printf("\n\n--|Lista 1|--");
                      printf("\nIntroduzca el nombre del autor: ");
                      gets(autor);
                      printf("\nIntroduzca el titulo de la cancion: ");
                      gets(titulo);
                      fflush(stdin);
                      eliminarCancion(L1_I,L1_F, autor, titulo);
                      printf("\n Eliminar otra cancion de esta lista? (s/n) : ");
                      scanf("%c", &respuesta);
                      fflush(stdin);

                    }while(respuesta == 's' || respuesta == 'S');
                  break;
        case '2': do{
                      printf("\n\n--|Lista 2|--");
                      printf("\nIntroduzca el nombre del autor: ");
                      gets(autor);
                      printf("\nIntroduzca el titulo de la cancion: ");
                      gets(titulo);
                      fflush(stdin);
                      eliminarCancion(L2_I,L2_F, autor, titulo);
                      printf("\n Eliminar otra cancion de esta lista? (s/n) : ");
                      scanf("%c", &respuesta);
                      fflush(stdin);

                    }while(respuesta == 's' || respuesta == 'S');
                  break;
        case '3': do{
                      printf("\n\n--|Lista 3|--");
                      printf("\nIntroduzca el nombre del autor: ");
                      gets(autor);
                      printf("\nIntroduzca el titulo de la cancion: ");
                      gets(titulo);
                      fflush(stdin);
                      eliminarCancion(L3_I,L3_F, autor, titulo);
                      printf("\n Eliminar otra cancion de esta lista? (s/n) : ");
                      scanf("%c", &respuesta);
                      fflush(stdin);

                    }while(respuesta == 's' || respuesta == 'S');
                  break;
    }
}

void menu_reproducir(struct nodo **L1_I,struct nodo **L1_F, struct nodo **L2_I,struct nodo **L2_F, struct nodo **L3_I,struct nodo **L3_F)
{
    char respuesta;
    printf("\nselecciona la lista que desea REPRODUCIR  ");
    printf("\n(1)Lista 1");
    printf("\n(2)Lista 2");
    printf("\n(3)Lista 3");
    printf("\n(4)Cancelar");
    printf("\n Elige la opcion deseada: ");
    scanf("%c", &respuesta);
    fflush(stdin);

    switch(respuesta){
        case '1': printf("\n\n--|Reproduciendo Lista 1|--");
                  reproducir_Lista(*L1_I);
                  break;
        case '2': printf("\n\n--|Reproduciendo Lista 2|--");
                  reproducir_Lista(*L2_I);
                  break;
        case '3': printf("\n\n--|Reproduciendo Lista 1|--");
                  reproducir_Lista(*L3_I);
                  break;
    }
}
