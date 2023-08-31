#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>


void inicializa()
{
  int gm, gd=DETECT;
  initgraph( &gd, &gm,"C:\\turboc3\\bgi");

}

void box(int x1,int y1,int x2,int y2, int relleno,int color)
{
int r[8];

 r[0]=x1; r[1]=y1;

 r[2]=x2; r[3]=y1;

 r[4]=x2; r[5]=y2;

 r[6]=x1; r[7]=y2;


setfillstyle(relleno,color);
fillpoly(4,r);//  numero de cordenadas

 }
void uno () //

{
     clearviewport();
     setbkcolor(BLUE);
     rectangle(100,100,540,300);
     outtextxy(190,50,"GRAFICA DE LINIAS ");

     settextstyle(1,0,2);

     outtextxy(90,300,"Telcel "); //cantidad
     settextstyle(1,0,2);
     outtextxy(180,300,"Movistar "); //cantidad

     line(100,300,150,150);     //linias de perdidas y ganacias
     line(150,150,200,250);
     line(200,250,250,110);
     line(250,110,280,180);
     line(280,180,300,225);
     line(300,225,350,250);

     settextstyle(1,0,1);
     outtextxy(70,350," Ubicacio en x :");

getch();
}

void dos()
{
clearviewport();
setbkcolor(BLUE);
fillellipse(300,250,130,150);
line(300,250,205,150);

getch();
}
void letrax()

{    int x[40];
     clearviewport();
     setbkcolor(BLUE);

     outtextxy(190,50,"GRAFICA DE BARRAAS ");
     x[0]=100;
     x[1]=300;
     x[2]=100;
     x[3]=100;
     x[4]=150;
     x[5]=100;
     x[6]=150;
     x[7]=300;
     x[8]=200;
     x[9]=300;
     x[10]=200;
     x[11]=100;
     x[12]=250;
     x[13]=100;
     x[14]=250;
     x[15]=300;
     x[16]=300;
     x[17]=300;
     x[18]=300;
     x[19]=100;
     x[20]=350;
     x[21]=100;
     x[22]=350;
     x[23]=300;
     x[24]=400;
     x[25]=300;
     x[26]=400;
     x[27]=100;
     x[28]=450;
     x[29]=100;
     x[30]=450;
     x[31]=300;
     x[32]=500;
     x[33]=300;
     x[34]=500;
     x[35]=100;
     x[36]=550;
     x[37]=100;
     x[38]=550;
     x[39]=300;



     setfillstyle(1, YELLOW);
     fillpoly( 20, x );

getch();

}

void pastel()
{
clearviewport();

setbkcolor(BLUE);
fillellipse(300,250,130,150);
line(300,250,205,150);
line(205,150,305,250);
line(300,250,205,150);

getch();

}
//en proceso
void construccion()
{
     clearviewport();
     setbkcolor(BLUE);

     circle(250,150,130);

  getch();
}

