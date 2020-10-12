/*----------------------   C program for Singly Linked-List with all operations   --------------------------------*/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start,*current,*temp,*prev;

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

//function to add a node at the starting
void insert_start()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value of node to add:");
	scanf("%d",&temp->data);
	temp->next=start->next;
	start->next=temp;
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
   	
   	if(temp->next!=NULL)
   	{
   	current=(struct node*)malloc(sizeof(struct node));
   	printf("\nEnter the value want to insert\n");
   	scanf("%d",&current->data);
   	prev->next=current;
   	current->next=temp;
    }
   else
   create_node();
}

//function to delete the last node
void delete_last()
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
		printf("Deleted node data: %d\n",temp->data);
    }
}

//function to delete the start node 
void delete_start()
{
	if(isEmpty())
	printf("\nThe List is Empty\n");
	else
	{
		temp=start->next;
		printf("Deleted node data: %d\n",temp->data);
		start->next=temp->next;
	}
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
	   printf("Deleted Node is having value %d",temp->data);
	   }
	   else
	   printf("List does not have that many elements");
	}	
}

//function to search whether element present in Linked List or not
void search()
{
	int to_search;int found=0;
	printf("Enter the number to be searched: ");
	scanf("%d",&to_search);
	temp=start;
	while(temp->next!=NULL)
	{
	if(temp->data!=to_search)
	temp=temp->next;
	else
	{
		found=1;
		break;}
    }
    if(temp->data==to_search)
    found=1;
    
    if(found=1)
    printf("Number found in the List");
    else
    printf("Number not found in the List");
	
}

//function to display the elements of the Linked List
void display()
{
temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%d    ",temp->data);
    }
}

//Main Driver Code
int main()
{
   	printf("Choose the operation to perform on the List\n");
	printf("1-Add element to the List\n");
	printf("2-Insert element at the starting of the List\n");
	printf("3-Insert Element at the given position\n");
	printf("4-Delete last element from the List\n");
	printf("5-Delete the first element from the List \n"); 
	printf("6-Delete the element specifed from the List \n");
	printf("7-Search an element from the List\n");
	printf("8-Print the elements of the List \n");
	printf("9-EXIT\n");
	
	int ch;
	printf("\nEnter your choice:\n");
	scanf("%d",&ch);
	create();
	while(ch!=9)
	{	
	switch(ch)
		{
		case 1:
			create_node();
			break;
	    case 2:
			insert_start();
			break;
		case 3:
		    insert_mid();
			break;
        case 4:
			delete_last();
			break;
        case 5:
			delete_start();
			break;
		case 6:
			delete_mid();
			break;
        case 7:
			search();
			break;
        case 8:
			display();
			break;  
      }
	printf("\nEnter your choice:\n");
	scanf("%d",&ch);	
	}
   return 0;
}
