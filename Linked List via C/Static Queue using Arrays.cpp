#include<stdlib.h>
#include<stdio.h>

int main()
{
	int queue[20];
	int front=-1;
	int rear=-1;
	
    //adding elements in the queue at the last
	for(int i=0;i<5;i++)
	{
		int val;
		if((front==-1)&&(rear==-1))
		{
           front=0;rear=0;
		   printf("Enter the Value to add:");
		   scanf("%d",&val);
		   queue[rear]=val;			
		}
		else if((rear+1)==20)
		printf("The queue is Full\n");
		else
		{
		    printf("Enter the Value to add:");
		    scanf("%d",&val);
			rear=rear+1;
			queue[rear]=val;
		}
	}
	printf("After adding values queue is:  ");
	for(int i=front;i<=rear;i++)
	printf("%d    ",queue[i]);
	
	//removing element from start of the queue
	for(int i=0;i<3;i++)
	{
		if(front==-1)
		printf("The queue is Empty\n");
		else
		front=front+1;
	}
	
	printf("\nAfter removing values queue is:");
	for(int i=front;i<=rear;i++)
	printf("%d   ",queue[i]);
	
	printf("\nFront=%d\nRear=%d",front,rear);
	return 0;
}
