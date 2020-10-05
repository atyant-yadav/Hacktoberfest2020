#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    double principle = 10000, rate = 10.25, time = 5; 
  
    /* Calculate compound interest */
    double CI = principle * (pow((1 + rate / 100), time)); 
  
    cout << "Compound interest is " << CI; 
  
    return 0; 
} 
