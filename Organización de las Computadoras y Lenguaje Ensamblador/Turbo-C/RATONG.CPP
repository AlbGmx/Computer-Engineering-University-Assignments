//  MANEJO DE RATON EN TURBO C GRAFICO

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

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


void inicializa()
{ int gd=DETECT, gm ;
  initgraph(&gd,&gm, "d:\\text\\tc3\\bgi");
}

void selecciona()
{  int i,a,b,c,d;

   clearviewport();
   setbkcolor(BLUE);
   setfillstyle(9,RED);
   i=0;
   bar (100,100,300,200); outtextxy( 150,150, " CUADRO UNO " );
   bar (100,300,300,400); outtextxy( 150,350, " CUADRO DOS " );

   do {
       a=3;
       mouse(a,b,c,d);

       switch( b ) {
       case 1 : quita();
		clearviewport();
		bar (100,100,300,200); outtextxy( 150,150, " CUADRO UNO " );
		bar (100,300,300,400); outtextxy( 150,350, " CUADRO DOS " );

		if ( c>100 && c<300 && d>100 && d<200 )
		   outtextxy(400,100, " Primer Cuadro ");
		else
		if ( c>100 && c<300 && d>300 && d<400 )
		   outtextxy(400,400, " Segundo Cuadro " );
		else outtextxy(400,250, " Afuera del Cuadro " );
		break;
       case 2 : i=2;

		break;
       }
       pon();

   } while ( i !=2 );
}

void main ()
{
   clrscr();
   activa();
   printf(" Presione una tecla para probrar el mouse en modo gr fico " );
   getch();
   inicializa();
   pon();

   selecciona();
   closegraph();
   quita();
}


