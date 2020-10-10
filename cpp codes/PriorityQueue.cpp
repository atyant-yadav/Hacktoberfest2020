#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct pqueue{
int data[MAX];
int rear,front;
}pqueue;

void initialize(pqueue *p);
int empty(pqueue *p);
int full(pqueue *p);
void enqueue(pqueue *p,int x);
int dequeue(pqueue *p);
void print(pqueue *p);

int main()
{


int x,op,n,i;
pqueue p;
initialize(&q);
do{
    cout<<"1. create \n 2. insert \n 3. delete \n 4. print \n 5. exit";
    cout<<"\n enter choice";
    cin>>op;
    switch(op){
case 1:
    cout<<"\n Enter no of elements: ";
    cin>>n;
    initialize(&q);
    cout<<"\n enter the data";
    for(i=0;i<n;i++)
    {
        cin>>x;
        if (full(&q)){
            cout<<"\n queue is full";
            exit(0);
        }
        enqueue(&q,x);

    }
      break;

case 2:
    cout<<"\n enter the element to be inserted: ";
    cin>>x;
    if(full(&q)){
     cout<<"\n queue is full";
            exit(0);
        }
        enqueue(&q,x);
        break;
case 3:
    if(empty(&q)){
        cout<<"\n queue is empty. ";
        exit(0);
    }
    x=dequeue(&q);
    cout<<"\n deleted element "<<x;
    break;
case 4:
    print(&q);
    break;
default:
    break;
    }
    }while(op!=5);
    return 0;
}

void initialize(pqueue *p){
p->rear=-1;
p->front=-1;
}

int empty(pqueue *p){
if(p->rear==1)
    return(1);
return(0);
}

int full(pqueue *p){
if((p->rear+1)%MAX==p->front)
    return(1);
return(0);
}

void enqueue(pqueue *p,int x)
{
    int i;
    if(full(p))
        cout<<"\n overflow";
    else{
        if(empty(p))
    }
}
}
