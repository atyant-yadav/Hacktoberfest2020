#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 20
typedef struct
{
	char **arr;
	int front;
	int rear;
}CQ_STR;
int isFull(CQ_STR *cq)
{
	int temp=(cq->rear+1)%MAX_SIZE;
	if(temp==MAX_SIZE)
	return 1;
	else
	return 0;
}
int isEmpty(CQ_STR *cq)
{
	if(cq->front==-1)
	return 1;
	else
	return 0;
}
void init(CQ_STR *cq)
{
	cq->front=-1;
	cq->rear=-1;
	cq->arr=malloc(sizeof(char*)*MAX_SIZE);
	for(int i=0;i<MAX_SIZE;i++)
	cq->arr[i]=malloc(sizeof(char)*MAX_SIZE);
}
void insertcq(CQ_STR *cq,char item[])
{
	if(!isFull(cq))
	{
		cq->rear=cq->rear+1;
		strcpy(cq->arr[cq->rear],item);
		if(cq->front==-1)
		cq->front=0;
	}
	else
	printf("Queue is Full\n");
}
char* deletecq(CQ_STR *cq)
{
	if(!isEmpty(cq))
	{
		return cq->arr[++cq->front];
	}
	else
	{
		printf("Queue is Empty\n");
	}
}
void displaycq(CQ_STR *cq)
{
	if(!isEmpty(cq))
	{
		for(int i=cq->front;i<=cq->rear;i++)
		printf("%s\t",cq->arr[i]);
		printf("\n");
	}
}
int main()
{
	CQ_STR cq;
	init(&cq);
	int flag=1;
	int x;
	char p[MAX_SIZE];
	char q[MAX_SIZE];
	init(&cq);
	while(flag==1)
	{
		printf("Enter 1 to insert, 2 to delete, 3 to display, and 4 to exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			printf("Enter a string to be inserted\n");
			scanf("%s",p);
			insertcq(&cq,p);
			break;
			case 2:
			strcpy(q,deletecq(&cq));
			break;
			case 3:
			printf("The Queue is\n");
			displaycq(&cq);
			break;
			case 4:
			flag=0;
			break;
			default:
			printf("Wrong Choice. Try Again\n");
			break;
		}

	}
}
