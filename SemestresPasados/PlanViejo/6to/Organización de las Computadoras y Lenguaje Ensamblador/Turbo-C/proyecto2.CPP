#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>


void inicializa()
{ int gm, gd=DETECT;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  }

void box(int x1, int y1, int x2, int y2, int relleno, int color)      //ponerle relleno y color
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

void nuevo1(int M[10][13],int G[10][13], int &turno, int gturno, int r, int &p)
{
int i,j;
     for(i=0;i<10;i++)
	for(j=0;j<13;j++) M[i][j]=G[i][j];
	turno=gturno;
	//
	p=r;

}



void guardar1(int M[10][13],int G[10][13], int turno, int &gturno, int &r, int p)
{
	int i,j;
	for(i=0;i<10;i++)
	for(j=0;j<13;j++) G[i][j]= M[i][j];
	gturno=turno;
	//
	r=p;
}

int validar(int x1, int y1, int x2, int y2,int M[10][13])
{
 int b=0;
  if(x1==1 && y1==1 && x2==7 && y2==1) {M[y1][x1]=1;
					M[y1][x1+1]=1;
					M[y1][x1+2]=1;
					M[y1][x1+3]=1;
					M[y1][x1+4]=1;
					M[y1][x1+5]=1;
					M[y1][x1+6]=1;

					b=1;
					}
  if(x1==7 && y1==1 && x2==1 && y2==1) {M[y1][x1]=1;
					M[y1][x1-1]=1;
					M[y1][x1-2]=1;
					M[y1][x1-3]=1;
					M[y1][x1-4]=1;
					M[y1][x1-5]=1;
					M[y1][x1-6]=1;

					b=1;
					}
    //LOBO
  if(x1==11 && y1==3 && x2==11 && y2==6){ M[y1][x1]=1;
					M[y1+1][x1]=1;
					M[y1+2][x1]=1;
					M[y1+3][x1]=1;

					b=1;
					}
  if(x1==11 && y1==6 && x2==11 && y2==3){ M[y1][x1]=1;
					M[y1-1][x1]=1;
					M[y1-2][x1]=1;
					M[y1-3][x1]=1;
					b=1;
					}
    //CAIMAN
  if(x1==1 && y1==0 && x2==1 && y2==5){ M[y1][x1]=1;
					M[y1+1][x1]=1;
					M[y1+2][x1]=1;
					M[y1+3][x1]=1;
					M[y1+4][x1]=1;
					M[y1+5][x1]=1;
					b=1;
					}
  if(x1==1 && y1==5 && x2==1 && y2==0){ M[y1][x1]=1;
					M[y1-1][x1]=1;
					M[y1-2][x1]=1;
					M[y1-3][x1]=1;
					M[y1-4][x1]=1;
					M[y1-5][x1]=1;
					b=1;
					}
    //PERRO
  if(x1==0 && y1==9 && x2==4 && y2==9){ M[y1][x1]=1;
					M[y1][x1+1]=1;
					M[y1][x1+2]=1;
					M[y1][x1+3]=1;
					M[y1][x1+4]=1;
					b=1;
					}
  if(x1==4 && y1==9 && x2==0 && y2==9){ M[y1][x1]=1;
					M[y1][x1-1]=1;
					M[y1][x1-2]=1;
					M[y1][x1-3]=1;
					M[y1][x1-4]=1;
					b=1;
					}
   //MURCIELAGO
  if(x1==2 && y1==6 && x2==11 && y2==6){ M[y1][x1]=1;
					M[y1][x1+1]=1;
					M[y1][x1+2]=1;
					M[y1][x1+3]=1;
					M[y1][x1+4]=1;
					M[y1][x1+5]=1;
					M[y1][x1+6]=1;
					M[y1][x1+7]=1;
					M[y1][x1+8]=1;
					M[y1][x1+9]=1;
					b=1;
					}
  if(x1==11 && y1==6 && x2==2 && y2==6){ M[y1][x1]=1;
					M[y1][x1-1]=1;
					M[y1][x1-2]=1;
					M[y1][x1-3]=1;
					M[y1][x1-4]=1;
					M[y1][x1-5]=1;
					M[y1][x1-6]=1;
					M[y1][x1-7]=1;
					M[y1][x1-8]=1;
					M[y1][x1-9]=1;
					b=1;
				      }
  //JAGUAR
  if(x1==5 && y1==5 && x2==10 && y2==0){ M[y1][x1]=1;
					M[y1-1][x1+1]=1;
					M[y1-2][x1+2]=1;
					M[y1-3][x1+3]=1;
					M[y1-4][x1+4]=1;
					M[y1-5][x1+5]=1;
					b=1;
					}
  if(x1==10 && y1==0 && x2==5 && y2==5){ M[y1][x1]=1;
					M[y1+1][x1-1]=1;
					M[y1+2][x1-2]=1;
					M[y1+3][x1-3]=1;
					M[y1+4][x1-4]=1;
					M[y1+5][x1-5]=1;
					b=1;
					}
  //COCODRILO
  if(x1==4 && y1==1 && x2==4 && y2==9) { M[y1][x1]=1;
					M[y1+1][x1]=1;
					M[y1+2][x1]=1;
					M[y1+3][x1]=1;
					M[y1+4][x1]=1;
					M[y1+5][x1]=1;
					M[y1+6][x1]=1;
					M[y1+7][x1]=1;
					M[y1+8][x1]=1;
					b=1;
					}
  if(x1==4 && y1==9 && x2==4 && y2==1) { M[y1][x1]=1;
					M[y1-1][x1]=1;
					M[y1-2][x1]=1;
					M[y1-3][x1]=1;
					M[y1-4][x1]=1;
					M[y1-5][x1]=1;
					M[y1-6][x1]=1;
					M[y1-7][x1]=1;
					M[y1-8][x1]=1;
					b=1;
					}
   //Elefante
  if(x1==3 && y1==8 && x2==10 && y2==8) { M[y1][x1]=1;
					M[y1][x1+1]=1;
					M[y1][x1+2]=1;
					M[y1][x1+3]=1;
					M[y1][x1+4]=1;
					M[y1][x1+5]=1;
					M[y1][x1+6]=1;
					M[y1][x1+7]=1;
					b=1;
					}
  if(x1==10 && y1==8 && x2==3 && y2==8) { M[y1][x1]=1;
					M[y1][x1-1]=1;
					M[y1][x1-2]=1;
					M[y1][x1-3]=1;
					M[y1][x1-4]=1;
					M[y1][x1-5]=1;
					M[y1][x1-6]=1;
					M[y1][x1-7]=1;
					b=1;
					}

  if(x1==7 && y1==2 && x2==12 && y2==7){ M[y1][x1]=1;
					M[y1+1][x1+1]=1;
					M[y1+2][x1+2]=1;
					M[y1+3][x1+3]=1;
					M[y1+4][x1+4]=1;
					M[y1+5][x1+5]=1;
					b=1;
					}

  if(x1==12 && y1==7 && x2==7 && y2==2){ M[y1][x1]=1;
					M[y1-1][x1-1]=1;
					M[y1-2][x1-2]=1;
					M[y1-3][x1-3]=1;
					M[y1-4][x1-4]=1;
					M[y1-5][x1-5]=1;
					b=1;
					}
 return(b);
 }


void animales(int M[10][13])
{
  int i,j;
  for(i=0; i<10; i++)
  for(j=0; j<13; j++) M[i][j]=0;

 }

 void pintamatriz(int M[10][13])
{
  int i,j;

  setcolor(WHITE);
  for(i=0; i<10;i++)
  for(j=0; j<13;j++)
  {
    if( M[i][j]==0 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
      }
    if( M[i][j]==1 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,MAGENTA);
      }


      }
}

void asignasopa(char N[10][13])
{
 clearviewport();
  int i,j;

  char N2[10][13]={'A','C','C','G','H','Y','R','H','S','K','R','E','A',
		 'D','A','L','A','C','R','A','N','T','A','Q','P','R',
		 'G','I','I','B','O','L','S','H','U','E','N','A','Q',
		 'T','M','F','L','C','J','N','G','A','M','W','L','C',
		 'Y','A','B','D','O','S','A','R','O','L','N','O','K',
		 'P','N','F','J','D','J','N','M','C','M','C','B','W',
		 'J','K','M','U','R','C','I','E','L','A','G','O','N',
		 'Y','E','N','D','I','F','J','E','Y','S','V','D','N',
		 'H','D','K','E','L','E','F','A','N','T','E','C','L',
		 'P','E','R','R','O','L','F','K','S','U','M','E','N',};

 for(i=0; i<10; i++)
  for(j=0; j<13; j++) N[i][j]=N2[i][j];
}

