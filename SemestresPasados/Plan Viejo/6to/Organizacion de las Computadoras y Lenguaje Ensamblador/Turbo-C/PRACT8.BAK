#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

void inicializa ()
{ int gm, gd=DETECT;
initgraph( &gd, &gm, "c:\\turboc3\\bgi");
}
void ejes()
{ line( 0,getmaxy()/2, getmaxx(), getmaxy()/2 );
  line( getmaxx()/2, 0, getmaxx()/2,getmaxy()   );
}
void captura(float &xmin, float &xmax, float&inc )
{
  clrscr();
  printf(" XMIN= "); scanf("%f", &xmin);
  printf(" XMAX= "); scanf("%f", &xmax);
  printf(" INC= "); scanf("%f", &inc);
}
void grafica( float xmin, float xmax, float inc)
{ float x, y, f=10;
  ejes();
  x=xmin;
  do{ y= tan(x);

     if (x==xmin) moveto( 320 + x, 240 - y*f);
		   // lineto(320 + x , 240 - y*f );
       putpixel(320 + x*f, 240 - y * f, WHITE);

     x= x + inc ;
    } while( x <= xmax);
  getch();

}

void main()
{
 float xmin, xmax, inc;
 captura(xmin, xmax, inc);
 inicializa();
 grafica(xmin, xmax, inc);
}



