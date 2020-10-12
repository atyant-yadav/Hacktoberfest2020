#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node *start, *current, *temp, *prev;

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
	current->next=start;
	temp=current;
}

//function to search whether element present in Linked List or not
void search()
{
	int pos=0;
	int to_search;
	int found=0;
	printf("Enter the number to be searched: ");
	scanf("%d",&to_search);
	temp=start;
	while(temp->next!=start)
	{
	if(temp->data!=to_search){
	temp=temp->next;
	pos++;
	}
	else
	{
		break;}
    }
    
    if(pos!=0)
    printf("Number found in the List at %d position",pos);
    else
    printf("Number not found in the List");
	
}

int main()
{
	create();
	create_node();
	create_node();
	create_node();
	create_node();
	search();
	return 0;
}
