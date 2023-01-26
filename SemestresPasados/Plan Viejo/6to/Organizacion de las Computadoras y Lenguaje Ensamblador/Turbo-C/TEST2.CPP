#include <stdio.h>
#include <conio.h>

#include <graphics.h>
#include <stdlib.h>

void inicializa()
{
int gm,gd=DETECT;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
}

void portada()
{
 clearviewport();
 setbkcolor(BLUE);
 settextstyle(1,0,7);
 outtextxy(130,45,"BATTLESHIP");
 }

void box(int x1, int y1, int x2, int y2, int relleno, int color)
{

int poly[8];
poly[0]=x1;
poly[1]=y1;
poly[2]=x2;
poly[3]=y1;
poly[4]=x2;
poly[5]=y2;
poly[6]=x1;
poly[7]=y2;

setfillstyle(relleno,color);
fillpoly(4,poly);



}

void guardar(int M[10][10], int G[10][10], int MCPU[10][10], int GCPU[10][10] )
{
 int i,j;

 for (i=0; i<10;i++)
 for (j=0; j<10;j++){G[i][j]=M[i][j];
		     GCPU[i][j]=MCPU[i][j];
		    }

}

void cargar(int M[10][10], int G[10][10], int MCPU[10][10], int GCPU[10][10])
{

 int i,j;

 for (i=0; i<10;i++)
 for (j=0; j<10;j++){M[i][j]=G[i][j];
		     MCPU[i][j]=GCPU[i][j];
		    }
}

void asigna (int M[10][10],int MCPU [10][10] )
{ int i,j;

  for ( i=0; i<10; i++)
  for ( j=0; j<10; j++) M[i][j]=3;

  M[1][1]=1;
  M[3][4]=1;

}

void asignaCPU (int M[10][10], int MCPU[10][10])
{ int i,j;

  for ( i=0; i<10; i++)
  for ( j=0; j<10; j++) MCPU[i][j]=3;

  MCPU[1][1]=1;
  MCPU[3][4]=1;
}



void pintatablero (int M[10][10],int  MCPU[10][10])
{ int i,j;

  for ( i=0; i<10; i++)
  for ( j=0; j<10; j++)

    {
     MCPU[i][j]=0;
     box (8+j*30, 130+i*30, 38+j*30, 160+i*30,1,CYAN);
    }

  outtextxy(0,130, "A");
  outtextxy(0,160, "B");
  outtextxy(0,190, "C");
  outtextxy(0,220, "D");
  outtextxy(0,250, "E");
  outtextxy(0,280, "F");
  outtextxy(0,310, "G");
  outtextxy(0,340, "H");
  outtextxy(0,370, "I");
  outtextxy(0,400, "J");

  outtextxy(20,120, "1");
  outtextxy(50,120, "2");
  outtextxy(80,120, "3");
  outtextxy(110,120, "4");
  outtextxy(140,120, "5");
  outtextxy(170,120, "6");
  outtextxy(200,120, "7");
  outtextxy(230,120, "8");
  outtextxy(260,120, "9");
  outtextxy(290,120, "10");

  outtextxy(0,432, "Ship's placement order");
  outtextxy(0,441, "Two small ships");
  outtextxy(0,450, "One regular ship");
  outtextxy(0,459, "One Battleship");
  outtextxy(0,468, "One Carrier");					    //OTRAS COORDENADAS
}

void pintatableroCPU (int M[10][10],int MCPU[10][10])
{int i,j;

    for ( i=0; i<10; i++)
    for ( j=0; j<10; j++)
    {
    box (330+j*30, 130+i*30,360+j*30, 160+i*30,1, 8);

    M[i][j]=0 ;

    }
  outtextxy(322,130, "A");
  outtextxy(322,160, "B");
  outtextxy(322,190, "C");
  outtextxy(322,220, "D");
  outtextxy(322,250, "E");
  outtextxy(322,280, "F");
  outtextxy(322,310, "G");
  outtextxy(322,340, "H");
  outtextxy(322,370, "I");
  outtextxy(322,400, "J");

  outtextxy(340,120, "1");
  outtextxy(370,120, "2");
  outtextxy(400,120, "3");
  outtextxy(430,120, "4");
  outtextxy(460,120, "5");
  outtextxy(490,120, "6");
  outtextxy(520,120, "7");
  outtextxy(550,120, "8");
  outtextxy(580,120, "9");
  outtextxy(610,120, "10");

  outtextxy(330,435, "Ship's orientation keys");
  outtextxy(330,444, "For vertical orientetion press 'V'");
  outtextxy(330,453, "For horizontal orientation 'H'");
}



