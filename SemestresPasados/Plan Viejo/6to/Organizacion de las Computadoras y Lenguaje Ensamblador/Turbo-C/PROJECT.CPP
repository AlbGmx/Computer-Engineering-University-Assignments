				//MANEJO DE MENUS
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void inicializa()
{
int gm, gd=DETECT;
initgraph(&gd,&gm, "C:\\tC\\bgi");
}
void uno()
{ clearviewport();

rectangle(100,100,500,200);
getch();
}

void dos()
{ clearviewport();
	fillellipse(320,240,100,50);
	getch();
}

void box(int x1, int y1, int x2, int y2, int relleno, int color)
{   int poly[8];
    poly[0]=x1 ; poly[1]=y1;
    poly[2]=x2 ; poly[3]=y1;
    poly[4]=x2 ; poly[5]=y2;
    poly[6]=x1 ; poly[7]=y2;
    setfillstyle(relleno, color);
    fillpoly(4,poly);

}
void menu()
{
box(0,0, getmaxx(), getmaxy(), 1, 9);

box(100,400,200,460,1, RED);
outtextxy(110,430,"OPCION 1");
box(250,400,350,460,1,RED);
outtextxy(260,430,"OPCION 2");

}

void mueve()
{   int i=1;
    char tecla;
    menu();
    outtextxy(45,50, "La historia comienza en un colegio de mucho prestigio donde un alumno");
    outtextxy(45,75, "de bajos recursos llamado Damian, que actualmente esta becado,");
    outtextxy(45,100, "se encuentra en examenes finales y debido al estres y a la complejidad");
    outtextxy(45,125, "de las clases le resulta muy dificil mantener su promedio, ya que si baja");
    outtextxy(45,150,"su promedio, su beca sera removida y no podra seguir sus estudios y entrar");
    outtextxy(45,175,"a la universidad.");
    outtextxy(45,200, "Damian no era muy bueno en matematicas y sentia que reprobaria esa asigna-");
    outtextxy(45,225, "tura al igual que varios de sus compa¤eros de clase. Por lo cual la profe-");
    outtextxy(45,250, "sora preocupada por los alumnos, ofrecio tutorias de matematicas despues");
    outtextxy(45,275, "de clases. Damian se cuestiono si ir o no...");
    setcolor(RED);
    outtextxy(45,300,"PRESIONA 1 SI QUIERES QUE DAMIAN VAYA");
    outtextxy(45,325, "PRESIONA 2 SI QUIERES QUE DAMIAN NO VAYA");
    setcolor(WHITE);

    do{ switch(i)
	{ case 1:	box(100,400,200,460,5, MAGENTA);
			outtextxy(110,430,"OPCION 1");

			break;
	  case 2:	box(250,400,350,460,5,MAGENTA);
			outtextxy(260,430,"OPCION 2");
			break;

	 }//fin magenta

       tecla=getch();
	switch(i)
	{ case 1:	box(100,400,200,460,1, RED);
			outtextxy(110,430,"OPCION 1");

			break;
	  case 2:	box(250,400,350,460,1,RED);
			outtextxy(260,430,"OPCION 2");
			break;


	 }//fin rojo

	 switch( tecla )
	 { case 0 : tecla=getch();
		    switch( tecla )
		    { case 75 : i--; break;
		      case 77 : i++; break;
		    }
		    if (i > 2 ) i=1;
		    if (i < 1 ) i=2;
		    break; //fin cero
	  case 13 : switch( i )
			{ case 1: clearviewport();
				  setbkcolor(9);
				  menu();
				  outtextxy(45,50, "Al dia siguiente al terminar las clases Damian asistio a las tutorias de");
				  outtextxy(45,75, "matematicas, conforme la clase fue avanzando Damian se dio cuenta de que");
				  outtextxy(45,100, "le faltaba bastante por repasar, realmente iba muy atrasado ya que le");
				  outtextxy(45,125, "dio prioridad a las otras materias. Entonces se acerco a la maestra con");
				  outtextxy(45,150, "muchas dudas y....");
				  setcolor(RED);
				  outtextxy(45,175, "1-LE PREGUNTA POR SESIONES PRIVADAS");
				  outtextxy(45,200,"2-POR PENA NO LE PREGUNTA NADA Y DECIDE IRSE");
				  setcolor(WHITE);
				  getch();

				break;



			  case 2:  clearviewport();
				  setbkcolor(9);
				  menu();
				  outtextxy(45,50, "De regreso a casa Damian se cuestiono acerca del tiempo que le queda para");
				  outtextxy(45,75, "presentar el examen y el poco tiempo que tiene para estudiar.");
				  outtextxy(45,100, "Entonces Damian decide....");
				  setcolor(RED);
				  outtextxy(45,175, "1-ESTUDIAR EN CASA");
				  outtextxy(45,200,"2-ESTUDIAR SOLAMENTE EN HORARIO DE CLASE");
				  setcolor(WHITE);
				  getch(); break;

			}
			 if ( i !=2) menu();

			 break; //fin enter
	 }
     }while(tecla!=27);
}

void main()
{
 inicializa();
 mueve();

}