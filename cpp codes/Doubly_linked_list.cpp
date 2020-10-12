#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node *next;
	node *prev;
};
node *head=NULL;
void binsert() //inserting element in the beginning of the Doubly LL
{
	node *p= new node();
	cout<<"Beginning Data"<<endl;
	cin>>p->data;
	p->next=NULL;
	p->prev=NULL;
	if(head==NULL)
	{
		head = p;
		return;
	}
		head->prev=p;
		p->next=head;
		head=p;
}
void einsert() //inserting at the end of a doubly ll
{
	node *p = new node();
	cout<<"Insert at end"<<endl;
	cin>>p->data;
	p->next=NULL;
	p->prev=NULL;
	if(head==NULL)//checking to see if the list is empty
	{
		head= p;
		return;
	}
	node *temp=head; 
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	p->prev=temp; 
	temp->next=p; 
	
}
void fdisplay() //print the doubly ll in forward order
{
	node *temp = new node();
	temp=head;
	cout<<"Forward printing"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void rdisplay() //print the doubly ll in reverse order
{
	node *temp=new node();
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<<"Reverse Display"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
}
int main()
{
	int n;
	cout<<"Enter the limit of the list"<<endl;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		binsert();
	}
	cout<<"Result"<<endl;
	einsert();
	fdisplay();
	rdisplay();
	
}
