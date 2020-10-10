#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2,min,i,hcf;
	clrscr();

	printf("Enter Number 1:");
	scanf("%d",&n1);

	printf("Enter Number 2:");
	scanf("%d",&n2);
	i=1;
	if(n1<n2)
	{ min=n1;}
	else
	{ min=n2;}
	do
	{
		if(n1%i==0 && n2%i==0)
		{
		hcf=i;
		}
		i++;
	}
	while(i<=min);

	printf("HCF=%d",hcf);

	getch();
}