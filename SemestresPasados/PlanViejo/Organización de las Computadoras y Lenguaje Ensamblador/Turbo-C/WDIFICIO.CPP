#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
	int xbuild, ybuild;	xbuild=20;	ybuild=10;
	textbackground(BLUE);
	clrscr();
	textcolor(WHITE);textbackground(BLACK);	gotoxy(xbuild,ybuild);cprintf("ÚÄÄÄÄÄÄÄ¿");	gotoxy(xbuild,ybuild+1);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+2);cprintf("³²");gotoxy(xbuild+4,ybuild+2);cprintf("²²²²³");	gotoxy(xbuild,ybuild+3);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+4);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+5);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+6);cprintf("³²²²²²");	gotoxy(xbuild,ybuild+7);cprintf("³²²²²²²²³");gotoxy(xbuild+8,ybuild+6); cprintf("³");	textcolor(YELLOW);	gotoxy(xbuild+2,ybuild+2);cprintf("±°");	gotoxy(xbuild+6,ybuild+6);cprintf("±°");
       gotoxy(1,1);    delay(1000);	insline();
	textbackground(BLUE);	clrscr();
	textcolor(WHITE);textbackground(BLACK);	gotoxy(xbuild,ybuild);cprintf("ÚÄÄÄÄÄÄÄ¿");	gotoxy(xbuild,ybuild+1);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+2);cprintf("³²");gotoxy(xbuild+4,ybuild+2);cprintf("²²²²³");	gotoxy(xbuild,ybuild+3);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+4);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+5);cprintf("³²²²²²²²³");	gotoxy(xbuild,ybuild+6);cprintf("³²²²²²");	gotoxy(xbuild,ybuild+7);cprintf("³²²²²²²²³");gotoxy(xbuild+8,ybuild+6); cprintf("³");	textcolor(YELLOW);	gotoxy(xbuild+2,ybuild+2);cprintf("±°");	gotoxy(xbuild+6,ybuild+6);cprintf("±°");


	getch();
}