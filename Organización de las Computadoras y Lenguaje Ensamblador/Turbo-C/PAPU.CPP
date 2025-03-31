
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void inicializa()
{ int gm, gd=DETECT;
  initgraph (&gd, &gm,"C:\\TURBOC3\\bgi");
}
void equis()
{int equ[24];
equ[0]=170;
equ[1]=125;
equ[2]=135;
equ[3]=260;
equ[4]=170;
equ[5]=400;
equ[6]=130;
equ[7]=400;
equ[8]=107;
equ[9]=320;
equ[10]=90;
equ[11]=400;
equ[12]=45;
equ[13]=400;
equ[14]=83;
equ[15]=260;
equ[16]=45;
equ[17]=125;
equ[18]=90;
equ[19]=125;
equ[20]=107;
equ[21]=200;
equ[22]=125;
equ[23]=125;
setfillstyle(1,RED);
fillpoly(12,equ);
getch();
}
void poly()
{int poll[44];
poll[0]=300;
poll[1]=12;
poll[2]=300;
poll[3]=22;
poll[4]=290;
poll[5]=22;
poll[6]=290;
poll[7]=32;
poll[8]=300;
poll[9]=32;
poll[10]=300;
poll[11]=42;
poll[12]=256;
poll[13]=68;
poll[14]=267;
poll[15]=94;
poll[16]=243;
poll[17]=94;
poll[18]=243;
poll[19]=115;
poll[20]=255;
poll[21]=115;
poll[22]=255;
poll[23]=135;
poll[24]=285;
poll[25]=135;
poll[26]=285;
poll[27]=215;
poll[28]=263;
poll[29]=217;
poll[30]=263;
poll[31]=302;
poll[32]=231;
poll[33]=344;
poll[34]=220;
poll[35]=345;
poll[36]=220;
poll[37]=365;
poll[38]=210;
poll[39]=365;
poll[40]=210;
poll[41]=380;
poll[42]=220;
poll[43]=380;
poll[44]=220;
poll[45]=430;
poll[46]=395;
poll[47]=430;
poll[48]=;
poll[49]=;
poll[50]=;
poll[51]=345;
poll[52]=220;
poll[53]=365;
poll[54]=210;
poll[55]=365;
poll[56]=210;
poll[57]=380;
poll[58]=220;
poll[59]=380;
poll[60]=220;
poll[61]=430;

setfillstyle(1,GREEN);
fillpoly(22,poll);
getch();
}
void octagono()
{int oct[16];
oct[0]=471;
oct[1]=354;
oct[2]=415;
oct[3]=300;
oct[4]=415;
oct[5]=225;
oct[6]=471;
oct[7]=171;
oct[8]=548;
oct[9]=171;
oct[10]=602;
oct[11]=225;
oct[12]=602;
oct[13]=300;
oct[14]=548;
oct[15]=354;
setfillstyle(1,YELLOW);
fillpoly(8,oct);
getch();
}
void iturbide(){
 int itur[24];
itur[0]=522;
itur[1]=21;
itur[2]=522;
itur[3]=40;
itur[4]=559;
itur[5]=40;
itur[6]=559;
itur[7]=137;
itur[8]=522;
itur[9]=137;
itur[10]=522;
itur[11]=157;
itur[12]=625;
itur[13]=157;
itur[14]=625;
itur[15]=137;
itur[16]=589;
itur[17]=137;
itur[18]=589;
itur[19]=40;
itur[20]=625;
itur[21]=40;
itur[22]=625;
itur[23]=20;


setfillstyle(1,BLUE);
fillpoly(12,itur);
getch();
}
void main()
{
inicializa();
setbkcolor(BROWN);
equis();
clearviewport();
poly();
clearviewport();
octagono();
clearviewport();
iturbide();
clearviewport();
getch();
}





















































