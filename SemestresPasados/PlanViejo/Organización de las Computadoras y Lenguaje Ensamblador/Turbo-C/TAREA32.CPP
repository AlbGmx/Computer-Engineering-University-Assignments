#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

void inicializa()
{
	int gm,gd=DETECT;
	initgraph(&gd,&gm, "C:\\turboc3\\bgi");
}


void inicial(int xg, int yg, int t, int relleno,int color)
{
	int g [38];
//	    X               Y
	g[0]=xg;	g[1]=yg;
	g[2]=xg+0*t;	g[3]=yg-1+t;
	g[4]=xg+8*t;	g[5]=yg+0*t;
	g[6]=xg+8*t;	g[7]=yg+9*t;
	g[8]=xg+0*t;	g[9]=yg+11*t;
	g[10]=xg-7*t;	g[11]=yg+10*t;
	g[12]=xg-10*t;	g[13]=yg+0*t;
	g[14]=xg-7*t;	g[15]=yg-10*t;
	g[16]=xg+0*t;	g[17]=yg-11*t;
	g[18]=xg+8*t;	g[19]=yg-9*t;
	g[20]=xg+8*t;	g[21]=yg-7*t;
	g[22]=xg+0*t;	g[23]=yg+9*t;
	g[24]=xg-5*t;	g[25]=yg-5*t;
	g[26]=xg-7*t;	g[27]=yg+0*t;
	g[28]=xg-5*t;	g[29]=yg+5*t;
	g[30]=xg+0*t;	g[31]=yg+8*t;
	g[32]=xg+5*t;	g[33]=yg+7*t;
	g[34]=xg+5*t;	g[35]=yg+1*t;
	g[36]=xg+0*t;	g[37]=yg+1*t;

	setfillstyle (relleno,color);
	fillpoly(19,g);

}

void cirqle(int cx,int cy)
{
	sector(cx,cy,18,90,100,100);  	delay(500);    	setfillstyle(8,RED);
	sector(cx,cy,90,162,100,100);   delay(500);     setfillstyle(8,BLUE);
	sector(cx,cy,162,234,100,100);  delay(500);     setfillstyle(8,YELLOW);
	sector(cx,cy,234,306,100,100);  delay(500);     setfillstyle(8,MAGENTA);
	sector(cx,cy,306,360,100,100);	sector(cx,cy,0,18,100,100);
	delay(500);     setfillstyle(8,LIGHTBLUE);
}

void penta(int px,int py,int t, int relleno, int color)
{
	int p[10];
	p[0]=px+95*t;	p[1]=py-30*t;
	p[2]=px+0*t;	p[3]=py-100*t;
	p[4]=px-95*t;	p[5]=py-30*t;
	p[6]=px-59*t;	p[7]=py+80*t;
	p[8]=px+59*t;	p[9]=py+80*t;

	setfillstyle(relleno,color);
	fillpoly(5,p);


}


void box (int x1, int y1, int x2, int y2, int relleno, int color)
{
	int poly[8];
	poly[0] = x1; poly[1] = y1;
	poly[2] = x2; poly[3] = y1;
	poly[4] = x2; poly[5] = y2;
	poly[6] = x1; poly[7] = y2;
	setfillstyle (relleno, color);
	fillpoly(4, poly);
}



void main()
{
	inicializa();
	box (0,0,getmaxx(),getmaxy(),1,BLUE);
	//(coordenada x, coordenada y, tama¤o, relleno, color);
	inicial(200,200,2,8,GREEN);
	getch();
	//(coordenada x, coordenada y);
	cirqle(200,200);
	//(Coordenada x, coordenada y, tama¤o, relleno, color);
	penta(200,200,1,9,BLACK);
	getch();


}