void pintamatris(char N[10][13])
{
  int i,j;

  char cad[2];

  for(i=0; i<10;i++)
  for(j=0; j<13;j++)
  {
    cad[0]= N[i][j];
    cad[1]='\x0';
    outtextxy(165+j*20,125+i*20,cad);
      }

      }
void jugar(char N[10][13],int M[10][13], int G[10][13], int turno, int gturno, int r, int p)
{
  int i,j,enter=0,x1,y1,x2,y2;
  p=0;

  char *cadena;
  char cad[2];
   char tecla;
   i=5; j=5;

   box(440,150,570,200,1,BLUE);
   outtextxy(460,155,"Oprime 'A'");
   outtextxy(460,165,"para ABRIR");

   box(440,220,570,265,1,BLUE);
   outtextxy(460,225,"Oprime 'G'");
   outtextxy(460,235,"para GUARDAR");

      do{
	  setcolor(MAGENTA);

	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	     tecla=getch();

	  setcolor(WHITE);
	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	switch(tecla)
	{ case 0 : tecla=getch();
		   switch(tecla)
		   { case 75 : j--;break;
		     case 77 : j++;break;
		     case 72 : i--;break;
		     case 80 : i++;break;
		   }

		  if(i>9)i=0; if(i<0)i=9;
		  if(j>12)j=0; if(j<0)j=12;
	   break ;//fin cero

	   case 13:


	       if(enter==1){x2=j;
			    y2=i;

			    if (validar(x1,y1,x2,y2,M)==0 )
				  {
				   box(90,380,140,430,1,RED);
				   p=p-100;
				   gcvt(p,4,cadena);
				   outtextxy(105,400,cadena);
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
				   cad[0]= N[i][j];
				   cad[1]='\x0';
				   outtextxy(165+j*20,125+i*20,cad);
				  }
			      else{
				   box(90,380,140,430,1,RED);
				   p=p+100;
				   gcvt(p,4,cadena);
				   outtextxy(105,400,cadena);

				 }
			    enter++;

			 }

	       if(enter==0){x1=j;
				   y1=i;
				  // M[i][j]=1;
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLUE);
				    cad[0]= N[i][j];
			     cad[1]='\x0';
				    outtextxy(165+j*20,125+i*20,cad);

				   enter++;
				   }
		if(enter==2){  // if(x2 && y2)
				   pintamatriz(M);
				   pintamatris(N);
				   enter=0;

				     }
		       break;
       //PRUEBA
	      case 'a':
	      case 'A': nuevo1(M,G,turno,gturno,r,p);
			pintamatriz(M);
			pintamatris(N);

			box(90,380,140,430,1,RED);
			gcvt(p,4,cadena);
			outtextxy(105,400,cadena);

			break;

	      case 'g':
	      case 'G': guardar1(M,G,turno,gturno,r,p);
			break;
	       } //fin de tecla

}  while(tecla!=27);
}


void nuevo2(int A[15][20],int S[15][20], int &turno, int gturno, int r, int &p)
{
int i,j;
     for(i=0;i<15;i++)
	for(j=0;j<20;j++) A[i][j]=S[i][j];
	turno=gturno;

	p=r;
}


void guardar2(int A[15][20],int S[15][20], int turno, int &gturno, int &r, int p)
{
	int i,j;
	for(i=0;i<15;i++)
	for(j=0;j<20;j++) S[i][j]=A[i][j];
	gturno=turno;

	r=p;
}



