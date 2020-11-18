#include<stdio.h>
#include<conio.h>
void main()
{
	int n,k,i=0,j=1,sum=0;

	clrscr();

	printf("Enter Limit n:");
	scanf("%d",&n);

	printf("The FIBONACCI series is:\n");

	k=2;

	printf("%d\t",i);
	printf("%d\t",j);

	while(k<n)
	{
	sum=i+j;
	i=j;
	j=sum;

	printf("%d\t",sum);

	k++;
	}

	getch();
	}