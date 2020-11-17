#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
void push(int a[],int x)
{
	++top;
	if(top>=MAX)
	{
	printf("Stack is full");
	exit(1);
	}
	a[top]=x;
}
int pop(int a[])
{
	int x;
	if(top==-1)
	{
	printf("Stack is Empty");
	exit(1);
	}
	x = a[top];
	top--;
	return x;
}
void main()
{
	int a[MAX],n,x;
	printf("How many elements to push...?");
	scanf("%d",&n);
	printf("Enter the elements...");
	for(int i=0;i<n;i++)
	{
	printf("Element sequential..");
	scanf("%d",&x);
	push(a,x);
	}
	for(int i=0;i<n;i++)
	{
	x=pop(a);
	printf("%d\n",x);
	}
}
