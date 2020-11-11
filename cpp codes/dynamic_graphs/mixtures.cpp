#include<bits/stdc++.h>
using namespace std;
long long a[1005];
long long dp[1000][1000];
long long sum(int i,int j)
{
	long long ans=0;
	for(int k=i;k<=j;k++)
	{
		ans+=a[k];
		ans=ans%100;
	}
return ans;

}
long long solve(int i,int j)
{
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
    dp[i][j]=INT_MAX;
	for(int k=i;k<=j;k++)
		dp[i][j]=min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)*sum(k+1,j));

	return dp[i][j]; 
}

int main()
{
	int t;
	while((scanf("%d",&t))!=EOF)
	{
		
		for(int i=0;i<t;i++)
			cin>>a[i];

		for(int i=0;i<1000;i++)
			for(int j=0;j<1000;j++)
				dp[i][j]=-1;
		cout<<solve(0,t-1)<<endl;
	}
	return 0;
}