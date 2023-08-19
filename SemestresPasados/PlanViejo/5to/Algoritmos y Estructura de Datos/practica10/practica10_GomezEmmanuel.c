/*
    Algoritmos y Estructura de Datos
    Práctica 10. Pilas Dinamicas
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 7 de diciembre a las 13:00

    Se tienen 2 pilas, la primera ordenada ascendentemente y la 2da ordenada descendentemente
    Elaborar un programa que fusione ambas pilas en una tercera ordenada descendientemente por titulo. 
    NOTA: no debe utilizar más de 3 pilas, pero si puede utilizar como base las funciones 
    y métodos de pila vistos en clase.
    -> El programa debe mostrar el estado de la pila durante el proceso de fusion.
    -> La fusion debe hacerse respetando el principio LIFO.
    -> El programa solo debe tener una funcion pop y una push.
    -> El programa debe mostrar el proceso de fusion paso a paso.
    -> Las pilas deben fusionarde despues de haberse capturado
    -> Lenguaje de programacion a eleccion (Solo C o JAVA).
    -> El programa debe ir organizado en funciones o metodos.
    -> No se pide que se implemente metodos de ordenacion, se asume que los elementos son insertados en orden.
    -> El programa debe repetirse N veces, MUD (mientras el usuario lo desea).	
    -> El programa debe mostrar mensajes apropiados.
    -> El programa debe incluir una descripcion completa, comentarios y espacios
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50 //Tamaño maximo del valor guardado en el atributo title de la pila

//Definicion del tipo node_t
typedef struct node_t{
    struct node_t* before;  //Direccion de pila anterior 
    char title[SIZE];        //Valor de pila
}node_t;

//Declaracion de funciones
int menu(node_t* stacks[3]);                    //Menu de presentacion de opciones
node_t* createNode(char*);                    //Crea un nodo reservando memoria necesaria dinamicamente
node_t* push(struct node_t* stacks, char*);     //Agrega un nodo
node_t* pop(node_t*, char[SIZE]);               //Elimina el ultimo nodo (Principio LIFO)
void freeStack(node_t**);                        //Elimina todos los elementos del nodo
char* peek(node_t*);                            //Obten el primer elemento (Principio LIFO) sin modificar la pila
void printStack(node_t*, char*);                //Imprime toda la pila
int compareWords(char*, char*);                 //Compara 2 palabras alfabeticamente sin importar mayusculas 
                                                //(devuelve 1 si el primer parametro es mas grande, 0 en cualquier otro caso)
void movNode(node_t**, node_t**, char[SIZE]);  //Mueve el nodo fuente al nodo destino
int sortNodes(node_t* stacks[3]);               //Funcion que ordena las pilas 0 y 1 dentro de la pila 2
                                                //Devuelve -1 si las pilas 0 y 1 estan vacias

//Definicion de funciones
void main(){
    int optn=1;
    node_t* stack1 = NULL;  //Pila 1
    node_t* stack2 = NULL;  //Pila 2
    node_t* stack3 = NULL;  //Pila en la cual se fusionan las pila 1 y 2 alfabeticamente
    node_t* stacks[3] = {stack1, stack2, stack3};   //Array de pilas para hacer mas sencillo el manejo de estas
    while (optn != 0) optn = menu(stacks);      //Menu opciones, se sale de este cuando el usuario lo desea
} 

int menu(node_t* stacks[3]){
    int aux = 0, counter = 0, flag=0, optn=0;
    char title[SIZE];
    printf("\n1) Inicializar Pilas\n2) Mostrar pilas 1 y 2\n3) Fusionar pilas 1 y 2\n4) Mostrar pila 3\n0) Salir");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &optn);
    fflush(stdin);
    switch (optn){
        case 1:
            freeStack(&stacks[0]);    //Elimina los nodos de la pila 1 y 2                 
            freeStack(&stacks[1]);    
            printf("\nRecordatorio en la pila 1 los valores son almacenados ascendentementes \n(Empezando por la Z hasta la A)");
            printf("\nMientras que en la pila 2 los valores son almacenados descendentementes \n(Empezando por la A hasta la Z)\n");
            while(aux<2){   //Mientras auxiliar (el numero de pila) sea menor a 2
                printf("\nLlenando pila %d:\nPresione enter sin capturar datos para salir\n", 1 + aux);
                while(!flag){           //Sigue capturando mientras la bandera este apagada
                    printf("Elemento %d: ", counter++);
                    fflush(stdin);
                    gets(title);
                    if(title[0]) stacks[aux]=push(stacks[aux],title); //Si el primer elemento es diferente de '\0' guardalo
                    else flag = 1;                                  //En cualquier otro caso activa la bandera
                }   
                if(counter==1){                                     //Si la bandera ha sido activada pero no se ha guardado
                    printf("\nDebe introducir al menos un elemento...\n");  //ninngun elemnto, regresa hasta capturar al menos
                } 
                else aux++;     //En cualquer otro caso, incrementa auxiliar para llenar la sig pila
                flag = 0;       //Reinicia la bandera y el contador
                counter = 0;
            }
            break;
        case 2:
            printStack(stacks[0], "Pila 1:");   //Imprime las pilas 1 y 2
            printStack(stacks[1], "Pila 2:");
            break;
        case 3:
            freeStack(&stacks[2]);    //Elimina los nodos de la pila 2                    
            if(sortNodes(stacks)==-1) printStack(stacks[2], "Pila Ordenada:");  //Si se puede ordenar, imprime la pila ordenada
            break;      
        case 4:
            printStack(stacks[2], "Pila 3:");   //Imprime la pila 3
            break;
        case 0:
            for (size_t i = 0; i < 3; i++) freeStack(&stacks[i]);    //Libera las pilas 
            return 0;                                               //Indica a la funcion main que el usuario desea salir
    }
    return optn;
}

node_t* createNode(char* title){
    node_t* node;
    node = (node_t*) malloc(sizeof (node_t));   //Reserva el espacio dinamicamente
    strcpy(node -> title, title);                 //Escribe el nombre en la pila
    node -> before = NULL;           
    return node;
}

node_t* push(struct node_t* stacks, char* title){
    node_t *aux;
    if(stacks == NULL) return createNode(title); //Si la pila esta vacia, crea un nodo y regresalo
    aux = createNode(title);                     //En cualquier otro caso, agrega el nodo creado a la pila
    aux -> before = stacks;
    stacks = aux;
    return stacks;
}

node_t* pop(node_t* stack, char title[SIZE]){
    strcpy(title, stack->title);                  //Mueve el valor title de la pila al parametro
    stack = stack -> before;                    //Elimina el nodo anterior
    return stack;
}

void freeStack(node_t** stack){
    char aux[SIZE];
    //Mientras la pila sea diferente de NULL (aun hay elementos) sigue eliminando
    while(*stack != NULL) *stack = pop(*stack, aux);    
}

char* peek(node_t* stacks){ return stacks -> title; } //Regresa el ultimo nombre ingresado a la pila (principio LIFO)

void printStack(node_t* stacks, char *message){
    node_t* aux = stacks;
    char auxName[SIZE];
    printf("\n%s\n", message);      //Imprime el mensaje enviado por parametro
    if(!aux) printf("Esta pila no tiene contenidos...\n");    //Indica si la pila esta vacia
    while(aux != NULL){             //Mientras la pila no esta vacia
        aux = pop(aux,auxName);     //Obtiene el valor actual de la pila
        printf("\t\'%s\'\n", auxName);  //Lo imprime
    }
}

int compareWords(char wordA[SIZE], char wordB[SIZE]){
    int i=0;
    char auxA = '\0',  auxB = '\0';
    while(wordA[i] & wordB[i]){                                   //Convierte las mayusculas a minusculas para que no importe si son diferentes
        if (wordA[i]>='A' & wordA[i]<='Z') auxA = wordA[i] + ' '; //Si el caracter actual de A se encuentra entre A -> Z convierte a minusculas
        else auxA = wordA[i];
        if (wordB[i]>='A' & wordB[i]<='Z') auxB = wordB[i] + ' '; //Si el caracter actual de B se encuentra entre A -> Z convierte a minusculas
        else auxB = wordB[i];      
        if ( !(auxA == auxB)) return (auxA > auxB) ? 1 : 0;
        i++;
    }
    return (wordA[i]) ? 1 : 0; //Si la palabra wordA sigue teniendo caracteres y wordB no, entonces regresa 1
}

void movNode(node_t** source, node_t** destiny, char* title){
    *source = pop(*source, title);       //Obtiene el valor de la fuente 
    *destiny = push(*destiny, title);    // y lo agrega al destino
}

void printStacks(node_t* stacks[3]){
        printStack(stacks[0], "Pila 1:"); //Imprime los 3 stacks 
        printStack(stacks[1], "Pila 2:");
        printStack(stacks[2], "Pila 3:");
}

int sortNodes(node_t* stacks[3]){
    char title[SIZE];
    int i=0;
    if (!(stacks[0])) {     //Si la pila 1 esta vacia no se puede ordenar 
        printf("\nError: Primero debe llenar las pilas 1 y 2");
        return -1;
    }

    while (stacks[0]!=NULL){ //Se mueve la pila 1 a la pila 3 respetando el principio LIFO
        printf("\n\nNodo de pila 1 \"%s\" copiado a pila 3\n", peek(stacks[0]));    //Imprime en pantalla el valor a mover 
        movNode(&stacks[0], &stacks[2], title);              //Mueve el valor de la pila 1 hacia la pila 3
        printStacks(stacks);
    }
    //Ahora que la pila 2 y 3 estan ambas ordenadas descendentemente, proecede a ordenarlas dentro de la pila 1
    while(stacks[2] != NULL && stacks[1] != NULL){  //Mientras la pila 1 y 2 tengan elementos
        printf("\n");
        if ( compareWords(peek(stacks[2]), peek(stacks[1])) ){  //Si el valor de la pila 1 es mas grande que el de la pila 2
            printf("\nNodo de pila 1 \"%s\" copiado a pila 3", peek(stacks[2]));    //Imprime en pantalla el valor a mover 
            movNode(&stacks[2], &stacks[0], title);              //Mueve el valor de la pila 1 hacia la pila 3
        }
        else {                                                  //En cualquier otro caso
            printf("\nNodo de pila 2 \"%s\" copiado a pila 3", peek(stacks[1]));    //Imprime en pantalla el valor a mover  
            movNode(&stacks[1], &stacks[0], title);              //Mueve el valor de la pila 2 hacia la pila 3 
        }
        printStacks(stacks);    //Imprime el estado actual de las 3 pilas
    }   
    while(stacks[2] != NULL || stacks[1] != NULL){  //Mientras haya elementos en al menos una pila (pila 1 o pila 2)
        if (stacks[2] != NULL){     //Si el elemento se encuentra en la pila 1
            printf("\nNodo de pila 1 \"%s\" copiado a pila 3", peek(stacks[2]));    //Imprime en pantalla el valor a mover 
            movNode(&stacks[2], &stacks[0], title); //Mueve el valor de la pila 1 hacia la pila 3
         }
        else{   //Si no se encuentra en la pila 1, esta en la pila 2
            printf("\nNodo de pila 2 \"%s\" copiado a pila 3", peek(stacks[1]));    //Imprime en pantalla el valor a mover 
            movNode(&stacks[1], &stacks[0], title); //Mueve el valor de la pila 2 hacia la pila 3    
        }
        printStacks(stacks);    //Imprime el estado actual de las 3 pilas
    }
        //Se mueve la pila ordenada hacia la pila 3, primero moviendola hacia la pila 2 de forma que termine almacenada ascendentemente
        //Para que al momento de imprimirla, se imprima descendentemente
    while (stacks[0]!=NULL){ //Se mueve la pila 1 a la pila 3 respetando el principio LIFO
        printf("\nNodo de pila 1 \"%s\" copiado a pila 3", peek(stacks[0]));    //Imprime en pantalla el valor a mover 
        movNode(&stacks[0], &stacks[1], title);              //Mueve el valor de la pila 1 hacia la pila 3
        printStacks(stacks);
    }
    while (stacks[1]!=NULL){ //Se mueve la pila 2 a la pila 3 respetando el principio LIFO
        printf("\nNodo de pila 2 \"%s\" copiado a pila 3", peek(stacks[1]));    //Imprime en pantalla el valor a mover 
        movNode(&stacks[1], &stacks[2], title);              //Mueve el valor de la pila 2 hacia la pila 3
        printStacks(stacks);
    }        
    return 0;
}