int valida2H(int M[10][10], int i, int j)
{
  int b=0;


  if (j<9 && M[i][j]==0 && M[i][j+1]==0)
  {
   setfillstyle(1,6);
   fillellipse(37 +  2+j*29, 143+i*30, 28,10);


   M[i][j  ]=220;
   M[i][j+1]=2;


   b=1;
   }

   return (b);


}

int valida3H(int M[10][10], int i, int j)
{
  int b=0;


  if (j<8 && M[i][j]==0 && M[i][j+1]==0 && M[i][j+2]==0)
  {
   setfillstyle(1,6);
   fillellipse(50+j*24, 143+i*30, 40,10);


   M[i][j  ]=330;
   M[i][j+1]=3;
   M[i][j+2]=3;


   b=1;
   }

   return (b);


}


int valida4H(int M[10][10], int i, int j)
{
  int b=0;


  if (j<7 && M[i][j]==0 && M[i][j+1]==0 && M[i][j+2]==0 && M[i][j+3]==0)
  {
   setfillstyle(1,6);
   fillellipse(61 + 8+j*30, 143+i*30, 60,10);


   M[i][j  ]=440;
   M[i][j+1]=4;
   M[i][j+2]=4;
   M[i][j+3]=4;

   b=1;
   }

   return (b);


}

int valida5H(int M[10][10], int i, int j)
{
  int b=0;


  if (j<6 && M[i][j]==0 && M[i][j+1]==0 && M[i][j+2]==0 && M[i][j+3]==0 && M[i][j+4]==0)
  {
   setfillstyle(1,6);
   fillellipse(80 + 8+j*2, 143+i*30, 76,10);


   M[i][j  ]=550;
   M[i][j+1]=5;
   M[i][j+2]=5;
   M[i][j+3]=5;
   M[i][j+4]=5;

   b=1;
   }

   return (b);


}



int valida2V(int M[10][10], int i, int j)
{
  int b=0;


  if (i<9 && M[i][j]==0 && M[i+1][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(0 + 20+j*31  ,160+i*30 , 10,28);


   M[i][j]=221;
   M[i+1][j]=2;


   b=1;
   }

   return (b);


}

int valida3V(int M[10][10], int i, int j)
{
  int b=0;


  if (i<8 && M[i][j]==0 && M[i+1][j]==0 && M[i+2][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(10 + 10+j*30, 170+i*30, 10,40);


   M[i][j]=331;
   M[i+1][j]=3;
   M[i+2][j]=3;


   b=1;
   }

   return (b);


}

int valida4V(int M[10][10], int i, int j)
{
  int b=0;


  if (i<7 && M[i][j]==0 && M[i+1][j]==0 && M[i+2][j]==0 && M[i+3][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(15 + 8+j*29, 190+i*30, 10,60);


   M[i][j]=441;
   M[i+1][j]=4;
   M[i+2][j]=4;
   M[i+3][j]=4;


   b=1;
   }

   return (b);


}

int valida5V(int M[10][10], int i, int j)
{
  int b=0;


  if (i<6 && M[i][j]==0 && M[i+1][j]==0 && M[i+2][j]==0 && M[i+3][j]==0 && M[i+4][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(15 + 8+j*30, 210+i*29,10,76);


   M[i][j]=551;
   M[i+1][j]=5;
   M[i+2][j]=5;
   M[i+3][j]=5;
   M[i+4][j]=5;

   b=1;
   }

   return (b);


}



int valida2HCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (j<9 && MCPU[i][j]==0 && MCPU[i][j+1]==0)
  {
   setfillstyle(1,6);
   fillellipse(358 +  2+j*29, 143+i*30, 28,10);


   MCPU[i][j  ]=220;
   MCPU[i][j+1]=2;


   b=1;
   }

   return (b);


}

int valida3HCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (j<8 && MCPU[i][j]==0 && MCPU[i][j+1]==0 && MCPU[i][j+2]==0)
  {
   setfillstyle(1,6);
   fillellipse(371 + j*24, 143+i*30, 40,10);


   MCPU[i][j  ]=330;
   MCPU[i][j+1]=3;
   MCPU[i][j+2]=3;


   b=1;
   }

   return (b);


}


int valida4HCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (j<7 && MCPU[i][j]==0 && MCPU[i][j+1]==0 && MCPU[i][j+2]==0 && MCPU[i][j+3]==0)
  {
   setfillstyle(1,6);
   fillellipse(382 + 8+j*30, 143+i*30, 60,10);


   MCPU[i][j  ]=440;
   MCPU[i][j+1]=4;
   MCPU[i][j+2]=4;
   MCPU[i][j+3]=4;

   b=1;
   }

   return (b);


}

int valida5HCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (j<6 && MCPU[i][j]==0 && MCPU[i][j+1]==0 && MCPU[i][j+2]==0 && MCPU[i][j+3]==0 && MCPU[i][j+4]==0)
  {
   setfillstyle(1,6);
   fillellipse(401 + 8+j*2, 143+i*30, 76,10);


   MCPU[i][j  ]=550;
   MCPU[i][j+1]=5;
   MCPU[i][j+2]=5;
   MCPU[i][j+3]=5;
   MCPU[i][j+4]=5;

   b=1;
   }

   return (b);


}



