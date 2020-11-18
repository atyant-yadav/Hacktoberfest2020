#include<stdio.h>
int main()
{
	int h1,m1,h2,m2,diff;
	printf(" Enter hour and minute  ");
	scanf(" %d %d",&h1,&m1);
		printf(" Enter hour and mminute ");
	scanf(" %d %d",&h2,&m2);
	
	if(m1==m2)
	{
		printf("Difference = %d :00",h2-h1);
	}
	else if(m2>m1)
	{
		printf("Difference = %d:%d",h2-h1,m2-m1);
		
	}
	else
	if(m2<m1)
	{
			printf("Difference = %d:%d",h2-h1-1,60-(m1-m2));
	}
	return 0;
}
