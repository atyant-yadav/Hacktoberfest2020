#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s1;  // Declaration of Stack of required data type
    
    s1.push(1);     // Pushing elements into stack
    s1.push(2);

    cout<<"Top of stack is: "<<s1.top()<<endl;  // Checking the top element of the stack

    for(int i=3;i<6;i++)
    {
        s1.push(i);     // Pushing elements in stack in a loop
    }

    if(!s1.empty())     // Check if stack is empty
    {
        s1.pop();       // Delete the top of stack
    }

    cout<<"The size of the stack is: "<<s1.size()<<endl;    // Check size of stack

    cout<<"The elements in the stack are:"<<endl;

    while(!s1.empty())      // Iterating through elements of stack
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;

    s1.emplace(2);      // To make a new element and insert on the top of stack
    s1.emplace(3);      // Only for C++11 and above

    stack<int> s2;

    s2.push(100);

    s1.swap(s2);        // For swapping two stacks of same data type, only for C++11 and above

    cout<<"Size of s1: "<<s1.size()<<endl;
    cout<<"Size of s2: "<<s2.size()<<endl;

    return 0;
}