int valida2VCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (i<9 && MCPU[i][j]==0 && MCPU[i+1][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(330 + 10+j*31  ,160+i*30 , 10,28);


   MCPU[i][j]=221;
   MCPU[i+1][j]=2;


   b=1;
   }

   return (b);


}

int valida3VCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (i<8 && MCPU[i][j]==0 && MCPU[i+1][j]==0 && MCPU[i+2][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(330 + 10+j*30, 170+i*30, 10,40);


   MCPU[i][j]=331;
   MCPU[i+1][j]=3;
   MCPU[i+2][j]=3;


   b=1;
   }

   return (b);


}

int valida4VCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (i<7 && MCPU[i][j]==0 && MCPU[i+1][j]==0 && MCPU[i+2][j]==0 && MCPU[i+3][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(333 + 10+j*29, 190+i*30, 10,60);


   MCPU[i][j]=441;
   MCPU[i+1][j]=4;
   MCPU[i+2][j]=4;
   MCPU[i+3][j]=4;


   b=1;
   }

   return (b);


}

int valida5VCPU(int MCPU[10][10], int i, int j)
{
  int b=0;


  if (i<6 && MCPU[i][j]==0 && MCPU[i+1][j]==0 && MCPU[i+2][j]==0 && MCPU[i+3][j]==0 && MCPU[i+4][j]==0)
  {
   setfillstyle(1,6);
   fillellipse(335 + 10+j*30, 240+i*29,10,76);


   MCPU[i][j]=551;
   MCPU[i+1][j]=5;
   MCPU[i+2][j]=5;
   MCPU[i+3][j]=5;
   MCPU[i+4][j]=5;

   b=1;
   }

   return (b);


}



