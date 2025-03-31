/*
    Algoritmos y Estructura de datos
    Algoritmo RadixSort
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Importante cambiar el define si se cambia el tamaño del arreglo
#define SIZE 10

struct node {
   struct node *next;  // Direccion de la siguiente pila
   int value;
};
// Definicion de Funciones
struct node *createNode(int);
struct node *queue(struct node *, int);
struct node *dequeue(struct node *, int *);
int isEmpty(struct node *);
int getMax(int[], int);
void radixSort(int[], int, int);
void sortByDigit(int[], int, int);

// Declaracion de funciones
int main() {
   unsigned int list[] = {123, 456, 789, 12, 345, 678, 901, 234, 567, 9};
   // int list[] = {2, 22, 222, 2, 22, 222, 22, 2, 2, 2};
   int max = getMax(list, SIZE);
   int digits = (int)(log10(list[max]) + 1);
   printf("\n\n-----------------Lista a ordenar-----------------");
   for (size_t j = 0; j < SIZE; j++) printf("\n\t\tLista [%d] = %*d", j, digits, list[j]);
   radixSort(list, digits, SIZE);
   printf("\n\n-----------------Lista ordenada-----------------");
   for (size_t j = 0; j < SIZE; j++) printf("\n\t\tLista [%d] = %*d", j, digits, list[j]);
   return 0;
}
// Regresa el indice del valor maximo de todo el arreglo
int getMax(int list[], int size) {
   int i, max = 0;
   for (i = 0; i < size; i++)
      if (list[i] > list[max]) max = i;
   return max;
}

struct node *createNode(int value) {
   struct node *node;
   node = (struct node *)malloc(sizeof(struct node));  // Reserva el espacio dinámicamente
   node->value = value;
   node->next = NULL;  // No hay nodo siguiente
   return node;        // Regresa el nodo creado
}
struct node *queue(struct node *start, int value) {
   struct node *p, *residue, *q;
   residue = createNode(value);
   p = start;
   while (p != NULL) {
      q = p;
      p = p->next;
   }
   q->next = residue;
   return start;
}
struct node *dequeue(struct node *start, int *value) {
   *value = start->value;
   start = start->next;
   return start;
}
int isEmpty(struct node *top) { return (top == NULL) ? 1 : 0; }

void radixSort(int list[], int digits, int size) {
   // Ordena por digitos, iniciando en 1 y terminando en el numero de digitos"
   for (size_t actualDigit = 1; actualDigit <= digits; actualDigit++) sortByDigit(list, actualDigit, size);
}
void sortByDigit(int list[], int actualDigit, int size) {
   int i, j, residue, aux;
   // Se inicializan los 10 "Buckets" en NULL o "vacio"
   struct node *zero = NULL, *one = NULL, *two = NULL, *three = NULL, *four = NULL;
   struct node *five = NULL, *six = NULL, *seven = NULL, *eight = NULL, *nine = NULL;
   // Se meten los 10 buckets a un arreglo de colas para un manejo mas sencillo
   struct node *dec[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
   // Desde 0 hasta el tamaño de la lista inicial
   // Cada valor de la lista, se agrega en el bucket
   // Que indique el digito en la posicion de actualDigit
   for (i = 0; i < size; i++) {
      j = 1;
      if (actualDigit == 1)
         residue = list[i] % 10;
      else
         residue = list[i];
      while (j < actualDigit) {
         // Se eliminan los digitos que esten demas
         residue /= 10;
         j++;
      }
      residue %= 10;  // Se obtiene el residuo
      // Si el bucket numero "residuo" del arreglo esta vacia, crea uno nuevo
      // si no, agrega el valor de lista[j] en la cola
      dec[residue] = (isEmpty(dec[residue])) ? dec[residue] = createNode(list[i]) : queue(dec[residue], list[i]);
   }
   aux = 0;  // Se reinicia el valor auxiliar, este indica el indice de la lista inicial a manipular
   for (j = 0; j < size; j++) {
      while (!(isEmpty(dec[j])))
         // Se agrega a la lista en el indice indicado por aux y aumenta aux
         dec[j] = dequeue(dec[j], &list[aux++]);
   }
}
