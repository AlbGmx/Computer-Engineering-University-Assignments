/*
    Algoritmos y Estructura de Datos
    Práctica 10. Pilas Dinamicas
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 14 de diciembre a las 13:00

    Programa que administra listas de reproduccion de canciones
    que permite tener 3 listas para diferentes estados de animo
    La aplicación de contar con lo siguinte:
        Agregar una cancion a una lista
        Borrar cancion (de una lista)
        Reproducir lista
        Salir 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define SIZE 50 //Tamaño maximo del valor guardado en el atributo title de la pila

//Definicion del tipo struct node
struct node{
    struct node *next;      //Direccion de la siguiente pila
    char title[SIZE];       //Título de la cancion
    char interpreter[SIZE]; //Intérprete
    int duration;           //Duración
};

//Declaracion de funciones
//Menu de presentacion de opciones
void menu();    
//Funciones para manipulació basica de nodos aplicando el concepto de listas circulares
struct node *createNode(char[], char[], int);  
void insert(struct node *, struct node **, char[], char[], int); 
void delete(struct node **, struct node **, char[], char[]);
//Funciones para seleccion de lista
int selectList2add(struct node **, struct node **, struct node **, struct node **, struct node **, struct node **);
int selectList2del(struct node **, struct node **, struct node **, struct node **, struct node **, struct node **);
int selectList2play(struct node **, struct node **, struct node **, struct node **, struct node **, struct node **);
//Funciones para añadir o eliminar un nodo y reproducir una lista
void add2List(struct node **, struct node **);
void delFromList(struct node **, struct node **);
void playList(struct node *);
//Definicion de funciones
int main(){
    printf("\n-----Bienvenido a PLAYLIST-----\n");  //Mensaje de bienvenida que solo se muestra una vez
    menu(); //Llama la funcion de menú
    printf("\n-----Que tenga un buen dia-----\n\n");  //Mensaje de despedida que solo se muestra una vez
    return 0;
}

void menu(){
    struct node *startSad   = NULL,   *endSad = NULL;         //Inicio y final de las listas 
    struct node *startHappy = NULL, *endHappy = NULL;  
    struct node *startWork  = NULL,  *endWork = NULL;    
    char optn;
    do{
        printf("\n\n   %cQu%c desea hacer?", 168, 130);
        printf("\n1) Agregar una canci%cn a una lista  \n2) Borrar canci%cn de una lista", 162, 162);
        printf("\n3) Reproducir una lista               \n4) Salir\n");
        printf("\nSeleccione una opci%cn: ", 162);
        scanf("%c", &optn);
        fflush(stdin);

        switch (optn){
            case '1':
                selectList2add(&startSad, &endSad, &startHappy, &endHappy, &startWork, &endWork);
                break;
            case '2':
                selectList2del(&startSad, &endSad, &startHappy, &endHappy, &startWork, &endWork);
                break;
            case '3':
                selectList2play(&startSad, &endSad, &startHappy, &endHappy, &startWork, &endWork);
                break;      
        }
    } while (optn != '4');  //Se repite mientras el usuario lo desea
}

struct node* createNode(char interpreter[], char title[], int duration){
    struct node* node;
    node = (struct node*) malloc(sizeof (struct node)); //Reserva el espacio dinámicamente
    strcpy(node->interpreter, interpreter);             //Guarda el intérprete de la canción
    strcpy(node->title, title);                         //Guarda el título de la canción
    node->duration = duration;                          //Guarda la duración de la canción 
    node->next = NULL;                                  //No hay nodo siguiente 
    return node;                                        //Regresa el nodo creado
}

void insert(struct node* start, struct node** end, char interpreter[], char title[],  int duration){
    struct node *new;
    new = createNode(interpreter, title, duration);     //Se crea el nodo auxiliar
    new->next = start;                                  //Se aplica el concepto de lista circular
    (*end)->next = new;                                 
    *end = new;
}

void delete (struct node **start, struct node **end, char interpreter[], char title[]){
    struct node *aux;
    struct node *aux2 = NULL;
    int flag = 0;   //Indica si se ha encontrado el nodo con el intérprete y título indicados
    aux = *start; 
    while (aux2 != *end && flag == 0){  //Mientras siga encontrando nodos y no sean los indicados
        //Compara los datos del nodo auxiliar con los datos solicitados
        if( !(strcmp(aux->interpreter,interpreter)) && !(strcmp(aux->title,title)) ) flag = 1;  //Activa bandera cuando se han encontrado
        else {  
            aux2 = aux;       
            aux = aux->next;
        }
    }
    if (flag){  //Si la bandera esta activa y...
        if (*start == *end){    //Si start y end son iguales, solo hay 1 elemento en la lista, por lo tanto se indica que la lista quedará vacía
            *start = NULL;          
            *end = NULL;
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            printf("\nLa lista ha quedado vac%ca", 161);
            free(aux);
        }
        else if(aux == *end){   //Si eliminara el nodo final
            *end = aux2;        //Se recorre el final hacia atras
            aux2->next = *start;
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            free(aux);
        }
        else if(aux2 == NULL){  //Si se eliminara el nodo inicial
            *start = (*start)->next;    //Se recorre el nodo inicial
            (*end)->next = *start;
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            free(aux);
        }
        else {  //Se elimina cualquier otro nodo 
            printf("\nSe ha eliminado la canci%cn \"%s\" del int%crprete \"%s\"", 162, title, 130, interpreter);
            aux2->next = aux->next;
            free(aux);
        }
    }
    else printf("\nNo se ha encontrado la cancion");
}

int selectList2add(struct node **startS, struct node **endS, struct node **startH, struct node **endH, struct node **startW, struct node **endW){
    char interpreter[SIZE];
    char title[SIZE];
    int duration = 0;
    char optn; 
    
    printf("\n-----Seleccione la lista a agregar-----");
    printf("\n1) Agregar una canci%cn a la lista triste", 162);
    printf("\n2) Agregar una canci%cn a la lista feliz", 162);
    printf("\n3) Agregar una canci%cn a la lista para trabajar", 162);
    printf("\n0) Salir\n");
    printf("\nSeleccione una opci%cn: ", 162);
    fflush(stdin);
    scanf("%c", &optn);
    while (optn > '3' || optn < '0'){
        printf("\nSeleccione una opci%cn v%clida: ", 162, 160);
        fflush(stdin);
        scanf("%c", &optn);
    }
    if (optn == '0') return 0;
    fflush(stdin);
    switch (optn){
    case '1': 
        add2List(startS, endS);
        break;
    case '2':
        add2List(startH, endH);
        break;
    case '3':
        add2List(startW, endW);
        break;
    }
    return 1;
}

void add2List(struct node **start, struct node **end){
    char opc, interpreter[SIZE], title[SIZE];
    int duration;
    do{
        printf("\n-----Introduce los datos de la canci%cn-----\n", 162);
        printf("\nNombre del interprete: ");
        fflush(stdin);
        scanf("%s", interpreter);
        printf("Titulo de la canci%cn: ", 162);
        fflush(stdin);
        scanf("%s",title);
        printf("Duraci%cn de la canci%cn (en enteros, ej: 3): ", 162, 162);
        scanf("%d", &duration);
        if( !*start ){ //Si la lista esta vacia, se crea un nodo, si no, solamente se inserta uno nuevo
            *start = createNode(interpreter, title, duration);
            *end = *start;
            (*start)->next = *end;
            (*end)->next = *start;
        }   else insert(*start, end, interpreter, title, duration);
        printf("\nDesea ingresar otra canci%cn a esta lista? (y/n): ", 162);
        fflush(stdin);
        scanf("%c", &opc);
    } while (opc == 'y' || opc == 'Y');
}

int selectList2del(struct node **startS, struct node **endS, struct node **startH, struct node **endH, struct node **startW, struct node **endW){
    char interpreter[SIZE];
    char title[SIZE];
    int duration = 0;
    char optn; 
    printf("\n-----Seleccione la lista de la cual borrar-----");
    printf("\n1) Borrar una canci%cn de la lista triste", 162);
    printf("\n2) Borrar una canci%cn de la lista feliz", 162);
    printf("\n3) Borrar una canci%cn de la lista para trabajar", 162);
    printf("\n0) Salir\n");
    printf("\nSeleccione una opci%cn: ", 162);
    scanf("%c", &optn);
    fflush(stdin);
    while (optn > '3' || optn < '0'){
        printf("\nSeleccione una opci%cn v%clida: ", 162, 160);
        scanf("%c", &optn);
        fflush(stdin);
    }
    if (optn == '0') return 0;
    switch (optn){
    case '1': 
        delFromList(startS, endS);
        break;
    case '2':
        delFromList(startH, endH);
        break;
    case '3':
        delFromList(startW, endW);
        break;
    }
    return 1;
}

void delFromList(struct node **start, struct node **end){
    char opc, interpreter[SIZE], title[SIZE];
    do{
        printf("\n-----Identifica la canci%cn a borrar-----\n", 162);
        printf("\nNombre del interprete: ");
        fflush(stdin);
        scanf("%s", interpreter);
        printf("T%ctulo de la canci%cn: ", 161, 162);
        fflush(stdin);
        scanf("%s", title);
        delete(start, end, interpreter, title);
        printf("\n\nDesea eliminar otra canci%cn de esta lista? (y/n): ", 162);
        fflush(stdin);
        scanf("%c", &opc);
    } while (opc == 'y' || opc == 'Y');
}

int selectList2play(struct node **startS, struct node **endS, struct node **startH, struct node **endH, struct node **startW, struct node **endW){
    char optn; 
    printf("\n-----Seleccione la lista a reproducir-----");
    printf("\n1) Reproducir la lista triste");
    printf("\n2) Reproducir la lista feliz");
    printf("\n3) Reproducir la lista para trabajar");
    printf("\n0) Salir\n");
    printf("\nSeleccione una opci%cn: ", 162);
    fflush(stdin);
    scanf("%c", &optn);
    while (optn > '3' || optn < '0'){
        printf("\nSeleccione una opci%cn valida: ", 162);
        fflush(stdin);
        scanf("%c", &optn);
    }
    if (optn == '0') return 0;
    fflush(stdin);
    switch (optn){
    case '1': 
        playList(*startS);
        break;
    case '2':
        playList(*startH);
        break;
    case '3':
        playList(*startW);
        break;
    }
    return 1;
}

void playList(struct node *start){
    char opc, interpreter[SIZE], title[SIZE];
    struct node *playing = start;
    int i, j;
    if(!start) {
        printf("A%cn no se han a%cadido canciones a esta lista", 163, 164);
    }
    else{
        do{
            printf("\n-----Iniciando Reproducci%cn-----\n",162);
            do{
                printf("\n-----Reproduciendo \"%s\" del artista \"%s\"-----\n", playing->title, playing->interpreter);
                for (i = 0; i < playing->duration; i++){
                    for (j = 0; j < 6; j++){
                        printf("\r-----Tiempo transcurrido %d:%d0 minutos de %d:00-----", i, j, playing->duration);
                        Sleep(100);
                    }
                }
                printf("\r-----Tiempo transcurrido %d:00 minutos de %d:00-----\n", i, playing->duration);
                playing = playing->next;
            } while (playing != NULL && playing != start);

            printf("\n\nDesea volver a reproducir la lista? (y/n): ");
            fflush(stdin);
            scanf("%c", &opc);
        } while (opc == 'y' || opc == 'Y');
    }
}