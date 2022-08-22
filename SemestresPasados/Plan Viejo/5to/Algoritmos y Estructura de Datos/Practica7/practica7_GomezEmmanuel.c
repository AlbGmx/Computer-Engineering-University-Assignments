/*
    Algoritmos y Estructura de Datos
    Práctica 7. Estructuras LIFO Estaticas
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 16 de noviembre a las 14:00

    Implemente un programa basado en el principio LIFO
    y funciones que lea un numero entero en base 10 y 
    lo convierta a una cadena que contenga su equivalente 
    binario
*/

#include <stdio.h> 
#include <stdlib.h> 

#define CAPACITY 32 //Numero maximo de bits a guardar 

//se define a la estructura stack como un tipo de dato stack_t
typedef struct stack {  
	int top; 
	unsigned int capacity; 
	int* array; 
}  stack_t; 

stack_t* createStack(unsigned int);
int isFull(stack_t*);
int isEmpty(stack_t*);
void push(stack_t*, int);
int pop(stack_t*);
int peek(stack_t*);
stack_t int2bin(int, char[]);

void main(){
    char binary[CAPACITY] = " ";
    int integer;
    printf("Introduzca el numero que desea convertir: ");
    scanf("%d",&integer);
    fflush(stdin);
    int2bin(integer, binary); 
    printf("\n\t%d en binario es: %s", integer, binary);
    printf("\n\nPresione cualquier tecla para salir...\n");
    getchar();
}

stack_t* createStack(unsigned int capacity){                    
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));         //Se asigna el bloque de memoria requerido para la pila
    stack->capacity = capacity;
    stack->top = -1;                                            //Se asigna -1 como posicion actual en la pila    
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); //Se asigna el bloque de memoria requerido para los valores de la pila
}

int isFull(stack_t* stack){
    return stack->top == stack->capacity-1; 
}

int isEmpty(stack_t* stack){
    return stack->top == -1;    
}

void push(stack_t* stack, int item){
    if(isFull(stack)) return;           //Si la pila esta llena, termina la función
    stack->array[++stack->top] = item;  //Si no esta llena incrementa el valor de top y agrega el item (en ese orden)
}

int pop(stack_t* stack){
    if(isEmpty(stack)) return INT_MIN;  //Si la pila esta vacia regresa el valor minimo permitido para indicar error
    return stack->array[stack->top--];  //Si no esta vacia regresa el valor actual y decrementa la posicion (en ese orden) 
}

int peek(stack_t* stack){
    if(isEmpty(stack)) return INT_MIN;  //Si la pila esta vacia regresa el valor minimo permitido para indicar error
    return stack->array[stack->top];    //Si la pila no esta vacia solamente regresa el valor, sin decrementar la posicion
}

stack_t int2bin(int integer, char binary[CAPACITY]){
    stack_t* stack = createStack(CAPACITY); //Crear un apuntador a tipo de dato stack_t
    int aux=0, i;
    while(integer){                         //Mientras el entero sea diferente de 0
        if(integer%2) push(stack, 1);       //Si el residuo es 1, empuja 1 a la pila
        else push(stack, 0);                //Si el residuo no es 1, empuja 0
        integer /= 2;                       //Divide el entero entre 2
        aux++;                              //Incrementa la el auxiliar
    }
    //Desde 0 hasta auxiliar, guarda el valor de la pila + 48 en la posicion i del string
    //48 y 49 son los valores 0 y 1 en char, respectivamente
    if(aux == 0) {
        binary[0] = 0;
        binary[1] = '\0';
    }else{
        for(i = 0; i<aux; i++) binary[i] = 48 + pop(stack);
        binary[i] = '\0';   //agrega el valor de terminacion de cadena al final del string
    }
}
