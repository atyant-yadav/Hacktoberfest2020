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
void create_node()
{
  current=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value of node to add:");
	scanf("%d",&current->data);
	temp->next=current;
	current->next=NULL;
	temp=current;
}

//function to add a node in the middle
void insert_mid()
{
    int pos;
   	printf("\nEnter the position want to insert\n");
   	scanf("%d",&pos);
   	prev=start;
   	temp=start;
   	int i=0;
   	while((temp->next!=NULL)&&(i<pos))
   	{
   		prev=temp;
   		temp=temp->next;
   		i++;
   	}
   	current=(struct node*)malloc(sizeof(struct node));
   	printf("\nEnter the value want to insert\n");
   	scanf("%d",&current->data);
   	prev->next=current;
   	current->next=temp;
}

//function to delete from the middle
void delete_mid()
{
   if(isEmpty())
   printf("\nList is Empty\n");
   else
   {
   	int pos;
   	printf("\nEnter the position want to delete\n");
   	scanf("%d",&pos);
   	prev=start;
   	temp=start;
   	int i=0;
   	while((temp->next!=NULL)&&(i<pos))
   	{
   	   prev=temp;
		temp=temp->next;
		i++;	
	   }
	   if(temp->next!=NULL)
	   {
	   prev->next=temp->next;
	   printf("Deleted Node is having value %d\n",temp->data);
	   }
	   else
	   printf("List does not have that many elements");
	}	
}


//function to display the elements of the Linked List
void display()
{
	printf("\nList is:");
     temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%d    ",temp->data);
    }
}

int main()
{
   create();
   create_node();
   create_node();
   create_node();
   display();
   insert_mid();
   display();
   delete_mid();
   display();
   return 0;
}
