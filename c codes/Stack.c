#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void Push(int x)
{
  if(top == MAX_SIZE -1)
    {
		printf("stack overflow\n");
		return;
	}
	A[++top] = x;
}
void Pop()
{
	if(top == -1) {
		printf("No element to pop\n");
		return;
	}
	top--;
}
int Peek()
{
	return A[top];
}
int IsEmpty()
{
    if(top == -1)
        return 1; //1 for true
    return 0;
}
void Print() {
	int i;
	for(i = 0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");
}
void main() {
  Push(2);
  Print();
	Push(5);
	Print();
	Push(10);
	Print();
	Pop();
	Print();
	Push(12);
	Print();
}
