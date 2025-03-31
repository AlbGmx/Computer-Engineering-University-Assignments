/*
    Algoritmos y Estructura de Datos
    Práctica 8. Estructuras Estaticas FIFO y LIFO
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 23 de noviembre a las 14:00

    Implementar el truco de cartas infantil que 
    consiste en adivinar la carta que el jugador 
    seleccione de un conjunto de 21 cartas diferentes.

  1 El algoritmo consiste en presentar las 21 cartas
    pedirle al usuario que seleccione y memorice una
  2 Se distrubuyen las cartas en 3 renglones y se pide
    al usuario que indique en cual se encuentra su carta
    se juntan las cartas, cuidando que el renglon en 
    donde se encuentra la carta del usuario quede entre
    los otros dos
  3 se distrubuyen y se repite el paso 2 veces mas
    La carta del usuario queda justo en el centro de la lista
  4 Se presenta la carta al usuario
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DELAY 32767 //Agrega delays de aprox 1 segundo
#define SIZE 21

//Se define la estructura queue
typedef struct{
    int front;
    int rear;
    char cards[21][3]; //Se define una matriz de 21 elementos de 3 chars cada uno
} queue_t;

void createQ(queue_t*);             //Se crea e inicializa la estructura queue                           
int isFull(queue_t*);               //Revisa si queue se encuentra llena
int isEmpty(queue_t*);              //Revisa si queue se encuentra vacia
void enqueue(queue_t*, char*);      //Añade un elemento hasta atras de la cola solo si esta no se encuentra llena
const char* dequeue(queue_t*);      //Elimina un elemento desde el frente de la cola si esta no se encuentra vacia y lo devuelve
const char* front(queue_t*);        //Devuelve el elemento desde el frente de la cola sin modificarla
const char* rear(queue_t*);         //Devuelve el elemento desde atras de la cola sin modificarla
void createDeck(char[21][3]);       //Crea el deck de cartas a utilizar
void delay(char*);                  //Ciclo grande que agrega un retraso
void shuffle(void *, int, size_t);  //Ordena aleatoriamente el array solicitado (en este caso, el deck de cartas)
int randCompare(const void *, const void *);    //Comparacion aleatoria 
void showFullDeck(char[][3], int, int);     //Muestra el deck en pantalla
void deQueueDeck(char [][3], queue_t*);     //Agrega toda la cola al deck  
void enQueueDeck(char [][3], queue_t*, int);    //Agrega todo el deck a la cola, dejando el renglon seleccionado en medio de los demas 

int main(){ 
    int i = 3, select;
    queue_t q;
    char deck[21][3];
    srand(time(0));
    system("cls");
    createDeck(deck);
    createQ(&q);
    showFullDeck(deck, 3, 7);
    printf("\nPresione cualquier tecla para continuar...");
    getchar();
    fflush(stdin);
    shuffle(deck, 21, sizeof(deck[0])); //Ordena aleatoriamente el deck
    while (i--){
        delay("Revolviendo");
        system("cls");
        showFullDeck(deck, 3, 7);
        printf("Seleccione el rengl%cn donde se encuentre su carta...(0-2): ", 162);
        scanf("%d", &select);
        fflush(stdin);
        if(select>2 || select<0){
            printf("Seleccione un rengl%cn v%clido...\n\n", 162, 160);
            i++;
        }
        else if (i){
            enQueueDeck(deck, &q, select);  //Uso de cola para ordenar el deck
            deQueueDeck(deck, &q);          //Dejando el renglón seleccionado en medio
        }
    }  
    delay("Pensando");
    delay("Su carta es");
    printf("\n\t __________%s__________", deck[10]);
    printf("\nPresione cualquier tecla para salir...");
    getchar();
}
//DISCLAIMER
//Los delays son utilizados con el único propósito darle la sensacion al 
//usuario que el programa esta "PENSANDO", el uso de esta funcion no es 
//obligatoria, sin embargo, ayudan a generar interés en el usuario.
void delay(char *text){
    printf("\n%s", text);
    for (size_t k = 0; k < 3; k++){
        for (size_t i = 0; i < DELAY; i++)
            for (size_t j = 0; j < DELAY/4; j++);
        printf(".");
    }
}
void createDeck(char deck[21][3]){
    for (size_t i = 0; i < 21; i++) {
        if(!(i%7)) deck[i][0] = 0 +'A';
        else deck[i][0] = (i % 7) + '1';                //Se crea una deck con las cartas A->7
        if(i<7) deck[i][1] = '\x3';                     //A las primeras 7 cartas se les asigna char 3 == ♥
        else if (i >= 7 && i < 14) deck[i][1] = '\x4';  //De la carta 7 hasta la 13 se le asigna char 4 == ♦
        else if (i >= 14 && i < 21) deck[i][1] = '\x6'; //Las ultimas 7 cartas son asignadas char 6 == ♠ 
        deck[i][2] = '\0';                              //Se agrega el caracter de terminación
    }
}
void createQ(queue_t *q){
    q->front = -1;
    q->rear = -1;
}
int isFull(queue_t *q){
    return (((q->rear + 1) % SIZE) == q->front) ? 1 : 0;    
}
int isEmpty(queue_t *q){
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}
void enqueue(queue_t *q, char card[]){
    if (isFull(q)) return;
    else if (isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }else  q->rear = (q->rear + 1) % SIZE;
    q->cards[q->rear][0] = card[0];
    q->cards[q->rear][1] = card[1];
    q->cards[q->rear][2] = '\0';
}
//Se ha implementado la cola, con la implementación de un array "circular" por lo que
//en vez de recorrer la cola hacia atras cada que se elimina un elemento de la cola
//ese lugar simplemente queda a disponibilidad de que se vuelva a ocupar
const char* dequeue(queue_t *q){
    const char *aux = "  ";
    if(isEmpty(q)) return NULL;
    if (q->front == q->rear){       //si front y rear sin iguales, quiere decir que solo existe un elemento
        aux = q->cards[q->front];   //por lo tanto, despues de eliminarlo la cola quedara vacia  
        q->front = -1;              //Front y rear son establecidos a -1 para indicar que quedo vacia
        q->rear = -1;
    }
    else {
        aux = q->cards[q->front];           //Si existe mas de un elemento simplemente se recorre front
        q->front = (q->front + 1) % SIZE;   //se utiliza modulo de SIZE para la implentacion del array circular
    }
    return aux;
}
const char* front(queue_t *q){
    if(isEmpty(q)) return NULL;
    return q->cards[q->front];
}
const char* rear(queue_t *q){
    if(isEmpty(q)) return NULL;
    return q->cards[q->rear];
}
int randCompare(const void *a, const void *b){
    (void)a; (void)b;
    return rand() % 2 ? +1 : -1;
}
void shuffle(void *array, int members, size_t sizeOf){
    qsort(array, members, sizeOf, randCompare);
}
void showFullDeck(char deck[21][3], int rows, int cols){
    printf("\nElija una carta y memor%ccela\n\n", 161);
    for (size_t i = 0; i < rows; i++){
        printf("Rengl%cn %d\t", 162, i);
        for (size_t j = 0; j < cols; j++){
            printf("%c%s%c ", 179, deck[j+i*7], 186);
        }
    printf("\n\n");
    }
}
void enQueueDeck(char deck[21][3], queue_t *q, int select){
    int first = (select-1<0) ? 1:select-1; 
    int last = (select+1>2) ? 0:select+1;
    for (size_t j  = 0; j < 7; j++) enqueue(q,deck[first*7+j]); 
    for (size_t j  = 0; j < 7; j++) enqueue(q,deck[select*7+j]);
    for (size_t j  = 0; j < 7; j++) enqueue(q,deck[last*7+j]);
}
void deQueueDeck(char deck[21][3], queue_t *q){
    const char *temp;
    for (size_t i  = 0; i < 7; i++) 
        for (size_t j = 0; j < 3; j++){
            temp = dequeue(q);
            for (size_t k = 0; k < 3; k++)  
                deck[j*7+i][k] = temp[k];
        }
}
