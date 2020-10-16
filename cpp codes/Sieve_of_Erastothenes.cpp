// C++ program to print all primes smaller than or equal to num
#include <bits/stdc++.h>
using namespace std;

void SOE(int num)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true.
    bool prime[num+1];
    memset(prime, true, sizeof(prime));

    for (int i=2; i*i<=num; i++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[i] == true)
        {
            for (int j=2*i; j<=num; j += i)
                prime[j] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=num; p++)
       if (prime[p])
          cout << p << " ";
}

int main()
{
    int n;

    cout<<"Enter the no. to which you want to print primes : ";
    cin>>n;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SOE(n);
    return 0;
}