int valida(int x1, int y1, int x2, int y2,int A[15][20])
{
  int b=0;
 //SILVANA
  if(x1==6 && y1==5 && x2==12 && y2==5){ A[y1][x1]=1;
					A[y1][x1+1]=1;
					A[y1][x1+2]=1;
					A[y1][x1+3]=1;
					A[y1][x1+4]=1;
					A[y1][x1+5]=1;
					A[y1][x1+6]=1;
					b=1;
					}
  if(x1==12 && y1==5 && x2==6 && y2==5){ A[y1][x1]=1;
					A[y1][x1-1]=1;
					A[y1][x1-2]=1;
					A[y1][x1-3]=1;
					A[y1][x1-4]=1;
					A[y1][x1-5]=1;
					A[y1][x1-6]=1;
					b=1;
					}
    //BRUNO
  if(x1==7 && y1==7 && x2==11 && y2==7){ A[y1][x1]=1;
					A[y1][x1+1]=1;
					A[y1][x1+2]=1;
					A[y1][x1+3]=1;
					A[y1][x1+4]=1;
					b=1;
					}
  if(x1==11 && y1==7 && x2==7 && y2==7){ A[y1][x1]=1;
					A[y1][x1-1]=1;
					A[y1][x1-2]=1;
					A[y1][x1-3]=1;
					A[y1][x1-4]=1;
					b=1;
					}
    //BLANCA
  if(x1==7 && y1==7 && x2==12 && y2==12){ A[y1][x1]=1;
					A[y1+1][x1+1]=1;
					A[y1+2][x1+2]=1;
					A[y1+3][x1+3]=1;
					A[y1+4][x1+4]=1;
					A[y1+5][x1+5]=1;
					b=1;
					}
  if(x1==12 && y1==12 && x2==7 && y2==7){ A[y1][x1]=1;
					A[y1-1][x1-1]=1;
					A[y1-2][x1-2]=1;
					A[y1-3][x1-3]=1;
					A[y1-4][x1-4]=1;
					A[y1-5][x1-5]=1;
					b=1;
					}
    //CAMILA
  if(x1==2 && y1==11 && x2==7 && y2==11){ A[y1][x1]=1;
					A[y1][x1+1]=1;
					A[y1][x1+2]=1;
					A[y1][x1+3]=1;
					A[y1][x1+4]=1;
					A[y1][x1+5]=1;
					b=1;
					}
  if(x1==7 && y1==11 && x2==2 && y2==11){ A[y1][x1]=1;
					A[y1][x1-1]=1;
					A[y1][x1-2]=1;
					A[y1][x1-3]=1;
					A[y1][x1-4]=1;
					A[y1][x1-5]=1;
					b=1;
					}
   //ARIANA
  if(x1==17 && y1==0 && x2==12 && y2==5){ A[y1][x1]=1;
					A[y1+1][x1-1]=1;
					A[y1+2][x1-2]=1;
					A[y1+3][x1-3]=1;
					A[y1+4][x1-4]=1;
					A[y1+5][x1-5]=1;
					b=1;
				      }
  if(x1==12 && y1==5 && x2==17 && y2==0){ A[y1][x1]=1;
					A[y1-1][x1+1]=1;
					A[y1-2][x1+2]=1;
					A[y1-3][x1+3]=1;
					A[y1-4][x1+4]=1;
					A[y1-5][x1+5]=1;
					b=1;
				      }
  //ESTEBAN
  if(x1==6 && y1==4 && x2==6 && y2==10){ A[y1][x1]=1;
					A[y1+1][x1]=1;
					A[y1+2][x1]=1;
					A[y1+3][x1]=1;
					A[y1+4][x1]=1;
					A[y1+5][x1]=1;
					A[y1+6][x1]=1;
					b=1;
					}
  if(x1==6 && y1==10 && x2==6 && y2==4){ A[y1][x1]=1;
					A[y1-1][x1]=1;
					A[y1-2][x1]=1;
					A[y1-3][x1]=1;
					A[y1-4][x1]=1;
					A[y1-5][x1]=1;
					A[y1-6][x1]=1;
					b=1;
					}
  //RICARDO
  if(x1==9 && y1==12 && x2==15 && y2==12) { A[y1][x1]=1;
					A[y1][x1+1]=1;
					A[y1][x1+2]=1;
					A[y1][x1+3]=1;
					A[y1][x1+4]=1;
					A[y1][x1+5]=1;
					A[y1][x1+6]=1;
					b=1;
					}
  if(x1==15 && y1==12 && x2==9 && y2==12) { A[y1][x1]=1;
					A[y1][x1-1]=1;
					A[y1][x1-2]=1;
					A[y1][x1-3]=1;
					A[y1][x1-4]=1;
					A[y1][x1-5]=1;
					A[y1][x1-6]=1;
					b=1;
					}
   //XIMENA
  if(x1==14 && y1==8 && x2==19 && y2==13) { A[y1][x1]=1;
					A[y1+1][x1+1]=1;
					A[y1+2][x1+2]=1;
					A[y1+3][x1+3]=1;
					A[y1+4][x1+4]=1;
					A[y1+5][x1+5]=1;
					b=1;
					}
  if(x1==19 && y1==13 && x2==14 && y2==8) { A[y1][x1]=1;
					A[y1-1][x1-1]=1;
					A[y1-2][x1-2]=1;
					A[y1-3][x1-3]=1;
					A[y1-4][x1-4]=1;
					A[y1-5][x1-5]=1;
					b=1;
					}
  //GABINO
  if(x1==7 && y1==1 && x2==12 && y2==6){ A[y1][x1]=1;
					A[y1+1][x1+1]=1;
					A[y1+2][x1+2]=1;
					A[y1+3][x1+3]=1;
					A[y1+4][x1+4]=1;
					A[y1+5][x1+5]=1;
					b=1;
					}
  if(x1==12 && y1==6 && x2==7 && y2==1){ A[y1][x1]=1;
					A[y1-1][x1-1]=1;
					A[y1-2][x1-2]=1;
					A[y1-3][x1-3]=1;
					A[y1-4][x1-4]=1;
					A[y1-5][x1-5]=1;
					b=1;
					}
   //SAMUEL
  if(x1==6 && y1==5 && x2==1 && y2==10){ A[y1][x1]=1;
					A[y1+1][x1-1]=1;
					A[y1+2][x1-2]=1;
					A[y1+3][x1-3]=1;
					A[y1+4][x1-4]=1;
					A[y1+5][x1-5]=1;
					b=1;
				      }
  if(x1==1 && y1==10 && x2==6 && y2==5){ A[y1][x1]=1;
					A[y1-1][x1+1]=1;
					A[y1-2][x1+2]=1;
					A[y1-3][x1+3]=1;
					A[y1-4][x1+4]=1;
					A[y1-5][x1+5]=1;
					b=1;
				      }
  //MARIBEL
  if(x1==1 && y1==2 && x2==1 && y2==8){ A[y1][x1]=1;
					A[y1+1][x1]=1;
					A[y1+2][x1]=1;
					A[y1+3][x1]=1;
					A[y1+4][x1]=1;
					A[y1+5][x1]=1;
					A[y1+6][x1]=1;
					b=1;
					}
  if(x1==1 && y1==8 && x2==1 && y2==2){ A[y1][x1]=1;
					A[y1-1][x1]=1;
					A[y1-2][x1]=1;
					A[y1-3][x1]=1;
					A[y1-4][x1]=1;
					A[y1-5][x1]=1;
					A[y1-6][x1]=1;
					b=1;
					}
  //MARCO
  if(x1==19 && y1==3 && x2==15 && y2==7) { A[y1][x1]=1;
					A[y1+1][x1-1]=1;
					A[y1+2][x1-2]=1;
					A[y1+3][x1-3]=1;
					A[y1+4][x1-4]=1;
					b=1;
					}
  if(x1==15 && y1==7 && x2==19 && y2==3) { A[y1][x1]=1;
					A[y1-1][x1+1]=1;
					A[y1-2][x1+2]=1;
					A[y1-3][x1+3]=1;
					A[y1-4][x1+4]=1;
					b=1;
					}
   //ALONDRA
  if(x1==17 && y1==0 && x2==17 && y2==6) { A[y1][x1]=1;
					A[y1+1][x1]=1;
					A[y1+2][x1]=1;
					A[y1+3][x1]=1;
					A[y1+4][x1]=1;
					A[y1+5][x1]=1;
					A[y1+6][x1]=1;
					b=1;
					}
  if(x1==17 && y1==6 && x2==17 && y2==0) { A[y1][x1]=1;
					A[y1-1][x1]=1;
					A[y1-2][x1]=1;
					A[y1-3][x1]=1;
					A[y1-4][x1]=1;
					A[y1-5][x1]=1;
					A[y1-6][x1]=1;
					b=1;
					}
  //MIGUEL
  if(x1==15 && y1==1 && x2==15 && y2==6){ A[y1][x1]=1;
					A[y1+1][x1]=1;
					A[y1+2][x1]=1;
					A[y1+3][x1]=1;
					A[y1+4][x1]=1;
					A[y1+5][x1]=1;
					b=1;
					}
  if(x1==15 && y1==6 && x2==15 && y2==1){ A[y1][x1]=1;
					A[y1-1][x1]=1;
					A[y1-2][x1]=1;
					A[y1-3][x1]=1;
					A[y1-4][x1]=1;
					A[y1-5][x1]=1;
					b=1;
					}
  return(b);
  }



void nombres(int A[15][20])
{
  int i,j;
  for(i=0; i<15; i++)
  for(j=0; j<20; j++) A[i][j]=0;

 }

 void pintanombresc(int A[15][20])
{
  int i,j;

  setcolor(WHITE);
  for(i=0; i<15;i++)
  for(j=0; j<20;j++)
  {
    if( A[i][j]==0 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
      }
    if( A[i][j]==1 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,MAGENTA);
      }

      }
}

void asignanombres(char B[15][20])
{
  int i,j;

  char B2[15][20]={'A','B','C','G','H','Y','R','H','S','L','K','E','I','O','E','J','R','A','I','B',
		 'D','F','R','W','U','N','S','G','T','N','Q','P','R','O','P','M','R','L','E','K',
		 'G','M','I','B','H','L','S','I','A','E','N','A','Q','T','Y','I','D','O','E','T',
		 'T','A','F','L','K','J','N','S','U','B','W','Y','C','J','A','G','S','N','F','M',
		 'Y','R','B','D','L','S','E','R','O','T','I','S','K','N','U','U','S','D','A','F',
		 'P','I','F','J','U','E','S','I','L','V','A','N','A','R','W','E','K','R','U','E',
		 'J','B','A','S','D','A','T','B','C','Y','T','W','O','D','L','L','C','A','E','B',
		 'Y','E','N','D','M','F','E','B','R','U','N','O','M','C','L','O','D','H','D','Y',
		 'H','L','K','U','U','I','B','E','L','A','M','C','L','F','X','J','D','Y','D','B',
		 'T','E','E','M','D','L','A','K','S','A','M','E','N','D','O','I','S','U','B','N',
		 'Y','L','N','E','K','D','N','D','H','F','N','D','F','I','S','L','M','O','S','T',
		 'A','B','C','A','M','I','L','A','S','L','K','C','I','O','E','N','M','E','G','K',
		 'D','F','R','W','U','N','S','L','T','R','I','C','A','R','D','O','A','O','N','F',
		 'G','H','I','B','H','L','S','I','O','E','N','A','Q','T','Y','Y','E','B','N','A',
		 'T','G','F','L','K','J','N','S','U','M','W','Y','C','J','A','T','S','Y','U','E'};

 for(i=0; i<15; i++)
  for(j=0; j<20; j++) B[i][j]=B2[i][j];
}

void pintanombres(char B[15][20])
{
  int i,j;

  char cad[2];

  for(i=0; i<15;i++)
  for(j=0; j<20;j++)
  {
    cad[0]= B[i][j];
    cad[1]='\x0';
    outtextxy(165+j*20,125+i*20,cad);
      }
}

