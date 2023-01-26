
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main(){
	int gdriver=DETECT,gmode;
	int i,j,c1,c2;

	initgraph(&gdriver,&gmode,"c:\\TURBOC3\\BGI");
	for(i=0;i<120;i++){
		clrscr();
		for( j=0; j<35; j++){
			if(190-i>130){
				c1=4,c2=1;
			}
			else{
				c1=14,c2=11;
			}
			setcolor(c1);
			circle(320,190-i,j-10);  //sun
			//clouds
			setcolor(c2);
			arc(100+i,200,0,180,j-25);
			arc(115+i,200,0,180,j-20);
			arc(140+i,200,0,180,j-15);
			arc(165+i,200,0,180,j-25);

			arc(405+i,150,0,180,j-25);
			arc(430+i,150,0,180,j-15);
			arc(455+i,150,0,180,j-25);
		 }
	}
      //mountains
	int b=0;
	while(b+250!=300){
		b++;
		setcolor(2);
		line(0,300,250,250+b);
		line(250,250+b,310,300);
		line(380,250+b,220,300);
		line(380,250+b,660,300);
		delay(10);
	}
	for( j=0;j<35;j++){
		if(190-i>13){
			c1=4,c2=1;
		}
		else{
			 c1=14,c2=11;
		}
		setcolor(c1);
		circle(320,190-i,j-10);                       //sun
		//clouds
		setcolor(c2);
		arc(100+i,200,0,180,j-25);
		arc(115+i,200,0,180,j-20);
		arc(140+i,200,0,180,j-15);
		arc(165+i,200,0,180,j-25);

		arc(405+i,150,0,180,j-25);
		arc(430+i,150,0,180,j-15);
		arc(455+i,150,0,180,j-25);
		sound(400);
		delay(200);
		sound(450);
		delay(100);
		sound(500);
		sound(550);
		sound(450);
		sound(400);
		sound(350);




		}
    getch();
}

