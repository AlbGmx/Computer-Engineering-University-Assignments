#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void inicializa()
{ int gm, gd=DETECT;
  initgraph (&gd, &gm,"C:\\turboc3\\bgi");
}
void box(int x1, int y1, int x2, int y2, int relleno, int color)
{int poly [8];
	poly[0]=x1; poly [1]=y1;
	poly[2]=x2; poly [3]=y1;
	poly[4]=x2; poly [5]=y2;
	poly[6]=x1; poly [7]=y2;
setfillstyle (relleno, color);
fillpoly (4,poly);
}
void asigna ( int M[5][5] )
{ int i,j;
char A[5][5] = { 'A','U','A','B','C',
		 'A','A','A','A','A',
		 'A','A','A','A','A',
		 'A','A','A','A','A',
		 'A','A','A','A','A' };
for ( i = 0 ; i < 5 ; i++ )
for ( j = 0 ; j < 5 ; j++ ) M[i][j] = A[i][j];
}
void pintatablero( char M [5][5])
{ int i,j;
char cad [2];
	for ( i = 0 ; i < 5 ; i++ )
	for ( j = 0 ; j < 5 ; j++ )
	{
	 box (100 + j*50, 100 + i*50, 150 + j*50, 150 + i*50, 1, RED);
	 cad [0] = M [i] [j] ;
	 cad [1] =  '\x0' ;
outtextxy (125 + j*50, 125 + i*50 , cad );
}
}
void juega ( char M[5][5] )
{ int i,j,x,y, puntos=0;
char tecla, cad [10];
i=0; j=0; x=0; y=0;
asigna ( M );
pintatablero ( M );

do {
     box (100 + j*50, 100 + i*50, 150 + j*50, 150 + i*50, 1, BLUE);
     tecla= getch();
     box (100 + j*50, 100 + i*50, 150 + j*50, 150 + i*50, 1, RED);
     switch ( tecla )
     { case 0 : tecla = getch ();
	       switch ( tecla )
		 {case 72 : i-- ; break;
		  case 80 : i++ ; break;
		  case 75 : j-- ; break;
		  case 77 : j++ ; break;
		}
		if ( i < 0  ) i = 0 ;
		if ( i > 4  ) i = 4 ;
		if ( j < 0  ) j = 0 ;
		if ( j > 4  ) j = 4;
				break;// fin de cero
case 13 :
		setfillstyle (1, YELLOW);
		fillellipse (125 + j*50, 125 + i*50, 10,10);
		break;
	}// fin tecla
} while ( tecla !=27 );
}
void main ()
{ char M[5][5];
inicializa ();
asigna (M);
pintatablero (M);
juega (M);
}
