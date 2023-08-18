#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void inicializa()
{
	int gm, gd=DETECT;
	initgraph(&gd, &gm,"c:\\turboc3\\bgi");
}

void box (int x1, int y1, int relleno, int color)
{
	int poly[8];
	poly [0]=x1;		poly [1]=y1;
	poly [2]=x1 + 100;	poly [3]=y1;
	poly [4]=x1 + 100;	poly [5]=y1 + 50;
	poly [6]=x1;		poly [7]=y1 + 50;
	setfillstyle(relleno,color);
	fillpoly(4,poly);

}

void box1 (int x1, int y1, int x2, int y2, int relleno, int color)
{
	int poly[8];
	poly [0]=x1;  	poly [1]=y1;
	poly [2]=x2;	poly [3]=y1;
	poly [4]=x2;	poly [5]=y2;
	poly [6]=x1;	poly [7]=y2;
	setfillstyle(relleno,color);
	fillpoly(4,poly);
}


void menu1()
{

	box1 (0,0,getmaxx(),getmaxy(),1,RED);

	outtextxy(300,100, "MENU2");

	box (135,150,1,RED);
	outtextxy(155,172,"OPCION 1");

	box (265,150,1,RED);
	outtextxy(285,172,"CX");

	box1 (395,150,555,200,1,RED);
	outtextxy(415,172,"REGRESAR AL MENU");

}

void menu2()
{
	clearviewport();
	rectangle(100,100,330,430);
	outtextxy(110,110,"OPCION 2 ELEGIDA");
	getch();
}

void black()
{
clearviewport();
outtextxy(200,200,"OPCION 1 ELEGIDA");
getch();      }

void menu()
{
	box1 (0,0,getmaxx(),getmaxy(),1,BLUE);

	outtextxy(300,100, "MENU");

	box (135,150,1,RED);
	outtextxy(155,172,"OPCION 1");

	box (265,150,1,RED);
	outtextxy(285,172,"OPCION 2");

	box (395,150,1,RED);
	outtextxy(415,172,"SALIDA");

}
void mueve1 ()
{
	char tecla;
	int i = 2;
	menu1 ();

	do
	{
		switch(i)
		{
			case 1:	box (135,150,1,GREEN);
					outtextxy(155,172,"OPCION 1");
					break;
			case 2:	box1 (395,150,555,200,1,GREEN);
					outtextxy(415,172,"REGRESAR AL MENU");
					break;
		}
		tecla = getch();
		switch(i)
		{
			case 1:	box (135,150,1,RED);
					outtextxy(155,172,"OPCION 1");
					break;
			case 2:	box1 (395,150,555,200,1,RED);
					outtextxy(415,172,"REGRESAR AL MENU");
					break;
		}
		switch (tecla)
		{
		  case 0: tecla=getch();
			  switch (tecla)
			{
				case 75: i--;	break;
				case 77: i++;	break;
			}
			if (i<1) i=2;
			if (i>2) i=1;
			break;
			case 13: switch (i)
			{
				case 1: black();
				break;
				case 2: tecla=27;
				break;
			 }
				if (i==1) menu1();
				break;
		}
	}

	while (tecla != 27);



}



void mueve ()
{
	char tecla;
	int i = 2;
	menu ();

	do
	{
		switch(i)
		{
			case 1:	box (135,150,1,GREEN);
					outtextxy(155,172,"OPCION 1");
					break;
			case 2: box (265,150,1,GREEN);
					outtextxy(285,172,"OPCION 2");
					break;
			case 3: box (395,150,1,GREEN);
					outtextxy(415,172,"SALIDA");
					break;
		}
		tecla = getch();
		switch(i)
		{
			case 1:	box (135,150,1,MAGENTA);
					outtextxy(155,172,"OPCION 1");
					break;
			case 2: box (265,150,1,MAGENTA);
					outtextxy(285,172,"OPCION 2");
					break;
			case 3: box (395,150,1,MAGENTA);
					outtextxy(415,172,"SALIDA");
					break;
		}
		switch (tecla)
		{
		  case 0: tecla=getch();
			  switch (tecla)
			{
				case 75: i--;	break;
				case 77: i++;	break;
			}
			if (i<1) i=3;
			if (i>3) i=1;
			break;
			case 13: switch (i)
			{
				case 1: mueve1(); menu();
				break;
				case 2: menu2();
				break;
				case 3: tecla=27;
				break;
			 }
				if (i !=3) menu();
				break;
		}
	}

	while (tecla != 27);


}


void main()
{
	inicializa();
	mueve();

}