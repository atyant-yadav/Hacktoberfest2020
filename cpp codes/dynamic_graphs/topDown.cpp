#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
	if(n==0||n==1)
	{
	return n;
	}
	return fib(n-1)+fib(n-2);
}
int topDownDP(int n,int *dp)
{
	if(n==0||n==1)
	{
	dp[n]=n;
	return n;
	}
	else if(dp[n]!=-1)
		return dp[n];
	else{
	dp[n]=topDownDP(n-1)+topDownDP(n-2);
	return dp[n];
}
}
int main()
{
	cout<<fib(5)<<endl;
	int dp[100];
	for(int i=0;i<100;i++)
	{
	dp[i]=-1;
	}
	cout<<topDownDP(5,dp);
	return 0;
}