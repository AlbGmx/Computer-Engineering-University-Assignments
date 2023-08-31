/*  Gómez Cárdenas Emmanuel Alberto Grupo 531
Adivina mi numero
Este programa genera un numero aleatorio entre 1 y 1000, el usuario intentará adivinarlo, con lo que, cada intento será tomado en cuenta.
Si adivina en menos de 10 intentos se muestra un mensaje felicitandolo.
Si adivina en exactamente 10 intentos se le dirá un mensaje relacionado al numero de intentos secreto.
En caso de hacer mas de 10 intentos, se le dirá que lo puede hacer mejor.
El programa se repetirá hasta que el usuario ontroduzca el mismo numero que estpa almacenado.
Al introducir el mismo numero, el usuario tendrá que elegir si quiere volver a jugar o no.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaracion de funciones
int setup(); //genera un numero aleatorio entre 1 y 1000
int play(int numPC); //Empieza el juego
int compare(int a, int b); //Compara el numero introducido por el usuario y el almacenado por la pc
void endMessage(int counter); //Mensaje de final de partida
void randomize(); //Genera una semilla usando el tiempo actual para evitar que la funcion rand() repita los mismos numeros 

//Programa
int main(){
  int numPC;
  randomize();
  do{
	system("cls"); //Limpiar pantalla al inicio de un nuevo juego
	numPC=setup();
//    printf("%d\n",numPC); //Para testear, muestra el numero almacenado por la computadora
 }while(play(numPC)!=2);
system("cls");	
return 0;
}


//Definicion de funciones
void randomize(){
  srand(time(NULL));
}

int setup(){
  return (rand()%1000 + 1);
}

int play(int numPC){                //counter lleva la cuenta de los intentos efectuados
  int numUser, counter=0, status=0; //status 1 = jugar de nuevo; 2 = salir; 0 = juego en proceso
  char tecla;
  printf("Tengo un numero entre 1 y 1000\n");
  printf("Puedes adivinar mi numero?\n");
  do{
	scanf(" %d", &numUser);
	while(getchar()!='\n'); //limpia el buffer del teclado (referencia: forosdelweb.com/f96/error-extrano-programa-salta-scanf-999074/)
	switch(compare(numPC,numUser)){
	  case -1: printf("Por favor introduzca un numero valido (desde 1 hasta 1000)\n"); break;
      case  0: endMessage(counter);  
	           printf("Excelente! has adivinado el numero!\n");
			   printf("Quieres jugar una vez mas? (y/n)\n");
			   scanf(" %c",&tecla);
			   system("cls");
			   if (tecla=='y')  status=1; else status=2;
			   break;
	  case  1: printf("Muy bajo. Intentalo nuevamente.\n"); counter++; break;
	  case  2: printf("Muy alto. Intentalo nuevamente.\n"); counter++; break;
	 }
  }while(status==0 && tecla!=27);
   		  
  return status;

}

int compare(int numPC, int numUser){ //si el numero introducido es mayor de 1000 se cuenta como invalido
  if (numUser>1000) return -1;   //al introducir una tecla en scanf("%d") se guarda como un numero mayor de 1000
  else if (numPC<numUser) return 2;    //el numero del usuario es mas grande que el de la computadora 
  else if (numPC>numUser) return 1;    //el numero del usuario es mas pequeño que el de la computadora
  else if (numPC==numUser) return 0;   //el numero del usuaario y el de la computadora son iguales
  
}

void endMessage(int counter){ //
  if (counter<10) printf("Felicidades!! has adivinado en pocos intentos.\n");
  else if (counter==10) printf("Haaa!! ya conoces el secreto \n.");
  else if (counter>10) printf("Lo puedes hacer mejor.\n");
}
/*
Conclusiones y comentarios
esta practica me sirvió para mejorar en el usos de los inputs y outputs scanf y print f





*/
