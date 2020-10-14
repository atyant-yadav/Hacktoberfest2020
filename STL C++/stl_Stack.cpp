#include <iostream>      
#include <stack>

using namespace std;  
      
int main ()
{
    stack<int> s; 
    
    // pushing elements into stack
    s.push(2);   
    s.push(3);   
    s.push(4);   
    
    cout << s.top();   // prints 4, as 4 is the topmost element 
    
    cout << s.size();  // prints 3, as there are 3 elements in 
}
