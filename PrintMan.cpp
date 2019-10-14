#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver, &gmode, “c:\turboc3\bgi”);

   //for head
   ellipse(320,95,360,0,25,20);
   line(298,85,341,85);
   circle(310,90,2);
   circle(330,90,2);
   arc(320,100,200,-20,10);

   //for neck
   line(313,115,313,125);
   line(328,115,328,125);

   //For centre part
   arc(320,225,72,107,100);
   line(290,129,290,200);
   line(350,129,350,200);
   line(290,193,350,193);
   line(290,200,350,200);

   //for legs
   line(290,200,285,280);
   line(320,225,305,280);
   line(322,225,335,280);
   line(350,200,355,280);

   //for right hand
   line(290,129,255,165);
   line(255,165,290,200);
   line(290,149,275,165);
   line(275,165,290,182);

   //for left hand
   line(350,129,385,165);
   line(385,165,350,200);
   line(350,149,365,165);
   line(365,165,350,182);

   //for shoes
   line(285,280,275,287);
   line(275,287,305,287);
   line(305,280,305,287);

   line(335,280,335,287);
   line(335,287,365,287);
   line(355,280,365,287);

   //for name
   settextstyle(2,HORIZ_DIR,4);
   outtextxy(293,150,”The Crazy”);
   outtextxy(292,160,”Programmer”);

   getch();
   closegraph();
}
