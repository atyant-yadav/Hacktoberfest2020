#include<iostream>
using namespace std;

class node{
    public:
int data;
node * next;
};

node* head = NULL;
void insert(int n)
{
    cout<<" entered fucntion "<<endl;
    if(head==NULL)
        {head = new node;
        head->data = n;
        head->next = NULL;

        }
        else
        {
            node * tempa = head;
            while(tempa->next!=NULL)
            {
                tempa = tempa->next;
            }
            tempa->next = new node;
            tempa= tempa
            ->next;
        tempa->data = n;
        tempa->next = NULL;

        }
}
void print()
{ cout<<" entered print";
     node* temp = head;
    while(temp!=NULL)

        {cout<< " "<<temp->data <<" "<<endl;
        temp = temp->next;}


}
void deleter(int p)
{ node * temp = head;
    for(int i=1;i<p-1;i++)
    {
        temp = temp->next;

    }
    node *cur = temp;
    temp = temp->next;
    node* nexter = temp->next;
    cur->next = nexter;

}

int main()
{

    int n;
    cout<<" enter he number of elements you want to enter ";
    cin>>n;

    for(int i=0;i<n;i++)
    {  int a;
        cout<<"enter number ";
        cin>>a;

        insert(a);
        print();
    }
    int p;
    cout<<" to delete any position tell ";
    cin>>p;
    deleter(p);
    cout<<" after deleting "<<endl;
    print();

}
