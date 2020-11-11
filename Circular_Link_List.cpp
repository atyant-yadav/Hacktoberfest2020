#include<iostream>
#include<conio.h>
using namespace std;
class Node{
    public:
        int data;
        Node *link;
};
Node *head=NULL;
void createNode(){
    char ch;
    do{
        Node *current;
        Node *new_node=new Node;
        cout<<"\nEnter the data:";
        cin>>new_node->data;
        new_node->link=NULL;
        if (head==NULL){
            head=new_node;
            current=new_node;
        }
        else{
            current->link=new_node;
            current=new_node;
            current->link=head;
        }
        cout<<"\nDo you want to add more nodes?";
        ch=getche();
    }while(ch!='n');
}
void print(){
    Node *new_node;
    new_node=head;
    if (new_node==NULL){
        cout<<"\nLink list is empty.";
    }
    else{
        cout<<"\nData in list is as follows:"<<endl;
        cout<<new_node->data<<"\t";
        new_node=new_node->link;
        while(new_node!=head){
            cout<<new_node->data<<"\t";
            new_node=new_node->link;
        }
        cout<<new_node->data<<"\t";
    }
}
int main(){
    createNode();
    print();
}
