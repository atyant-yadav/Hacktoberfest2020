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
	return x;
}
int popdisplay(int a[])
{
	int x;
	if(top==-1)
	{
	exit(1);
	}
	x = a[top];
	top--;
	return x;
}
void main()
{
	int ch=-1,a[MAX];
	while(ch!=0)
	{
	printf("Enter your choice: 1 for pushing into the stack, 2 for popping out of the stack,3 for displaying all the stack elements and 0 to exit:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	{
	int n;
	printf("Enter the element to be inserted:");
	scanf("%d",&n);
	push(a,n);
	break;
	}
	case 2:
	{
	int n;
	printf("The popped out element is:");
	n = pop(a);
	printf("%d\n",n);
	break;
	}
	case 3:
	{
	int n;
	printf("The elements are:\n");
	while(n!=-999)
	{
	n = popdisplay(a);
	printf("%d\n",n);
	}
	break;
	}
	}
	}
}

