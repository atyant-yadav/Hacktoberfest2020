#include<stdio.h>
#include<stdlib.h>
# define max 3
int queue[max],front,rear;
front=-1;
rear=-1;
void create(int val)
{

    if(front==-1)
    {
        front=rear=0;
        queue[rear]=val;
    }
    else if(rear==max-1)
        printf("\n\n QUEUE OVERFLOW!!!!!");
    else
    {
        rear++;
        queue[rear]=val;
    }

}
void dequeue()
{
    if(front==-1)
        printf("\n\n QUEUE UNDERFLOW!!!!!");

    else if(front==rear)
    {
        printf("\n The deleted element is : %d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n The deleted element is : %d",queue[front]);
        front++;
    }

}
void display()
{
    int temp;
    temp=front;
    printf("\n THE POSITION OF FRONT IS %d\n THE POSITION OF REAR IS %d",front,rear);
    printf("\n The elements in array : ");
    while(temp<=rear)
    {
        printf("\t%d",queue[temp]);
        temp++;
    }
}
int main()
{
    int ch,val;
while(ch!=4)
{
printf("\n\n\t MENU \n 1. PUSH VALUES IN QUEUE\n 2.POP VALUE FROM QUEUE\n 3.DISPLAY QUEUE\n 4.EXIT \n\n Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
    case 1 : printf("\n Enter value to be pushed in queue : ");
             scanf("%d",&val);
             create(val);
             break;
    case 2 : dequeue();
             break;
    case 3 : display();
             break;
    case 4 : exit(0);
             break;
   default : printf("Invalid Choice !!!!!\n");
}
}
 return 0;

}
