#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

 void inicializa ()
	{ int gm, gd=DETECT;

 initgraph( &gd, &gm, "c:\\turboc3\\bgi");
}
void hexagono()
{
 int hex[12];

 hex[0]=182;
 hex[1]=72;
 hex[2]=244;
 hex[3]=106;
 hex[4]=244;
 hex[5]=172;
 hex[6]=182;
 hex[7]=206;
 hex[8]=120;
 hex[9]=172;
 hex[10]=120;
 hex[11]=106;
 setfillstyle(1, BLUE);
 fillpoly(6, hex);
 }
 void letra()
 {
  int hep[14];

 hep[0]=500;
 hep[1]=159;
 hep[2]=375;
 hep[3]=424;
 hep[4]=265;
 hep[5]=424;
 hep[6]=138;
 hep[7]=159;
 hep[8]=246;
 hep[9]=159;
 hep[10]=323;
 hep[11]=373;
 hep[12]=398;
 hep[13]=159;


 setfillstyle(1, RED);
 fillpoly(7, hep);
 }
 void poly ()
 {
  int poly[46];
 poly[0]=605;
 poly[1]=25;
 poly[2]=590;
 poly[3]=61;
 poly[4]=370;
 poly[5]=228;
 poly[6]=250;
 poly[7]=328;
 poly[8]=240;
 poly[9]=360;
 poly[10]=295;
 poly[11]=345;
 poly[12]=322;
 poly[13]=415;
 poly[14]=268;
 poly[15]=395;
 poly[16]=213;
 poly[17]=394;
 poly[18]=195;
 poly[19]=347;
 poly[20]=128;
 poly[21]=392;
 poly[22]=127;
 poly[23]=414;
 poly[24]=80;
 poly[25]=375;
 poly[26]=100;
 poly[27]=370;
 poly[28]=161;
 poly[29]=312;
 poly[30]=125;
 poly[31]=295;
 poly[32]=128;
 poly[33]=248;
 poly[34]=119;
 poly[35]=200;
 poly[36]=190;
 poly[37]=239;
 poly[38]=170;
 poly[39]=280;
 poly[40]=204;
 poly[41]=270;
 poly[42]=330;
 poly[43]=190;
 poly[44]=565;
 poly[45]=34;

 setfillstyle(1, BROWN);
 fillpoly(23, poly);
 }
void espada()
{
  int poly[46];
 poly[0]=605;
 poly[1]=25;
 poly[2]=590;
 poly[3]=61;
 poly[4]=370;
 poly[5]=228;
 poly[6]=250;
 poly[7]=328;
 poly[8]=240;
 poly[9]=360;
 poly[10]=295;
 poly[11]=345;
 poly[12]=322;
 poly[13]=415;
 poly[14]=268;
 poly[15]=395;
 poly[16]=213;
 poly[17]=394;
 poly[18]=195;
 poly[19]=347;
 poly[20]=128;
 poly[21]=392;
 poly[22]=127;
 poly[23]=414;
 poly[24]=80;
 poly[25]=375;
 poly[26]=100;
 poly[27]=370;
 poly[28]=161;
 poly[29]=312;
 poly[30]=125;
 poly[31]=295;
 poly[32]=128;
 poly[33]=248;
 poly[34]=119;
 poly[35]=200;
 poly[36]=190;
 poly[37]=239;
 poly[38]=170;
 poly[39]=280;
 poly[40]=204;
 poly[41]=270;
 poly[42]=330;
 poly[43]=190;
 poly[44]=565;
 poly[45]=34;

 setfillstyle(1, YELLOW);
 fillpoly(23, poly);

}
void casa()
{
  int poly[66];

 poly[0]=563;
 poly[1]=28;
 poly[2]=563;
 poly[3]=72;
 poly[4]=593;
 poly[5]=72;
 poly[6]=630;
 poly[7]=201;
 poly[8]=603;
 poly[9]=201;
 poly[10]=606;
 poly[11]=431;
 poly[12]=466;
 poly[13]=431;
 poly[14]=465;
 poly[15]=315;
 poly[16]=388;
 poly[17]=315;
 poly[18]=388;
 poly[19]=431;
 poly[20]=249;
 poly[21]=431;
 poly[22]=245;
 poly[23]=445;
 poly[24]=24;
 poly[25]=445;
 poly[26]=24;
 poly[27]=215;
 poly[28]=3;
 poly[29]=212;
 poly[30]=132;
 poly[31]=23;
 poly[32]=170;
 poly[33]=72;
 poly[34]=517;
 poly[35]=72;
 poly[36]=263;
 poly[37]=212;
 poly[38]=245;
 poly[39]=215;
 poly[40]=233;
 poly[41]=212;
 poly[42]=113;
 poly[43]=62;
 poly[44]=36;
 poly[45]=212;
 poly[46]=120;
 poly[47]=202;
 poly[48]=120;
 poly[49]=273;
 poly[50]=62;
 poly[51]=273;
 poly[52]=62;
 poly[53]=202;
 poly[54]=517;
 poly[55]=72;
 poly[56]=523;
 poly[57]=28;
 poly[58]=579;
 poly[59]=236;
 poly[60]=579;
 poly[61]=371;
 poly[62]=520;
 poly[63]=371;
 poly[64]=520;
 poly[65]=236;


 setfillstyle(1, BROWN);
 fillpoly(33, poly);

}

void main()
{
	inicializa();

	hexagono();
	getch();
	clearviewport();

	letra();
	getch();
	clearviewport();

	espada();
	getch();
	clearviewport();

	casa();
	getch();

}