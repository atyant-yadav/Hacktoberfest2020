#include<iostream>
using namespace std;
int maxsize=10;
int stack[10];
int top=-1;

int isempty(){
	if(top==-1){
		return 1;
	}
	return 0;
}
int isfull(){
	if(top==maxsize){
		return 1;
	}
	return 0;
}
int peek(){
	return stack[top];
}
int pop(){
	int data;
	if(!isempty()){
		data=stack[top];
		top--;
		return data;
	}
	cout<<"Stack is empty"<<endl;
	return 0;
}
void push(int data){
	if(!isfull()){
		top++;
		stack[top]=data;
	}
	else{
	cout<<"Stack is full"<<endl;
    }
}
int display(){
	int t=top;
	while(t>=0){
		cout<<stack[t]<<" ";
		t--;
	}
	cout<<endl;
}
int main(){
	cout<<"17001012019 Aastha Bansal"<<endl;

   int ch, val,s;
   int e,t;
   cout<<"1)Push\n";
   cout<<"2)Pop\n";
   cout<<"3)Display\n";
   cout<<"4)IsEmpty\n";
   cout<<"5)Isfull\n";
   cout<<"6)Top Element\n";
   cout<<"7)Exit\n";
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         push(val);
         break;

         case 2:
         pop();
         break;

         case 3:
         display();
         break;

         case 4:
         e=isempty();
         if(e==1){
            cout<<"Stack is empty"<<endl;
         }
         else{
            cout<<"Stack is not empty"<<endl;
         }
         break;
         case 5:
         s=isfull();
          if(s==1){
            cout<<"Stack is full"<<endl;
         }
         else{
            cout<<"Stack is not full"<<endl;
         }
         
         break;

         case 6:
         t=peek();
         cout<<"Top element is: "<<t<<endl;

         case 7:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 7);
   return 0;
}