void jugar2(char B[15][20],int A[15][20], int S[15][20], int turno, int gturno, int r, int p)
{
  int i,j,enter=0,x1,y1,x2,y2;
  p=0;

  char *cadena;
  char cad[2];
   char tecla;
   i=5; j=5;


   box(250,425,380,475,1,BLUE);
   outtextxy(260,435,"Oprime 'A'");
   outtextxy(260,445,"para ABRIR");

   box(410,425,540,475,1,BLUE);
   outtextxy(420,435,"Oprime 'G'");
   outtextxy(420,445,"para GUARDAR");



      do{
	  setcolor(MAGENTA);

	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	     tecla=getch();

	  setcolor(WHITE);
	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	switch(tecla)
	{ case 0 : tecla=getch();
		   switch(tecla)
		   { case 75 : j--;break;
		     case 77 : j++;break;
		     case 72 : i--;break;
		     case 80 : i++;break;
		   }

		  if(i>14)i=0; if(i<0)i=14;
		  if(j>19)j=0; if(j<0)j=19;
	   break ;//fin cero

	   case 13:
	       if(enter==1){x2=j;
			    y2=i;
			  if (valida(x1,y1,x2,y2,A)==0 )
				  {
				   box(90,380,140,430,1,RED);
				   p=p-100;
				   gcvt(p,4,cadena);
				   outtextxy(105,400,cadena);
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
				   cad[0]= B[i][j];
				   cad[1]='\x0';
				   outtextxy(165+j*20,125+i*20,cad);
				  }
			      else{
				   box(90,380,140,430,1,RED);
				   p=p+100;
				   gcvt(p,4,cadena);
				   outtextxy(105,400,cadena);

				 }
			    enter++;

			 }
	       if(enter==0){x1=j;
				   y1=i;
				  // M[i][j]=1;
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLUE);
				    cad[0]= B[i][j];
			     cad[1]='\x0';
				    outtextxy(165+j*20,125+i*20,cad);
				   enter++;
				   }
		if(enter==2){
				   pintanombresc(A);
				   pintanombres(B);
				   enter=0;
				     }
	    //   if(i<=6 && j=1)
	      // pintamatriz(M);
	      // pintamatris(N,M);
	      // outtextxy(160+j*20,120+i*20,BLUE);
		       break;
	      case 'a':
	      case 'A': nuevo2(A,S,turno,gturno,r,p);
			pintanombresc(A);
			pintanombres(B);

			box(90,380,140,430,1,RED);
			gcvt(p,4,cadena);
			outtextxy(105,400,cadena);
			break;

	      case 'g':
	      case 'G': guardar2(A,S,turno,gturno,r,p);
			break;
									       // outtextxy(129+j*17,49+i*17,"F"
	       } //fin de tecla

}  while(tecla!=27);

}

void nuevo3(int C[15][20],int G3[15][20], int &turno, int gturno, int r, int &p)
{
int i,j;
     for(i=0;i<15;i++)
	for(j=0;j<20;j++) C[i][j]=G3[i][j];
	turno=gturno;
	p=r;
}


void guardar3(int C[15][20],int G3[15][20], int turno, int & gturno, int &r, int p)
{
	int i,j;
	for(i=0;i<15;i++)
	for(j=0;j<20;j++) G3[i][j]=C[i][j];
	gturno=turno;
	r=p;
}




int valido(int x1, int y1, int x2, int y2,int C[15][20])
{  int b=0;

 //MEXICO
  if(x1==11 && y1==5 && x2==16 && y2==5){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					C[y1][x1+5]=1;
					b=1;
					}
  if(x1==16 && y1==5 && x2==11 && y2==5){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					C[y1][x1-5]=1;
					b=1;
					}
    //REINO UNIDO
  if(x1==6 && y1==2 && x2==6 && y2==11){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					C[y1+6][x1]=1;
					C[y1+7][x1]=1;
					C[y1+8][x1]=1;
					C[y1+9][x1]=1;
					b=1;
					}
  if(x1==6 && y1==11 && x2==6 && y2==2){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					C[y1-6][x1]=1;
					C[y1-7][x1]=1;
					C[y1-8][x1]=1;
					C[y1-9][x1]=1;
					b=1;
					}
    //CROACIA
  if(x1==11 && y1==1 && x2==17 && y2==7){ C[y1][x1]=1;
					C[y1+1][x1+1]=1;
					C[y1+2][x1+2]=1;
					C[y1+3][x1+3]=1;
					C[y1+4][x1+4]=1;
					C[y1+5][x1+5]=1;
					C[y1+6][x1+6]=1;
					b=1;
					}
  if(x1==17 && y1==7 && x2==11 && y2==1){ C[y1][x1]=1;
					C[y1-1][x1-1]=1;
					C[y1-2][x1-2]=1;
					C[y1-3][x1-3]=1;
					C[y1-4][x1-4]=1;
					C[y1-5][x1-5]=1;
					C[y1-6][x1-6]=1;
					b=1;
					}
    //PUERTO RICO
  if(x1==12 && y1==3 && x2==12 && y2==12){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					C[y1+6][x1]=1;
					C[y1+7][x1]=1;
					C[y1+8][x1]=1;
					C[y1+9][x1]=1;
					b=1;
					}
  if(x1==12 && y1==12 && x2==12 && y2==3){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					C[y1-6][x1]=1;
					C[y1-7][x1]=1;
					C[y1-8][x1]=1;
					C[y1-9][x1]=1;
					b=1;
					}
   //RUSIA
  if(x1==11 && y1==13 && x2==15 && y2==13){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					b=1;
				      }
  if(x1==15 && y1==13 && x2==11 && y2==13){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					b=1;
				      }
  //BRAZIL
  if(x1==17 && y1==5 && x2==17 && y2==10){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					b=1;
					}
  if(x1==17 && y1==10 && x2==17 && y2==5){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					b=1;
					}
  //ARGENTINA
  if(x1==4 && y1==4 && x2==4 && y2==12) { C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					C[y1+6][x1]=1;
					C[y1+7][x1]=1;
					C[y1+8][x1]=1;
					b=1;
					}
  if(x1==4 && y1==12 && x2==4 && y2==4) { C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					C[y1-6][x1]=1;
					C[y1-7][x1]=1;
					C[y1-8][x1]=1;
					b=1;
					}
   //ESPA¥A
  if(x1==0 && y1==7 && x2==5 && y2==12) { C[y1][x1]=1;
					C[y1+1][x1+1]=1;
					C[y1+2][x1+2]=1;
					C[y1+3][x1+3]=1;
					C[y1+4][x1+4]=1;
					C[y1+5][x1+5]=1;
					b=1;
					}
  if(x1==5 && y1==12 && x2==0 && y2==7) { C[y1][x1]=1;
					C[y1-1][x1-1]=1;
					C[y1-2][x1-2]=1;
					C[y1-3][x1-3]=1;
					C[y1-4][x1-4]=1;
					C[y1-5][x1-5]=1;
					b=1;
					}
  //FRANCIA
  if(x1==5 && y1==2 && x2==11 && y2==2){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					C[y1][x1+5]=1;
					C[y1][x1+6]=1;
					b=1;
					}
  if(x1==11 && y1==2 && x2==5 && y2==2){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					C[y1][x1-5]=1;
					C[y1][x1-6]=1;
					b=1;
					}
   //CHILE
  if(x1==15 && y1==9 && x2==19 && y2==9){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
				      b=1;
				      }
  if(x1==19 && y1==9 && x2==15 && y2==9){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
				      b=1;
				      }
  //MADRID
  if(x1==10 && y1==6 && x2==10 && y2==11){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					b=1;
					}
  if(x1==10 && y1==11 && x2==10 && y2==6){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					b=1;
					}
  //COLOMBIA
  if(x1==11 && y1==1 && x2==18 && y2==1) { C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					C[y1][x1+5]=1;
					C[y1][x1+6]=1;
					C[y1][x1+7]=1;
					b=1;
					}
  if(x1==18 && y1==1 && x2==11 && y2==1) { C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					C[y1][x1-5]=1;
					C[y1][x1-6]=1;
					C[y1][x1-7]=1;
					b=1;
					}
   //CHIPRE
  if(x1==0 && y1==2 && x2==0 && y2==7) { C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					b=1;
					}
  if(x1==0 && y1==7 && x2==0 && y2==2) { C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					b=1;
					}
  //ESTADOS UNIDOS
  if(x1==1 && y1==1 && x2==13 && y2==13){ C[y1][x1]=1;
					C[y1+1][x1+1]=1;
					C[y1+2][x1+2]=1;
					C[y1+3][x1+3]=1;
					C[y1+4][x1+4]=1;
					C[y1+5][x1+5]=1;
					C[y1+6][x1+6]=1;
					C[y1+7][x1+7]=1;
					C[y1+8][x1+8]=1;
					C[y1+9][x1+9]=1;
					C[y1+10][x1+10]=1;
					C[y1+11][x1+11]=1;
					C[y1+12][x1+12]=1;
					b=1;
					}
  if(x1==13 && y1==13 && x2==1 && y2==1){ C[y1][x1]=1;
					C[y1-1][x1-1]=1;
					C[y1-2][x1-2]=1;
					C[y1-3][x1-3]=1;
					C[y1-4][x1-4]=1;
					C[y1-5][x1-5]=1;
					C[y1-6][x1-6]=1;
					C[y1-7][x1-7]=1;
					C[y1-8][x1-8]=1;
					C[y1-9][x1-9]=1;
					C[y1-10][x1-10]=1;
					C[y1-11][x1-11]=1;
					C[y1-12][x1-12]=1;
					b=1;
					}
   //DINAMARCA
  if(x1==0 && y1==14 && x2==8 && y2==14){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					C[y1][x1+5]=1;
					C[y1][x1+6]=1;
					C[y1][x1+7]=1;
					C[y1][x1+8]=1;
					b=1;
					}
  if(x1==8 && y1==14 && x2==0 && y2==14){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					C[y1][x1-5]=1;
					C[y1][x1-6]=1;
					C[y1][x1-7]=1;
					C[y1][x1-8]=1;
					b=1;
					}
    //CANADA
  if(x1==8 && y1==9 && x2==8 && y2==14){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					b=1;
					}
  if(x1==8 && y1==14 && x2==8 && y2==9){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					b=1;
					}
    //GRECIA
  if(x1==3 && y1==0 && x2==8 && y2==0){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					C[y1][x1+5]=1;
					b=1;
					}
  if(x1==8 && y1==0 && x2==3 && y2==0){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					C[y1][x1-5]=1;
					b=1;
					}
    //ALEMANIA
  if(x1==10 && y1==14 && x2==17 && y2==14){ C[y1][x1]=1;
					C[y1][x1+1]=1;
					C[y1][x1+2]=1;
					C[y1][x1+3]=1;
					C[y1][x1+4]=1;
					C[y1][x1+5]=1;
					C[y1][x1+6]=1;
					C[y1][x1+7]=1;
					b=1;
					}
  if(x1==17 && y1==14 && x2==10 && y2==14){ C[y1][x1]=1;
					C[y1][x1-1]=1;
					C[y1][x1-2]=1;
					C[y1][x1-3]=1;
					C[y1][x1-4]=1;
					C[y1][x1-5]=1;
					C[y1][x1-6]=1;
					C[y1][x1-7]=1;
					b=1;
					}
   //HOLANDA
  if(x1==18 && y1==7 && x2==18 && y2==13){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					C[y1+6][x1]=1;
				      b=1;
				      }
  if(x1==18 && y1==13 && x2==18 && y2==7){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					C[y1-6][x1]=1;
				      b=1;
				      }
  //ITALIA
  if(x1==19 && y1==2 && x2==19 && y2==7){ C[y1][x1]=1;
					C[y1+1][x1]=1;
					C[y1+2][x1]=1;
					C[y1+3][x1]=1;
					C[y1+4][x1]=1;
					C[y1+5][x1]=1;
					b=1;
					}
  if(x1==19 && y1==7 && x2==19 && y2==2){ C[y1][x1]=1;
					C[y1-1][x1]=1;
					C[y1-2][x1]=1;
					C[y1-3][x1]=1;
					C[y1-4][x1]=1;
					C[y1-5][x1]=1;
					b=1;
					}

  return(b);
  }



