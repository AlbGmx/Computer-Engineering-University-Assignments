#include <conio.h>
#include <stdio.h>
#include <dos.h>
//
//

void main()
{
 textbackground(RED);
 clrscr();

 textbackground (BLUE);
 textcolor(CYAN);
 cprintf("somos ingenieros");

 textbackground(RED);
 textcolor(YELLOW);
 gotoxy( 8, 9); cprintf("������ͻ");
 gotoxy( 8, 10);cprintf("�      �");
 gotoxy( 8, 11);cprintf("������ͼ");


 gotoxy(10,10); cprintf("UABC");
 delay(1000);

 textcolor(RED);
 gotoxy(10,10);cprintf("UABC");
 delay(1000);

 textcolor(YELLOW);
 gotoxy(20,10);cprintf("UABC");
 delay(1000);

textcolor(RED);
 gotoxy(20,10);cprintf("UABC");
 delay(1000);

 textcolor(YELLOW);
 gotoxy(30,10);cprintf("UABC");
 delay(1000);

textcolor(RED);
 gotoxy(30,10);cprintf("UABC");
 delay(1000);

 textcolor(YELLOW);
 gotoxy(40,10);cprintf("UABC");
 delay(1000);

  insline(); delay(1000); sound(90000);
  insline(); delay(1000); sound(90000);
  insline(); delay(1000); sound(90000);
  insline(); delay(1000); sound(90000);

  delline(); delay(1000); sound(90000);
  delline(); delay(1000); sound(90000);
  delline(); delay(1000); sound(90000);
  delline(); delay(1000); sound(90000);

  getch();
}