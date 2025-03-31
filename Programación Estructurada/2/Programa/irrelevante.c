#include<stdlib.h>
#include<stdio.h>
int num;
int opc;

void binario() 
{ 
   int aux; 
   if(num==0) 
      return; 

   aux=num%2; 
   num=num/2; 
   binario(); 
   
   printf(" %d",aux); 
 
}
void octal()
{
    int aux1; 
   if(num==0) 
      return; 

   aux1=num%8; 
   num=num/8; 
   octal(); 

   printf(" %d",aux1); 
}

void hex()
{
 printf("\n");
 printf("Hexadecimal: %x",num);

}

int main() 
{ 
do
    {
   system("color A");
   printf("\n Introduce un numero: \n"); 
   scanf("%d",&num);
   
   printf("\n 1- Binario \n 2- Octal \n 3- Hexadecimal \n 4- Salir \n Ingresa una opcion: ");
   scanf("%d",&opc);
   switch (opc)
   {
    case 1:
 binario(); 
 getchar();

 break;
 
 case 2: 
 octal();
 getchar();

 break;
 
 case 3: 
 hex();
 getchar();

 break;
 
 case 4:
 exit(4);
 
 default:
 
 printf("Esa opcion no esta disponible! \n \n \a \a");   
 getchar();
 
 }  
 } while ( opc = 5 );
   
}