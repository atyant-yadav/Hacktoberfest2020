#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node *start, *current, *temp, *prev;

//function to check if the List is empty or not
bool isEmpty()
{
	if(start->next==NULL)
		return true;
		else
		return false;
}

//function to create the Linked List
void create()
{
	start=(struct node*)malloc(sizeof(struct node));
	start->data=NULL;
	start->next=NULL;
	temp=start;
}

//function to add nodes to the Linked List
void enqueue()
{
    current=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value of node to add:");
	scanf("%d",&current->data);
	temp->next=current;
	current->next=start;
	temp=current;
}

//function to delete nodes from the starting of the queue
void dequeue()
{
   if(isEmpty())
	printf("\nThe List is Empty\n");
	else
	{
		temp=start->next;
		printf("\nDeleted node data: %d\n",temp->data);
		start->next=temp->next;
	}	
}

void display()
{
    temp=start;
	while(temp->next!=start)
	{
		temp=temp->next;
		printf("%d    ",temp->data);
    }
}

int main()
{
   create();
   for(int i=0;i<5;i++)
   enqueue();
   printf("\nThe queue after enqueue operations is:   ");
   display();
   dequeue();
   dequeue();
   printf("\nThe queue after dequeue operations is:   ");
   display();
 	return 0;
}
