#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack
{
	queue<int>q;
public:
	void push(int val);
	int pop();
	int top();
	bool empty();
	
};

void Stack::push(int val)
{
	int s= q.size(); //gett previous size of queue
	q.push(val);
	// pop or dequeue all previous elements and put them after current value which we have entered
	for(int i=0;i<s;i++)
	{
		//this will add front element into rear of queue
		q.push(q.front());
		//this will pop the current elemnt that we just have entered
		q.pop();
	}
	
}
//Remove top element
int Stack::pop()
{
	if(q.empty())
		cout<<"No elements\n";
	else
		q.pop();	
}

int Stack::top()
{
	return (q.empty())? -1 : q.front();
}

bool Stack::empty() 
{
	return (q.empty());
}

int main()
{
	Stack s;
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	cout<<s.top() << endl;
	s.pop();
	s.push(30);
	cout<<s.top() <<endl;
	s.pop();
	
	return 0;
	
}
