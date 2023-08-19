#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void inicializa ()
{ int gm, gd=DETECT;
initgraph( &gd, &gm, "c:\\turboc3\\bgi");
}
void pixeleada()
{ int i;
 for(i=0; i<1000; i=i+1) putpixel(rand()%640, rand()%480, WHITE);
}
void triangulo()
{
 int tri[6];

 tri[0]=400;
 tri[1]=150;
 tri[2]=250;
 tri[3]=250;
 tri[4]=300;
 tri[5]=100;
 setfillstyle(9,DARKGRAY);
 fillpoly(3,tri);
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
rectangle(100,100,540,300);
getch();
}

void dos()
{clearviewport();
fillellipse(320,240,100,50);
getch();
}
void menu()
{
box

