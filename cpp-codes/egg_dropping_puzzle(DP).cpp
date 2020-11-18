
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n)  for(ll i = 0; i < (n); ++i)
#define rep1(i,n)  for(ll i = 1;i <= (n); ++i)
#define pb push_back
#define M 1000000007
int dp[11][51];
int solve(int e,int f)
{
	if(f==0 || f==1)
	return f;
	if(e==1)
	return f;
	if(dp[e][f]!=-1)
	return dp[e][f];
	int mn=INT_MAX,low,high;
	for(int k=1;k<=f;k++)
	{
		if(dp[e-1][k-1]!=-1)
		low=dp[e-1][k-1];
		else
		{
			low=solve(e-1,k-1);
			dp[e-1][k-1]=low;
		}
		
		if(dp[e][f-k]!=-1)
		high=dp[e][f-k];
		else
		{
			high=solve(e,f-k);
			dp[e][f-k]=high;
		}
		int temp=1+max(low,high);
		mn=min(mn,temp);
	}
	return dp[e][f]=mn;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll e,f;
		cin>>e>>f;
		memset(dp,-1,sizeof(dp));
		cout<<solve(e,f)<<"\n";
		
		
	}
	return 0;
}
