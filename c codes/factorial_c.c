#include<stdio.h>
#include<math.h>
int main()
{
	int fact=1, num=5;
	for(int i=1;i<=num;i++)
	{
		fact*=i;
	}
	cout<<"\nFactorial of  5 is : "<<fact<<endl;
	return 0;
}		
