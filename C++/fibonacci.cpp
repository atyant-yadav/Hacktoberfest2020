//this program display the Fibonacci series
#include <iostream>
using namespace std;

class Fibonacci
{
    public:
    int n,a,b,c;
    
    void fibo()
    {
         int n, a = 0, b = 1, c = 0;

         cout << "Enter the number of terms: ";
         cin >> n;

         cout << "Fibonacci Series: ";

        for (int i = 1; i <= n; ++i)
        {
       
        if(i == 1)
        {
            cout << a << " ";
            continue;
        }
        if(i == 2)
        {
            cout << b << " ";
            continue;
        }
        c = a + b;
        a = b;
        b = c;
        
        cout << c << " ";
    }
  }
};
int main()
{
   Fibonacci obj;
   obj.fibo();
   
   
    return 0;
}