void paises(int C[15][20])
{
  int i,j;
  for(i=0; i<15; i++)
  for(j=0; j<20; j++) C[i][j]=0;

 }

 void pintapaisesc(int C[15][20])
{
  int i,j;

  setcolor(WHITE);
  for(i=0; i<15;i++)
  for(j=0; j<20;j++)
  {
    if( C[i][j]==0 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
      }
    if( C[i][j]==1 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,MAGENTA);
      }


      }
}

void asignapaises(char D[15][20])
{
  int i,j;

  char D2[15][20]={'A','B','C','G','R','E','C','I','A','L','K','E','I','O','E','D','F','G','D','D',
		 'D','E','R','W','U','N','S','L','T','N','Q','C','O','L','O','M','B','I','A','A',
		 'C','H','S','B','H','F','R','A','N','C','I','A','R','T','Y','A','G','T','E','I',
		 'H','G','F','T','K','J','E','S','U','M','W','Y','P','O','A','A','W','Y','O','T',
		 'I','E','B','D','A','S','I','R','O','T','N','S','U','E','A','B','S','J','I','A',
		 'P','K','F','J','R','D','N','M','C','M','S','M','E','X','I','C','O','B','Z','L',
		 'R','K','A','S','G','F','O','B','C','M','M','W','R','D','L','Q','I','R','J','I',
		 'E','E','N','D','E','F','U','S','Y','S','A','D','T','C','L','L','W','A','H','A',
		 'H','S','K','F','N','I','N','E','U','A','D','C','O','F','J','K','R','Z','O','F',
		 'T','E','P','M','T','L','I','K','C','N','R','E','R','D','O','C','H','I','L','E',
		 'Y','E','N','A','I','D','D','D','A','F','I','D','I','I','S','X','V','L','A','U',
		 'A','B','C','G','N','Y','O','H','N','L','D','D','C','O','E','L','M','D','N','U',
		 'D','F','R','W','A','A','S','L','A','N','Q','P','O','O','P','Y','O','S','D','H',
		 'G','H','I','B','H','L','E','I','D','E','N','R','U','S','I','A','R','Y','A','S',
		 'D','I','N','A','M','A','R','C','A','M','A','L','E','M','A','N','I','A','F','O'};

 for(i=0; i<15; i++)
  for(j=0; j<20; j++) D[i][j]=D2[i][j];
}

void pintapaises(char D[15][20]) // int C[15][20])
{
  int i,j;

  char cad[2];

  for(i=0; i<15;i++)
  for(j=0; j<20;j++)
  {
    cad[0]= D[i][j];
    cad[1]='\x0';
    outtextxy(165+j*20,125+i*20,cad);
      }
}


void jugar3(char D[15][20],int C[15][20], int G2[15][20], int turno, int gturno, int r, int p)
{
  int i,j,enter=0,x1,y1,x2,y2;
  p=0;

  char *cadena;
  char cad[2];
   char tecla;
   i=5; j=5;


   box(250,425,380,475,1,BLUE);
   outtextxy(260,435,"Oprime 'A'");
   outtextxy(260,445,"para ABRIR");

   box(410,425,540,475,1,BLUE);
   outtextxy(420,435,"Oprime 'G'");
   outtextxy(420,445,"para GUARDAR");



      do{
	  setcolor(MAGENTA);

	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	     tecla=getch();

	  setcolor(WHITE);
	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	switch(tecla)
	{ case 0 : tecla=getch();
		   switch(tecla)
		   { case 75 : j--;break;
		     case 77 : j++;break;
		     case 72 : i--;break;
		     case 80 : i++;break;
		   }

		  if(i>14)i=0; if(i<0)i=14;
		  if(j>19)j=0; if(j<0)j=19;
	   break ;//fin cero


	    case 13:
	       if(enter==1){x2=j;
			    y2=i;
			  if (valido(x1,y1,x2,y2,C)==0 )
				  {
				   box(90,435,190,465,1,RED);
				   p=p-100;
				   gcvt(p,4,cadena);
				   outtextxy(100,445,cadena);
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
				   cad[0]= D[i][j];
				   cad[1]='\x0';
				   outtextxy(165+j*20,125+i*20,cad);
				  }
			      else{
				   box(90,435,190,465,1,RED);
				   p=p+100;
				   gcvt(p,4,cadena);
				   outtextxy(100,445,cadena);

				 }
			    enter++;


			 }
	       if(enter==0){x1=j;
				   y1=i;
				  // M[i][j]=1;
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLUE);
				    cad[0]= D[i][j];
			     cad[1]='\x0';
				    outtextxy(165+j*20,125+i*20,cad);
				   enter++;
				   }
		if(enter==2){
				   pintapaisesc(C);
				   pintapaises(D);
				   enter=0;
				   }
	    //   if(i<=6 && j=1)
	      // pintamatriz(M);
	      // pintamatris(N,M);
	      // outtextxy(160+j*20,120+i*20,BLUE);
		       break;


	      case 'a':
	      case 'A': nuevo3(C,G2,turno,gturno,r,p);
			pintapaisesc(C);
			pintapaises(D);

			box(90,435,190,465,1,RED);
			gcvt(p,4,cadena);
			outtextxy(100,445,cadena);

			break;

	      case 'g':
	      case 'G': guardar3(C,G2,turno,gturno,r,p);

			break;

									       // outtextxy(129+j*17,49+i*17,"F"
	       } //fin de tecla

}  while(tecla!=27);
}