void juega (int M[10][10], int MCPU[10][10] )
{ clearviewport();
  int i=0,j=0;
  int tb=1 ;
  int dir=1;
  char tecla;
  pintatablero(M,MCPU);
  pintatableroCPU(M,MCPU);
  settextstyle(1,0,6);
  outtextxy(33,25,"ELIMINATE THE ENEMY");
 do{

     setcolor(RED);
     rectangle(8+j*30, 130+i*30, 38+j*30, 160+i*30);

     tecla=getche();

     setcolor(WHITE);
     rectangle(8+j*30, 130+i*30, 38+j*30, 160+i*30);

     switch(tecla)

     {




      case 0: tecla=getch();
	      switch(tecla)
	      {case 75: j--; break;
	       case 77: j++; break;
	       case 72: i--; break;
	       case 80: i++; break;
	      }

	      if (i<0) i=0; if (i>9) i=9;
	      if (j<0) j=0; if (j>9) j=9;

	      break;


       case 13:



	     if(dir==1)
	       {
		if (tb==1){if (valida2H(M,i,j)==1)tb++;}
		if (tb==2){if (valida2H(M,i,j)==1)tb++;}
		if (tb==3){if (valida3H(M,i,j)==1)tb++;}
		if (tb==4){if (valida4H(M,i,j)==1)tb++;}
		if (tb==5){if (valida5H(M,i,j)==1)tb++;}
	       }


	     if(dir==2)

	       {
		if (tb==1){if (valida2V(M,i,j)==1)tb++;}
		if (tb==2){if (valida2V(M,i,j)==1)tb++;}
		if (tb==3){if (valida3V(M,i,j)==1)tb++;}
		if (tb==4){if (valida4V(M,i,j)==1)tb++;}
		if (tb==5){if (valida5V(M,i,j)==1)tb++;}
	       }



	 break;

      case 'H':
      case 'h': dir=1;



	      break;

      case 'V':
      case 'v': dir=2;

	      break;





     }

  }while(tecla!=27 && tb<6);





tb=1;


 do{

     i=rand()%10;
     j=rand()%10;
     dir=1+rand()%2;


	     if(dir==1)
	       {
		if (tb==1){if (valida2HCPU(MCPU,i,j)==1)tb++;}
		if (tb==2){if (valida2HCPU(MCPU,i,j)==1)tb++;}
		if (tb==3){if (valida3HCPU(MCPU,i,j)==1)tb++;}
		if (tb==4){if (valida4HCPU(MCPU,i,j)==1)tb++;}
		if (tb==5){if (valida5HCPU(MCPU,i,j)==1)tb++;}
	       }


	     if(dir==2)

	       {
		if (tb==1){if (valida2VCPU(MCPU,i,j)==1)tb++;}
		if (tb==2){if (valida2VCPU(MCPU,i,j)==1)tb++;}
		if (tb==3){if (valida3VCPU(MCPU,i,j)==1)tb++;}
		if (tb==4){if (valida4VCPU(MCPU,i,j)==1)tb++;}
		if (tb==5){if (valida5VCPU(MCPU,i,j)==1)tb++;}
	       }

  }while(tecla!=27 && tb<6);





 do{
     setcolor(RED);
     rectangle(330+j*30, 130+i*30,360+j*30, 160+i*30);

     tecla=getch();

     setcolor(WHITE);
     rectangle(330+j*30, 130+i*30,360+j*30, 160+i*30);

     switch(tecla)
     {case 0: tecla=getch();
	      switch(tecla)
	      {case 75: j--; break;
	       case 77: j++; break;
	       case 72: i--; break;
	       case 80: i++; break;
	      }

	      if (i<0) i=0; if (i>9) i=9;
	      if (j<0) j=0; if (j>9) j=9;

	      break;
       case 13:
	       setfillstyle(1,RED);
	       fillellipse(345+j*30, 145+i*30, 8,8);

     }

  }while(tecla!=27);


}


void menu()
{
  settextstyle(0,0,0);
  box(0,0,getmaxx(),getmaxy(),1,BLUE);
  box(250,150,350,210,1,CYAN);
  outtextxy(260,180,"Fight");
  box(250,250,350,310,1,CYAN);
  outtextxy(260,280,"Save");
  box(250,350,350,410,1,CYAN);
  outtextxy(260,380,"Load");
  settextstyle(1,0,7);
  outtextxy(130,45,"BATTLESHIP");
  settextstyle(0,0,0);
}


void mueve(int M[10][10],int G[10][10],int MCPU[10][10], int GCPU[10][10])
{ int i=1;
  char tecla;

  portada();
  guardar(M,G, MCPU, GCPU);
  cargar(M,G, MCPU, GCPU);
  menu();

  do{
     switch(i)
     {case 1: box(250,150,350,210,1,MAGENTA);
	      outtextxy(260,180,"Fight");
	      break;

      case 2: box(250,250,350,310,1,MAGENTA);
	      outtextxy(260,280,"Save");
	      break;

      case 3: box(250,350,350,410,1,MAGENTA);
	      outtextxy(260,380,"Load");
	      break;

      }

    tecla=getch();

	 switch(i)
     {
      case 1: box(250,150,350,210,1,CYAN);
	      outtextxy(260,180,"Fight");
	      break;

      case 2: box(250,250,350,310,1,CYAN);
	      outtextxy(260,280,"Save");
	      break;

      case 3: box(250,350,350,410,1,CYAN);
	      outtextxy(260,380,"Load");
	      break;


      }


    switch(tecla)
    {
     case 0: tecla=getch();
	     switch(tecla)
	     { case 72: i--; break;
	       case 80: i++; break;
	     }

	     if (i>4) i=1;
	     if (i<1) i=4;

	     break; //fin flecha

     case 13: switch(i)
	      {
	       case 1: juega(M,MCPU); break;
	       case 2: guardar(M,G, MCPU, GCPU); break;
	       case 3: cargar(M,G, MCPU, GCPU); break;
	       case 4: tecla=27; break;

	      }

	      if (i!=3 ) menu();

	      break;


    }

    }while(tecla != 27);

getch();


}



void main()
{
int M[10][10];
int MCPU[10][10];
int G[10][10];
int GCPU[10][10];
  inicializa();
  mueve(M,G, MCPU,GCPU);
  asigna(M,MCPU);
  asignaCPU(M,MCPU);
  randomize();



}

