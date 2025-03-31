#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void inicializa()
{
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\bgi");
}

void box(int x1,int y1,int x2, int y2, int relleno, int color)
{
 int poly[8];
 poly[0]=x1; poly[1]=y1;
 poly[2]=x2; poly[3]=y1;
 poly[4]=x2; poly[5]=y2;
 poly[6]=x1; poly[7]=y2;

 setfillstyle(relleno,color);
 fillpoly(4,poly);
}

void nuevo()
{ clearviewport();
  outtextxy(100,100,"protsimamente");
  getch();
}

void guardar()
{ clearviewport();
  outtextxy(100,100,"ya mero sale");
  getch();
}

void wardadito()
{ clearviewport();
  outtextxy(100,100,"ya merito");
  getch();
}

void guardarcomo()
{ clearviewport();
  outtextxy(100,100,"nomas aprendo mas y lo acabo");
  getch();
}

void menu()
 {
   box(0,0,getmaxx(),getmaxy(),1,4);

   box(100,100,200,150,1,2);
   outtextxy(110,130,"nuevo");

   box(100,170,200,220,1,2);
   outtextxy(110,200,"guardar");


   box(100,240,200,290,1,2);
   outtextxy(110,270,"Salir");
 }
 void submenu()
 { clearviewport();
    box(100,100,200,150,1,2);
   outtextxy(110,130,"guardar");

   box(100,170,200,220,1,2);
   outtextxy(110,200,"guardar como");


   box(100,240,200,290,1,2);
   outtextxy(110,270,"volver");
   getch();
 }

void mueve()
 { int i=1;
   char tecla;

   menu();
   do{
       switch(i)
       {
	case 1:  box(100,100,200,150,1,3);
		 outtextxy(110,130,"nuevo");
		 break;

	case 2:	  box(100,170,200,220,1,3);
		  outtextxy(110,200,"guardar");
		  break;

	case 3:	  box(100,240,200,290,1,3);
		  outtextxy(110,270,"Salir");
		  break;
       } //Para que se resalte
      tecla=getch();

       switch(i)
       {
	case 1:  box(100,100,200,150,1,2);
		 outtextxy(110,130,"nuevo");
		 break;

	case 2:	  box(100,170,200,220,1,2);
		  outtextxy(110,200,"guardar");
		  break;

	case 3:	  box(100,240,200,290,1,2);
		  outtextxy(110,270,"Salir");
		  break;
       } //Para que parpadea

       switch(tecla)
       { case 0: tecla=getch();
		 switch(tecla)
		 {
		  case 75: i--;
			   break;

		  case 77: i++;
			   break;
		 }

		 if (i>3) i=1;
		 if (i<1) i=3;
		 break;  //se mueve aqui

	 case 13: switch(i)
		  {
		   case 1: nuevo();
			   break;

		   case 2: guardar();
			   break;

		   case 3: tecla=27;
			   break;
		  } // enter

		  if(i!=3) menu();
		  break;

       } //Fin switch
     }while (tecla!=27);
 }

 void muevesub()
 { int i=1;
   char tecla;

   submenu();
   do{
       switch(i)
       {
	case 1:  box(100,100,200,150,1,3);
		 outtextxy(110,130,"guardar");
		 break;

	case 2:	  box(100,170,200,220,1,3);
		  outtextxy(110,200,"guardar como");
		  break;

	case 3:	  box(100,240,200,290,1,3);
		  outtextxy(110,270,"volver");
		  break;
       } //Para que se resalte
      tecla=getch();

       switch(i)
       {
	case 1:  box(100,100,200,150,1,2);
		 outtextxy(110,130,"guardar");
		 break;

	case 2:	  box(100,170,200,220,1,2);
		  outtextxy(110,200,"guardar como");
		  break;

	case 3:	  box(100,240,200,290,1,2);
		  outtextxy(110,270,"volver");
		  break;
       } //Para que parpadea

       switch(tecla)
       { case 0: tecla=getch();
		 switch(tecla)
		 {
		  case 75: i--;
			   break;

		  case 77: i++;
			   break;
		 }

		 if (i>3) i=1;
		 if (i<1) i=3;
		 break;  //se mueve aqui

	 case 13: switch(i)
		  {
		   case 1: wardadito();
			   break;

		   case 2: guardarcomo();
			   break;

		   case 3: tecla=27;
			   break;
		  } // enter

		  if(i!=3) submenu();
		  break;

       } //Fin switch
     }while (tecla!=27);
 }

void main()
{
 inicializa();
 mueve();
 muevesub();
 getch();
}