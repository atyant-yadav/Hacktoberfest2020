#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};
struct Node* top;               //head ptr of LL & top of stack

void push(int x){
    struct Node* temp=new Node();
    temp->data=x;               //x is the element that to be pushed onto the stack
    temp->link=top;
    top=temp;
}

int isEmpty(){
    return top==NULL;
}

void pop(){

    if(isEmpty()){
        cout<<"No elements in the stack that to be popped \n";
    }
    else{
        struct Node* temp;
        temp=top;
        top=top->link;
        temp->link=NULL;
        delete temp;
    }
}

int peek(){
    return top->data;
}

void printStack(){
    if(isEmpty())
        cout<<"No elements in stack\n";
    else{
        struct Node* temp;
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    }
}

int main(){
    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;  cin>>x;
        push(x);
    }
    cout<<"\nTop element: "<<peek();
    cout<<"\nStack elements are: \n";
    printStack();
    int p=peek();
    pop();
    cout<<"\nElement that is popped out of stack: "<<p;
    cout<<"\nElements after POP operation: \n";
    printStack();
    return 0;
}
