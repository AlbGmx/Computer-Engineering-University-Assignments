#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
void inicializa(){
	int gm, gd=DETECT;
	initgraph(&gd, &gm,"c:\\turboc3\\bgi");
}
void box (int x1, int y1, int x2, int y2, int relleno, int color){
	int poly[8];
	poly [0]=x1;	poly [1]=y1;
	poly [2]=x2;	poly [3]=y1;
	poly [4]=x2;	poly [5]=y2;
	poly [6]=x1;	poly [7]=y2;
	setfillstyle(relleno,color);
	fillpoly(4,poly);
}
void mouse(int &a,int &b,int &c,int &d )
{
 union REGS inregs, outregs;

 inregs.x.ax  =  a;
 inregs.x.bx  =  b;
 inregs.x.cx  =  c;
 inregs.x.dx  =  d;
 int86( '\x33' , &inregs, &outregs );
 a = outregs.x.ax ;
 b = outregs.x.bx ;
 c = outregs.x.cx ;
 d = outregs.x.dx ;
}

void activa()
{  int a=0,b,c,d;
   mouse(a,b,c,d);
}
void pon()
{  int a=1,b,c,d;
   mouse(a,b,c,d);
}
void quita()
{  int a=2,b,c,d;
   mouse(a,b,c,d);
}
void mcoord ( int &a, int &b, int &x, int &y )
{
   mouse(a,b,x,y);
}
void mgoto( int x, int y )
{  int a=4,b;
   mouse(a,b,x,y);
}
void columnas ( int low, int hi )
{  int a=7,b;
   mouse(a,b,low,hi);
}
void renglones ( int low, int hi )
{  int a=8,b;
   mouse(a,b,low,hi);
}

void startup(int &cpu){
	box(0,0,getmaxx(),getmaxy(),1,0);	//fondoxd
	settextstyle(0,0,4);
	outtextxy(80,166,"CUBILETE");
	outtextxy(120,226,"SUPER");
	outtextxy(40,286,"MINIMALISTA");
	settextstyle(0,0,2);
	box(0,getmaxy()-80,160,getmaxy(),1,4);	//boton salida
	outtextxy(30,getmaxy()-50,"SALIDA");
	box(400,80,560,160,1,2);	//boton vs CPU
	outtextxy(440,115,"PvC");
	box(400,200,560,280,1,2);	//boton vs 2 Jugadores
	outtextxy(440,235,"PvP");
	box(400,320,560,400,1,2);	//boton Ayuda
	outtextxy(435,355,"Ayuda");
	int a,b,c,d,i=0;
	activa();
   do {
       a=3;
       mouse(a,b,c,d);
	   pon();	

		if ( c>0 && c<160 && d>getmaxy()-80 && d<getmaxy() ){
			settextstyle(0,0,2);
			box(0,getmaxy()-80,160,getmaxy(),1,3);	//boton salida
			outtextxy(30,getmaxy()-50,"SALIDA");
		}
		else if(c>400 && c<560 && d>80 && d<160){
			box(400,80,560,160,1,1);	//boton vs CPU
			outtextxy(440,115,"PvC");
		}
		else if(c>400 && c<560 && d>200 && d<280){
			box(400,200,560,280,1,1);	//boton vs 2 Jugadores
			outtextxy(440,235,"PvP");
		}	
		else if(c>400 && c<560 && d>320 && d<400){
			box(400,320,560,400,1,1);	//boton Ayuda
			outtextxy(435,355,"Ayuda");
		}
		else{
			box(0,getmaxy()-80,160,getmaxy(),1,4);	//boton salida
			outtextxy(30,getmaxy()-50,"SALIDA");
			box(400,80,560,160,1,2);	//boton vs CPU
			outtextxy(440,115,"PvC");
			box(400,200,560,280,1,2);	//boton vs 2 Jugadores
			outtextxy(440,235,"PvP");
			box(400,320,560,400,1,2);	//boton Ayuda
			outtextxy(435,355,"Ayuda");
		}	
		switch( b ) {
		case 1: if ( c>0 && c<160 && d>getmaxy()-80 && d<getmaxy()){
					cpu=0;
					i=2;
				}
				else if(c>400 && c<560 && d>80 && d<160){
					cpu=1;
					i=2;
				}
				else if(c>400 && c<560 && d>200 && d<280){
					cpu=2;
					i=2;
				}	
				else if(c>400 && c<560 && d>320 && d<400){
					cpu=3;
					i=2;
				}
				else;
		break;
		case 2:	if ( c>0 && c<160 && d>getmaxy()-80 && d<getmaxy()){
					cpu=0;
					i=2;
				}
				else if(c>400 && c<560 && d>80 && d<160){
					cpu=1;
					i=2;
				}
				else if(c>400 && c<560 && d>200 && d<280){
					cpu=2;
					i=2;
				}	
				else if(c>400 && c<560 && d>320 && d<400){
					cpu=3;
					i=2;
				}
				else;
		break;
       }
	delay(10);
	quita();
   } 
   while ( i !=2 );
}
void main(){
	inicializa();
	int cpu=0;
	startup(cpu);
	clearviewport();
	printf("%d",cpu);
	getch();
}

