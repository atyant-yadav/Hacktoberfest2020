#include<stdio.h>
#include<math.h>
int main()
{
	int arr[5]={1,2,0,6,9}, min=99;
	for(int i=0;i<5;i++)
	{
		if(min>arr[i])
			min=arr[i];
	}
	cout<<"\nMinimum is : "<<min<<endl;
	return 0;
}		
