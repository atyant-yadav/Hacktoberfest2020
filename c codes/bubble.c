#include<stdio.h>
main()
{
	int i, a[50],j,n,temp;
	printf("Enter the no of elements in array\n");
	scanf("%d",&n);
	printf("Enter the elements in array\n");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{	for(j=0;j<n-1-i;j++)
		{	if(a[j]>a[j+1])
			{	temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			
		}
		
	}
	printf("The sorted array\n");
	for(i=0;i<n;i++)
	{	printf("%d\n",a[i]);
	}
}
