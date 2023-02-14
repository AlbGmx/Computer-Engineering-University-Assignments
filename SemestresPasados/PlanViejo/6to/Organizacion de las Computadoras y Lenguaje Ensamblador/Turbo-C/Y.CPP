#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
	clrscr();
	sound(146);     delay(200);	nosound();   delay(10);	//re
	sound(146);     delay(200);	nosound();   delay(10);	//re
	sound(146);     delay(200);	nosound();   delay(10);	//re
	sound(146);     delay(200);	nosound();   delay(500);//re


	sound(146);     delay(200);	nosound();   delay(10);	//re
	sound(130);     delay(200);	nosound();   delay(200);//do

	sound(110);     delay(200);	nosound();   delay(10); //la
	sound(87);   	delay(200);	nosound();   delay(500);//fa

	sound(87);     	delay(200);	nosound();   delay(10);	//fa
	sound(146);     delay(200);	nosound();   delay(200);//re

	sound(146);     delay(200);	nosound();   delay(200);//re

	sound(130);     delay(200);	nosound();   delay(10);	//do
	sound(116);     delay(200);	nosound();   delay(10);//sib
	sound(130);     delay(500);	nosound();   delay(10);	//do


	getch();
}