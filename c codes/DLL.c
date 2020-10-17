#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *link;
	struct node *back;
	
};

struct node *start=NULL;
struct node *tail=NULL;
struct node *ptr,*temp,*save,*next;



void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void insert_after_pos();
void delete_from_beg();
void delete_from_end();
void delete_from_pos();
void reverse();
void display();
//void insert_after_pos();


int main()
{
	int choice;

/////////////////////////////////////////////////////////////
printf(" ******* IMPLEMENTATION OF DOUBLY LINKED LIST ************************\n\n\n");	
	while(1)
	{
	printf("What do you want?\n1: Insert at begining\n2: Insert at end\n3: Insert at a given pos\n4: Insert after a position\n5: Delete from beginning\n6: Delete from end\n7: Delete from position\n8: Reverse the linked list\n9: Display\n\n");
	printf("Choice Selected = ");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		insert_at_beg();
	}
	else if(choice==2)
	{
		insert_at_end();
		
	}
	else if(choice==3)
	{
		insert_at_pos();
	}
	

	else if(choice==4)
	{
		insert_after_pos();
	}
	else if(choice==5)
	{
		delete_from_beg();
	}
	else if(choice==6)
	{
		delete_from_end();
	}
	else if(choice==7)
	{
		delete_from_pos();
	}
	else if(choice==8)
	{
		reverse();
	}
	else if(choice==9)
	{
		display();
	}
	else
	{
		break;
	}
}		
}


void insert_at_beg()
{
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&item);
	
	
	temp->data=item;
	temp->link=NULL;
	temp->back=NULL;	
	
	if(start==NULL)
	{
		start=temp;
		tail=temp;
	}
	else
	{
		temp->link=start;
		start->back=temp;
		start=temp;
	}
	printf(" DATA IS INSERTED AT BEGINING OF THE LIST \n");
}


void insert_at_end()
{
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&item);
	
	
	temp->data=item;
	temp->link=NULL;
	temp->back=NULL;	
	
	if(start==NULL)
	{
		start=temp;
		tail=temp;
	}
	
	else
	{
		tail->link=temp;
		temp->back=tail;
		tail=temp;
	}
		printf(" DATA IS INSERTED AT END OF THE LIST \n");
}

void insert_at_pos()
{
	int item,pos,i=1;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&item);
	
	
	temp->data=item;
	temp->link=NULL;
	temp->back=NULL;
	printf("Enter position where you want to insert: ");
	scanf("%d",&pos);	
	
	if(start==NULL)
	{
	
		start=temp;
		tail=temp;	
	}
	else
	{
		ptr=start;
		while(i<pos)
		{
			save=ptr;
			ptr=ptr->link;
			i++;
		}
		
		temp->link = save->link;
		ptr->back=temp;
		save->link=temp;
		temp->back=save;
	}
		printf(" DATA IS INSERTED AT POSITION %d OF THE LIST \n",pos);
}

void insert_after_pos()
{
	int item,pos,i=1;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&item);
	
	
	temp->data=item;
	temp->link=NULL;
	temp->back=NULL;
	printf("Enter position where you want to insert: ");
	scanf("%d",&pos);	
	
	if(start==NULL)
	{
	
		start=temp;
		tail=temp;	
	}
	else
	{
		ptr=start;
		while(i<pos+1)
		{
			save=ptr;
			ptr=ptr->link;
			i++;
		}
		
		temp->link = save->link;
		ptr->back=temp;
		save->link=temp;
		temp->back=save;
	}
		printf(" DATA IS INSERTED AFTER POSITION %d OF THE LIST \n",pos);
}

void delete_from_beg()
{
	if(start==NULL)
	{
		printf("THERE IS NOTHING TO DELETE !!! GET LOST\n");
	}
	else
	{
		ptr=start;
		save=ptr->link;
		save->back=NULL;
		start=save;
		free(ptr);
		
	}
}


void delete_from_end()
{
	if(start==NULL)
	{
		printf("THERE IS NOTHING TO DELETE !!! GET LOST\n");
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
			save=ptr;
			ptr=ptr->link;
			
		}
		
		save->link=NULL;
		tail=save;
		ptr->back=NULL;
		free(ptr);
		
	}
}

void delete_from_pos()
{
	int i=1,pos;
	printf("ENTER POSITION WHERE YOU WANT TO DELETE\n");
	scanf("%d",&pos);
	if(start==NULL)
	{
		printf("THERE IS NOTHING TO DELETE !! GET LOST ");
	}
	else
	{
		ptr=start;
		while(i<pos)
		{
			ptr=ptr->link;
			i++;
		}
		
		save=ptr->back;
		next=ptr->link;
		next->back=save;
		save->link=next;
		free(ptr);
	}
}

void reverse()
{
	if(start==NULL)
	{
		printf("LIST IS EMPTY SO CANT BE REVERSED\n");
	}
	else
	{
		//printf("hello");
		ptr=start;
		while(ptr!=NULL)
		{
			next=ptr->link;
			ptr->link=ptr->back;
			ptr->back=next;
			
			ptr=next;
		}
		ptr=start;
		start=tail;
		tail=ptr;
	}
	printf("LINKED LIST IS REVERSED\n");
}
void display()
{
	printf("*********************  DATA IN DOUBLE LINKED LIST IS  ******************************\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
}
