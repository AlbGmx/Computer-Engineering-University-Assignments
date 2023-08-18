#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <ctype.h>

 //#6 Manjeo de Cadenas
void inicializa()
{
	int gm, gd=DETECT;
	initgraph(&gd, &gm,"c:\\turboc3\\bgi");
}

void captura(int x, int y, char cad[200])//par metro por referencia
{
	int pos;
	char tecla;

	cad[0] = '\x0'; //cadena vacia
	do
	{
		setcolor (WHITE);
		outtextxy(x,y,cad);
		tecla = getch();
		if ( isalnum(tecla) || tecla == ' ')
		{
			pos = strlen(cad);
			cad[pos]  = tecla;
			cad[pos+1] = '\x0';
		}
		if (tecla == 8)
		{  	setcolor (BLUE);
			outtextxy(x,y,cad);
			pos =strlen(cad);
			cad [pos-1]='\x0';

		}

	}while(tecla !=13);
}

void main()
{	char cad [200];

	inicializa();
	setbkcolor(BLUE);
	captura(40,100, cad);

	outtextxy(40,200,cad);
	getch();

}