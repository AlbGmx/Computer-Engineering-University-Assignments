//dec2base.c
#include <stdio.h>
#include <stdlib.h>
//Uso de la funcion strcpy para demostracion
#include <string.h>

int main (){
	int num=200;
    int value=num;
	int i=0;
	char *binchar;
    do{
	  if (value%2==1) binchar[i]='1';
	  else binchar[i]='0';
	  value=(value/2);
	  printf("%c", binchar[i]);
	  i++;
	}while(value>2);
    binchar[i]='\0';
    strrev(binchar); 
    printf("%s", binchar);
	 
	return(num);
	
	/*
	int i=0, j=0, value=999999, quotient;
	char temp[2];
	char hexa[10];
	
	for (i; i<10; i++){
	    itoa(value%2, temp, 16);
		value=(value/2);
		hexa[i]=temp[0];
		printf("hexa= %s  dec= %d  hexann= %c\n", temp, value, hexa[i]); 
	}
	hexa[10]='\0'; 
	printf("200 dec es igual a ");
	for(j=0; j<10; j++){
		printf("%c",hexa[j]);
	}
	printf(" hexaario");

   do{
	   quotient=value/16;
	   switch(value-(quotient*16)){
         case 0:   hexa[i]='0';  hexa[i+1]='\0';    break;
 		 case 1:   hexa[i]='1';  hexa[i+1]='\0';    break;
         case 2:   hexa[i]='2';  hexa[i+1]='\0';    break;
         case 3:   hexa[i]='3';  hexa[i+1]='\0';    break;
         case 4:   hexa[i]='4';  hexa[i+1]='\0';    break;
         case 5:   hexa[i]='5';  hexa[i+1]='\0';    break;
         case 6:   hexa[i]='6';  hexa[i+1]='\0';    break;
         case 7:   hexa[i]='7';  hexa[i+1]='\0';    break;
         case 8:   hexa[i]='8';  hexa[i+1]='\0';    break;
         case 9:   hexa[i]='9';  hexa[i+1]='\0';    break;
         case 10:  hexa[i]='A';  hexa[i+1]='\0';    break;
         case 11:  hexa[i]='B';  hexa[i+1]='\0';    break;
         case 12:  hexa[i]='C';  hexa[i+1]='\0';    break;
         case 13:  hexa[i]='D';  hexa[i+1]='\0';    break;
         case 14:  hexa[i]='E';  hexa[i+1]='\0';    break;
         case 15:  hexa[i]='F';  hexa[i+1]='\0';    break;
        }
		value=value/16;
		printf("hexa = %c\n", hexa[i]);
		i++;
   }while(value>16);
	   switch(value){
         case 0:   hexa[i]='0';  hexa[i+1]='\0';   break;
 		 case 1:   hexa[i]='1';  hexa[i+1]='\0';   break;
         case 2:   hexa[i]='2';  hexa[i+1]='\0';   break;
         case 3:   hexa[i]='3';  hexa[i+1]='\0';   break;
         case 4:   hexa[i]='4';  hexa[i+1]='\0';   break;
         case 5:   hexa[i]='5';  hexa[i+1]='\0';   break;
         case 6:   hexa[i]='6';  hexa[i+1]='\0';   break;
         case 7:   hexa[i]='7';  hexa[i+1]='\0';   break;
         case 8:   hexa[i]='8';  hexa[i+1]='\0';   break;
         case 9:   hexa[i]='9';  hexa[i+1]='\0';   break;
         case 10:  hexa[i]='A';  hexa[i+1]='\0';   break;
         case 11:  hexa[i]='B';  hexa[i+1]='\0';   break;
         case 12:  hexa[i]='C';  hexa[i+1]='\0';   break;
         case 13:  hexa[i]='D';  hexa[i+1]='\0';   break;
         case 14:  hexa[i]='E';  hexa[i+1]='\0';   break;
         case 15:  hexa[i]='F';  hexa[i+1]='\0';   break;
        }
		strrev(hexa);
		for(j=0; j<=i; j++){
		  printf("%c", hexa[j]);	
		
		}
		
    */		
}

