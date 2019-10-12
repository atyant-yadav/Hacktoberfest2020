#include<iostream>
using namespace std;

int main()
{

    int a[100];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    int cs=0;
    int ms=0;
    for(int i=0;i<5;i++)
    {
        cs=cs+a[i];
        if(cs<0)
        {
            cs=0;
        }
       ms=max(cs,ms);  ///inbuilt function for maximum sum
    }
    cout<<ms;
}
