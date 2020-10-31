#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main(int a,char *p[])
{
	int x,y,z;
	clrscr();
	x=atoi(p[1]);
	y=atoi(p[2]);
	z=x+y;
	printf("%d",z);
}