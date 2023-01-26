#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void inicializa ()
{ int gm, gd=DETECT;
initgraph( &gd, &gm, "c:\\turboc3\\bgi");
}

 void box(int x1, int y1, int x2, int y2, int relleno, int color)
{
 int poly[8];

 poly[0]=x1;  poly[1]=y1;
 poly[2]=x2;  poly[3]=y1;
 poly[4]=x2;  poly[5]=y2;
 poly[6]=x1;  poly[7]=y2;
 setfillstyle(relleno,color);
 fillpoly(4,poly);
}

void uno()
{ clearviewport();
 rectangle(100,100,540, 300);
 getch();
}

void dos()
{ clearviewport();
 fillellipse(320,240,100,50);
 getch();
}
void menu()
{
 box(0,0, getmaxx(), getmaxy(), 1, BLUE);

 box(100,100,200,160, 1, RED);
 outtextxy(110,130, "OPCION 1");

 box(250,100,350,160, 1, RED);
 outtextxy(260,130, "OPCION 2");

 box(400,100,500,160, 1, RED);
 outtextxy(410,130, "SALIR");

}

void mueve()
{
 int i=1;
 char tecla;

 menu();

 do{
     switch( i )
     {
     case 1: box(100,100,200,160, 1, MAGENTA);
	     outtextxy(110,130, "OPCION 1");
	     break;

     case 2: box(250,100,350,160, 1, MAGENTA);
	     outtextxy(260,130, "OPCION 2");
	     break;

    case 3:  box(400,100,500,160, 1, MAGENTA);
	     outtextxy(410,130, "SALIR");
	     break;

     }// fin magenta

     tecla=getch();

     switch( i )
     {
     case 1: box(100,100,200,160, 1, RED);
	     outtextxy(110,130, "OPCION 1");
	     break;

     case 2: box(250,100,350,160, 1, RED);
	     outtextxy(260,130, "OPCION 2");
	     break;

    case 3:  box(400,100,500,160, 1, RED);
	     outtextxy(410,130, "SALIR");
	     break;

     }// fin rojo
   switch( tecla)
   {
     case 0: tecla=getch();

	     switch(tecla)
	     {
	      case 75 : i--; break;
	      case 77 : i++; break;
	     }
	     if (i > 3 ) i = 1;
	     if (i < 1 ) i = 3;

	     break; //fin cero
     case 13: switch( i )
	      { case 1: uno();
			break;
		case 2: dos();
			break;
		case 3: tecla=27;
			break;
	      }
	      if( 1 != 3 ) menu();
	      break; //fin enter


     } // fin tecla
   } while( tecla != 27 );
}

void main()
{
 inicializa();
 mueve();
}