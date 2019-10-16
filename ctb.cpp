#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int t,n,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=n/26;
        y=n%26;
        if(y>0 && y<=2)
        {
            cout<<pow(2,x)<<" 0 0"<<endl;
        }
        else if(y>2 && y<=10)
        {
            cout<<"0 "<<pow(2,x)<<" 0"<<endl;
        }
        else 
        {
            if(y==0)
            cout<<"0 0 "<<pow(2,x-1)<<endl;
            else
            cout<<"0 0 "<<pow(2,x)<<endl;
        }
    }
    return 0;
}
