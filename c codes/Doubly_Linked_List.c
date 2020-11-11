/* Write a C program to implement the basic operations of doubly linked list. */

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node //node structure
{
	int data;
	struct node *next;
	struct node *prev;
}*start=NULL;

void add_beg() //Adds value at the begining
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&tmp->data);
	tmp->prev=NULL;
	if(start==NULL)
	{
		tmp->next=NULL;
	}
	else
	{
		tmp->next=start;
		start->prev=tmp;
	}
	start=tmp;
}

void add_end()  //adds node at the end
{
	struct node *tmp, *q;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	q=start;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&tmp->data);
	q->next=tmp;
	tmp->prev=q;
	tmp->next=NULL;
}

void add_after() //adds node after a particular node
{
	struct node *tmp, *q;
	int pos, i;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	printf("Enter the node number after which you want to insert data: ");
	scanf("%d", &pos);
	if(pos==1)
	{
		add_beg();
	}
	else
	{
		q=start;
		for(i=1; i<pos; i++)
		{
			q=q->next;
			if(q==NULL)
			{
				printf("Less number of nodes present.\n");
				return ;
			}
		}
		if(q->next==NULL)
		{
			add_end();
		}
		else
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			printf("Enter data: ");
			scanf("%d",&tmp->data);
			tmp->next=q->next;
			tmp->prev=q;
			q->next->prev=tmp;
			q->next=tmp;
		}
	}
}

void display() //displays the nodes
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

void count() //counts number of nodes
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

void del_beg() //deletes the first node
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	tmp=start;
	start=start->next;
	start->prev=NULL;
	printf("%d is deleted form the begining.\n",tmp->data);
	free(tmp);
}

void del_end() //deletes the last node
{
	struct node *p, *q;
	int i;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	p=start;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	q=p->next;
	p->next=NULL;
	printf("%d is deleted form the end.\n",q->data);
	free(q);
}

void del_after() //deletes a particular node
{
	struct node *p, *q, *tmp;
	int pos,i;
	if(start==NULL)
	{
		printf("No node present.\n");
		return ;
	}
	printf("Enter the node position you want to delete: ");
	scanf("%d",&pos);
	if(pos<=0)
	{
		printf("Positon should be more than 0");
		return ;
	}
	if(pos==1)
	{
		del_beg();
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
		if(q->next!=NULL)
		{
			q->next->prev=p;
		}
		else
		{
			del_end();
		}
		printf("%d is deleted form the node with position %d.\n",q->data,pos);
		free(q);
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
