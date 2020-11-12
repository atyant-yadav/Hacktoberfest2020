#include<iostream>
using namespace std;
int main()1
{
    int a[100];
    int n;
    cout<<"Enter the no. of elements";
    cin>>n;
    int i=0;
    while(i<n)
    {
        cin>>a[i];
        i++;
    }
    
    for(i=0;i<=n-2;i++)
    {
    int count=0;
    for(int j=0;j<=n-2-i;j++)     //(n-2) compares the last element also but works too
    {
    if(a[j]>a[j+1])
    {
    count++;
    swap(a[j],a[j+1]);
    }
    }
    if(count==0)
    {
        cout<<"Break at iteration:"<<i<<endl;
    break;
    }
    }
    i=0;
    while(i<n)
    {
        cout<<a[i]<<' ';
        i++;
    }   
    return 0;
}
