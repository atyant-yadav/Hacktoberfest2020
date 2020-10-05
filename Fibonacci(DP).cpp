#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> dp(1000,0);
int fib(int N) {
    if(N==0) return 0;
    if(N==1 or N==2) return 1;
    if(dp[N]>0) return dp[N];
    int ans=fib(N-1)+fib(N-2);
    return dp[N]=ans;
}
int main()
{
    int x=0;
    cout<<"To get the nth term enter the value of n : ";
    cin>>x;
    cout<<fib(x);
    return 0;
}
