#include<iostream>
#include<conio.h>
using namespace std;
class Node{
    public:
        int data;
        Node *link;
};
Node *head=NULL;
void create(){
    char ch;
    do{
        Node *current;
        Node *new_node=new Node;
        cout<<"\nEnter the data:";
        cin>>new_node->data;
        new_node->link=NULL;
        if (head==NULL){
            current=new_node;
            head=new_node;
        }
        else{
            current->link=new_node;
            current=new_node;
        }
        cout<<"\nDo you want to continue?";
        ch=getche();
    }while(ch!='n');
}
void display(){
    Node *new_node;
    new_node=head;
    cout<<"\nDisplaying the data"<<endl;
    while(new_node!=NULL){
        cout<<new_node->data<<"\t";
        new_node=new_node->link;
    }
}

int main(){
    create();
    display();
    return 0;
}
