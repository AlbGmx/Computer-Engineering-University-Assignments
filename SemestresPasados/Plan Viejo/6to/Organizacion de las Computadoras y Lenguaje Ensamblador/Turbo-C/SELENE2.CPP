#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <ctype.h>
#include <dos.h>

void inicializa()
{
int gm, gd=DETECT;
initgraph(&gd,&gm, "C:\\turboc3\\bgi");
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

void generaVector(int L[25]){
	int i;
	for(i=0; i<25; i++) L[i]=0;
	L[12]=1;
	L[21]=2;
}

void punto( int x, int y, int color)
 { setfillstyle( 1, color);
   fillellipse(x, y, 8, 8);
 }

void borrar(int t)
{
	if(t==1){
	  box( 600, 40, 630,  60,1, BLUE );
	}
	else if (t==2){
	  box( 600, 70, 630,  90,1, BLUE );
	}
	else{
      box( 600, 40, 630,  60,1, BLUE );
      box( 600, 70, 630,  90,1, BLUE );			
	  box( 430,100, 630, 130,1, BLUE );
      box( 430,320, 620, 340,1, BLUE );
      box( 600,320, 630, 340,1, BLUE );
	}
}

void pintavector( int x, int y, int jg1, int jg2)
{ int i,n ;
  char cad[5];
  for(i = 0; i <5 ; i++){
  box( x+i*80, y    , (x+80)+i*80, y +  80, 1, MAGENTA);  //fila uno
  box (x+i*80, y+ 80, (x+80)+i*80, y + 160, 1, MAGENTA);   //fila dos
  box (x+i*80, y+160, (x+80)+i*80, y + 240, 1, MAGENTA);  // fi¤la 3
  box (x+i*80, y+240, (x+80)+i*80, y + 320, 1, MAGENTA); //fila 4
  box (x+i*80, y+320, (x+80)+i*80, y + 400, 1, MAGENTA);
			 }
   //numeros
  outtextxy( 405, 350,  "1"); outtextxy(  85, 270,  "6");
  outtextxy( 325, 350,  "2"); outtextxy( 165, 270,  "7");
  outtextxy( 245, 350,  "3"); outtextxy( 245, 270,  "8");
  outtextxy( 165, 350,  "4"); outtextxy( 325, 270,  "9");
  outtextxy(  85, 350,  "5"); outtextxy( 400, 270, "10");

  outtextxy( 400, 190, "11"); outtextxy(  80, 110, "16");
  outtextxy( 320, 190, "12"); outtextxy( 160, 110, "17");
  outtextxy( 240, 190, "13"); outtextxy( 240, 110, "18");
  outtextxy( 160, 190, "14"); outtextxy( 267, 110, "19");
  outtextxy(  80, 190, "15"); outtextxy( 400, 110, "20");

  outtextxy( 400, 30,  "21");
  outtextxy( 320, 30,  "22");
  outtextxy( 240, 30,  "23");
  outtextxy( 160, 30,  "24");
  outtextxy(  40, 30,"META");
   // serpiente1
  punto(188, 240, GREEN);
  punto(188, 250, GREEN);
  punto(188, 260, GREEN);
  punto(188, 270, GREEN);
  punto(188, 280, GREEN);
  punto(188, 290, GREEN);
  punto(188, 300, GREEN);
  punto(188, 310, GREEN);
  punto(188, 320, GREEN);
  punto(188, 330, GREEN);
  punto(188, 340, GREEN);
  punto(188, 350, GREEN);
 //serpiente dos
  punto(327,  90, GREEN);
  punto(330, 100, GREEN);
  punto(332, 110, GREEN);
  punto(335, 120, GREEN);
  punto(338, 130, GREEN);
  punto(342, 140, GREEN);
  punto(345, 150, GREEN);
  punto(345, 160, GREEN);
  punto(345, 170, GREEN);
  punto(345, 180, GREEN);
  punto(345, 190, GREEN);
  punto(345, 200, GREEN);
  punto(345, 210, GREEN);
  punto(345, 220, GREEN);
  punto(348, 230, GREEN);
  punto(351, 240, GREEN);
  punto(354, 250, GREEN);
  punto(358, 260, GREEN);
  outtextxy(435, 45, "Posicion Jugador 1");
  outtextxy(435, 75, "Posicion Jugador 2");
  box( 600,150, 630, 170,1, BLUE );
  outtextxy(435, 160, "Ganados Jugador 1");
  box( 600,180, 630, 200,1, BLUE );
  gcvt( jg1,3,cad );
  outtextxy(610, 155, cad);
  outtextxy(435, 190, "Ganados Jugador 2");
  box(570,370, 630, 430,1, WHITE );
  gcvt( jg2,3,cad );
  outtextxy(610, 185, cad);
		 
}


 void dado6()
{
  punto(580, 380, GREEN);  // setcolor( BLACK);  circle(580, 380, 5);
  punto(580, 400, GREEN); //setcolor( BLACK);  circle(580, 400, 5);
  punto(580, 420, GREEN);
  punto(620, 380, GREEN);
  punto(620, 400, GREEN);
  punto(620, 420, GREEN);
}
 void dado5()
{
  punto(580, 380, RED);
  punto(580, 420, RED);
  punto(620, 380, RED);
  punto(620, 420, RED);
  punto(600, 400, RED);
}
 void dado4()
{
  punto(580, 380, MAGENTA);
  punto(580, 420, MAGENTA);
  punto(620, 380, MAGENTA);
  punto(620, 420, MAGENTA);
}
void dado3()
{
  punto(580, 380, CYAN);
  punto(600, 400, CYAN);
  punto(620, 420, CYAN);
}
void dado2()
{
  punto(580, 380, LIGHTGREEN);
  punto(620, 420, LIGHTGREEN);
}
void dado1()
{
  punto(600, 400, BLACK);
}

int dado()
 { int i;

 do{

   box(570,370, 630, 430,1, WHITE );
   i=(1+rand()%6);

  switch(i)
   { case 1 : dado1();
	      break;
     case 2 : dado2();
	      break;
     case 3 : dado3();
	      break;
     case 4 : dado4();
	      break;
     case 5 : dado5();
	      break;
     case 6 : dado6();
	      break;
     }

   delay(200);

   } while( !kbhit() );

   return(i);
 }

void borraFicha(int pos){
	
     switch (pos)
     { case 1 :
		setcolor(MAGENTA);
		box(390,380, 410, 400, 1 , MAGENTA);	
		setcolor(15);
		break;
       case 2 :
		setcolor(MAGENTA);
		box(310,380, 330, 400, 1 , MAGENTA); 
		setcolor(15);
		break;
       case 3 :	
	    setcolor(MAGENTA);
		box(230,380, 250, 400, 1 , MAGENTA); 
		setcolor(15);
		break;
       case 4 : 
   	    setcolor(MAGENTA);
		box(150,380, 170, 400, 1 , MAGENTA);  
		setcolor(15);
		break;

       case 5 : 
	    setcolor(MAGENTA);
		box(70,380, 90, 400, 1 , MAGENTA);   
		setcolor(15);
		break;

       case 6 :
	    setcolor(MAGENTA);
		box(70,300, 90, 320, 1 , MAGENTA);   
		setcolor(15);
		break;
       case 7 : 
	    setcolor(MAGENTA);
    	box(150,300, 170, 320, 1 , MAGENTA);   
		setcolor(15);
		break;
       case 8 :
   	    setcolor(MAGENTA);
		box(230,300, 250, 320, 1 , MAGENTA);   
		setcolor(15);
		break;

       case 9 :
	    setcolor(MAGENTA);
		box(310,300, 330, 320, 1 , MAGENTA);   
		setcolor(15);
		break;
       case 10 :
        setcolor(MAGENTA);
	    box(390,300, 410, 320, 1 , MAGENTA);   
		setcolor(15);
		break;
       case 11 :
	    setcolor(MAGENTA);
		box(390,220, 410, 240, 1 , MAGENTA);   
		setcolor(15);
		break;
     
      case 12 :
	     setcolor(MAGENTA);
		box(310,220, 330, 240, 1 , MAGENTA);   
		setcolor(15);
		break;
     
      case 13 : 
	    setcolor(MAGENTA);
		box(230,220, 250, 240, 1 , MAGENTA);   
		setcolor(15);
		break;
     
      case 14 : 
        setcolor(MAGENTA);
     	box(150,220, 170, 240, 1 , MAGENTA);   
		setcolor(15);
		break;
      case 15 :
	     setcolor(MAGENTA);
		box( 70, 220, 90, 240, 1 , MAGENTA);  
		setcolor(15);
		break;
     
      case 16 :
	     setcolor(MAGENTA);
		box( 70, 140, 90, 160, 1 , MAGENTA);   
		setcolor(15);
		break;
     
      case 17 :
	     setcolor(MAGENTA);
		box(150,140, 170, 160, 1 , MAGENTA);    
		setcolor(15);
		break;
     
      case 18 : 
	    setcolor(MAGENTA);
		box( 230, 140, 250, 160, 1 , MAGENTA);    
		setcolor(15);
		break;
     
      case 19 : 
	   setcolor(MAGENTA);
     	box(310,140, 330, 160, 1 , MAGENTA);    
		setcolor(15);
		break;
      case 20 :
	   setcolor(MAGENTA);
     	box(390,140, 410, 160, 1 , MAGENTA);
		setcolor(15);
		break;
      case 21 : 
	   setcolor(MAGENTA);
     	box(390, 60, 410, 80, 1 , MAGENTA); 
		setcolor(15);
		break;
      case 22 : 
	   setcolor(MAGENTA);
     	box(310, 60, 330, 80, 1 , MAGENTA); 
		setcolor(15);
		break;
      case 23 : 
		setcolor(MAGENTA);
        box(230, 60, 250, 80, 1 , MAGENTA);    
		setcolor(15);
		break;
      case 24 : 
        setcolor(MAGENTA);
	    box(150, 60, 170, 80, 1 , MAGENTA);    
		setcolor(15);
		break;
     	
      case 25 : 
	    setcolor(MAGENTA);
		box( 70, 60, 90,  80, 1 , MAGENTA); 
		setcolor(15);
		break;
     
     }
}

void pintaficha(int i, int jg){
     switch (i)
     { case 1 : if( jg == 1 ) box(390,380, 410, 400, 2 , BLUE);
		   else box(390,380, 410, 400, 6 , RED);
		   break;
       case 2 : if( jg == 1 ) box(310,380, 330, 400, 2 , BLUE);
		    else box(310,380, 330, 400, 6 , RED);
			break;
	   case 3 : if( jg == 1 ) box(230,380, 250, 400, 2 , BLUE);
		    else box(230,380, 250, 400, 6 , RED);
			break;
	   case 4 : if( jg == 1 ) box(150,380, 170, 400, 2 , BLUE);
		    else box(150,380, 170, 400, 6 , RED);
			break;
	   case 5 : if( jg == 1 ) box(70,380, 90, 400, 2 , BLUE);
		    else box(70,380, 90, 400, 6 , RED);
			break;
	   case 6 : if( jg == 1 ) box(70,300, 90, 320, 2 , BLUE); //box(390,300, 410, 320, 2 , BLUE);
		    else box(70,300, 90, 320, 6 , RED);
			break;
	   case 7 : if( jg == 1 ) box(150,300, 170, 320, 2 , BLUE);//box(310,300, 330, 320, 2 , BLUE);
		    else box(150,300, 170, 320, 6 , RED);
			break;
	   case 8 : if( jg == 1 ) box(230,300, 250, 320, 2 , BLUE);
		    else box(230,300, 250, 320, 6 , RED);
			break;
	   case 9 : if( jg == 1 ) box(310,300, 330, 320, 2 , BLUE);//box(150,300, 170, 320, 2 , BLUE);
		    else box(310,300, 330, 320, 6 , RED);
			break;
	  case 10 : if( jg == 1 ) box(390,300, 410, 320, 2 , BLUE); //box(70,300, 90, 320, 2 , BLUE);
		    else box(390,300, 410, 320, 6 , RED);
			break;
	  case 11 : if( jg == 1 ) box(390,220, 410, 240, 2 , BLUE);
		    else box(390,220, 410, 240, 6 , RED);
			break;
	  case 12 : if( jg == 1 ) box(310,220, 330, 240, 2 , BLUE);
		    else box(310,220, 330, 240, 6 , RED);
			break;
	  case 13 : if( jg == 1 ) box(230,220, 250, 240, 2 , BLUE);
		    else box(230,220, 250, 240, 6 , RED);
			break;
	  case 14 : if( jg == 1 ) box(150,220, 170, 240, 2 , BLUE);
		    else box(150,220, 170, 240, 6 , RED);
			break;
	  case 15 : if( jg == 1 ) box( 70, 220, 90, 240, 2 , BLUE);
		    else box( 70, 220, 90, 240, 6 , RED);
			break;
	  case 16 : if( jg == 1 ) box( 70, 140, 90, 160, 2 , BLUE);//box(390,140, 410, 160, 2 , BLUE);
	    	else box( 70, 140, 90, 160, 6 , RED);
 			break;
	  case 17 : if( jg == 1 ) box(150,140, 170, 160, 2 , BLUE);//box(310,140, 330, 160, 2 , BLUE);
		    else box(150,140, 170, 160, 6 , RED);
  			break;
	  case 18 : if( jg == 1 ) box( 230, 140, 250, 160, 2 , BLUE);
		    else box( 230, 140, 250, 160, 6 , RED);
  			break;
	  case 19 : if( jg == 1 ) box(310,140, 330, 160, 2 , BLUE);//box(150,140, 170, 160, 2 , BLUE);
	    	else box(310,140, 330, 160, 6 , RED);
  			break;
	  case 20 : if( jg == 1 ) box(390,140, 410, 160, 2 , BLUE);//box( 70, 140, 90, 160, 2 , BLUE);
		    else box(390,140, 410, 160, 6 , RED);
  			break;
	  case 21 : if( jg == 1 ) box(390, 60, 410, 80, 2 , BLUE);
		    else box(390, 60, 410, 80, 6 , RED);
  			break;
	  case 22 : if( jg == 1 ) box(310, 60, 330, 80, 2 , BLUE);
		    else box(310, 60, 330, 80, 6 , RED);
			break;
	  case 23 : if( jg == 1 ) box(230, 60, 250, 80, 2 , BLUE);
		    else box(230, 60, 250, 80, 6 , RED);
			break;
	  case 24 : if( jg == 1 ) box(150, 60, 170, 80, 2 , BLUE);
		    else box(150, 60, 170, 80, 6 , RED);
			break;	 
	  case 25 : if( jg == 1 ) box( 70, 60, 90,  80, 2 , BLUE);
		    else box( 70, 60, 90,  80, 6 , RED);
	 		break;
	 }

   }

void main()
{ int p, jg1 = 0, jg2 = 0, pos1 = 0, pos2 = 0, t = 1, L[25];
  char tecla, cad[6];
  randomize();
  inicializa();
  generaVector(L);
  pintavector(20,20, jg1, jg2);

do{
				

    if( t == 1 ){
 	   tecla = getch();
       pintaficha( pos1 , 1);
       pintaficha( pos2 , 2);
       p = dado();
  pintavector(20,20, jg1, jg2);
    
       box( 430,320, 620, 340,1, BLUE );
       box( 600,320, 630, 340,1, BLUE );
       outtextxy(435, 325, "Jugador uno");
       gcvt( p,3,cad );
       outtextxy(610,325, cad);
       delay(1000);
	   borraFicha(pos1);
       pos1 = pos1 + p;
	   if(L[pos1-1]==1){
 		delay(200);
	    borraFicha(pos1);
	    pos1 = 3;
	    pintaficha(pos1, t);
       }
	   if(L[pos1-1]==2){
         delay(200);		
	     borraFicha(pos1);
	     pos1 = 10;
         pintaficha( pos1 , t);
	   }
	   
       if ( pos1 > 25 ) pos1 = 25;
	   box( 600, 40, 630,  60,1, BLUE );
       gcvt( pos1,3,cad );
       outtextxy(610, 45, cad);
       pintaficha( pos1 , t);
    
  	   if( pos1 >= 25 ){
	     outtextxy(435, 110, "Ha ganado el jugador uno");
	     delay(1000);
	     borrar(3);
	     pos1 = pos2 = 0;
	     box( 600,150, 630, 170,1, BLUE );
	     jg1 = jg1 + 1;
	     gcvt( jg1,3,cad );
	     outtextxy(610, 155, cad);
         pintavector(20,20, jg1, jg2);
			}
         t = 2;
	       }

    if( t == 2 ){
		tecla = getch();
		pintaficha( pos1 , 1);
		pintaficha( pos2 , 2);
	    p = dado();
	    pintavector(20,20, jg1, jg2);
	    box( 430,320, 620, 340,1, BLUE );
	    box( 600,320, 630, 340,1, BLUE );
	    outtextxy(435, 325, "Jugador dos");
	    gcvt( p,3,cad );
	    outtextxy(610,325, cad);
	    delay(1000);
	    borraFicha(pos2);
	    pos2 = pos2 + p;
	    if(L[pos2-1]==1){
		  borraFicha(pos2);
		  delay(200);
		  pos2 = 3;
          pintaficha( pos2 , t);
	    }
	    if(L[pos2-1]==2){
	      pos2 = 10;
          delay(200); 
	      borraFicha(pos2);
          pintaficha( pos2 , t);
        }
	 
	   if ( pos2 > 25 ) pos2 = 25;
	      
		box( 600, 70, 630,  90,1, BLUE );
	    gcvt( pos2,3,cad );
	    outtextxy(610, 75, cad);
	    pintaficha( pos2, t );
	   
	   if( pos2 >= 25 ){
	      outtextxy(435, 110, "Ha ganado el jugador dos");
	      delay(1000);
	      borrar(3);
	      pos1 = pos2 = 0;
		  box( 600,180, 630, 200,1, BLUE );
	      jg2 = jg2 + 1;
	      gcvt( jg2,3,cad );
	      outtextxy(610, 185, cad);
		  pintavector(20,20, jg1, jg2);
			 }
	t = 1;
	       }
	if( pos1>25 && pos2>25 ){
	    outtextxy(435, 110, "Ambos han perdido");
	    delay(1000);
		borrar(3);
		
	    pos1 = pos2 = 0;
				}
				
  }while( tecla!=27 );
}