#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
	textbackground(RED);
	clrscr();
	int xbuild, ybuild;	xbuild=20;	ybuild=10;
	int x,y; x=1; y=1;
	textcolor(BLACK);
			textbackground(BLACK);	cprintf("                                                                                ");
		delay(100);	textbackground(BLACK);	cprintf("                                                                                ");
	sound(130);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(138);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(146);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(155);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(164);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(174);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(185);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(196);		delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(207);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(220);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(233);	delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	sound(246);		delay(100); 		cprintf("                                                                                ");
		delay(100); 		cprintf("                                                                                ");
	nosound();	delay(100);	textbackground(BLUE);	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(246);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(233);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(220);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(207);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(196);		delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(185);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(174);		delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(164);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(155);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(146);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(138);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(130);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(1000);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	sound(500);	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");
	nosound();	delay(100);    	cprintf("                                                                                ");
		delay(100);    	cprintf("                                                                                ");

	xbuild=71; ybuild=18;
	textcolor(WHITE);	textbackground(BLACK);
	gotoxy(xbuild,ybuild);		cprintf("ÚÄÄÄÄÄÄÄ¿");
	gotoxy(xbuild,ybuild+1);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+2);	cprintf("³²");		gotoxy(xbuild+4,ybuild+2);	cprintf("²²²²³");
	gotoxy(xbuild,ybuild+3);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+4);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+5);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+6);	cprintf("³²²²²²");	gotoxy(xbuild+8,ybuild+6); 	cprintf("³");
	gotoxy(xbuild,ybuild+7);	cprintf("³²²²²²²²³");
	textcolor(YELLOW);
	gotoxy(xbuild+2,ybuild+2);cprintf("±°");
	gotoxy(xbuild+6,ybuild+6);cprintf("±°");
