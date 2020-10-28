#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int a[MAX],front=-1,rear=-1;
void push(int x){
    if(rear==MAX-1){
        cout<<"stack is overflow"<<endl;
    }
    else
    {   rear=(rear+1)%MAX;
        a[rear]=x;
        if(front==-1)
            front++;
    }}
 void pop()
 {
     if(front==-1){
        cout<<"stack is underflow"<<endl;
     }
     else{
        cout<<"deleted element is "<<a[front]<<endl;

        if(front==rear){
            front=rear=-1;
        }
        else
          front=(front+1)%MAX;
     }
}
void disp(){
    cout<<"elements are"<<endl;
    for(int i=front;i<=rear;i=(i+1)%MAX){
        cout<<a[i]<<" ";
    }

}
int main()
{
    push(10);
    push(20);
    push(30);
    disp();
    pop();
    pop();
    disp();
   return 0;
}
