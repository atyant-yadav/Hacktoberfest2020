/* Write a C program to implement the basic operations of circular linked list. */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node //node structure
{
	int data;
	struct node *next;
}*last=NULL;


void add_beg() //Adds value at the begining
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&tmp->data);
	
	if(last==NULL)
	{
		tmp->next=tmp;
		last=tmp;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
	}
}

void add_after() //Adds value after a specific positon
{
	struct node *tmp, *q;
	int pos, i;
	if(last==NULL)
	{
		printf("No node is present.\n");
		return ;
	}
	printf("Enter the node number after which you want to insert data: ");
	scanf("%d", &pos);
	q=last->next;
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
	if(q==last)
	{
		last=tmp;
	}
}

void add_end() //Adds value at the end
{
	struct node *q, *tmp;
	if(last==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=last->next;
	do
	{
		q=q->next;
	}while(q!=last->next->next);
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&tmp->data);
	tmp->next = q->next;
	q->next = tmp;
	last = tmp;
}

void display() //Displays the whole list
{
	struct node *q;
	if(last==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=last->next;
	printf("The nodes are:\n");
	do
	{
		printf("%d\n",q->data);
		q=q->next;
	}while(q!=last->next);
}

void count() //Counts the number of nodes
{
	int count=0;
	struct node *q;
	if(last==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=last->next;
	do
	{
		count++;
		q=q->next;
	}while(q!=last->next);
	printf("Number of Nodes: %d\n",count);
}

void del_beg() //Deletes the first element
{
	struct node *tmp;
	if(last==NULL)
	{
		printf("No node present.\n");
	}
	tmp=last->next;
	if(last->next==last)
	{
		last=NULL;
	}
	else
	{
		last->next=tmp->next;
	}
	printf("%d is deleted form the begining.\n",tmp->data);
	free(tmp);
}

void del_after() //Deletes the element in a specified position
{
	struct node *tmp, *p, *q;
	int pos, i;
	if(last==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	printf("Enter the node number you want to delete: ");
	scanf("%d",&pos);
	if(pos<=0)
	{
		printf("Position should be more than 1.\n");
		return ;
	}
	else if(pos==1)
	{
		del_beg();
	}
	else
	{
		if(last->next==last)
		{
			last=NULL;
		}
		else
		{
			p=last->next;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
			if(p==last->next)
			{
				printf("Less number of nodes present.\n");
				return ;
			}
		}
		q=p->next;
		p->next=q->next;
		if(q==last)
		{
			last=p;
		}
		printf("%d is deleted form the node with position %d.\n",q->data,pos);
		free(q);
		}
	}
}

void del_end() //Deletes the last element
{
	struct node *q;
	if(last==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	if(last->next==last)
	{
		del_beg();
	}
	else
	{
		q=last->next;
		do
		{
			q=q->next;
		}while(q!=last->next->next);
		q->next=last->next;
		printf("%d is deleted form the end.\n",last->data);
		free(last);
		last=q;
		}
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
