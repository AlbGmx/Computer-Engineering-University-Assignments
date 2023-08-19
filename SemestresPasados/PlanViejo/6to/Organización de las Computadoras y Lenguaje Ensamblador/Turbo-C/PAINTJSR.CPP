// MANEJO DE RATON EN TURBO C GRAFICO

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>


void box( int x1, int y1, int x2, int y2, int relleno, int color)
{ int poly[8];
  poly[0]=x1;  poly[1]=y1;
  poly[2]=x2;  poly[3]=y1;
  poly[4]=x2;  poly[5]=y2;
  poly[6]=x1;  poly[7]=y2;
  setfillstyle(relleno,color);
  fillpoly(4,poly);
}

void mouse(int &a,int &b,int &c,int &d )
{
 union REGS inregs, outregs;

 inregs.x.ax  =  a;
 inregs.x.bx  =  b;
 inregs.x.cx  =  c;
 inregs.x.dx  =  d;
 int86( '\x33' , &inregs, &outregs );
 a = outregs.x.ax ;
 b = outregs.x.bx ;
 c = outregs.x.cx ;
 d = outregs.x.dx ;
}

void activa()
{  int a=0,b,c,d;
   mouse(a,b,c,d);
}
void pon()
{  int a=1,b,c,d;
   mouse(a,b,c,d);
}
void quita()
{  int a=2,b,c,d;
   mouse(a,b,c,d);
}
void mcoord ( int &a, int &b, int &x, int &y )
{
   mouse(a,b,x,y);
}
void mgoto( int x, int y )
{  int a=4,b;
   mouse(a,b,x,y);
}
void columnas ( int low, int hi )
{  int a=7,b;
   mouse(a,b,low,hi);
}
void renglones ( int low, int hi )
{  int a=8,b;
   mouse(a,b,low,hi);
}


void inicializa()
{ int gd=DETECT, gm ;
  initgraph(&gd,&gm, "C:\\bgi");
}

void menu()
{
clearviewport();
   setbkcolor(BLACK);
   setfillstyle(1,LIGHTGREEN);

   //OPCIONES PRINCIPALES
   setfillstyle(1,LIGHTBLUE);
   bar (0,15,110,40); outtextxy( 0,25, " NUEVA HOJA" );
   setfillstyle(1,LIGHTBLUE);
   bar (590,5,635,20); outtextxy( 590,10, "þ ß X" );

   setfillstyle(1,LIGHTBLUE);
  bar(3,455,637,470);
  outtextxy(5,459,"Graficador con mouse");
   //OPCIONES SECUNDARIAS
     setfillstyle(1,LIGHTBLUE);
     bar (0,100,43,165); //lapiz
     bar (45,100,90,165); //SPRAY
     bar (0,170,43,235);  //plumon
     bar (45,170,90,235); //borrador
     bar (0,240,43,305); //cuadro
     bar (45,240,90,305);//circulo
     bar (0,310,43,380); //linea
     bar (45,310,90,380);//pluma

     //FIGURAS
     setfillstyle(1,YELLOW);
     bar (15,110,35,150);
     setfillstyle(1,BLACK);
     bar (20,151,30,160);

     setfillstyle(1,BLACK);
     bar (55,125,75,160);
     setfillstyle(1,RED);
     bar (60,115,70,125);

     setfillstyle(1,WHITE);
     bar (60,190,75,205);

     setfillstyle(1,LIGHTGRAY);
     bar (10,260,33,290);

     setfillstyle(1,WHITE);
     line(10,320,35,370);

     setfillstyle(1,WHITE);
     circle(68,275,20);


    setfillstyle(1,WHITE);
    box(10,260,35,290,1,0);

    // bar (45,310,90,380);//pluma
    setfillstyle(1,LIGHTCYAN);
    bar(60,330,70,365);
    setfillstyle(1,BLACK);
    bar(64,330,68,360);
    setfillstyle(1,BLACK);
    bar(64,320,66,330);


  setfillstyle(1,LIGHTRED);
  bar(18,190,33,220);
  setfillstyle(1,LIGHTGREEN);
  bar(22,190,28,185);


     //COLORES
	    box(70,420,100,450,1,BLACK);
	    box(100,420,130,450,1,BLUE);
	    box(130,420,160,450,1,GREEN);
	    box(160,420,190,450,1,CYAN);
	    box(190,420,220,450,1,RED);
	    box(220,420,250,450,1,MAGENTA);
	    box(250,420,280,450,1,BROWN);
	    box(280,420,310,450,1,LIGHTGRAY);
	    box(310,420,340,450,1,DARKGRAY);
	    box(340,420,370,450,1,LIGHTBLUE);
	    box(370,420,400,450,1,LIGHTGREEN);
	    box(400,420,430,450,1,LIGHTCYAN);
	    box(430,420,460,450,1,LIGHTRED);
	    box(460,420,490,450,1,LIGHTMAGENTA);
	    box(490,420,520,450,1,YELLOW);
	    box(520,420,550,450,1,WHITE);

	   //LIENZO
	   box(100,50,635,410,1,WHITE);

}

