#include<stdio.h>
#include<math.h>
 main()
{
	int i=0,n,re,num=0;
	printf("Enter the binary number:");
	scanf("%d",&n);
	while(n>0)
	{
		re=n%10;
		num=num+re*pow(2,i);
		i++;
		n=n/10;
	}
	printf("The decimal number =%d",num);
}
