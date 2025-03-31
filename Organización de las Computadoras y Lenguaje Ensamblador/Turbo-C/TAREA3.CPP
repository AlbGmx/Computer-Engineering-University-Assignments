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
	g[2]=xg+0*t;	g[3]=yg-1*t;
	g[4]=xg+8*t;	g[5]=yg-1*t;
	g[6]=xg+8*t;	g[7]=yg+9*t;
	g[8]=xg+0*t;	g[9]=yg+11*t;
	g[10]=xg-7*t;	g[11]=yg+7*t;
	g[12]=xg-10*t;	g[13]=yg+0*t;
	g[14]=xg-7*t;	g[15]=yg-7*t;
	g[16]=xg-0*t;	g[17]=yg-12*t;
	g[18]=xg+8*t;	g[19]=yg-10*t;
	g[20]=xg+8*t;	g[21]=yg-7*t;
	g[22]=xg+0*t;	g[23]=yg-9*t;
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

void circulos_y_sectores(int cx,int cy)
{                                                       setfillstyle(8,GREEN);
	sector(cx,cy,18,90,100,100);  	delay(500);    	setfillstyle(8,RED);
	sector(cx,cy,90,162,100,100);   delay(500);     setfillstyle(8,BLUE);
	sector(cx,cy,162,234,100,100);  delay(500);     setfillstyle(8,YELLOW);
	sector(cx,cy,234,306,100,100);  delay(500);     setfillstyle(8,MAGENTA);
	sector(cx,cy,306,360,100,100);
	sector(cx,cy,0,18,100,100);	delay(500);
	setfillstyle(8,LIGHTBLUE);
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

void nazi(int xn, int yn,int t, int relleno, int color)
{
	int swastika [42];
	swastika[0]=xn-1*t;	swastika[1]=yn-1*t;
	swastika[2]=xn-1*t;	swastika[3]=yn-5*t;
	swastika[4]=xn+5*t;    	swastika[5]=yn-5*t;
	swastika[6]=xn+5*t;    	swastika[7]=yn-3*t;
	swastika[8]=xn+1*t;	swastika[9]=yn-3*t;
	swastika[10]=xn+1*t;	swastika[11]=yn-1*t;
	swastika[12]=xn+5*t;	swastika[13]=yn-1*t;
	swastika[14]=xn+5*t;	swastika[15]=yn+5*t;
	swastika[16]=xn+3*t;	swastika[17]=yn+5*t;
	swastika[18]=xn+3*t;	swastika[19]=yn+1*t;
	swastika[20]=xn+1*t;	swastika[21]=yn+1*t;
	swastika[22]=xn+1*t;	swastika[23]=yn+5*t;
	swastika[24]=xn-5*t;	swastika[25]=yn+5*t;
	swastika[26]=xn-5*t;	swastika[27]=yn+3*t;
	swastika[28]=xn-1*t;	swastika[29]=yn+3*t;
	swastika[30]=xn-1*t;	swastika[31]=yn+1*t;
	swastika[32]=xn-5*t;	swastika[33]=yn+1*t;
	swastika[34]=xn-5*t;	swastika[35]=yn-1*t;
	swastika[36]=xn-5*t; 	swastika[37]=yn-5*t;
	swastika[38]=xn-3*t;	swastika[39]=yn-5*t;
	swastika[40]=xn-3*t;	swastika[41]=yn-1*t;

	setfillstyle (relleno, color);
	fillpoly(21, swastika);
}

void sword (int xs,int ys, int t)
{

	int espada_hoja[12];
	espada_hoja[0]=xs-2*t;		espada_hoja[1]=ys+0*t;
	espada_hoja[2]=xs-2*t;		espada_hoja[3]=ys+33*t;
	espada_hoja[4]=xs+0*t;		espada_hoja[5]=ys+35*t;
	espada_hoja[6]=xs+2*t;		espada_hoja[7]=ys+33*t;
	espada_hoja[8]=xs+2*t;		espada_hoja[9]=ys+0*t;
	espada_hoja[10]=xs+0*t;		espada_hoja[11]=ys+2*t;

	int espada_centro [8];
	espada_centro[0]=xs-2*t;   	espada_centro[1]=ys+0*t;
	espada_centro[2]=xs+0*t;        espada_centro[3]=ys+2*t;
	espada_centro[4]=xs+2*t;       	espada_centro[5]=ys+0*t;
	espada_centro[6]=xs+0*t;        espada_centro[7]=ys-2*t;

	int espada_guarda [22];
	espada_guarda[0]=xs-2*t;      	espada_guarda[1]=ys+0*t;
	espada_guarda[2]=xs-5*t;      	espada_guarda[3]=ys+1*t;
	espada_guarda[4]=xs-9*t;      	espada_guarda[5]=ys+7*t;
	espada_guarda[6]=xs-9*t;      	espada_guarda[7]=ys-1*t;
	espada_guarda[8]=xs-3*t;      	espada_guarda[9]=ys-3*t;
	espada_guarda[10]=xs+3*t;      	espada_guarda[11]=ys-3*t;
	espada_guarda[12]=xs+9*t;      	espada_guarda[13]=ys-1*t;
	espada_guarda[14]=xs+9*t;      	espada_guarda[15]=ys+7*t;
	espada_guarda[16]=xs+5*t;      	espada_guarda[17]=ys+1*t;
	espada_guarda[18]=xs+2*t;      	espada_guarda[19]=ys+0*t;
	espada_guarda[20]=xs-0*t;      	espada_guarda[21]=ys-2*t;

	int espada_empuniadura [8];
	espada_empuniadura [0]=xs-2*t;	espada_empuniadura [1]=ys-3*t;
	espada_empuniadura [2]=xs-2*t;	espada_empuniadura [3]=ys-9*t;
	espada_empuniadura [4]=xs+2*t;	espada_empuniadura [5]=ys-9*t;
	espada_empuniadura [6]=xs+2*t;	espada_empuniadura [7]=ys-3*t;

	int espada_pomo[12];

	espada_pomo[0]=xs-2*t;	espada_pomo[1]=ys-9*t;
	espada_pomo[2]=xs-3*t;	espada_pomo[3]=ys-10*t;
	espada_pomo[4]=xs-1*t;	espada_pomo[5]=ys-12*t;
	espada_pomo[6]=xs+1*t;	espada_pomo[7]=ys-12*t;
	espada_pomo[8]=xs+3*t;	espada_pomo[9]=ys-10*t;
	espada_pomo[10]=xs+2*t;	espada_pomo[11]=ys-9*t;


	setfillstyle(2,WHITE);
	fillpoly(6,espada_hoja);

	setfillstyle(1,YELLOW);
	fillpoly(4,espada_centro);

	setfillstyle(1,BLUE);
	fillpoly(11,espada_guarda);
	fillpoly(4,espada_empuniadura);
	fillpoly(6,espada_pomo);

}

void raven ()
{
	int raven[64];
	raven[0]=25; 	raven[1]=260;
	raven[2]=73; 	raven[3]=222;
	raven[4]=95; 	raven[5]=200;
	raven[6]=123; 	raven[7]=200;
	raven[8]=138; 	raven[9]=217;
	raven[10]=170; 	raven[11]=150;
	raven[12]=294; 	raven[13]=46;
	raven[14]=380; 	raven[15]=20;
	raven[16]=332; 	raven[17]=117;
	raven[18]=418; 	raven[19]=73;
	raven[20]=353; 	raven[21]=153;
	raven[22]=414; 	raven[23]=144;
	raven[24]=333; 	raven[25]=205;
	raven[26]=387; 	raven[27]=209;
	raven[28]=263; 	raven[29]=263;
	raven[30]=373; 	raven[31]=256;
	raven[32]=410; 	raven[33]=273;
	raven[34]=231; 	raven[35]=325;
	raven[36]=204; 	raven[37]=347;
	raven[38]=225; 	raven[39]=366;
	raven[40]=230; 	raven[41]=388;
	raven[42]=240; 	raven[43]=399;
	raven[44]=217; 	raven[45]=412;
	raven[46]=225; 	raven[47]=424;
	raven[48]=207; 	raven[49]=415;
	raven[50]=222; 	raven[51]=390;
	raven[52]=213; 	raven[53]=364;
	raven[54]=190; 	raven[55]=360;
	raven[56]=133; 	raven[57]=343;
	raven[58]=97; 	raven[59]=290;
	raven[60]=96; 	raven[61]=277;
	raven[62]=81; 	raven[63]=247;
	setfillstyle(1,BLACK);
	fillpoly(32,raven);

}
void main()
{
	inicializa();
	box (0,0,getmaxx(),getmaxy(),1,BLUE);

	//Inicial
	//(coordenada x, coordenada y, tama¤o, relleno, color);
	inicial(300,250,15,8,GREEN);
	getch();

	//Pent gono
	box (0,0,getmaxx(),getmaxy(),1,MAGENTA);
	delay(100);
	//(coordenada x, coordenada y);
	circulos_y_sectores(300,250);
	//(Coordenada x, coordenada y, tama¤o, relleno, color);
	penta(300,250,1,1,BLACK);
	delay(500);
	box(0,0,getmaxx(),getmaxy(),1,MAGENTA);
	penta(300,250,1,1,BLACK);
	getch();

	//Espada
	box(0,0,getmaxx(),getmaxy(),1,GREEN);
	//(coordenada x, coordenada y, tama¤o);
	sword(300,250,5);
	getch();

	//Sv stica
	box(0,0,getmaxx(),getmaxy(),1,RED);
	//(coordenada x, coordenada y, tama¤o, relleno, color);
	nazi(300,250,20,1,YELLOW);
	getch();
	box(0,0,getmaxx(),getmaxy(),1,BLUE);
	raven();
	getch();

}