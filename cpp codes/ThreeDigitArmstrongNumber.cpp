#include <bits/stdc++.h>  
using namespace std;  
int main()  
{  
    int n,r,sum=0,temp;    
    cout<<"Enter a three digit positive integer: ";    
    cin>>n;    
    temp=n;    
    while(n>0)    
    {    
        r=n%10;    
        sum=sum+(r*r*r);    
        n=n/10;    
    }    
    if(temp==sum)    
        cout<<temp<<" is an Armstrong Number."<<endl;    
    else    
        cout<<temp<<" is not an Armstrong Number."<<endl;   
    return 0;  
}  
