#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void graphics()
{
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
}

void letra()
{int letra[24];
	letra[0]=100;
	letra[1]=100;
	letra[2]=400;
	letra[3]=100;
	letra[4]=400;
	letra[5]=150;
	letra[6]=300;
	letra[7]=150;
	letra[8]=300;
	letra[9]=400;
	letra[10]=100;
	letra[11]=400;
	letra[12]=100;
	letra[13]=300;
	letra[14]=150;
	letra[15]=300;
	letra[16]=150;
	letra[17]=350;
	letra[18]=200;
	letra[19]=350;
	letra[20]=200;
	letra[21]=150;
	letra[22]=100;
	letra[23]=150;
	setfillstyle(1,DARKGRAY);
	fillpoly(12,letra);
	getch();

}

void cruz()
{

	int cruz[24];
	cruz[0]=200;
	cruz[1]=100;
	cruz[2]=300;
	cruz[3]=100;
	cruz[4]=300;
	cruz[5]=200;
	cruz[6]=400;
	cruz[7]=200;
	cruz[8]=400;
	cruz[9]=300;
	cruz[10]=300;
	cruz[11]=300;
	cruz[12]=300;
	cruz[13]=400;
	cruz[14]=200;
	cruz[15]=400;
	cruz[16]=200;
	cruz[17]=300;
	cruz[18]=100;
	cruz[19]=300;
	cruz[20]=100;
	cruz[21]=200;
	cruz[22]=200;
	cruz[23]=200;

	setfillstyle(1,RED);
	fillpoly(12,cruz);
	getch();
       }

void heptagono()
{int hepta[14];
	hepta[0]=250;
	hepta[1]=100;
	hepta[2]=360;
	hepta[3]=150;
	hepta[4]=390;
	hepta[5]=270;
	hepta[6]=310;
	hepta[7]=370;
	hepta[8]=190;
	hepta[9]=370;
	hepta[10]=110;
	hepta[11]=270;
	hepta[12]=140;
	hepta[13]=150;

	setfillstyle(1,BLUE);
	fillpoly(7,hepta);
	getch();
	}
void caca()
{ int caca[74];
	caca[0]=120;
	caca[1]=380;
	caca[2]=100;
	caca[3]=360;
	caca[4]=100;
	caca[5]=340;
	caca[6]=120;
	caca[7]=320;
	caca[8]=160;
	caca[9]=320;
	caca[10]=140;
	caca[11]=300;
	caca[12]=140;
	caca[13]=280;
	caca[14]=160;
	caca[15]=260;
	caca[16]=180;
	caca[17]=260;
	caca[18]=160;
	caca[19]=240;
	caca[20]=160;
	caca[21]=220;
	caca[22]=180;
	caca[23]=200;
	caca[24]=220;
	caca[25]=200;
	caca[26]=200;
	caca[27]=180;
	caca[28]=200;
	caca[29]=160;
	caca[30]=220;
	caca[31]=140;
	caca[32]=240;
	caca[33]=140;
	caca[34]=260;
	caca[35]=120;
	caca[36]=280;
	caca[37]=120;
	caca[38]=300;
	caca[39]=100;
	caca[40]=290;
	caca[41]=130;
	caca[42]=300;
	caca[43]=140;
	caca[44]=320;
	caca[45]=160;
	caca[46]=320;
	caca[47]=180;
	caca[48]=300;
	caca[49]=200;
	caca[50]=320;
	caca[51]=200;
	caca[52]=340;
	caca[53]=220;
	caca[54]=340;
	caca[55]=240;
	caca[56]=320;
	caca[57]=260;
	caca[58]=340;
	caca[59]=260;
	caca[60]=360;
	caca[61]=280;
	caca[62]=360;
	caca[63]=300;
	caca[64]=340;
	caca[65]=320;
	caca[66]=380;
	caca[67]=320;
	caca[68]=400;
	caca[69]=340;
	caca[70]=400;
	caca[71]=360;
	caca[72]=380;
	caca[73]=380;

	setfillstyle(1,6);
	fillpoly(37,caca);
	getch();
	}
void main()
{
graphics();
letra();
clearviewport();
cruz();
clearviewport();
heptagono();
clearviewport();
caca();
}