//poligono = figura con 3 lados o mas

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void inicializa ()
{
	int gm,gd=DETECT;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

}

void pixelada ()
{
	int i;
	for (i=0; i<10000; i=i+1)
		putpixel ( rand()%640, rand()%480, WHITE);

}

void triangulo()
{
	int tri [6];
	tri[0]=300;
	tri[1]=300;
	tri[2]=400;
	tri[3]=350;
	tri[4]=200;
	tri[5]=380;
	setcolor(BLUE);
	setfillstyle (8,BLUE);
	fillpoly (3,tri);


}

void box (int x1, int y1, int x2, int y2, int relleno, int color)
{
	int poly[8];
	poly[0] = x1; poly[1] = y1;
	poly[2] = x2; poly[3] = y1;
	poly[4] = x2; poly[5] = y2;
	poly[6] = x1; poly[7] = y2;
	setfillstyle (relleno, color);
	fillpoly(4, poly);
}

void main ()//TODO CODIGO NUEVO SE ESCRIBE ANTES DE VOID MAIN
{

	inicializa();
	box (0,0, getmaxx(), getmaxy(), 1, BLUE);
	triangulo();
	box (100,40,540,80,4,RED);
	pixelada();
	box(100,400,540,440,5, GREEN);
	getch();

}
/*
	int tri[6]; fillpoly(3,tri);
	int penta[10]; fillpoly (5,penta);
	int dodeca[24]; fillpoly (12,dodeca);
	int fig50[100]; fillpoly (50,fig50);





	1ER LETRA APELLIDO
	PENTAGONO		GEOMETRICAMENTE EQUIDISTANTE
	ESPADA                  CUALQUIERA
	SVASTICA
	FIGURA DE 25+



*/