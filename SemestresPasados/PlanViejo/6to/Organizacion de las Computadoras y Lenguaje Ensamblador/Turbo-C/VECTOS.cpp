			  //esta es mi primer practica
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void inicializa(){
   int gm, gd=DETECT;
   initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
   randomize();
}
void box( int x1, int y1, int x2, int y2, int relleno, int color ){
 int poly[8];
 poly[0]= x1; poly[1]= y1;
 poly[2]= x2; poly[3]= y1;
 poly[4]= x2; poly[5]= y2;
 poly[6]= x1; poly[7]= y2;
 setfillstyle( relleno,color);
 fillpoly( 4,poly);
}
void iniciavector(int L[10]){
 int i;
 for(i=0;i<10;i++)L[i]=0;
}
void genera(int L[10]){
  int i;
  for(i=0;i<10;i++)L[i] = rand()%50;
}
void pintavector(int x, int y, int color){
  int i, s=40;
  for(i=0;i<10;i++) box(x+i*s,y,(x+s)+i*s,y+s,1,color);

}
void pintadatos(int x, int y, int L[10]){
 int i, s=40;
 char cad[5];
 for(i=0;i<10;i++){
  gcvt(L[i], 3, cad);
  outtextxy(x+13+i*s, y+20, cad);
 }
}
void vector(){
 int i=0, c, L[10], E[10], s=40;
 char tecla, cad[5];
 genera(L);
 iniciavector(E);

 pintavector(50,100, DARKGRAY);
 pintavector(50,200, LIGHTGRAY);
 pintadatos(50,100,L);
 i=0; c=0;
 do{
   setcolor(BLUE);
   rectangle(50+i*s,100,90+i*s,140);
   tecla=getch();
   setcolor(WHITE);
   rectangle(50+i*s,100,90+i*s,140);
   switch(tecla){
     case 0:tecla=getch();
	    switch(tecla){
	      case 75: i--; break;
	      case 77: i++; break;
	    }
	    if(i<0)i=9;
	    if(i>9)i=0;
	    break;
     case 13:
	box(50+i*s, 100, 90+i*s,140, 1,LIGHTGRAY); //Desaparece ficha

	//transferir ficha
	E[c]=L[i];
	box(50+c*40, 200,90+c*40,240,1,DARKGRAY);
	gcvt(E[c],3,cad);
	outtextxy(63+c*40,220,cad);
	c++;
	if(c==10) tecla=27;
	break;
   }
 }while(tecla!=27);

}
void main()
{
 inicializa();
 vector();
}