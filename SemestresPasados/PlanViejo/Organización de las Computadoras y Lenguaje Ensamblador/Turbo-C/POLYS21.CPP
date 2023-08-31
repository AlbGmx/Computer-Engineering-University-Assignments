
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>


void inicializa()
{
 int gm, gd=DETECT;
 initgraph(&gd, &gm,"d:\\bgi");
}
void grid()
{
  for(int i=37; i<640;i+=100)
  {
   line(i,0,i,480);
   line(0,i,640,i);
  }
}
void r(int relleno, int color)
{
  int fig[24];
  fig[0]=100; fig [1]=50;
  fig[2]=310; fig [3]=50;

  fig[4]=335; fig [5]=80;
  fig[6]=343; fig [7]=120;
  fig[8]=335; fig [9]=170;
  fig[10]=300; fig [11]=200;

  fig[12]=370; fig [13]=350;
  fig[14]=280; fig [15]=350;
  fig[16]=220; fig [17]=230;
  fig[18]=180; fig [19]=230;
  fig[20]=180; fig [21]=350;
  fig[22]=100; fig [23]=350;

  setfillstyle(relleno, color);
  fillpoly(12,fig);

  setfillstyle(1,0);
  bar(180,100,250,160);
  rectangle(180,100,250,160);
}
void penta(int relleno, int color)
{
  int fig[10];
  fig[0]=320; fig [1]=40;
  fig[2]=510; fig [3]=178;
  fig[4]=437; fig [5]=401;
  fig[6]=202; fig [7]=401;
  fig[8]=129; fig [9]=178;
  setfillstyle(relleno, color);
  circle(getmaxx()/2+1,getmaxy()/2,200);
  fillpoly(5,fig);
}
void heil(int relleno,int color)
{
 int fig[40];
 fig[0]=150; fig [1]=150;
 fig[2]=150; fig [3]=30;
 fig[4]=330; fig [5]=30;
 fig[6]=330; fig [7]=90;
 fig[8]=210; fig [9]=90;
 fig[10]=210; fig [11]=150;

 fig[12]=330; fig [13]=150;
 fig[14]=330; fig [15]=330;
 fig[16]=270; fig [17]=330;
 fig[18]=270; fig [19]=210;
 fig[20]=210; fig [21]=210;

 fig[22]=210; fig [23]=330;
 fig[24]=30; fig [25]=330;
 fig[26]=30; fig [27]=270;
 fig[28]=150; fig [29]=270;
 fig[30]=150; fig [31]=210;

 fig[32]=30; fig [33]=210;
 fig[34]=30; fig [35]=30;
 fig[36]=90; fig [37]=30;
 fig[38]=90; fig [39]=150;
 setfillstyle(relleno, color);
 fillpoly(20,fig);
}
void sword(int relleno, int color)
{
 int fig[42];
 fig[0]=250; fig [1]=120;
 fig[2]=250; fig [3]=30;
 fig[4]=235; fig [5]=15;
 fig[6]=270; fig [7]=0;
 fig[8]=305; fig [9]=15;
 fig[10]=290; fig [11]=30;
 fig[12]=290; fig[13]=120;

 fig[14]=380; fig [15]=120;
 fig[16]=385; fig [17]=135;
 fig[18]=380; fig [19]=150;

 fig[20]=290; fig [21]=150;
 fig[22]=290; fig [23]=450;
 fig[24]=270; fig [25]=475;
 fig[26]=250; fig [27]=450;

 fig[28]=250; fig [29]=320;
 fig[30]=255; fig [31]=318;
 fig[32]=250; fig [33]=316;

 fig[34]=250; fig [35]=150;
 fig[36]=160; fig [37]=150;
 fig[38]=155; fig [39]=135;
 fig[40]=160; fig [41]=120;


 setfillstyle(relleno,color);
 fillpoly(21,fig);
 //detalles
 setfillstyle(1,0);
 setcolor(0);
 bar(270,150,270,476);
 rectangle(250,32,290,119);
 int pesas[12];
 pesas[0]= 381; pesas[1]= 120;
 pesas[2]= 386; pesas[3]=135;
 pesas[4]=381 ; pesas[5]= 150;

 pesas[6]=159; pesas [7]=150;
 pesas[8]=154; pesas [9]=135;
 pesas[10]=159; pesas [11]=120;


 setcolor(0);
 drawpoly(6,pesas);
}
void main()
{
 inicializa();
 clearviewport();
 r(1,3);
 getch();
 clearviewport();
 penta(1,2);
 getch();
 clearviewport();
 heil(1,9);
 getch();
 clearviewport();
 sword(1,8);
 getch();

}