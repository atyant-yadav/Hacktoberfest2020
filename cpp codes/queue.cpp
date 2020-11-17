#include <iostream>
#include <queue>
 
using namespace std;
 
void printQueue(queue <int> gq)
{
    queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
 
int main()
{
    queue <int> newQueue;
    newQueue.push(100);
    newQueue.push(110);
    newQueue.push(120);
 
    cout << "The queue contents are : ";
    printQueue(newQueue);
 
    cout << "\newQueue.size() : " << newQueue.size();
    cout << "\newQueue.front() : " << newQueue.front();
    cout << "\newQueue.back() : " << newQueue.back();
 
    cout << "\newQueue.pop() : ";
    newQueue.pop();
    printQueue(newQueue);
 
    //print queue using iterators
    count<<"Using iterators : ";
    for(auto i = newQueue.front(); i != newQueue.back(); i++)
    {
      cout<< i <<" ";
    }
    return 0;
}
