#include <stdlib.h>
#include <stdio.h>

int sprDgts(int num, char Dgts[15]){  //Separa los digitos y devuelve el numero de digitos que se han separado
  int i=0;
  do{
    Dgts[i]=48+num%10;
    i++;	
	num=num/10;
  }while(num!=0);
  Dgts[i]='\0';
  return i;
}
void rev(int num, char revnum[15]){  //Invierte el sentido de los numeros
  int i=0;
  do{
    revnum[i]=48+num%10;
    i++;	
	num=num/10;
  }while(num!=0);
  revnum[i]='\0';
}
int sum(int num){  //Regresa el valor de la suma de los digitos del numero 
  int i,sum=0, aux;
  char Dgts[15];
  aux=sprDgts(num, Dgts);
  for(i=0; i<aux; i++){
    sum=sum+((Dgts[i])-'0');  
  }
  return sum;
}
int dgts(int num){  //Regresa el valor del numero de digitos
  char Dgts[15];
  int dgtsnum;
  dgtsnum=sprDgts(num,Dgts);
  return dgtsnum;
}
int prfct(int num){  //Regresa 1 si el numero es perfecto y 0 si no lo es
  int i, sum=0, aux;
  for(i=1; i<num; i++){
    aux=num%i;
	if(!aux){
      sum=sum+i;
	}
  }
  if (sum==num) return 1;
  else return 0;  
}
int frnds(int num, int num2){  //Regresa 1 si los numeros son amigos y 0 si no lo son
  int i, sum=0, aux;
  for(i=1; i<num; i++){
    aux=num%i;
	if(!aux){
      sum=sum+i;
	}
  }
  if (sum==num2) return 1;
  else return 0;  
}
