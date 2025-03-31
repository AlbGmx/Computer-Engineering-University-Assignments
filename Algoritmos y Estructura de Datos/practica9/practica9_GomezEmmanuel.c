/*
    Algoritmos y Estructura de Datos
    Práctica 8. Estructuras Estaticas FIFO y LIFO
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 23 de noviembre a las 14:00




*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

//Se define la estructura lista
struct node{
    char name[SIZE];
    struct node* next;
};

struct node* createNode(char[SIZE]);
struct node* insertNode(struct node*, char[SIZE]);
struct node* deleteNode(struct node*, char[SIZE]);
struct node* draw(struct node* , int);
void showNodes (struct node *);

int main(){
    char name[SIZE];
    char company[50] = "Telcel No Es";
    struct node* start;
    char opc = '1';

    printf("\nBienvenido al sistema de sorteos de la compa%c%ca '%s'", 164, 161, company);
    printf("\nPara empezar, introduzca el nombre del primer usuario: ");
    scanf("%s", name);
    fflush(stdin);
    start = createNode(name);
    while (opc != '0'){
        fflush(stdin);
        system("cls");
        printf("\nBienvenido al sistema de sorteos de la compa%c%ca '%s'", 164, 161, company);
        printf("\n%cQu%c operaci%cn desea realizar?", 168, 130, 162);    
        printf("\n1) Agregar usuario\t2) Empezar sorteo\t0) Salir");
        printf("\nSeleccione una opcion: ");
        scanf("%c", &opc);
        fflush(stdin);

        switch (opc){
        case '0':

            break;
        case '1':
            printf("\nIntroduzca el nombre del usuario: ");
            scanf("%s", name);
            fflush(stdin);
            start = insertNode(start, name);
            printf("\nListo.\nPresione cualquier tecla para continuar...");
            getchar();
            break;
        case '2':
            showNodes(start);
            printf("\nListo\nPresione cualquier tecla para continuar...");
            getchar();
            break;
        default:
            printf("Seleccione una opcion valida...");
            getchar();
            break;
        }
    };
    


    return 0;
}

struct node* createNode(char name[SIZE]){
    struct node *p;
    p = (struct node*) malloc(sizeof(struct node));
    strcpy(p->name, name);
    p->next = NULL;
    return p;
}

struct node* insertNode(struct node *start, char name[SIZE]){
    struct node *p, *new, *q;
    new = createNode(name);   
    p = start;
    while (p!= NULL){
        q = p;
        p = p->next;
    }
    q->next = new;
    return start;
}

void showNodes(struct node* start){
    struct node* aux;
    system("cls");
    if (!start) printf("Vacio");
    else{ 
        aux=start;
        do{ 
            printf("\n%s", aux->name);
            aux=aux->next;
        }while(aux);
    }
}

struct node* borrar(struct node* start, char name[]){
	struct node *p,*q=NULL;
	p=start;
	while(p!=NULL && stricmp(name,p->name)!=0){
		q=p;
		p=p->next;
	}
	if(q==NULL){
		start = p->next;
		free(p);
	}else if (p!=NULL){
        q->next=p->next;
        free(p);
    }
	else printf("\nNo ha sido encontrado");
	return start;
}

struct node* draw(struct node* start, int k){
    

}
