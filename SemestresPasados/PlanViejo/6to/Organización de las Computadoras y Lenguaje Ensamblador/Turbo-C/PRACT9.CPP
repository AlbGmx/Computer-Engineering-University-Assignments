#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

void inicializa ()
{ int gm, gd=DETECT;
initgraph( &gd, &gm, "c:\\turboc3\\bgi");
}
void ejes()
{ line( 100, 100, 100, 400);
  line( 100, 400, 600, 400);
}
void captura(float L[5] )
{ int i;
  clrscr();
  for( i=0; i<5; i++ )
   {   printf(" Dato [ %d ] = ", i);
       scanf("%f", & L[i] );
   }
}
 float mayor ( float L[5] )
{ float m;
  int i;

  m= L[0];

  for( i=1; i<5; i++ ) if( L[i] > m) m= L[i];
  return (m);

}
void lineas( float L[5])
{ int i;
  float m, h;

  ejes ();
  m= mayor (L);

  moveto (100, 400);
  for (i=0; i<5; i++)
  {
   h= L[i]*300/ m ;
   lineto (150 + i*100, 400 - h);
  }
  getch();
}
void puntos( float L[5])
{ int i;
  float m, h;

  ejes ();
  m= mayor (L);

  moveto (100, 400);
  for (i=0; i<5; i++)
  {
   h= L[i]*300/ m ;
   fillellipse ( 150 + i*100, 400 - h, 4, 4 );
  }
  getch();
}
void barras( float L[5])
{ int i;
  float m, h;

  ejes ();
  m= mayor (L);

  moveto (100, 400);
  for (i=0; i<5; i++)
  {
   h= L[i]*300/ m ;
   bar ( 150 + i*100, 400 - h, 180 + i*100, 399 );
  }
  getch();
}

void pastel( float L[5])
{ int i;
  float sum=0, a=0;

 for (i=0; i<5; i++) sum = sum + L[i];
 setfillstyle( 1, 4);
 fillellipse( 320, 240, 100, 100);

 for (i=0; i<4; i++)
 {
  a= a + L[i]*360/sum;
  setfillstyle( 1, 8 + i);
  pieslice( 320, 240, 0, 360 - a, 100);

  }
  getch();
}

void main()
{
 float L[5];
 captura(L);
 inicializa();
// lineas(L);
// puntos(L);
 barras(L);
// pastel(L);

}

