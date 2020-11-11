#include<bits/stdc++.h>
using namespace std;

int minCoins(int N,int coins[],int T,int dp[])
{
    if(N==0)
    return 0;
    
    for(int n=1;n<=N;n++)
    {
        dp[n]=INT_MAX;
        for(int i=0;i<T;i++)
        {
            if(n-coins[i]>=0)
            {
                int sub=minCoins(n-coins[i],coins,T,dp);
                dp[n]=min(dp[n],sub);
            }
        }
    }
    return dp[N];
}
int main() {
	
    
	int t;
	cin>>t;
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int dp[1000005]={0};
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    
	    cout<<minCoins(n,coins,10,dp)<<endl;
	}
	return 0;
}