void circulo2(int x1, int y1, int x2, int y2, int color, int contorno)
{
 int alt,base,rad=0,hip;


 if(y2<y1 && x2==x1) //arriba
 {
   rad=y1-y2;

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
   setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }

 if(y2>y1 && x2==x1) //abajo
 {
   rad=y2-y1;

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
   setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }

 if(x2<x1 && y2==y1) //izquierda
 {
   rad=x1-x2;
   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
      setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }

 if(x2>x1 && y2==y1) // derecha
  {
   rad=x2-x1;

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
      setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }


 if(x2<x1 && y2<y1) //arriba izquierda
 {
   base=x1-x2;
   alt=y1-y2;
   hip=(base*base)+(alt*alt);

   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
      setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }

 if(y2<y1 && x2>x1) //arriba derecha
 {
   base=x2-x1;
   alt=y1-y2;
   hip=(base*base)+(alt*alt);
   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
      setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }

 if(y1<y2 && x2<x1) //abajo izquierda
 {
   base=x1-x2;
   alt=y2-y1;
   hip=(base*base)+(alt*alt);
   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
      setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }

 if(y1<y2 && x2>x1) //abajo derecha
 {
   base=x2-x1;
   alt=y2-y1;
   hip=(base*base)+(alt*alt);
   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
      setcolor(contorno);
     setfillstyle(1,color);
     fillellipse(x1,y1,rad,rad);
   }
 }


}