void nuevo4(int E[15][15],int G4[15][15], int &turno, int gturno, int r, int &p)
{
int i,j;
     for(i=0;i<15;i++)
	for(j=0;j<15;j++) E[i][j]=G4[i][j];
	turno=gturno;
	p=r;
}


void guardar4(int E[15][15],int G4[15][15], int turno, int & gturno, int &r, int p)
{
	int i,j;
	for(i=0;i<15;i++)
	for(j=0;j<15;j++) G4[i][j]=E[i][j];
	gturno=turno;

	r=p;
}




int val(int x1, int y1, int x2, int y2,int E[15][15])
{ int b=0;
 //SILVANA
  if(x1==3 && y1==6 && x2==3 && y2==13){ E[y1][x1]=1;
					E[y1+1][x1]=1;
					E[y1+2][x1]=1;
					E[y1+3][x1]=1;
					E[y1+4][x1]=1;
					E[y1+5][x1]=1;
					E[y1+6][x1]=1;
					E[y1+7][x1]=1;
					b=1;
					}
  if(x1==3 && y1==13 && x2==3 && y2==6){ E[y1][x1]=1;
					E[y1-1][x1]=1;
					E[y1-2][x1]=1;
					E[y1-3][x1]=1;
					E[y1-4][x1]=1;
					E[y1-5][x1]=1;
					E[y1-6][x1]=1;
					E[y1-7][x1]=1;
					b=1;
					}
    //BRUNO
  if(x1==2 && y1==13 && x2==10 && y2==13){ E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					E[y1][x1+4]=1;
					E[y1][x1+5]=1;
					E[y1][x1+6]=1;
					E[y1][x1+7]=1;
					E[y1][x1+8]=1;
						b=1;
						}
  if(x1==10 && y1==13 && x2==2 && y2==13){ E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					E[y1][x1-4]=1;
					E[y1][x1-5]=1;
					E[y1][x1-6]=1;
					E[y1][x1-7]=1;
					E[y1][x1-8]=1;
						b=1;
						}
    //BLANCA
  if(x1==5 && y1==8 && x2==8 && y2==8){ E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					b=1;
					}
  if(x1==8 && y1==8 && x2==5 && y2==8){ E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					b=1;
					}
    //CAMILA
  if(x1==0 && y1==3 && x2==6 && y2==3){ E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					E[y1][x1+4]=1;
					E[y1][x1+5]=1;
					E[y1][x1+6]=1;
					b=1;
					}
  if(x1==6 && y1==3 && x2==0 && y2==3){ E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					E[y1][x1-4]=1;
					E[y1][x1-5]=1;
					E[y1][x1-6]=1;
					b=1;
					}
   //ARCANE
  if(x1==3 && y1==5 && x2==8 && y2==10){ E[y1][x1]=1;
					E[y1+1][x1+1]=1;
					E[y1+2][x1+2]=1;
					E[y1+3][x1+3]=1;
					E[y1+4][x1+4]=1;
					E[y1+5][x1+5]=1;
				      b=1;
				      }
  if(x1==8 && y1==10 && x2==3 && y2==5){ E[y1][x1]=1;
					E[y1-1][x1-1]=1;
					E[y1-2][x1-2]=1;
					E[y1-3][x1-3]=1;
					E[y1-4][x1-4]=1;
					E[y1-5][x1-5]=1;
				      b=1;
				      }
  //WANTON
  if(x1==2 && y1==10 && x2==7 && y2==10){ E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					E[y1][x1+4]=1;
					E[y1][x1+5]=1;
					b=1;
					}
  if(x1==7 && y1==10 && x2==2 && y2==10){ E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					E[y1][x1-4]=1;
					E[y1][x1-5]=1;
					b=1;
					}
  //DOWNFALL
  if(x1==7 && y1==1 && x2==14 && y2==1) { E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					E[y1][x1+4]=1;
					E[y1][x1+5]=1;
					E[y1][x1+6]=1;
					E[y1][x1+7]=1;
					b=1;
					}
  if(x1==14 && y1==1 && x2==7 && y2==1) { E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					E[y1][x1-4]=1;
					E[y1][x1-5]=1;
					E[y1][x1-6]=1;
					E[y1][x1-7]=1;
					b=1;
					}
   //MELLIFLUOS
  if(x1==4 && y1==2 && x2==14 && y2==12) { E[y1][x1]=1;
					E[y1+1][x1+1]=1;
					E[y1+2][x1+2]=1;
					E[y1+3][x1+3]=1;
					E[y1+4][x1+4]=1;
					E[y1+5][x1+5]=1;
					E[y1+6][x1+6]=1;
					E[y1+7][x1+7]=1;
					E[y1+8][x1+8]=1;
					E[y1+9][x1+9]=1;
					E[y1+10][x1+10]=1;
					b=1;
					}
  if(x1==14 && y1==12 && x2==4 && y2==2) { E[y1][x1]=1;
					E[y1-1][x1-1]=1;
					E[y1-2][x1-2]=1;
					E[y1-3][x1-3]=1;
					E[y1-4][x1-4]=1;
					E[y1-5][x1-5]=1;
					E[y1-6][x1-6]=1;
					E[y1-7][x1-7]=1;
					E[y1-8][x1-8]=1;
					E[y1-9][x1-9]=1;
					E[y1-10][x1-10]=1;
					b=1;
					}
  //FANCY
  if(x1==8 && y1==2 && x2==12 && y2==6){ E[y1][x1]=1;
					E[y1+1][x1+1]=1;
					E[y1+2][x1+2]=1;
					E[y1+3][x1+3]=1;
					E[y1+4][x1+4]=1;
					b=1;
					}
  if(x1==12 && y1==6 && x2==8 && y2==2){ E[y1][x1]=1;
					E[y1-1][x1-1]=1;
					E[y1-2][x1-2]=1;
					E[y1-3][x1-3]=1;
					E[y1-4][x1-4]=1;
					b=1;
					}
   //SERENDIPITY
  if(x1==2 && y1==6 && x2==12 && y2==6){ E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					E[y1][x1+4]=1;
					E[y1][x1+5]=1;
					E[y1][x1+6]=1;
					E[y1][x1+7]=1;
					E[y1][x1+8]=1;
					E[y1][x1+9]=1;
					E[y1][x1+10]=1;
					b=1;
				      }
  if(x1==12 && y1==6 && x2==2 && y2==6){ E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					E[y1][x1-4]=1;
					E[y1][x1-5]=1;
					E[y1][x1-6]=1;
					E[y1][x1-7]=1;
					E[y1][x1-8]=1;
					E[y1][x1-9]=1;
					E[y1][x1-10]=1;
				      b=1;
				      }
  //HA
  if(x1==1 && y1==2 && x2==1 && y2==8){ E[y1][x1]=1;
					E[y1+1][x1]=1;
					E[y1+2][x1]=1;
					E[y1+3][x1]=1;
					E[y1+4][x1]=1;
					E[y1+5][x1]=1;
					E[y1+6][x1]=1;
					b=1;
					}
  if(x1==1 && y1==8 && x2==1 && y2==2){ E[y1][x1]=1;
					E[y1-1][x1]=1;
					E[y1-2][x1]=1;
					E[y1-3][x1]=1;
					E[y1-4][x1]=1;
					E[y1-5][x1]=1;
					E[y1-6][x1]=1;
					b=1;
					}
  //MARCO
  if(x1==12 && y1==0 && x2==12 && y2==6) { E[y1][x1]=1;
					E[y1+1][x1]=1;
					E[y1+2][x1]=1;
					E[y1+3][x1]=1;
					E[y1+4][x1]=1;
					E[y1+5][x1]=1;
					E[y1+6][x1]=1;
					b=1;
					}
  if(x1==12 && y1==6 && x2==12 && y2==0) { E[y1][x1]=1;
					E[y1-1][x1]=1;
					E[y1-2][x1]=1;
					E[y1-3][x1]=1;
					E[y1-4][x1]=1;
					E[y1-5][x1]=1;
					E[y1-6][x1]=1;
					b=1;
					}
   //ALONDRA
  if(x1==10 && y1==8 && x2==13 && y2==8) { E[y1][x1]=1;
					E[y1][x1+1]=1;
					E[y1][x1+2]=1;
					E[y1][x1+3]=1;
					b=1;
					}
  if(x1==13 && y1==8 && x2==10 && y2==8) { E[y1][x1]=1;
					E[y1][x1-1]=1;
					E[y1][x1-2]=1;
					E[y1][x1-3]=1;
					b=1;
					}
  //HIRAETH
  if(x1==1 && y1==3 && x2==1 && y2==9){ E[y1][x1]=1;
					E[y1+1][x1]=1;
					E[y1+2][x1]=1;
					E[y1+3][x1]=1;
					E[y1+4][x1]=1;
					E[y1+5][x1]=1;
					E[y1+6][x1]=1;
					b=1;
					}
  if(x1==1 && y1==9 && x2==1 && y2==3){ E[y1][x1]=1;
					E[y1-1][x1]=1;
					E[y1-2][x1]=1;
					E[y1-3][x1]=1;
					E[y1-4][x1]=1;
					E[y1-5][x1]=1;
					E[y1-6][x1]=1;
					b=1;
					}
  //
  if(x1==9 && y1==7 && x2==9 && y2==12){ E[y1][x1]=1;
					E[y1+1][x1]=1;
					E[y1+2][x1]=1;
					E[y1+3][x1]=1;
					E[y1+4][x1]=1;
					E[y1+5][x1]=1;
					b=1;
					}
  if(x1==9 && y1==12 && x2==9 && y2==7){ E[y1][x1]=1;
					E[y1-1][x1]=1;
					E[y1-2][x1]=1;
					E[y1-3][x1]=1;
					E[y1-4][x1]=1;
					E[y1-5][x1]=1;
					b=1;
					}
  return(b);
  }

