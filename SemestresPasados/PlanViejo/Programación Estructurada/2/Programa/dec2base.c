//dec2base.c
#include "dec2base.h"
#include <stdio.h>
#include <stdlib.h>
//Uso de la funcion strcpy para demostracion
#include <string.h>
#include <math.h>


int dec2binchar (int num, char* binchar)
{
    int i=0, value=num;
	do{
		if(value%2==0){
			binchar[i] = '0';
		}
		else{
			binchar[i] = '1';
		}
		value= value>>1;
		i++;
	}while(value!=0);
	binchar[i] = '\0';
	strrev(binchar);
	return num;
}

int dec2bin(int value){

	int i=0, binint=0;
    do{
	  binint+=(value%2*round(pow(10,i)));
	  value=value>>1;
	  i++;
	}while(value!=0);
	return binint;
}

int dec2hex(int num, char* hexa){	
  int i=0, value=num, quotient;
  do{
    quotient=value%16;
    if (quotient>=0&&quotient<10) hexa[i]=48+quotient;
    else if (quotient>=10&&quotient<17) hexa[i]=55+quotient;
		value=value>>4;
		i++;
	}while(value!=0);
	hexa[i] = '\0';
	strrev(hexa);
	return num;
 
 
 /*  int quotient, value=num, i=0;
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
	return num;
	*/
}

int dec2oct(int num){ 
	int i=0;
	int octint=0;
	int value=num;
    do{
		octint+=(value%8*round(pow(10,i)));
		value=value>>3;
		i++;
	}while(value!=0);
	return octint;
}