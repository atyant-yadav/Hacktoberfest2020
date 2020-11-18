#include<stdio.h>
#define MAX 5
int Stack[MAX];
int top=-1;

void push()
{
    int x;
    while(top<MAX)
    {
        if(top==MAX-1)
        {
            printf("MAX limit reached (Overflow)\n");
            return;
        }
        else
        {
            printf("Enter data\n");
            scanf("%d",&x);
            top++;
            Stack[top]=x;
        }
        
    }
}
void display()
{
    int i;
    printf("Your elements are\n");
    for(i=top;i>-1;i--)
    {
        printf("%d\n",Stack[i]);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Topmost element is %d",Stack[top]);  
    } 
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        item=Stack[top];
        top--;
        printf("poped item is %d",item);
    }
    
}
void main()
{
    int a;

    while(a!=5)
    {
        printf("\nType 1 to push\nType 2 to Display\nType 3 to pop\nType 4 to peek\nType 5 to exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
        push();
        break;
        
        case 2:
        display();
        break;
        
        case 3:
        pop();
        break;

        case 4:
        peek();
        break;

        case 5:
        printf("Exited\n");
        break;

        default:
        printf("Wrong Choice!!");
        }
    }
}
//Ashutosh Pandey