void ingles(int E[15][15])
{
  int i,j;
  for(i=0; i<15; i++)
  for(j=0; j<15; j++) E[i][j]=0;

 }

 void pintainglesc(int E[15][15])
{
  int i,j;

  setcolor(WHITE);
  for(i=0; i<15;i++)
  for(j=0; j<15;j++)
  {
    if( E[i][j]==0 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);

      }
    if( E[i][j]==1 )
    {
      box(160+j*20,120+i*20,180+j*20,140+i*20,1,MAGENTA);
      }


      }
}

void asignaingles(char F[15][15])
{
  int i,j;

  char F2[15][15]={'A','B','C','G','H','Y','R','H','S','L','K','E','H','O','E',
		 'D','F','R','W','U','N','S','D','O','W','N','F','A','L','L',
		 'G','M','I','B','M','L','S','I','F','E','R','A','U','T','Y',
		 'W','H','I','S','P','E','R','S','U','A','C','Y','G','J','A',
		 'Y','I','B','D','L','D','L','W','N','F','N','L','H','E','U',
		 'P','R','F','A','U','E','P','L','G','A','N','C','T','R','W',
		 'J','A','S','E','R','E','N','D','I','P','I','T','Y','D','L',
		 'Y','E','N','L','K','C','D','E','Y','F','V','D','M','C','W',
		 'H','T','K','E','U','L','A','D','Y','R','L','O','V','E','A',
		 'T','H','B','G','D','L','F','N','S','I','M','U','N','D','N',
		 'Y','O','W','A','N','T','O','N','E','E','J','D','O','I','T',
		 'A','U','C','N','H','Y','R','H','S','N','K','E','I','U','O',
		 'D','S','R','C','U','N','S','L','T','D','Q','P','R','O','S',
		 'G','H','G','E','N','T','L','E','M','A','N','A','Q','T','Y',
		 'T','G','F','L','K','J','N','S','U','M','W','Y','C','J','A',};

 for(i=0; i<15; i++)
  for(j=0; j<15; j++) F[i][j]=F2[i][j];
}

void pintaingles(char F[15][15])
{
  int i,j;

  char cad[2];

  for(i=0; i<15;i++)
  for(j=0; j<15;j++)
  {
    cad[0]= F[i][j];
    cad[1]='\x0';
    outtextxy(165+j*20,125+i*20,cad);
      }
}

void jugar4(char F[15][15],int E[15][15], int G3[15][15], int turno, int gturno, int r, int p)
{ int i,j,enter=0,x1,y1,x2,y2;
   p=0;

   char *cadena;
   char cad[2];
   char tecla;
   i=5; j=5;

   box(480,150,610,200,1,BLUE);
   outtextxy(500,155,"Oprime 'A'");
   outtextxy(500,165,"para ABRIR");

   box(480,220,610,265,1,BLUE);
   outtextxy(500,225,"Oprime 'G'");
   outtextxy(500,235,"para GUARDAR");


      do{
	  setcolor(MAGENTA);

	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	     tecla=getch();

	  setcolor(WHITE);
	  rectangle(160+j*20,120+i*20,180+j*20,140+i*20);

	switch(tecla)
	{ case 0 : tecla=getch();
		   switch(tecla)
		   { case 75 : j--;break;
		     case 77 : j++;break;
		     case 72 : i--;break;
		     case 80 : i++;break;
		   }

		  if(i>14)i=0; if(i<0)i=14;
		  if(j>14)j=0; if(j<0)j=14;
	   break ;//fin cero

	   case 13:
	  if(enter==1){x2=j;
			    y2=i;
			 if (val(x1,y1,x2,y2,E)==0 )
				  {
				   box(90,380,140,430,1,RED);
				   p=p-100;
				   gcvt(p,4,cadena);
				   outtextxy(100,400,cadena);
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLACK);
				   cad[0]= F[i][j];
				   cad[1]='\x0';
				   outtextxy(165+j*20,125+i*20,cad);
				  }
			      else{
				   box(90,380,140,430,1,RED);
				   p=p+100;
				   gcvt(p,4,cadena);
				   outtextxy(100,400,cadena);
				 }
			    enter++;


			 }

	       if(enter==0){x1=j;
				   y1=i;
				  // M[i][j]=1;
				   box(160+j*20,120+i*20,180+j*20,140+i*20,1,BLUE);
				    cad[0]= F[i][j];
			     cad[1]='\x0';
				    outtextxy(165+j*20,125+i*20,cad);
				   enter++;
				   }
		if(enter==2){
				   pintainglesc(E);
				   pintaingles(F);
				   enter=0;
				     }
	    //   if(i<=6 && j=1)
	      // pintamatriz(M);
	      // pintamatris(N,M);
	      // outtextxy(160+j*20,120+i*20,BLUE);
		       break;


	      case 'a':
	      case 'A': nuevo4(E,G3,turno,gturno,r,p);
			pintainglesc(E);
			pintaingles(F);

			box(90,380,140,430,1,RED);
			gcvt(p,4,cadena);
			outtextxy(100,400,cadena);


			break;

	      case 'g':
	      case 'G': guardar4(E,G3,turno,gturno,r,p);
			break;



									       // outtextxy(129+j*17,49+i*17,"F"
	       } //fin de tecla




}  while(tecla!=27);
}


void animaless()
{
     box(10,100,130,350,1,BLUE);

     outtextxy(30,110,"ANIMALES");

     outtextxy(20,135,"HALCON");
     outtextxy(20,150,"ELEFANTE");
     outtextxy(20,165,"COCODRILO");
     outtextxy(20,180,"JAGUAR");
     outtextxy(20,195,"MURCIELAGO");
     outtextxy(20,210,"PERRO");
     outtextxy(20,225,"ALACRAN");
     outtextxy(20,240,"CAIMAN");
     outtextxy(20,255,"LOBO");

     box(5,380,145,450,1,RED);
     outtextxy(20,400,"PUNTOS =");

}

void nombress()
{
     box(10,100,130,350,1,BLUE);

     outtextxy(30,110,"NOMBRES");

     outtextxy(20,135,"SILVANA");
     outtextxy(20,150,"BRUNO");
     outtextxy(20,165,"BLANCA");
     outtextxy(20,180,"CAMILA");
     outtextxy(20,195,"ARIANA");
     outtextxy(20,210,"ESTEBAN");
     outtextxy(20,225,"RICARDO");
     outtextxy(20,240,"XIMENA");
     outtextxy(20,255,"GABINO");
     outtextxy(20,270,"SAMUEL");
     outtextxy(20,285,"MARIBEL");
     outtextxy(20,300,"MARCO");
     outtextxy(20,315,"ALONDRA");
     outtextxy(20,330,"MIGUEL");

     box(5,380,145,450,1,RED);
     outtextxy(20,400,"PUNTOS =");

   }
