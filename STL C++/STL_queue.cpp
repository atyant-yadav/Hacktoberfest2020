#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> s1;  // Declaration of queue of required data type
    
    s1.push('1');     // Pushing elements into queue at rear
    s1.push('2');
    s1.push('3');

    cout<<"Front of stack is: "<<s1.front()<<endl;  // Checking the front element of the queue
    cout<<"Rear of stack is: "<<s1.back()<<endl;  // Checking the rear element of the queue

    for(char i='4';i<'7';i++)
    {
        s1.push(i);     // Pushing elements in queue in a loop
    }

    if(!s1.empty())     // Check if queue is empty
    {
        s1.pop();       // Delete the front of queue
    }

    cout<<"The size of the stack is: "<<s1.size()<<endl;    // Check size of queue

    cout<<"The elements in the stack are:"<<endl;

    while(!s1.empty())      // Iterating through elements of queue
    {
        cout<<s1.front()<<" ";
        s1.pop();
    }
    cout<<endl;

    s1.emplace('7');      // To make a new element and insert on the rear of queue
    s1.emplace('8');      // Only for C++11 and above

    queue<char> s2;

    s2.push('a');

    s1.swap(s2);        // For swapping two queues of same data type, only for C++11 and above

    cout<<"Size of s1: "<<s1.size()<<endl;
    cout<<"Size of s2: "<<s2.size()<<endl;
    cout<<"Front of stack s1: "<<s1.front()<<endl;
    cout<<"Front of stack s2: "<<s2.front()<<endl;

    return 0;
}