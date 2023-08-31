#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
void inicializa()
{
  int gm, gd=DETECT;
  initgraph(&gd, &gm,"c:\\turboc3\\bgi");
}
void box (int x1, int y1, int x2, int y2, int relleno, int color)
{
  int poly[8];
  poly [0]=x1;	poly [1]=y1;
  poly [2]=x2;	poly [3]=y1;
  poly [4]=x2;	poly [5]=y2;
  poly [6]=x1;	poly [7]=y2;
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
void generaMatrices(int MatrizBooleana[10][10], int MatrizInt[10][10], char MatrizChar[10][10], int ListaBooleana[10])
{
  int i,j;
  for (i=0; i<10; i++) ListaBooleana[i]=0; //Lista con una bandera para cada palabra
  for (i=0; i<10; i++) for(j=0; j<10; j++){
	  //Matriz booleana para pintar las casillas ya descubiertas
	  MatrizBooleana[i][j]=0; MatrizInt[i][j]=0;  //inicializa matrices en 0
  }   
  //Matriz con char para hacer la sopa
  MatrizChar[0][0]='O';  MatrizChar[0][1]='N';  MatrizChar[0][2]='I';  MatrizChar[0][3]='P';  MatrizChar[0][4]='E';  MatrizChar[0][5]='P';  MatrizChar[0][6]='C';  MatrizChar[0][7]='A';  MatrizChar[0][8]='S';  MatrizChar[0][9]='P';  //Sopa de letras
  MatrizChar[1][0]='L';  MatrizChar[1][1]='T';  MatrizChar[1][2]='E';  MatrizChar[1][3]='D';  MatrizChar[1][4]='C';  MatrizChar[1][5]='L';  MatrizChar[1][6]='A';  MatrizChar[1][7]='L';  MatrizChar[1][8]='E';  MatrizChar[1][9]='L';
  MatrizChar[2][0]='I';  MatrizChar[2][1]='R';  MatrizChar[2][2]='U';  MatrizChar[2][3]='U';  MatrizChar[2][4]='S';  MatrizChar[2][5]='M';  MatrizChar[2][6]='L';  MatrizChar[2][7]='E';  MatrizChar[2][8]='T';  MatrizChar[2][9]='A';
  MatrizChar[3][0]='M';  MatrizChar[3][1]='P';  MatrizChar[3][2]='E';  MatrizChar[3][3]='R';  MatrizChar[3][4]='A';  MatrizChar[3][5]='W';  MatrizChar[3][6]='A';  MatrizChar[3][7]='B';  MatrizChar[3][8]='O';  MatrizChar[3][9]='T';
  MatrizChar[4][0]='A';  MatrizChar[4][1]='T';  MatrizChar[4][2]='A';  MatrizChar[4][3]='A';  MatrizChar[4][4]='K';  MatrizChar[4][5]='L';  MatrizChar[4][6]='B';  MatrizChar[4][7]='S';  MatrizChar[4][8]='Y';  MatrizChar[4][9]='A';
  MatrizChar[5][0]='M';  MatrizChar[5][1]='A';  MatrizChar[5][2]='N';  MatrizChar[5][3]='Z';  MatrizChar[5][4]='A';  MatrizChar[5][5]='N';  MatrizChar[5][6]='A';  MatrizChar[5][7]='B';  MatrizChar[5][8]='A';  MatrizChar[5][9]='N';
  MatrizChar[6][0]='A';  MatrizChar[6][1]='R';  MatrizChar[6][2]='I';  MatrizChar[6][3]='N';  MatrizChar[6][4]='H';  MatrizChar[6][5]='A';  MatrizChar[6][6]='Z';  MatrizChar[6][7]='A';  MatrizChar[6][8]='H';  MatrizChar[6][9]='O';
  MatrizChar[7][0]='M';  MatrizChar[7][1]='A';  MatrizChar[7][2]='N';  MatrizChar[7][3]='O';  MatrizChar[7][4]='N';  MatrizChar[7][5]='I';  MatrizChar[7][6]='A';  MatrizChar[7][7]='R';  MatrizChar[7][8]='C';  MatrizChar[7][9]='L';
  MatrizChar[8][0]='K';  MatrizChar[8][1]='I';  MatrizChar[8][2]='R';  MatrizChar[8][3]='A';  MatrizChar[8][4]='M';  MatrizChar[8][5]='A';  MatrizChar[8][6]='N';  MatrizChar[8][7]='G';  MatrizChar[8][8]='O';  MatrizChar[8][9]='O';
  MatrizChar[9][0]='Z';  MatrizChar[9][1]='A';  MatrizChar[9][2]='N';  MatrizChar[9][3]='A';  MatrizChar[9][4]='H';  MatrizChar[9][5]='O';  MatrizChar[9][6]='R';  MatrizChar[9][7]='I';  MatrizChar[9][8]='A';  MatrizChar[9][9]='L';

  //Matriz en enteros para comparar palabras 
  MatrizInt[1][0]=1;    MatrizInt[3][0]=1;   MatrizInt[4][0]=1;  //LIMA en 1
  MatrizInt[3][1]=2;    MatrizInt[3][3]=2;   MatrizInt[3][4]=2;  //PERA en 2
  MatrizInt[8][4]=3;    MatrizInt[8][7]=3;   MatrizInt[8][8]=3;  //MANGO en 3
  MatrizInt[0][0]=4;    MatrizInt[0][4]=4;   MatrizInt[0][5]=4;  //PEPINO en 4
  MatrizInt[1][3]=5;    MatrizInt[6][3]=5;   MatrizInt[7][3]=5;  //DURAZNO en 5
  MatrizInt[1][8]=6;    MatrizInt[6][8]=6;   MatrizInt[7][8]=6;  //CHAYOTE en 6
  MatrizInt[5][0]=7;    MatrizInt[5][5]=7;   MatrizInt[5][6]=7;  //MANZANA en 7
  MatrizInt[0][9]=8;    MatrizInt[5][9]=8;   MatrizInt[6][9]=8;  //PLATANO en 8
  MatrizInt[0][6]=9;    MatrizInt[6][6]=9;   MatrizInt[7][6]=9;  //CALABAZA en 9
  MatrizInt[9][0]=10;   MatrizInt[9][7]=10;  MatrizInt[9][8]=10; //ZANAHORIA en 10
 }
void generaSopa(int MatrizBooleana[10][10], char MatrizChar[10][10])
{
  int j, i;
  char aux[5];
  //Escribir las palabras que se buscaran en la sopa de letras
  settextstyle(8,0,3);
  outtextxy(470,50, "LIMA");
  outtextxy(470,90, "PERA");
  outtextxy(470,130,"MANGO");
  outtextxy(470,170,"PEPINO");
  outtextxy(470,210,"DURAZNO");
  outtextxy(470,250,"CHAYOTE");
  outtextxy(470,290,"MANZANA");
  outtextxy(470,330,"PLATANO");
  outtextxy(470,370,"CALABAZA");
  outtextxy(470,410,"ZANAHORIA");
  
  for(i=0; i<10; i++) for(j=0; j<10; j++){
	//Matriz boolena en 0 significa que esa casilla no ha sido descubierta
	if (MatrizBooleana[i][j]==0) box(50+j*40,50+i*40,90+j*40,90+i*40,1,0);
	//Matriz boolena en 1 significa que esa casilla ya ha sido descubierta
	else if (MatrizBooleana[i][j]!=0) box(50+j*40,50+i*40,90+j*40,90+i*40,1,3);
	//Se utiliza auxiliar para convertir el char a string y asi poder usarlo en la funcion outtextxy (x,y, string);
	aux[0]=MatrizChar[i][j];  aux[1]='\x0';
	outtextxy(65+j*40,50+i*40, aux);
  }
}
void cambiaBandera(int MatrizBooleana[10][10], int palabra, int ListaBooleana[10])
{
  //cambia los valores booleanos de 0 a 1 de la palabra descubierta
  switch (palabra){
    case 1:  MatrizBooleana[1][0]=1;  MatrizBooleana[2][0]=1;  MatrizBooleana[3][0]=1;  MatrizBooleana[4][0]=1;  //LIMA en 1 
             ListaBooleana[palabra-1]=1;  break;
	case 2:  MatrizBooleana[3][1]=1;  MatrizBooleana[3][2]=1;  MatrizBooleana[3][3]=1;  MatrizBooleana[3][4]=1;  //PERA en 2
             ListaBooleana[palabra-1]=1;  break;
	case 3:  MatrizBooleana[8][4]=1;  MatrizBooleana[8][5]=1;  MatrizBooleana[8][6]=1;  MatrizBooleana[8][7]=1;  MatrizBooleana[8][8]=1;  //MANGO en 3
             ListaBooleana[palabra-1]=1;  break;
	case 4:  MatrizBooleana[0][0]=1;  MatrizBooleana[0][1]=1;  MatrizBooleana[0][2]=1;  MatrizBooleana[0][3]=1;  MatrizBooleana[0][4]=1;  MatrizBooleana[0][5]=1;  //PEPINO en 4
             ListaBooleana[palabra-1]=1;  break;
	case 5:  MatrizBooleana[1][3]=1;  MatrizBooleana[2][3]=1;  MatrizBooleana[3][3]=1;  MatrizBooleana[4][3]=1;  MatrizBooleana[5][3]=1;  MatrizBooleana[6][3]=1;  MatrizBooleana[7][3]=1;  //DURAZNO en 5
             ListaBooleana[palabra-1]=1;  break;
	case 6:  MatrizBooleana[1][8]=1;  MatrizBooleana[2][8]=1;  MatrizBooleana[3][8]=1;  MatrizBooleana[4][8]=1;  MatrizBooleana[5][8]=1;  MatrizBooleana[6][8]=1;  MatrizBooleana[7][8]=1;  //CHAYOTE en 6
             ListaBooleana[palabra-1]=1;  break;
	case 7:  MatrizBooleana[5][0]=1;  MatrizBooleana[5][1]=1;  MatrizBooleana[5][2]=1;  MatrizBooleana[5][3]=1;  MatrizBooleana[5][4]=1;  MatrizBooleana[5][5]=1;  MatrizBooleana[5][6]=1;  //MANZANA en 7
             ListaBooleana[palabra-1]=1;  break;
	case 8:  MatrizBooleana[0][9]=1;  MatrizBooleana[1][9]=1;  MatrizBooleana[2][9]=1;  MatrizBooleana[3][9]=1;  MatrizBooleana[4][9]=1;  MatrizBooleana[5][9]=1;  MatrizBooleana[6][9]=1;  //PLATANO en 8
             ListaBooleana[palabra-1]=1;  break;
	case 9:  MatrizBooleana[0][6]=1;  MatrizBooleana[1][6]=1;  MatrizBooleana[2][6]=1;  MatrizBooleana[3][6]=1;  MatrizBooleana[4][6]=1;  MatrizBooleana[5][6]=1;  MatrizBooleana[6][6]=1;  MatrizBooleana[7][6]=1;  //CALABAZA en 9
             ListaBooleana[palabra-1]=1;  break;
	case 10: MatrizBooleana[9][0]=1;  MatrizBooleana[9][1]=1;  MatrizBooleana[9][2]=1;  MatrizBooleana[9][3]=1;  MatrizBooleana[9][4]=1;  MatrizBooleana[9][5]=1;  MatrizBooleana[9][6]=1;  MatrizBooleana[9][7]=1;  MatrizBooleana[9][8]=1;  //ZANAHORIA en 10
             ListaBooleana[palabra-1]=1;
  }	  
}
void pintaPalabra(int i, int j, int iprev, int jprev, char MatrizChar[10][10])
{
  char aux[5];
  //compara los valores de i y de iprev para saber hacia donde y desde donde pintar la palabra descubierta
  //Se utiliza auxiliar para convertir el char a string y asi poder usarlo en la funcion outtextxy (x,y, string);
  if (i>iprev && j==jprev)  for (iprev; iprev<i;iprev++){
    box(50+(j)*40,50+(iprev)*40,90+(j)*40,90+(iprev)*40,1,3);
    aux[0]=MatrizChar[iprev][j];  aux[1]='\x0';
    outtextxy(65+(j)*40,50+(iprev)*40, aux);
  }
  else if (i<iprev && j==jprev)  for (iprev; iprev>i;iprev--){
    box(50+(j)*40,50+(iprev)*40,90+(j)*40,90+(iprev)*40,1,3);
    aux[0]=MatrizChar[iprev][j];  aux[1]='\x0';
    outtextxy(65+(j)*40,50+(iprev)*40, aux);
  }
  else if (j>jprev && i==iprev)  for (jprev; jprev<j;jprev++){
    box(50+(jprev)*40,50+(i)*40,90+(jprev)*40,90+(i)*40,1,3);
    aux[0]=MatrizChar[i][jprev];  aux[1]='\x0';
    outtextxy(65+(jprev)*40,50+(i)*40, aux);
  }
  else if (j<jprev && i==iprev)  for (jprev; jprev>j;jprev--){
    box(50+(jprev)*40,50+(i)*40,90+(jprev)*40,90+(i)*40,1,3);
    aux[0]=MatrizChar[i][jprev];  aux[1]='\x0';
    outtextxy(65+(jprev)*40,50+(i)*40, aux);
  }
  else {
   box(50+(j)*40,50+(i)*40,90+(j)*40,90+(i)*40,1,0);
   aux[0]=MatrizChar[i][j];  aux[1]='\x0';
   outtextxy(65+(j)*40,50+(i)*40, aux);
   box(50+(jprev)*40,50+(iprev)*40,90+(jprev)*40,90+(iprev)*40,1,0);
   aux[0]=MatrizChar[iprev][jprev];  aux[1]='\x0';
   outtextxy(65+(jprev)*40,50+(iprev)*40, aux);
 }
	
	
	
}
int comparaPalabra(int MatrizInt[10][10], int i, int j, int iprev, int jprev, int palabra)
{
  int r=0;
  //Si los valores seleccionados coinciden con los valores especificos de esa palabra regresa 1, si no, regresa -1
  switch(palabra){
    case 1:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 2:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 3:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 4:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 5:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 6:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 7:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 8:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 9:  if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
    case 10: if(MatrizInt[i][j]==palabra  &&  MatrizInt[iprev][jprev]==palabra)  r=1;  else r=-1;  break;
  }
  return(r);

}
void raya(int palabra, int &puntos)
{
  //raya la palabra que ya ha sido descubierta 
  switch (palabra){
  case 1:   line(470,  70, 527,  70);  puntos+=20;  break;  //Lima
  case 2:   line(470, 110, 527, 110);  puntos+=20;  break;  //Pera
  case 3:   line(470, 150, 545, 150);  puntos+=15;  break;  //Mango
  case 4:   line(470, 190, 560, 190);  puntos+=15;  break;  //Pepino
  case 5:   line(470, 230, 585, 230);  puntos+=10;  break;  //Durazno
  case 6:   line(470, 270, 585, 270);  puntos+=10;  break;  //Chayote
  case 7:   line(470, 310, 585, 310);  puntos+=10;  break;  //Manzana
  case 8:   line(470, 350, 585, 350);  puntos+=10;  break;  //Platano
  case 9:   line(470, 390, 600, 390);  puntos+=5;   break;  //Calabaza
  case 10:  line(470, 430, 610, 430);  puntos+=5;   break;  //Zanahoria
  }
}
int completo(int ListaBooleana[10])
{
	int i;
    //revisa si ya han sido descubiertas todas las palabras y, por lo tanto, si ya se ha completado la sopa de letras
	for (i=0; i<10; i++) if(ListaBooleana[i]==0) return 0; //Si aun faltan palabras por descubrir regresa 0
	return 1;	//Si ya se encontraron todas regresa 1
}
void comienza(int &jugar)
{
  int ListaBooleana[10],MatrizBooleana[10][10], MatrizInt[10][10], i, j,k, iprev, jprev, a, b, c, d, boolean=0, palabra=0, puntos = 0;
  char tecla, MatrizChar[10][10], aux[5], puntaje[50];
  generaMatrices(MatrizBooleana, MatrizInt, MatrizChar,ListaBooleana);
  generaSopa(MatrizBooleana, MatrizChar);
  outtextxy(50,0,"Pantalla para destrabar el mouse");
  getch();
	setcolor(0); 
	box(0,0,getmaxx(),40,1,1);  //Parche para tapar el texto
    setcolor(15);
do {
	if(palabra==0){  //Si aún no has seleccionado palabra te pide que selecciones una
		outtextxy(30,0,"Seleccione la palabra encontrada");
		outtextxy(480,0,itoa(puntos,puntaje,10));  
		outtextxy(535,0,"Puntos");
	}
	else if(palabra!=0) outtextxy(30,0,"Seleccione inicio y final de la palabra");
  a=3;
  mouse(a,b,c,d);
  switch(b){
  case 1 : quita();
	if (  c>450 && c<getmaxx() && d>50 && d<450){ //comparar que el mouse se encuentre dentro del rango de las palabras
	  //Lista booleana se encarga de revisar que la palabra aun no haya sido descubierta, de ser el caso no te deja seleccionarla
	  if ( d>50  &&  d<90  &&  ListaBooleana[0] == 0) palabra=1;
	  else if (d>90  && d<130  &&  ListaBooleana[1] == 0) palabra=2;
	  else if (d>130 && d<170  &&  ListaBooleana[2] == 0) palabra=3;
	  else if (d>170 && d<210  &&  ListaBooleana[3] == 0) palabra=4;
	  else if (d>210 && d<250  &&  ListaBooleana[4] == 0) palabra=5;
	  else if (d>250 && d<290  &&  ListaBooleana[5] == 0) palabra=6;
	  else if (d>290 && d<330  &&  ListaBooleana[6] == 0) palabra=7;
	  else if (d>330 && d<370  &&  ListaBooleana[7] == 0) palabra=8;
	  else if (d>370 && d<410  &&  ListaBooleana[8] == 0) palabra=9;
	  else if (d>410 && d<450  &&  ListaBooleana[9] == 0) palabra=10;
	  setcolor(0);
	  box(0,0,getmaxx(),40,1,1); //Parche para eliminar el texto guia
      setcolor(15); 
	}
	if ( c>50 && c<450 && d>50 && d<450 && palabra !=0){  //compara que el mouse se encuentre dentro de la sopa y que ya se haya seleccionado una palabra
      if ( c>50 && c<450 && d>50 && d<450 && boolean == 0  ){ //boolean se encarga de diferenciar el inicio y el final de la palabra
	    i=(d-50)/40;  j=(c-50)/40;  //Relacionar i y j con la posicion del mouse (d y c respectivamente)
        box(50+(j)*40,50+(i)*40,90+(j)*40,90+(i)*40,1,2);
	    aux[0]=MatrizChar[i][j];  aux[1]='\x0';
	    outtextxy(65+(j)*40,50+(i)*40, aux);
	    boolean = 1;   //boolean==1 se refiere a que ya se ha seleccionado el inicio y falta el final
	    iprev=i;  jprev=j;  //iprev y jprev guarda los valores x y y de la casilla inicial
	    delay(100);  //para evitar que un clic sea tomado como mas de uno (te da tiempo para soltar el clic) 
	  }
	  else if ( c>50 && c<450 && d>50 && d<450 && boolean == 1 ){
	    i=(d-50)/40;  j=(c-50)/40;  //Relacionar i y j con la posicion del mouse (d y c respectivamente)
        box(50+(j)*40,50+(i)*40,90+(j)*40,90+(i)*40,1,3);
	    aux[0]=MatrizChar[i][j];  aux[1]='\x0';
	    outtextxy(65+(j)*40,50+(i)*40, aux);
	    boolean = 0;
		//compara palabra compara las posiciones de casilla inicial y final para saber si pertenecen a el inicio y el final de alguna palabra
		if(comparaPalabra(MatrizInt,i,j,iprev,jprev,palabra)==1){ //Si la comparacion es exitosa regresa 1
	      pintaPalabra(i, j, iprev, jprev, MatrizChar); //te pinta la palabra en la sopa de letras
		  raya(palabra, puntos);   //subraya la palabra de la lista de la derecha
		  cambiaBandera(MatrizBooleana,palabra, ListaBooleana);  //establece los valores booleanos a 1 porque ya se ha encontrado la palabra
		  palabra=0;  //reinicia la palabra para que elijan otra
		  setcolor(0);
	      box(0,0,getmaxx(),40,1,1);  //parche para borrar el texto guia
          setcolor(15);
		}
		else if(comparaPalabra(MatrizInt,i,j,iprev,jprev,palabra)==-1){  //si la comparacion fracasa devuelve -1
          box(50+(j)*40,50+(i)*40,90+(j)*40,90+(i)*40,1,0);  //despinta la casilla seleccionada
          aux[0]=MatrizChar[i][j];  aux[1]='\x0';  //convierte el char de la casilla a string (*char)
          outtextxy(65+(j)*40,50+(i)*40, aux);  //le escribe el char correspondiente a la casilla
          box(50+(jprev)*40,50+(iprev)*40,90+(jprev)*40,90+(iprev)*40,1,0);  //despinta la casilla seleccionada
          aux[0]=MatrizChar[iprev][jprev];  aux[1]='\x0';
          outtextxy(65+(jprev)*40,50+(iprev)*40, aux);
          generaSopa(MatrizBooleana, MatrizChar);  //vuelve a generar la sopa de letras
		  palabra=0;  //reinicia la palabra para que elijan otra
		  setcolor(0);
	      box(0,0,getmaxx(),40,1,1);
          setcolor(15);
		  }
	    delay(100);
	  }
	}
	if(completo(ListaBooleana)==1)k=2;  //Si ya se han descubierto todas las palabras, sacame del do_while
    break;
    case 2 : k=2;  //salir del do_while
	break;
  }
  pon();
  }while  (k !=2);
  box(0,0,getmaxx(),getmaxy(),1,1);  //limpia pantalla
  if (puntos==120){  //Si tienes la mayor puntuacion, entonces encontraste las 10 palabras
	  box(0,0,getmaxx(),getmaxy(),1,3);
      outtextxy(40,100,"Felicidades has encontrado las 10 palabras");
      outtextxy(50,140,"  y obtenido un puntaje perfecto de 120");
  }
  else{  //la otra forma para llegar aca sin haber decubierto las 10 palabras es rindiendote
    box(0,0,getmaxx(),getmaxy(),1,4);
  	outtextxy(230,100,"Te has rendido");
  }
  outtextxy(140,180,"Desea volver a jugar? S/N"); 
  tecla=getch();
  if(tecla=='s' || tecla == 'S') jugar = 1;  //jugar 1 = volver a jugar  
  else jugar = 0;  //jugar 0 = salir
}
void main()
{
  inicializa();
  int jugar=0;
  do{
  box(0,0,getmaxx(),getmaxy(),1,1); //limpia pantalla
  comienza(jugar);
  }while(jugar!=0);
}


