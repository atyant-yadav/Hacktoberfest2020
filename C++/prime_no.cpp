//Write a Program to check whether number is prime or not.

#include <iostream>
using namespace std;

int main()
{
  int n, i, m=0, count=0;
  cout << "Enter a Number to check if it is Prime or not: ";
  cin >> n;
  m=n/2;
  for(i = 2; i <= m; i++)
  {
      if(n % i == 0)
      {
          cout << n <<" is not Prime."<<endl;
          count=1;
          break;
      }
  }
  if (count==0)
      cout << n << " is Prime."<<endl;
  return 0;
}