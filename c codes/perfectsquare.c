//program to find whether a number is a perfect square
#include<stdio.h>
#include<math.h>

int main()
{
	int n,temp;
	
	printf("enter the number\n");
	
	scanf("%d",&n);
	
	temp=sqrt(n);
	
	if(temp*temp==n)
		
		printf("the number is a perfect square\n");
	
	else
		
		printf("the number is not a perfect square\n");
	
	return 0;
}


