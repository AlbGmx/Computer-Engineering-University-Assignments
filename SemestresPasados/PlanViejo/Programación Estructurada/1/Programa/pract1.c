#include <stdio.h>
//Declaracion de funciones
int setup();
int play(int numPC);

//Programa principal
int main(){
  int numPC;
  do{
	system("cls"); //Limpiar pantalla al inicio de un nuevo juego
	numPC=setup();
    printf("%d\n",numPC); //Para probar, muestra el numero almacenado por la pc
 }while(play(numPC)!=2);
return 0;
}

//Definicion de funciones
int setup(){
  return (rand()%1000 + 1);
}

int play(){
  int numUser, counter=0, status=0;
  char tecla;  
  printf("Puedes adivinar mi numero?\n");
  do{ 
	  
  }while (status==0 && tecla=!27)
  
  	
  return status;
}