/*
	xbuild=70; ybuild=18;
	textcolor(WHITE);	textbackground(BLACK);
	gotoxy(xbuild,ybuild);		cprintf("ÚÄÄÄÄÄÄÄ¿");
	gotoxy(xbuild,ybuild+1);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+2);	cprintf("³²");		gotoxy(xbuild+4,ybuild+2);	cprintf("²²²²³");
	gotoxy(xbuild,ybuild+3);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+4);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+5);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+6);	cprintf("³²²²²²");	gotoxy(xbuild+8,ybuild+6); 	cprintf("³");
	gotoxy(xbuild,ybuild+7);	cprintf("³²²²²²²²³");
	textcolor(YELLOW);
	gotoxy(xbuild+2,ybuild+2);cprintf("±°");
	gotoxy(xbuild+6,ybuild+6);cprintf("±°");




  */
	delay(10);
	x=1; y=13;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER
	xbuild=55; ybuild=18;
	textcolor(WHITE);	textbackground(BLACK);
	gotoxy(xbuild,ybuild);		cprintf("ÚÄÄÄÄÄÄÄ¿");
	gotoxy(xbuild,ybuild+1);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+2);	cprintf("³²");		gotoxy(xbuild+4,ybuild+2);	cprintf("²²²²³");
	gotoxy(xbuild,ybuild+3);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+4);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+5);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+6);	cprintf("³²²²²²");	gotoxy(xbuild+8,ybuild+6); 	cprintf("³");
	gotoxy(xbuild,ybuild+7);	cprintf("³²²²²²²²³");
	textcolor(YELLOW);
	gotoxy(xbuild+2,ybuild+2);cprintf("±°");
	gotoxy(xbuild+6,ybuild+6);cprintf("±°");
	textcolor(BLACK);	textbackground(BLUE);


	x=16; y=10;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER

	xbuild=40; ybuild=18;
	textcolor(WHITE);	textbackground(BLACK);
	gotoxy(xbuild,ybuild);		cprintf("ÚÄÄÄÄÄÄÄ¿");
	gotoxy(xbuild,ybuild+1);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+2);	cprintf("³²");		gotoxy(xbuild+4,ybuild+2);	cprintf("²²²²³");
	gotoxy(xbuild,ybuild+3);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+4);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+5);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+6);	cprintf("³²²²²²");	gotoxy(xbuild+8,ybuild+6); 	cprintf("³");
	gotoxy(xbuild,ybuild+7);	cprintf("³²²²²²²²³");
	textcolor(YELLOW);
	gotoxy(xbuild+2,ybuild+2);cprintf("±°");
	gotoxy(xbuild+6,ybuild+6);cprintf("±°");
	textcolor(BLACK);	textbackground(BLUE);


	x=31; y=7;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER


	xbuild=25; ybuild=18;
	textcolor(WHITE);	textbackground(BLACK);
	gotoxy(xbuild,ybuild);		cprintf("ÚÄÄÄÄÄÄÄ¿");
	gotoxy(xbuild,ybuild+1);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+2);	cprintf("³²");		gotoxy(xbuild+4,ybuild+2);	cprintf("²²²²³");
	gotoxy(xbuild,ybuild+3);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+4);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+5);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+6);	cprintf("³²²²²²");	gotoxy(xbuild+8,ybuild+6); 	cprintf("³");
	gotoxy(xbuild,ybuild+7);	cprintf("³²²²²²²²³");
	textcolor(YELLOW);
	gotoxy(xbuild+2,ybuild+2);cprintf("±°");
	gotoxy(xbuild+6,ybuild+6);cprintf("±°");
	textcolor(BLACK);	textbackground(BLUE);


	x=40; y=10;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER


	xbuild=10; ybuild=18;
	textcolor(WHITE);	textbackground(BLACK);
	gotoxy(xbuild,ybuild);		cprintf("ÚÄÄÄÄÄÄÄ¿");
	gotoxy(xbuild,ybuild+1);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+2);	cprintf("³²");		gotoxy(xbuild+4,ybuild+2);	cprintf("²²²²³");
	gotoxy(xbuild,ybuild+3);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+4);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+5);	cprintf("³²²²²²²²³");
	gotoxy(xbuild,ybuild+6);	cprintf("³²²²²²");	gotoxy(xbuild+8,ybuild+6); 	cprintf("³");
	gotoxy(xbuild,ybuild+7);	cprintf("³²²²²²²²³");
	textcolor(YELLOW);
	gotoxy(xbuild+2,ybuild+2);cprintf("±°");
	gotoxy(xbuild+6,ybuild+6);cprintf("±°");
	textcolor(BLACK);	textbackground(BLUE);
	gotoxy(1,1);	insline();
	x=40; y=10;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER

	gotoxy(1,1);	insline();

	x=40; y=8;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER

	gotoxy(1,1);	insline();

	x=40; y=6;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);

	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER

	gotoxy(1,1);	insline();

	x=40; y=4;
	textbackground(BLUE);	textcolor(BLACK);	sound(100);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	gotoxy(x,y);	cprintf("       ÄÂÄ  ");
	gotoxy(x,y+1 );	cprintf("ÄÅÄ   ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(200);
	//CLEAR COPTER
	textcolor(BLUE);
	gotoxy(x,y);	cprintf("     ÄÄÄÂÄÄÄ");
	gotoxy(x,y+1 );	cprintf(" Å    ÉÍÊÍ» ");
	gotoxy(x,y+2);	cprintf(" ÈÍÍÍÍ¹   º ");
	gotoxy(x,y+3);	cprintf("      ÈÍÍÍ¼ ");
	delay(10);
	//CLEAR COPTER




	textcolor(BLACK);
	gotoxy(1,1);
	textbackground(BLACK);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	insline();delay(100);
	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(100); 	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(10);
	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(100); 	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(10);
	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(100); 	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(100);	textbackground(BLUE);	cprintf("                                                                                ");  delay(10);


	nosound();
	getch();
}