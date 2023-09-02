//  MANEJO DE RATON EN TURBO C   archivo RATONT.CPP

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

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

void usa()
{  int  a,b,x,y ;
   char tecla;

   clrscr();

   activa();

   // cuadro limitado
   columnas ( 80,460 );
   renglones( 40,160 );

   do {
      gotoxy(x/8,y/8); cprintf("               ");
      a=3;
      mouse(a,b,x,y);
      textcolor(WHITE);
      gotoxy(x/8,y/8); cprintf("%d  %d   %d  %d", a,b,x,y);

   }  while ( b!=1  );


   quita();
   gotoxy(2,20);
   clrscr();
   cprintf("\n  QUITA %d  %d   %d  %d", a,b,x,y);
   getch();
}

void main ()
{
   clrscr();

   usa();
}