void circulo(int x1, int y1, int x2, int y2, int relleno)
{
 int alt,base,rad=0,hip;


 if(y2<y1 && x2==x1) //arriba
 {
   rad=y1-y2;

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }

 if(y2>y1 && x2==x1) //abajo
 {
   rad=y2-y1;

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }

 if(x2<x1 && y2==y1) //izquierda
 {
   rad=x1-x2;
   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }

 if(x2>x1 && y2==y1) //derecha
  {
   rad=x2-x1;

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }

 if(x2<x1 && y2<y1) //arriba izquierda
 {
   base=x1-x2;
   alt=y1-y2;
   hip=(base*base)+(alt*alt);

   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }

 if(y2<y1 && x2>x1) //arriba derecha
 {
   base=x2-x1;
   alt=y1-y2;
   hip=(base*base)+(alt*alt);
   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }

 if(y1<y2 && x2<x1) //abajo izquierda
 {
   base=x1-x2;
   alt=y2-y1;
   hip=(base*base)+(alt*alt);
   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
    setcolor(relleno);
    circle(x1,y1,rad);
   }
 }

 if(y1<y2 && x2>x1) //abajo izquierda
 {
   base=x2-x1;
   alt=y2-y1;
   hip=(base*base)+(alt*alt);
   if(hip>0) rad=sqrt(hip);

   if((x1-rad)>65 && (x1+rad)<600 && (y1-rad)>35 && (y1+rad)<440 && rad!=0)
   {
   setcolor(relleno);
   circle(x1,y1,rad);
   }
 }


}
void selecciona()
{  int i,a,b,c,d,j,x1,y1,x2,y2;
   int s=0,h=1,click=0;
   int color=0,relleno=WHITE;
   menu();
   pon();
   do {
       a=3;
       mouse(a,b,c,d);

       switch( b )
       {
	 case 1 : quita();
		  delay(10);


		  if (c>600 && c<640 && d>0 && d<40) s=1;

		   if (c>70 && c<100 && d>420 && d<450) color= 0;
		  if (c>100 && c<130 && d>420 && d<450) color= 1;
		  if (c>130 && c<160 && d>420 && d<450) color= 2;
		  if (c>160 && c<190 && d>420 && d<450) color= 3;
		  if (c>190 && c<220 && d>420 && d<450) color= 4;
		  if (c>220 && c<250 && d>420 && d<450) color= 5;
		  if (c>250 && c<280 && d>420 && d<450) color= 6;
		  if (c>280 && c<310 && d>420 && d<450) color= 7;
		  if (c>310 && c<340 && d>420 && d<450) color= 8;
		  if (c>340 && c<370 && d>420 && d<450) color= 9;
		  if (c>370 && c<400 && d>420 && d<450) color= 10;
		  if (c>400 && c<430 && d>420 && d<450) color= 11;
		  if (c>430 && c<460 && d>420 && d<450) color= 12;
		  if (c>460 && c<490 && d>420 && d<450) color= 13;
		  if (c>490 && c<520 && d>420 && d<450) color= 14;
		  if (c>520 && c<550 && d>420 && d<450) color= 15;


		  if (c>0 && c<110 && d>15 && d<40)  {setfillstyle(1,WHITE);
						     bar (100,50,635,410);
						     }
		  if (c>0  && c<43 && d>100 && d<165) {click=0; h=1;}//lapiz
		  if (c>45 && c<90 && d>100 && d<165) {click=0; h=2;}//sp
		  if (c>0  && c<43 && d>170 && d<235) {click=0; h=3;}//PLU
		  if (c>45 && c<90 && d>170 && d<235) {click=0; h=4;}//borrador
		  if (c>0  && c<43 && d>240 && d<305) {click=0; h=5;}//cua
		  if (c>45 && c<90 && d>240 && d<305) {click=0; h=6;}//cir
		  if (c>0  && c<43 && d>310 && d<380) {click=0; h=7;}//lin
		  if (c>45 && c<90 && d>310 && d<380) {click=0; h=8;}//PLUM


    //LAPIZ
   if (c>100 && c<635 && d>50 && d<410 && h==1) putpixel(c,d,color);
   //SPRAY
   if (c>100 && c<635 && d>50 && d<410 && h==2){ for (i=0;i<10;i++) putpixel(c+rand()%10, d+rand()%10,color);}
   //PLUMON
   if (c>100 && c<635 && d>50 && d<410 && h==3) { setcolor(relleno);
						setfillstyle (1,color);
						fillellipse(c,d,5,5);
					      }
   //BORRADOR
   if (c>108 && c<635 && d>58 && d<410 && h==4) {setcolor(WHITE);
						setfillstyle (1,WHITE);
						fillellipse(c,d,10,10);
						}
   //cuadro
   if (c>100 && c<635 && d>50 && d<410 && h==5){
				      if(click==1)
				       { x2=c;
					 y2=d;
					 setcolor(color);
					 putpixel(x2,y2,color);

					 click=2;
				       }

				       if (click==0)
				       { //delay(500);
					 x1=c;
					 y1=d;
					 putpixel(x1,y1,color);
					 click++;
				       }

				       if (click==2)
				       { rectangle(x1,y1,x2,y2);
					 click=0;
				       }
				     }
   //pluma
  if (c>100 && c<635 && d>50 && d<410 && h==8) { setcolor(relleno);
				     setfillstyle(1,color);
				      fillellipse(c,d,1,4);
				      }
   //linea
   if (c>100 && c<635 && d>50 && d<410 && h==7) {if (click==1){
						 x2=c;
						 y2=d;
						 click++;
						 }
				     if (click==0){
				      x1=c;
				      y1=d;
				      click++;}
				      if (click==2){
				       setlinestyle(0,0,0);
						 setcolor(color);
						 line(x1,y1,x2,y2);
						 click=0; }
						 }
     //circulo
    if (c>100 && c<635 && d>50 && d<410 && h==6)  {  if(click==1)
				       { x2=c;
					 y2=d;
					 putpixel(x2,y2,color);
					 click=2;
				       }
				       if (click==0)
				       { x1=c;
					 y1=d;
					 putpixel(x1,y1,color);
					 click++;
				       }

				       if (click==2)
				       { putpixel(x1,y1,WHITE);
					 putpixel(x2,y2,WHITE);
					 circulo(x1,y1,x2,y2,color);

					 click=0;
				       }

		 }

    box(580,420,610,450,1,color);

		 break;


	  case 2: if(h==5) delay(200);
		  quita();

		  if (c>70 && c<100 && d>420 && d<450) relleno= 0;
		  if (c>100 && c<130 && d>420 && d<450) relleno= 1;
		  if (c>130 && c<160 && d>420 && d<450) relleno= 2;
		  if (c>160 && c<190 && d>420 && d<450) relleno= 3;
		  if (c>190 && c<220 && d>420 && d<450) relleno= 4;
		  if (c>220 && c<250 && d>420 && d<450) relleno= 5;
		  if (c>250 && c<280 && d>420 && d<450) relleno= 6;
		  if (c>280 && c<310 && d>420 && d<450) relleno= 7;
		  if (c>310 && c<340 && d>420 && d<450) relleno= 8;
		  if (c>340 && c<370 && d>420 && d<450) relleno= 9;
		  if (c>370 && c<400 && d>420 && d<450) relleno= 10;
		  if (c>400 && c<430 && d>420 && d<450) relleno= 11;
		  if (c>430 && c<460 && d>420 && d<450) relleno= 12;
		  if (c>460 && c<490 && d>420 && d<450) relleno= 13;
		  if (c>490 && c<520 && d>420 && d<450) relleno= 14;
		  if (c>520 && c<550 && d>420 && d<450) relleno= 15;

		  box(610,420,638,450,1,relleno);

		  if (h==5 && c>100 && c<635 && d>50 && d<410)     //rectangulo
				    {
				      if(click==1)
				       { x2=c;
					 y2=d;
					 setcolor(color);
					 putpixel(x2,y2,color);

					 click=2;
				       }

				       if (click==0)
				       { //delay(500);
					 x1=c;
					 y1=d;
					 putpixel(x1,y1,color);
					 click++;
				       }

				       if (click==2)
				       { setcolor(color);
					 box(x1,y1,x2,y2,1,relleno);
					 click=0;
				       }
				     }

    if (h==6 &&   c>100 && c<635 && d>50 && d<410)    //circulo
		{  if(click==1)
				       { x2=c;
					 y2=d;
					 putpixel(x2,y2,color);
					 click=2;
				       }
				       if (click==0)
				       { x1=c;
					 y1=d;
					 putpixel(x1,y1,color);
					 click++;
				       }

				       if (click==2)
				       { putpixel(x1,y1,WHITE);
					 putpixel(x2,y2,WHITE);
					 circulo2(x1,y1,x2,y2,relleno,color);

					 click=0;
				       }

		 }
		  break;



       }
	 pon();


   } while ( s==0 );
}

void main ()
{
   clrscr();
   activa();
   printf(" Presione una tecla para empezar a pintar " );
   getch();
   inicializa();


   selecciona();
   closegraph();
   quita();
}


