#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2,max,lcm,i=1;
	clrscr();


	printf("Enter Number 1:");
	scanf("%d",&n1);

	printf("Enter Number 2:");
	scanf("%d",&n2);

	if(n1>n2)
	{
	max=n1;
	}
	else
	{
	max=n2;
	}
	 i=max;

	 do
	 {
	 if(i%n1==0 && i%n2==0)
	 {
	 lcm=i;
	 break;
	 }
	 i=i+max;
	 }
	 while(1);

	 printf("LCM=%d",lcm);
	 getch();
	 }
