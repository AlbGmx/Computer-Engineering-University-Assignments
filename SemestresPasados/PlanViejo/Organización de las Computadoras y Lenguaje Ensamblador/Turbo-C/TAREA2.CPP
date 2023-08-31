#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

void main()
{
	int gd,dm;
	gd=DETECT;
	initgraph ( &gd, &dm, "c:\\turboc3\\bgi");
	clearviewport();
	setbkcolor (BLUE);
	outtext ("HOLA");
	setcolor (RED);


	getch();
}