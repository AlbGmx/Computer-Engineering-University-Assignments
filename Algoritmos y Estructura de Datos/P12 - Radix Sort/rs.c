/*
    Algoritmos y Estructura de values
    Algoritmo RadixSort
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define SIZE 10
struct node
{
    struct node *next; //Direccion de la siguiente pila
    int value;
};
//Definicion de Funciones
struct node *createNode(int);
struct node *queue(struct node *, int);
struct node *dequeue(struct node *, int *);
int isEmpty(struct node *);
int mov2List(int[], struct node **, int);
//void mov2List(struct node **, struct node **);
int getMax(int[], int);
void radixSort(int[], int, int);
void sortByDigit(int[], int, int);
//Declaracion de funciones
void main()
{
    unsigned int list[] = {123, 456, 789, 12, 345, 678, 901, 234, 567, 9};
    //int list[] = {2, 22, 222, 2, 22, 222, 22, 2, 2, 2};
    int max = getMax(list, SIZE);
    int digits = (int)(log10(list[max]) + 1);
    radixSort(list, digits, SIZE);
}
int getMax(int list[], int size)
{
    int i, max = 0;
    for (i = 0; i < size; i++)
        if (list[i] > list[max])
            max = i;
    return max;
}
struct node *createNode(int value)
{
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node)); //Reserva el espacio dinámicamente
    node->value = value;
    node->next = NULL; //No hay nodo siguiente
    return node;       //Regresa el nodo creado
}
struct node *queue(struct node *start, int value)
{
    struct node *p, *aux, *q;
    aux = createNode(value);
    p = start;
    while (p != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = aux;
    return start;
}
struct node *dequeue(struct node *start, int *value)
{
    *value = start->value;
    start = start->next;
    return start;
}
int isEmpty(struct node *top) { return (top == NULL) ? 1 : 0; }
void movNode(struct node **destiny, struct node **source)
{
    int value=0;
    *source = dequeue(*source, &value); //Obtiene el valor de la fuente
    if(isEmpty(*destiny)) {
        createNode(value);
    }
    else{
        queue(*destiny, value);
    }
}
int mov2List(int list[], struct node**bucket, int i ){
    while (!(isEmpty(*bucket)))
    {  
        *bucket = dequeue(*bucket, &list[i]);
        i++;
    }
    return i;
}
void radixSort(int list[SIZE], int digits, int size)
{
    printf("\n----------Lista Original de tama%co %d----------", 164, size);
    printf("\n-----con el valor mayor teniendo %d digitos-----", digits);
    for (size_t j = 0; j < size; j++)
        printf("\n\t\tLista [%d] = %*d", j, digits, list[j]);
    printf("\n\nSe agregan los 0's para hacer mas sencilla la demostracion");
    for (size_t i = 1; i < digits + 1; i++){
        sortByDigit(list, i, size);
        printf("\n\n---------------iteracion numero %d---------------", i);
        for (size_t j = 0; j < size; j++)
            printf("\n\t\tLista [%d] = %.*d", j, digits, list[j]);
    }
    printf("\n\n-----------------Lista ordenada-----------------");
    printf("\n---------------Eliminando los 0's---------------");
    for (size_t j = 0; j < size; j++)
        printf("\n\t\tLista [%d] = %*d", j, digits, list[j]);
}
void sortByDigit(int list[SIZE],int actualDigit, int size){
    int j, k, aux;
    struct node *zero = NULL, *one = NULL, *two = NULL, *three = NULL, *four = NULL;
    struct node *five = NULL, *six = NULL, *seven = NULL, *eight = NULL, *nine = NULL;
    for (j = 0; j < size; j++)
    {
        k = 1;
        if(actualDigit==1) aux = list[j] % 10;
        else aux = list[j];
        while(k<actualDigit) {
            aux /= 10;
            k++;
        }
        aux %=10;
        switch (aux){
        case 0: zero  = (isEmpty(zero))  ? createNode(list[j]) : queue(zero,  list[j]); break; 
        case 1: one   = (isEmpty(one))   ? createNode(list[j]) : queue(one,   list[j]); break;
        case 2: two   = (isEmpty(two))   ? createNode(list[j]) : queue(two,   list[j]); break;
        case 3: three = (isEmpty(three)) ? createNode(list[j]) : queue(three, list[j]); break;
        case 4: four  = (isEmpty(four))  ? createNode(list[j]) : queue(four,  list[j]); break;
        case 5: five  = (isEmpty(five))  ? createNode(list[j]) : queue(five,  list[j]); break;
        case 6: six   = (isEmpty(six))   ? createNode(list[j]) : queue(six,   list[j]); break;
        case 7: seven = (isEmpty(seven)) ? createNode(list[j]) : queue(seven, list[j]); break;
        case 8: eight = (isEmpty(eight)) ? createNode(list[j]) : queue(eight, list[j]); break;
        case 9: nine  = (isEmpty(nine))  ? createNode(list[j]) : queue(nine,  list[j]); break;
        }
    }
    k = 0;
    k = mov2List(list, &zero,  k);
    k = mov2List(list, &one,   k);
    k = mov2List(list, &two,   k);
    k = mov2List(list, &three, k);
    k = mov2List(list, &four,  k);
    k = mov2List(list, &five,  k);
    k = mov2List(list, &six,   k);
    k = mov2List(list, &seven, k);
    k = mov2List(list, &eight, k);
    k = mov2List(list, &nine,  k);
}