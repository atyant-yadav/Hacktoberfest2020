#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct Bt_node
{
	struct Bt_node *left;
	char data;
	struct Bt_node *right;
}*root;
void create();
void inorder(struct Bt_node *);
void postorder(struct Bt_node *);
void preorder(struct Bt_node *);
main()
{
	int choice;
//	clrscr();
	while(1)
	{
		printf("1->create\n2->print\n3->preorder\n4->postorder\nany other key for exit\n");
		printf("enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			default:
				exit(1);
		}
	}
}
void create()
{
	struct Bt_node *temp,*t,*s;
	char a;
	int a1;
	t=(struct Bt_node *)malloc(sizeof(struct Bt_node));
	printf("enter the data ");
	fflush(stdin);
	scanf("%c",&a);
	t->data=a;
	t->right=NULL;
	t->left=NULL;
	if(root==NULL)
	{
		root=t;
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			s=temp;
			if(int(temp->data)>int(t->data))
			{
			       a1=1;
			       temp=temp->left;
			}
			else
			{
				a1=0;
				temp=temp->right;
			}
		}
		if(a1==1)
			s->left=t;
		else
			s->right=t;
		t=NULL; 
		temp=NULL;
		s=NULL;
		free(temp);free(s);free(t);
	}
	printf("\n");
}
void inorder(struct Bt_node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	else
	{
		inorder(temp->left);
		printf("%c\t",temp->data);
		inorder(temp->right);
	}
	printf("\n");
}
void preorder(struct Bt_node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	else
	{
		printf("%c\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
	printf("\n");
}
void postorder(struct Bt_node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	else
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%c\t",temp->data);
	}
	printf("\n");
}