#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node *start, *current, *temp, *prev,*top;

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
void push()
{
  current=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value of node to add:");
	scanf("%d",&current->data);
	temp->next=current;
	current->next=NULL;
	temp=current;
	top=current;
}

//function to delete the last node
void pop()
{
     if(isEmpty())
	printf("\nThe List is Empty\n");
	else
	{
		prev=start;
		temp=start;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		top=prev;
		printf("Poping Value %d\n",temp->data);
    }
}

int main()
{
	create();
	for(int i=0;i<10;i++)
	push();
	for(int i=0;i<5;i++)
	pop();
    printf("Top of Stack has the Value: %d",top->data);
    return 0;
	}