//submenu1
void submenu1 ()
{
 box( 6,80,120,230 , 1 , RED);

 box(10,120,115,100,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(45,105,"Linias");

 box(10,130,115,150,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(45,135,"Barras");

 box(10,160,115,180,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(45,165,"Pastel");

 box(10,190,115,210,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(45,195,"Histogra");
 getch();
}
void mueve2()
{  int j=1;
   char flecha;
   submenu1();
   do{
	switch ( j )
	{

	 case 1 :   box(10,120,115,100,1,MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(45,105,"Linias");
		    break;

	 case 2 :   box(10,130,115,150,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(45,135,"Barras");
		    break;

	 case 3 :   box(10,160,115,180,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(45,165,"Pastel");
		    break;

	 case 4 :   box(10,190,115,210,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(45,195,"Histograma");
		    break;

		} // fin de magenta

	flecha=getch();

	switch ( j )
	{
	 case 1 :   box(10,120,115,100,1,BLUE);
		    settextstyle(2,0,0);
		    outtextxy(45,105,"Linias");
		    break;

	 case 2 :   box(10,130,115,150,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(45,135,"Barras");
		    break;

	 case 3 :   box(10,160,115,180,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(45,165,"Pastel");
		    break;

	 case 4 :   box(10,190,115,210,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(45,195,"Histograma");
		    break;

	 } // fin rojo

	 switch ( flecha )
	 {
	   case 0 : flecha = getch() ;
		    switch( flecha )
		    {
		      case 75 : j -- ; break;
		      case 77 : j ++ ; break;
		    }
		    if ( j > 5 ) j = 1 ;
		    if ( j < 1 ) j = 5 ;
		    break; // fin cero

	   case 13:  switch ( j )
		   {
		    case 1: uno();
			    break;
		    case 2: letrax();
			    break;
		    case 3: dos();
			    break;
		    case 4: uno();
			    break;

		    }

		    if ( j != 5 ) submenu1();


		    break; // fin enter


     }// fin flecha
   } while ( flecha !=27 );
}

			    // submenu 2
//submenu2
void submenu2 ()
{
 box( 130,80,240,230 , 1 , RED);

 box(135,100,235,120,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(170,105,"Nuevo");

 box(135,130,235,150,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(170,135,"Guardar");

 box(135,160,235,180,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(170,165,"HOLA 3");

 box(135,190,235,210,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(170,195,"HOLA 4");
 getch();
}
void mueve3()
{  int t=1;
   char fecha;
   submenu2();
   do{
	switch ( t )
	{

	 case 1 :   box(135,100,235,120,1,MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(170,105,"Nuevo");
		    break;

	 case 2 :   box(135,130,235,150,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(170,135,"Guardar");
		    break;

	 case 3 :   box(135,160,235,180,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(170,165,"HOLA 3");
		    break;

	 case 4 :   box(135,190,235,210,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(170,195,"HOLA 4");
		    break;

		} // fin de magenta

	fecha=getch();

	switch ( t )
	{

	 case 1 :   box(135,100,235,120,1,BLUE);
		    settextstyle(2,0,0);
		    outtextxy(170,105,"Nuevo");
		    break;

	 case 2 :   box(135,130,235,150,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(170,135,"Guardar");
		    break;

	 case 3 :   box(135,160,235,180,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(170,165,"HOLA 3");
		    break;

	 case 4 :   box(135,190,235,210,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(170,195,"HOLA 4");
		    break;

	 } // fin rojo

	 switch ( fecha )
	 {
	   case 0 : fecha = getch() ;
		    switch( fecha )
		    {
		      case 75 : t -- ; break;
		      case 77 : t ++ ; break;
		    }
		    if ( t > 5 ) t = 1 ;
		    if ( t < 1 ) t = 5 ;
		    break; // fin cero

	   case 13:  switch ( t )
		   {
		    case 1: uno();
			    break;
		    case 2: construccion();
			    break;
		    case 3: dos();
			    break;
		    case 4: letrax();
			    break;

		    }

		    if ( t != 5 ) submenu2();


		    break; // fin enter


     }// fin flecha
   } while ( fecha !=27 );
}
 void submenu3 ()       // submenu 33333
{
 box( 260,80,370,240, 1 , RED);

 box(265,100,365,120,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(300,105,"Grafica");

 box(265,130,365,150,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(300,135,"Color");

 box(265,160,365,180,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(300,165,"Datos");

 box(265,190,365,210,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(300,195,"HOLA 4");
 getch();
}

void mueve4()
{  int c=1;
   char feca;
   submenu3();
   do{
	switch ( c )
	{

	 case 1 :   box(265,100,365,120,1,MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(300,105,"Grafica");
		    break;

	 case 2 :   box(265,130,365,150,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(300,135,"Color");
		    break;

	 case 3 :   box(265,160,365,180,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(300,165,"Datos");
		    break;

	 case 4 :   box(265,190,365,210,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(300,195,"HOLA 4");
		    break;

		} // fin de magenta

	feca=getch();

	switch ( c )
	{

	 case 1 :   box(265,100,365,120,1,BLUE);
		    settextstyle(2,0,0);
		    outtextxy(300,105,"Grafica");
		    break;

	 case 2 :   box(265,130,365,150,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(300,135,"Color");
		    break;

	 case 3 :   box(265,160,365,180,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(300,165,"Datos");
		    break;

	 case 4 :   box(265,190,365,210,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(300,195,"HOLA 4");
		    break;


	 } // fin rojo

	 switch ( feca )
	 {
	   case 0 : feca = getch() ;
		    switch( feca )
		    {
		      case 75 : c -- ; break;
		      case 77 : c ++ ; break;
		    }
		    if ( c > 5 ) c = 1 ;
		    if ( c < 1 ) c = 5 ;
		    break; // fin cero

	   case 13:  switch ( c )
		   {
		    case 1: uno();
			    break;
		    case 2: construccion();
			    break;
		    case 3: dos();
			    break;
		    case 4: letrax();
			    break;

		    }

		    if ( c != 5 ) submenu3();


		    break; // fin enter


     }// fin flecha
   } while ( feca !=27 );
}

 void submenu5 ()       // submenu 555555
{
 box( 390,70,500,170, 1 , RED);


 box(395,80,495,100,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(430,85,"Grafica");

 box(395,110,495,130,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(430,115,"Datos");

 box(395,140,495,160,1, BLUE);
 settextstyle(2,0,0);
 outtextxy(430,145,"Sitio Web");


 getch();
}

void mueve5()
{  int q=1;
   char eca;
   submenu5();
   do{
	switch ( q )
	{

	 case 1 :  box(395,80,495,100,1, MAGENTA);
		   settextstyle(2,0,0);
		   outtextxy(430,85,"Grafica");
		    break;


	 case 2 :   box(395,110,495,130,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(430,115,"Datos");

		    break;

	 case 3 :   box(395,140,495,160,1, MAGENTA);
		    settextstyle(2,0,0);
		    outtextxy(430,145,"Sitio Web");

		    break;
		} // fin de magenta

	eca=getch();

	switch ( q )
	{

	 case 1 :   box(395,80,495,100,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(430,85,"Grafica");

		    break;


	 case 2 :   box(395,110,495,130,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(430,115,"Datos ");

		    break;

	 case 3 :   box(395,140,495,160,1, BLUE);
		    settextstyle(2,0,0);
		    outtextxy(430,145,"Sitio Web");
		    break;

	 } // fin rojo

	 switch ( eca )
	 {
	   case 0 : eca = getch() ;
		    switch( eca )
		    {
		      case 75 : q -- ; break;
		      case 77 : q ++ ; break;
		    }
		    if ( q > 5 ) q = 1 ;
		    if ( q < 1 ) q = 5 ;
		    break; // fin cero

	   case 13:  switch ( q )
		   {
		    case 1: uno();
			    break;
		    case 2: construccion();
			    break;
		    case 3: dos();
			    break;

		    }

		    if ( q != 5 ) submenu5();


		    break; // fin enter


     }// fin flecha
   } while ( eca !=27 );
}


void menu()
{
box(0,0,getmaxx(),getmaxy(),1,BLUE);

settextstyle(3,0,1);

box(0,0,120,80,1,RED);
outtextxy(40,5,"Tipo ");
outtextxy(45,30,"de");
outtextxy(30,55,"Grafica");


box(130,0,240,80,1,RED);
outtextxy(150,20,"Archivo");


box(260,0,370,80,1,RED);
outtextxy(280,20,"Ajustes ");


box(390,0,500,80,1,RED);
outtextxy(410,20,"Help");


box(530,0,640,80,1,RED);
outtextxy(545,20," Salir");    //op

rectangle(100,130,540,450);

outtextxy(230,300,"  la mas bella");

}

void mueve()
{
int i=1;
char tecla;

 menu();
 do
 {
 switch(i)
 {
 case 1:    box(0,0,120,80,1,MAGENTA);
	    outtextxy(40,5,"Tipo ");
	    outtextxy(45,30,"de");
	    outtextxy(30,55,"Grafica");

	    break;
 case 2:    box(130,0,240,80,1,MAGENTA);
	    outtextxy(150,20,"Archivo");
	    break;

 case 3:    box(260,0,370,80,1,MAGENTA);
	    outtextxy(280,20,"Ajustes");
	    break;

 case 4:    box(390,0,500,80,1,MAGENTA);
	    outtextxy(410,20,"Help");
	    break;

 case 5:    box(530,0,640,80,1,MAGENTA);
	    outtextxy(545,20,"Salir");
	    break;


 }//fin de magenta
 tecla=getch();

 switch(i)
 {

 case 1:    box(0,0,120,80,1,RED);
	    outtextxy(40,5,"Tipo ");
	    outtextxy(45,30,"de");
	    outtextxy(30,55,"Grafica");

	    break;

 case 2:    box(130,0,240,80,1,RED);
	    outtextxy(150,20,"Archivo");
	    break;


 case 3:    box(260,0,370,80,1,RED);
	    outtextxy(280,20,"Ajustes");
	    break;


 case 4:    box(390,0,500,80,1,RED);
	    outtextxy(410,20,"Help ");
	    break;


 case 5:    box(530,0,640,80,1,RED);
	    outtextxy(545,20,"Salir");
	    break;


 }//fin de rojo

 switch(tecla)
 {
  case 0:tecla=getch();
	switch(tecla)
	{
	case 75: i-- ; break;
	case 77: i++ ; break;
	}
	if (i > 7) i = 1;
	if (i < 1) i = 7;
	break; //fin cero

  case 13: switch(i)
	   {
	   case 1: mueve2();
		   break;

	   case 2: mueve3();
		   break;
	   case 3: mueve4();
		   break;

	   case 4: mueve5();
		   break;

	   case 5: tecla=27;

		   break;

	   }

	   if (i != 10)menu();
	   break;    //fin enter

 }//fin tecla


 }while(tecla!=27);
}

void main()
{
inicializa();
mueve();

}

