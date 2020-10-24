#include<iostream>
using namespace std;
inline float simple interest(int p,int t ,int r)
{
    return(p*t*r)/100;   // Simple Interest =(p*t*r)/100
}
    int main()
    {
        int p,t,r;
        cout<<"please enter principle,time and rate";
        cin>>p>>t>>r;
        cout<<"simple interest ="<<simple interest(p,t,r);          //function call 
        return 0;
    }