void paisess()
{
     box(10,100,130,430,1,BLUE);

     outtextxy(30,110,"PAISES");

     outtextxy(20,135,"MEXICO");
     outtextxy(20,150,"REINO UNIDO");
     outtextxy(20,165,"CROACIA");
     outtextxy(20,180,"PUERTO RICO");
     outtextxy(20,195,"RUSIA");
     outtextxy(20,210,"BRAZIL");
     outtextxy(20,225,"ARGENTINA");
     outtextxy(20,240,"ESPA¥A");
     outtextxy(20,255,"FRANCIA");
     outtextxy(20,270,"CHILE");
     outtextxy(20,285,"MADRID");
     outtextxy(20,300,"COLOMBIA");
     outtextxy(20,315,"CHIPRE");
     outtextxy(20,330,"ESTADOS UNIDOS");
     outtextxy(20,345,"DINAMARCA");
     outtextxy(20,360,"CANADA");
     outtextxy(20,375,"GRECIA");
     outtextxy(20,390,"ITALIA");
     outtextxy(20,405,"ALEMANIA");
     outtextxy(20,420,"HOLANDA");

     box(5,435,200,465,1,RED);
     outtextxy(20,445,"PUNTOS =");

 }
void ingless()
   {
   box(10,100,130,350,1,BLUE);

     outtextxy(30,110,"WORDS");

     outtextxy(20,135,"ELEGANCE");
     outtextxy(20,150,"GENTLEMAN");
     outtextxy(20,165,"LADY");
     outtextxy(20,180,"WHISPER");
     outtextxy(20,195,"ARCANE");
     outtextxy(20,210,"WANTON");
     outtextxy(20,225,"DOWNFALL");
     outtextxy(20,240,"MELLIFLUOUS");
     outtextxy(20,255,"FANCY");
     outtextxy(20,270,"SERENDIPITY");
     outtextxy(20,285,"HAUGHTY");
     outtextxy(20,300,"LOVE");
     outtextxy(20,315,"HIRAETH");
     outtextxy(20,330,"FRIEND");

     box(5,380,145,450,1,RED);
     outtextxy(20,400,"POINTS =");

   }

void guardar()
{ clearviewport();
	outtextxy(300,240,"CARGANDO CONTENIDO......");
getch();
}

void nuevo()
{ clearviewport();
	outtextxy(300,240,"CARGANDO CONTENIDO......");
getch();
}

void menu()

{
	box(0,0,getmaxx(), getmaxy(), 1, 6);

	box(30,50,130,100,1,3);
	outtextxy(40,70,"NIVELES");

	box(180,50,280,100,1,3);
	outtextxy(200,70,"NUEVO");

	box(330,50,430,100,1,3);
	outtextxy(360,70,"GUARDAR");

	box(480,50,580,100,1,3);
	outtextxy(500,70,"SALIR");
}

 void submenu()
 {

	box(30,100,130,130,1,GREEN);
	outtextxy(60,110,"ANIMALES");

	box(30,130,130,160,1,GREEN);
	outtextxy(60,140,"NOMBRES");

	box(30,160,130,190,1,GREEN);
	outtextxy(60,170,"PAISES");

	box(30,190,130,210,1,GREEN);
	outtextxy(60,200,"INGLES");

	box(30,220,130,240,1,GREEN);
	outtextxy(60,230,"MENU");
   }

   void muevesub()         //nombre de juego
{

	int j;
	char tecla;
	int turno,gturno;
	int r,p;

 int M[10][13];
  char N[10][13];

  int A[15][20];
  char B[15][20];

  int C[15][20];
  char D[15][20];

  int E[15][15];
  char F[15][15];

  int G[10][13];
  int S[15][20];
  int G2[15][20];
  int G3[15][15];

	submenu();
	j=1;
	do{
	 switch(j)
	    {

	case 1:	box(30,100,130,130,1,BROWN);
		outtextxy(60,110,"ANIMALES");
		break;
	case 2:	box(30,130,130,160,1,BROWN);
		outtextxy(60,140,"NOMBRES");
		break;
	case 3:	box(30,160,130,190,1,BROWN);
		outtextxy(60,170,"PAISES");
		break;
	case 4: box(30,190,130,210,1,BROWN);
		outtextxy(60,200,"INGLES");
		break;
       case 5: box(30,220,130,240,1,BROWN);
		outtextxy(60,230,"MENU");
		break;
	      }  //fin magenta

	tecla=getch();
      switch(j)
      {

	case 1:	box(30,100,130,130,1,GREEN);
		outtextxy(60,110,"ANIMALES");
		break;
	case 2:	box(30,130,130,160,1,GREEN);
		outtextxy(60,140,"NOMBRES");
		break;
	case 3:	box(30,160,130,190,1,GREEN);
		outtextxy(60,170,"PAISES");
		break;
	case 4: box(30,190,130,210,1,GREEN);
		outtextxy(60,200,"INGLES");
		break;
	case 5: box(30,220,130,240,1,GREEN);
		outtextxy(60,230,"MENU");
		break;
	      }  //fin magenta

	switch(tecla)
     {
	case 0:tecla=getch();
	switch(tecla)
	{
	case 80 : j++; break;
	case 72 : j--; break;
	}
	if(j>5) j=1;
	if(j<1) j=5;
	break;// fin 0

		case 13: switch(j)
		{
		   case 1:
			   box(5,115,620,490,1,BROWN);

			   animaless();
			   animales(M);
			   asignasopa(N);
			   pintamatriz(M);
			   pintamatris(N);
			   jugar(N,M,G,turno,gturno,r,p);


			break; //vas a ir a hacer uno
		   case 2:
			   box(5,115,620,490,1,BROWN);
			   nombress();
			   nombres(A);
			   asignanombres(B);
			   pintanombresc(A);
			   pintanombres(B);
			   jugar2(B,A,S,turno,gturno,r,p);
			break; //vas a ir a hacer dos
		   case 3:
			   box(5,115,620,490,1,BROWN);
			   paisess();
			   paises(C);
			   asignapaises(D);
			   pintapaisesc(C);
			   pintapaises(D);
			   jugar3(D,C,G2,turno,gturno,r,p);
			 break;
		   case 4:
			   box(5,115,620,490,1,BROWN);
			   ingless();
			   ingles(E);
			   asignaingles(F);
			   pintainglesc(E);
			   pintaingles(F);
			   jugar4(F,E,G3,turno,gturno,r,p);
			break;
		   case 5: tecla=27;break;


		 }

	       if(j!=4) submenu();
	       break; //fin enter


  }
	}while(tecla !=27);
 }


void mueve()         //nombre de juego
{
	int i;
	char tecla;

	menu();
	i=1;
	do{
	      switch(i)
	      {

	      case 1:box(30,50,130,100,1,9);
			outtextxy(40,70,"NIVELES");
			break;
	      case 2:box(180,50,280,100,1,9);
			outtextxy(200,70,"NUEVO");
			break;
	      case 3:box(330,50,430,100,1,9);
			outtextxy(360,70,"GUARDAR");
			break;
	      case 4:box(480,50,580,100,1,9);
			outtextxy(500,70,"SALIR");
			break;
	      }  //fin magenta

	tecla=getch();
      switch(i)
      {
	       case 1:box(30,50,130,100,1,3);
			outtextxy(40,70,"NIVELES");
			break;
	      case 2:box(180,50,280,100,1,3);
			outtextxy(200,70,"NUEVO");
			break;
	      case 3:box(330,50,430,100,1,3);
			outtextxy(360,70,"GUARDAR");
			break;
	      case 4:box(480,50,580,100,1,3);
			outtextxy(500,70,"SALIR");
			break;
	} //fin rojo

     switch(tecla)
     {
	case 0:tecla=getch();
	switch(tecla)
	{
	case 75 : i--; break;
	case 77 : i++; break;
	}
	if(i>4) i=1;
	if(i<1) i=4;
	break;// fin 0

		case 13: switch(i)
		{
		   case 1: muevesub (); break; //vas a ir a hacer uno
		   case 2: nuevo (); break; //vas a ir a hacer dos
		   case 3: guardar(); break;
		   case 4: tecla=27; break;
		 }

	      if(i!=4) menu();
	       break; //fin enter
	}//fin tecla

	}while(tecla !=27);
}


void main()
{
  inicializa();
  mueve();
}


