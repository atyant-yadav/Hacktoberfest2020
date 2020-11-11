/* Write a C program to implement the basic operations of singly linked list. */

#include<stdio.h>
#include<stdlib.h>

struct node //Node Structure
{
	int data;
	struct node *next;
}*start=NULL;

void add_beg() //Adds value at the begining
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&tmp->data);
	
	if(start==NULL)
	{
		tmp->next=NULL;
	}
	else
	{
		tmp->next=start;
	}
	start=tmp;
}

void add_after() //Adds value after a specific positon
{
	struct node *tmp, *q;
	int pos, i;
	if(start==NULL)
	{
		printf("No node is present.\n");
		return ;
	}
	printf("Enter the node number after which you want to insert data: ");
	scanf("%d", &pos);
	q=start;
	for(i=1;i<pos;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			printf("Less number of nodes present.\n");
			return ;
		}
	}
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&tmp->data);
	tmp->next = q->next;
	q->next = tmp;
}

void add_end() //Adds value at the end
{
	struct node *q, *tmp, *p;
	q=start;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	while(q->next!=NULL)
	{
		q=q->next;
	}
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&tmp->data);
	q->next=tmp;
	tmp->next=NULL;
}

void display() //Displays the whole list
{
	struct node *q;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=start;
	printf("The nodes are:\n");
	while(q!=NULL)
	{
		printf("%d\n",q->data);
		q=q->next;
	}
}

void count() //Counts the number of nodes
{
	int count=0;
	struct node *q;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=start;
	while(q!=NULL)
	{
		count++;
		q=q->next;
	}
	printf("Number of Nodes: %d\n",count);
}

void del_beg() //Deletes the first element
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("No node present.\n");
	}
	tmp=start;
	start=start->next;
	printf("%d is deleted form the begining.\n",tmp->data);
	free(tmp);
}

void del_after() //Deletes the element in a specified position
{
	struct node *tmp, *p, *q;
	int pos,i;
	if(start==NULL)
	{
		printf("No node present.\n");
	}
	printf("Enter the node number you want to delete: ");
	scanf("%d",&pos);
	if(pos<=0)
	{
		printf("Position should be more than 1.\n");
		return ;
	}
	if(pos==1)
	{
		tmp=start;
		start=start->next;
		printf("%d is deleted form the node with position %d.\n",tmp->data,pos);
		free(tmp);
	}
	else
	{
		p=start;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
			if(p==NULL)
			{
				printf("Less number of nodes present.\n");
				return ;
			}
		}
		q=p->next;
		p->next=q->next;
		printf("%d is deleted form the node with position %d.\n",q->data,pos);
		free(q);
	}
}

void del_end() //Deletes the last element
{
	struct node *q, *p;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=start;
	while(q->next->next!=NULL)
	{
		q=q->next;
	}
	p=q->next;
	q->next=NULL;
	printf("%d is deleted form the end.\n",p->data);
	free(p);
}

int main() //main
{
	int ch;
	while(1)
	{
		printf("1. Add at begining\n2. Add after position\n3. Add at end \n4. Display the node data\n5. Count the number of nodes\n6. Delete at begining\n7. Delete after position\n8. Delete at end\n9. Exit\nYour choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				add_beg();
				break;
			case 2:
				add_after();
				break;
			case 3:
				add_end();
				break;
			case 4:
				display();
				break;
			case 5:
				count();
				break;
			case 6:
				del_beg();
				break;
			case 7:
				del_after();
				break;
			case 8:
				del_end();
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid Option!\n");
		}
	}
}
