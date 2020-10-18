#include<stdio.h>
#include<conio.h> 
# define N 5
int stack[N],top=-1; 
void push(void); 
void pop(void); 
void display(void); 
void peek(void);
void push()
{
  if(top>=N-1)
  {
    printf("overflow condition\n");
  }
  else
  {  
    int data;
    printf("enter the value you want to push"); 
    scanf("%d",&data);
    top++;
    stack[top]=data;
  } 
}
void pop() 
{
  if(top==-1)
   {printf("underflow condition"); }
   else
   {
     top--; }
   }
 void display()
 {
    if(top==-1)
    {printf("stack is empty");}
    else
    {
        int i;
        printf("elememt in the stack :-");
        for(i=top;i>=0;i--) {
        printf(" %d",stack[i]); }
    } 
 }
 void peek() {if(top==-1)
 {printf("stack is empty"); }
 else
 {printf("peek element is:- %d \n",stack[top]); }
}
int main()
{
  push();
  push();
  push();
  push(); 
  if(top==-1)
{printf("stack is empty"); return 0;
}
pop(); peek(); display();
}
