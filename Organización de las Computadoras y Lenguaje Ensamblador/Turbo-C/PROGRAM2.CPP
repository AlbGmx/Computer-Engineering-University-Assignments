#include <conio.h>
#include <stdio.h>
#include <graphics.h>
/*
Pantalla modo grafico
En el laboratorio se usa "c:\\turboc3\\bgi"
mount --> "c:\\bgi"
*/
void main()
{
/*
clrscr();	 <-- modo texto \\ modo grafico -->  clearviewport();
textcolor(color);<-- modo texto \\ modo grafico -->  setcolor(color);
textbackground();<-- modo texto \\ modo grafico -->  setbkcolor();
printf("txt");   <-- modo texto \\ modo grafico -->  outtext("txt:);
gotoxy(x,y);     <-- modo texto \\ modo grafico -->  movetoxy(x,y);
24x80 caracteres <-- modo texto \\ modo grafico -->  840x pixeles
outtextxy(xy);  imprime un texto en las coordenadas indicadas
settextstyle (estilo 0-4, direccion, tama¤o);   estilo de texto
line(x1,y1,x2,y2);                              linea
setlinestyle(estilo 0-3,a,b);                   estilo de linea
rectangle(x1,y1,x2,y2);                         pinta contorno
bar(x1,y1,x2,y2);                               pinta lo de adentro
bar3d(x1,y1,x2,y2,z,tapa);                      pinta un cubo
setfillstyle(relleno 0-11, color);              estilo del relleno
circle(x,y,radio);
ellipse(x,y,angulo inicial;,angulo final,rx,ry);
arc(x,y,anguloi,angulof,radio);
fillellipse(x,y,rx,ry);
pieslice(angulo inicial, angulofinal, radio);
sector(x,y,angulo inicial, angulo final, rx,ry);
*/
	int gd,dm;

	gd=DETECT;
	initgraph( &gd, &dm, "c:\\turboc3\\bgi");
	clearviewport();
	setbkcolor(GREEN);
	setcolor(BLUE);
	settextstyle(4,0,0);
	outtextxy(100,100, "INGENIERIA");
	settextstyle(3,0,0);
	outtextxy(100,150, "INGENIERIA");
	settextstyle(2,0,0);
	outtextxy(100,200, "INGENIERIA");
	settextstyle(1,0,0);
	outtextxy(100,250, "INGENIERIA");
	settextstyle(0,0,0);
	outtextxy(100,300, "INGENIERIA");


	getch();
	clearviewport();

	setlinestyle(3,0,0);
	line(100,100,540,100);

	setlinestyle(2,0,0);
	line(100,150,540,150);

	setlinestyle(1,0,0);
	line(100,200,540,200);

	setlinestyle(0,0,0);
	line(100,250,540,250);

	getch();
	clearviewport();

	setfillstyle(3,MAGENTA);

	rectangle (50,100,150,200);
	bar (250,100,350,200);
	bar3d (450,100,550,200,50,1);

	getch();
	putpixel(50,50,RED);	putpixel(51,50,RED);
	putpixel(50,51,RED);    putpixel(51,51,RED);
	clearviewport();
	circle(100,150,75);         	//circulo
	arc(250,150,45,270,50);       	//pedazo circulo
	ellipse(400,150,0,360,50,100);  //elipse
	ellipse(550,150,90,320,75,40);  //pedazo de elipse

	fillellipse(100,350,50,100);  	//elipse rellena
	fillellipse(220,350,40,40);     //circulo relleno
	pieslice(350,350,120,320,50);	//pedazo de circulo relleno
	sector(500,350,20,220,100,25);  //pedazo de elipse relleno


	getch();

/*
		TRAER PRESENTACION EN MODO GRAFICO
	CREATIVIDAD 	ORIGINALIDAD	DIVERSIDAD
			MOVIMIENTO	SONIDO
			FIGURAS


*/
}