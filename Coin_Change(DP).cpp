#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int sum;
    cin>>sum;
    int m;
    cin>>m;
    int coins[m];
    for(int i=0;i<m;i++)
    cin>>coins[i];
    int arr[m+1][sum+1];
    for(int i=1;i<=sum;i++)
    {
        arr[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        arr[i][0]=1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=coins[i-1])
            arr[i][j]=arr[i-1][j]+arr[i][j-coins[i-1]];
            else
            arr[i][j]=arr[i-1][j];
        }
    }
    cout<<arr[m][sum]<<endl;
}