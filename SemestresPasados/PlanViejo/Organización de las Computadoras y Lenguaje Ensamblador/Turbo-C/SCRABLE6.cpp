
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>


void inicializa()
{ int gm, gd= DETECT;
  initgraph( &gd, &gm, "C:\\turboc3\\bgi");
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



void box( int x1, int y1, int x2, int y2,int relleno, int color )
{  int poly[8];
   poly [0]= x1 ; poly[1] = y1;
   poly [2]= x2 ; poly[3] = y1;
   poly [4]= x2 ; poly[5] = y2;
   poly [6]= x1 ; poly[7] = y2;
   setfillstyle (relleno, color);
   fillpoly (4, poly);
}

 void asigna(int M[11][11])
  {int i,j;
  for (i=0;i<11;i++)
  for (j=0;j<11;j++) M[i][j]=-1;
  }


 void generajugador1(int J1[6])
 {
  int i;

  for(i=0;i<6;i++) J1[i]=rand()%26;

 }
 void jugador1(int J1[6])
 {int i;
  char cad[6];
 for(i=0;i<6;i++)
 {
 gcvt(J1[i],3,cad);

  outtextxy(513,193+i*30,cad);
  box (500,180+i*30,530,210+i*30,1,RED);
   }
 }
 void generajugador2(int J2[6])
 {
  int i;


  for(i=0;i<6;i++) J2[i]=rand()%26;


 }
 void jugador2(int J2[6])
 {
   int i;
   char cad2[6];

   for(i=0; i<6; i++)
   {
 gcvt(J2[i],3,cad2);

  outtextxy(583,193+i*30,cad2);
    box (570,180+i*30,600,210+i*30,1,BLUE);
   }

 }
 void generamatriz(int M2[11][11])
 {  int i, j;
   for (i=0;i<11;i++)
  for (j=0;j<11;j++) M2[i][j]=-1;

  }
 void pintamatriz (int M2[11][11])
 {int i,j,J1[6],J2[6];


  generamatriz(M2);

  for (i=0;i<11;i++)
  for (j=0;j<11;j++) box(50+j*40, 30+i*40, 90+j*40, 70+i*40,1,GREEN);


  box(500,120,630,140,1,DARKGRAY);
  outtextxy(505,125,"Cambio de turno");
  box(500,155,530,175,1,RED);
  outtextxy(504,160,"J1");
  box(570,155,599,175,1,BLUE);
  outtextxy(574,160,"J2");
  outtextxy(500,30,"PUNTOS J1= ");
  outtextxy(500,70,"PUNTOS J2= ");

  setcolor(WHITE);
  generajugador1(J1);
  generajugador2(J2);
  jugador1(J1);
  jugador2(J2);

    for(i=0; i<6; i++)
	{
	switch(J1[i])
		{ case 0:  outtextxy(513,193+i*30,"A"); break;
		  case 1:  outtextxy(513,193+i*30,"B"); break;
		  case 2:  outtextxy(513,193+i*30,"C"); break;
		  case 3:  outtextxy(513,193+i*30,"D"); break;
		  case 4:  outtextxy(513,193+i*30,"E"); break;
		  case 5:  outtextxy(513,193+i*30,"F"); break;
		  case 6:  outtextxy(513,193+i*30,"G"); break;
		  case 7:  outtextxy(513,193+i*30,"H"); break;
		  case 8:  outtextxy(513,193+i*30,"I"); break;
		  case 9:  outtextxy(513,193+i*30,"J"); break;
		  case 10:  outtextxy(513,193+i*30,"K"); break;
		  case 11:  outtextxy(513,193+i*30,"L"); break;
		  case 12:  outtextxy(513,193+i*30,"M"); break;
		  case 13:  outtextxy(513,193+i*30,"N"); break;
		  case 14:  outtextxy(513,193+i*30,"O"); break;
		  case 15:  outtextxy(513,193+i*30,"P"); break;
		  case 16:  outtextxy(513,193+i*30,"Q"); break;
		  case 17:  outtextxy(513,193+i*30,"R"); break;
		  case 18:  outtextxy(513,193+i*30,"S"); break;
		  case 19:  outtextxy(513,193+i*30,"T"); break;
		  case 20:  outtextxy(513,193+i*30,"U"); break;
		  case 21:  outtextxy(513,193+i*30,"V"); break;
		  case 22:  outtextxy(513,193+i*30,"W"); break;
		  case 23:  outtextxy(513,193+i*30,"X"); break;
		  case 24:  outtextxy(513,193+i*30,"Y"); break;
		  case 25:  outtextxy(513,193+i*30,"Z"); break;

		}


	switch(J2[i])
		{ case 0:  outtextxy(583,193+i*30,"A"); break;
		  case 1:  outtextxy(583,193+i*30,"B"); break;
		  case 2:  outtextxy(583,193+i*30,"C"); break;
		  case 3:  outtextxy(583,193+i*30,"D"); break;
		  case 4:  outtextxy(583,193+i*30,"E"); break;
		  case 5:  outtextxy(583,193+i*30,"F"); break;
		  case 6:  outtextxy(583,193+i*30,"G"); break;
		  case 7:  outtextxy(583,193+i*30,"H"); break;
		  case 8:  outtextxy(583,193+i*30,"I"); break;
		  case 9:  outtextxy(583,193+i*30,"J"); break;
		  case 10:  outtextxy(583,193+i*30,"K"); break;
		  case 11:  outtextxy(583,193+i*30,"L"); break;
		  case 12:  outtextxy(583,193+i*30,"M"); break;
		  case 13:  outtextxy(583,193+i*30,"N"); break;
		  case 14:  outtextxy(583,193+i*30,"O"); break;
		  case 15:  outtextxy(583,193+i*30,"P"); break;
		  case 16:  outtextxy(583,193+i*30,"Q"); break;
		  case 17:  outtextxy(583,193+i*30,"R"); break;
		  case 18:  outtextxy(583,193+i*30,"S"); break;
		  case 19:  outtextxy(583,193+i*30,"T"); break;
		  case 20:  outtextxy(583,193+i*30,"U"); break;
		  case 21:  outtextxy(583,193+i*30,"V"); break;
		  case 22:  outtextxy(583,193+i*30,"W"); break;
		  case 23:  outtextxy(583,193+i*30,"X"); break;
		  case 24:  outtextxy(583,193+i*30,"Y"); break;
		  case 25:  outtextxy(583,193+i*30,"Z"); break;



		  }

	   /*	for(i=0; i<11;i++)
		for(j=0; j<11;j++)
		{
		 switch(M2[i][j])
		{ case 0:  outtextxy(55+j*40,35+i*40,"A"); break;
		  case 1:  outtextxy(55+j*40,35+i*40,"B"); break;
		  case 2:  outtextxy(55+j*40,35+i*40,"C"); break;
		  case 3:  outtextxy(55+j*40,35+i*40,"D"); break;
		  case 4:  outtextxy(55+j*40,35+i*40,"E"); break;
		  case 5:  outtextxy(55+j*40,35+i*40,"F"); break;
		  case 6:  outtextxy(55+j*40,35+i*40,"G"); break;
		  case 7:  outtextxy(55+j*40,35+i*40,"H"); break;
		  case 8:  outtextxy(55+j*40,35+i*40,"I"); break;
		  case 9:  outtextxy(55+j*40,35+i*40,"J"); break;
		  case 10:  outtextxy(55+j*40,35+i*40,"K"); break;
		  case 11:  outtextxy(55+j*40,35+i*40,"L"); break;
		  case 12:  outtextxy(55+j*40,35+i*40,"M"); break;
		  case 13:  outtextxy(55+j*40,35+i*40,"N"); break;
		  case 14:  outtextxy(55+j*40,35+i*40,"O"); break;
		  case 15:  outtextxy(55+j*40,35+i*40,"P"); break;
		  case 16:  outtextxy(55+j*40,35+i*40,"Q"); break;
		  case 17:  outtextxy(55+j*40,35+i*40,"R"); break;
		  case 18:  outtextxy(55+j*40,35+i*40,"S"); break;
		  case 19:  outtextxy(55+j*40,35+i*40,"T"); break;
		  case 20:  outtextxy(55+j*40,35+i*40,"U"); break;
		  case 21:  outtextxy(55+j*40,35+i*40,"V"); break;
		  case 22:  outtextxy(55+j*40,35+i*40,"W"); break;
		  case 23:  outtextxy(55+j*40,35+i*40,"X"); break;
		  case 24:  outtextxy(55+j*40,35+i*40,"Y"); break;
		  case 25:  outtextxy(55+j*40,35+i*40,"Z"); break;



		  }


		} */


		//


	}

    }



void juego()
{  int s,a,b,c,d,i,j,J1[6],J2[6],M[11][11], M2[11][11], aux=-1,x,y;
   char tecla;


   box (0,0,getmaxx(),getmaxy(),1,BLACK);
   pintamatriz(M2);


   // cuadro limitado
   columnas ( 0,640 );
   renglones( 0,480 );

   s=0;

   do {
      a=3;
      mouse(a,b,c,d);

       switch( b ) {
		    case 1 : quita();

			for(i=0; i<6; i++){ if(J1[i]==-1) J1[i]=rand()%26;
					 if(J2[i]==-1) J2[i]=rand()%26;  }

			     if (c>620 && c<640 && d>0   && d<20) s=1;
			     if (c>500 && c<530 && d>180 && d<210)
			     {
			     aux=J1[0];
			     box (500,180,530,210,1,RED);

			     J1[0]=-1;
			     }

			     if (c>500 && c<530 && d>210 && d<240)
			     { aux=J1[1];
			       box(500,210,530,240,1,RED);

			     J1[1]=-1;
			       }

			     if (c>500 && c<530 && d>240 && d<270)
			     {
			     aux=J1[2];
			     box (500,240,530,270,1,RED);
			     J1[2]=-1;
			     }

			     if (c>500 && c<530 && d>270 && d<300)
			     {
			     aux=J1[3];
			     box (500,270,530,300,1,RED);
			     J1[3]=-1;
			     }

			     if (c>500 && c<530 && d>300 && d<330)
			     {
			     aux=J1[4];
			     box (500,300,530,330,1,RED);
			     J1[4]=-1;
			     }

			     if (c>500 && c<530 && d>330 && d<360)
			     {
			     aux=J1[5];
			     box (500,330,530,360,1,RED);
			     J1[5]=-1;
			     }

			     if (c>500 && c<530 && d>360 && d<390)
			     {
			     aux=J1[6];
			     box (500,360,530,390,1,RED);
			     J1[6]=-1;
			     }

			     if (c>570 && c<600 && d>180 && d<210)
			     {
			     aux=J2[0];
			     box (570,180,600,210,1,BLUE);
			     J2[0]=-1;
			     }

			     if (c>570 && c<600 && d>210 && d<240)
			     {
			     aux=J2[1];
			     box (570,210,600,240,1,BLUE);
			     J2[1]=-1;
			     }

			     if (c>570 && c<600 && d>240 && d<270)
			     {
			     aux=J2[2];
			     box (570,240,600,270,1,BLUE);
			     J2[2]=-1;
			     }

			     if (c>570 && c<600 && d>270 && d<300)
			     {
			     aux=J2[3];
			     box (570,270,600,300,1,BLUE);
			     J2[3]=-1;
			     }

			     if (c>570 && c<600 && d>300 && d<330)
			     {
			     aux=J2[4];
			     box (570,300,600,330,1,BLUE);
			     J2[4]=-1;
			     }

			     if (c>570 && c<600 && d>330 && d<360)
			     {
			     aux=J2[5];
			     box (570,330,600,360,1,BLUE);
			     J2[5]=-1;
			     }

			     if (c>570 && c<600 && d>360 && d<390)
			     {
			     aux=J2[6];
			     box (570,360,600,390,1,BLUE);
			     J2[6]=-1;
			     }


			     if(c>50 &&c<490 && d>30 && d<470)
			     {
			      y=(c-50)/40; x=(d-30)/40;
			      M2[x][y]=aux;



		for(i=0; i<11;i++)
		for(j=0; j<11;j++)   //quitar for y meter el switch arriba lol
		{
		setcolor(WHITE);
		 switch(M2[i][j])
		{ case 0:  outtextxy(65+j*40,35+i*40,"A"); break;
		  case 1:  outtextxy(65+j*40,35+i*40,"B"); break;
		  case 2:  outtextxy(65+j*40,35+i*40,"C"); break;
		  case 3:  outtextxy(65+j*40,35+i*40,"D"); break;
		  case 4:  outtextxy(65+j*40,35+i*40,"E"); break;
		  case 5:  outtextxy(65+j*40,35+i*40,"F"); break;
		  case 6:  outtextxy(65+j*40,35+i*40,"G"); break;
		  case 7:  outtextxy(65+j*40,35+i*40,"H"); break;
		  case 8:  outtextxy(65+j*40,35+i*40,"I"); break;
		  case 9:  outtextxy(65+j*40,35+i*40,"J"); break;
		  case 10:  outtextxy(65+j*40,35+i*40,"K"); break;
		  case 11:  outtextxy(65+j*40,35+i*40,"L"); break;
		  case 12:  outtextxy(65+j*40,35+i*40,"M"); break;
		  case 13:  outtextxy(65+j*40,35+i*40,"N"); break;
		  case 14:  outtextxy(65+j*40,35+i*40,"O"); break;
		  case 15:  outtextxy(65+j*40,35+i*40,"P"); break;
		  case 16:  outtextxy(65+j*40,35+i*40,"Q"); break;
		  case 17:  outtextxy(65+j*40,35+i*40,"R"); break;
		  case 18:  outtextxy(65+j*40,35+i*40,"S"); break;
		  case 19:  outtextxy(65+j*40,35+i*40,"T"); break;
		  case 20:  outtextxy(65+j*40,35+i*40,"U"); break;
		  case 21:  outtextxy(65+j*40,35+i*40,"V"); break;
		  case 22:  outtextxy(65+j*40,35+i*40,"W"); break;
		  case 23:  outtextxy(65+j*40,35+i*40,"X"); break;
		  case 24:  outtextxy(65+j*40,35+i*40,"Y"); break;
		  case 25:  outtextxy(65+j*40,35+i*40,"Z"); break;



		  }
			}

    for(i=0; i<6; i++)
	{
	switch(J1[i])
		{ case 0:  outtextxy(513,193+i*30,"A"); break;
		  case 1:  outtextxy(513,193+i*30,"B"); break;
		  case 2:  outtextxy(513,193+i*30,"C"); break;
		  case 3:  outtextxy(513,193+i*30,"D"); break;
		  case 4:  outtextxy(513,193+i*30,"E"); break;
		  case 5:  outtextxy(513,193+i*30,"F"); break;
		  case 6:  outtextxy(513,193+i*30,"G"); break;
		  case 7:  outtextxy(513,193+i*30,"H"); break;
		  case 8:  outtextxy(513,193+i*30,"I"); break;
		  case 9:  outtextxy(513,193+i*30,"J"); break;
		  case 10:  outtextxy(513,193+i*30,"K"); break;
		  case 11:  outtextxy(513,193+i*30,"L"); break;
		  case 12:  outtextxy(513,193+i*30,"M"); break;
		  case 13:  outtextxy(513,193+i*30,"N"); break;
		  case 14:  outtextxy(513,193+i*30,"O"); break;
		  case 15:  outtextxy(513,193+i*30,"P"); break;
		  case 16:  outtextxy(513,193+i*30,"Q"); break;
		  case 17:  outtextxy(513,193+i*30,"R"); break;
		  case 18:  outtextxy(513,193+i*30,"S"); break;
		  case 19:  outtextxy(513,193+i*30,"T"); break;
		  case 20:  outtextxy(513,193+i*30,"U"); break;
		  case 21:  outtextxy(513,193+i*30,"V"); break;
		  case 22:  outtextxy(513,193+i*30,"W"); break;
		  case 23:  outtextxy(513,193+i*30,"X"); break;
		  case 24:  outtextxy(513,193+i*30,"Y"); break;
		  case 25:  outtextxy(513,193+i*30,"Z"); break;

		}


	switch(J2[i])
		{ case 0:  outtextxy(583,193+i*30,"A"); break;
		  case 1:  outtextxy(583,193+i*30,"B"); break;
		  case 2:  outtextxy(583,193+i*30,"C"); break;
		  case 3:  outtextxy(583,193+i*30,"D"); break;
		  case 4:  outtextxy(583,193+i*30,"E"); break;
		  case 5:  outtextxy(583,193+i*30,"F"); break;
		  case 6:  outtextxy(583,193+i*30,"G"); break;
		  case 7:  outtextxy(583,193+i*30,"H"); break;
		  case 8:  outtextxy(583,193+i*30,"I"); break;
		  case 9:  outtextxy(583,193+i*30,"J"); break;
		  case 10:  outtextxy(583,193+i*30,"K"); break;
		  case 11:  outtextxy(583,193+i*30,"L"); break;
		  case 12:  outtextxy(583,193+i*30,"M"); break;
		  case 13:  outtextxy(583,193+i*30,"N"); break;
		  case 14:  outtextxy(583,193+i*30,"O"); break;
		  case 15:  outtextxy(583,193+i*30,"P"); break;
		  case 16:  outtextxy(583,193+i*30,"Q"); break;
		  case 17:  outtextxy(583,193+i*30,"R"); break;
		  case 18:  outtextxy(583,193+i*30,"S"); break;
		  case 19:  outtextxy(583,193+i*30,"T"); break;
		  case 20:  outtextxy(583,193+i*30,"U"); break;
		  case 21:  outtextxy(583,193+i*30,"V"); break;
		  case 22:  outtextxy(583,193+i*30,"W"); break;
		  case 23:  outtextxy(583,193+i*30,"X"); break;
		  case 24:  outtextxy(583,193+i*30,"Y"); break;
		  case 25:  outtextxy(583,193+i*30,"Z"); break;


			}
		  }       }


		  delay(400);



			 break;

		case 2 : s=1;
			 break;
		  }
		pon();

   }  while ( s==0 || tecla==27  );

}




void main()
{
clrscr();
activa();
printf("Presione tecla para iniciar");
getch();
inicializa();
pon();
randomize();
juego();
closegraph();

}