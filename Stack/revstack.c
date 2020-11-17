#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 6
int stk[MAX];
int top=-1;
void push(int element);
int pop();

int main()
{
	int arr[MAX],n,i,val;
	printf("\nEnter the number of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter the elements of the array sequentially:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		push(arr[i]);
	}
	for(i=0;i<n;i++)
	{
		val = pop();
		arr[i]=val;
	}
	printf("\nThe reversed array is:");
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
	return 0;
}

void push(int element)
{
	if(top==MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	stk[++top] = element;
}

int pop()
{
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	return (stk[top--]);
}