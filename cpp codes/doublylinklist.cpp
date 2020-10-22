#include<iostream>
using namespace std;
//Defining the structure of a linked list node
struct node{
string dat;
struct node *next,*prev;
};
node *getnewnode(string data)
{
    node *x=new node;
    x->dat=data;
    x->next=NULL;
    x->prev=NULL;
    return x; 
}
//inserting node at beg
 node *insertNodeBeg(node *head,string data)
{
node *ptr=getnewnode(data);
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        head->prev=ptr;
        ptr->next=head;
        head=ptr;
    }
    return head;
}

//Display the list
void displayList(node *head){
cout<<"Display list"<<endl;
while(head!=NULL)
{
cout<<head->dat<<"<->";
head=head->next;
}
cout<<"NULL";
cout<<endl;
}
//Diplay in reverse
void displayListrev(node *head)
{
	node *p1,*p2;
	p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
	cout<<"Display list in reverse"<<endl;
	while(p1!=NULL)
	{
	cout<<p1->dat<<"<->";
	p1=p1->next;
	}
	cout<<"NULL";
}
void search(node *head,string data){
	while(head!=NULL)
		{ 
			if(head->dat==data){
			cout<<"Yes present";
			return ;}
			else head=head->next;
		}
	cout<<"Not present"<<endl;
}
int main()
{
int ch,pos;
string x;
char op;
node *head=NULL;
cout << "DOUBLY LINKED LIST\n\n";
  do
    {      
cout << "\n\n1. INSERT AT BEGIN 2. DISPLAY 3.DISPLAY REVERSE  4.SEARCH COUNTRY 5. QUIT\n\nEnter the choice :: ";
 cin >> ch;
 switch (ch)
	{case 1: cout<<"Enter country to be inserted::";
	cin>>x;
	head=insertNodeBeg(head,x); break;
	case 2: displayList(head); break;
	case 3: displayListrev(head); break;
	case 4: cout<<"Enter the country to be searched::"; cin>>x; search(head,x);
	break;
	default:cout<<"Invalid"; exit(0);
    }
    cout << endl << "Try again? (y/n): ";
    cin >> op;

    }while(op=='Y'||op =='y');

return 0;
} 
