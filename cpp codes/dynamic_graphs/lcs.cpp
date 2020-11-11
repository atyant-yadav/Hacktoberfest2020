#include<iostream>
#include<string.h>
using namespace std;
#define MAX 3000

int dp[MAX][MAX];
string getLcs(string& s1,string& s2,int len)
{
int i=0,j=0;
string lcs;
	while(len>0)
	{
		if(s1[i]==s2[j])
		{
			lcs.push_back(s1[i]);
			i++;
			j++;
			len--;
		}
		else
		{
			if(dp[i+1][j]<dp[i][j+1])
			{
			 j++;
			}
			else
			{
			i++;
			}
		}
	}
	return lcs;
}
int find_lcsLen(string& s1,string& s2,int i,int j)
{
	if(i>=s1.length() || j>=s2.length())
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	if(s1[i]==s2[j])
	{
		return dp[i][j]=1+find_lcsLen(s1,s2,i+1,j+1);
	}
	else
	{
	 return max(find_lcsLen(s1,s2,i+1,j),find_lcsLen(s1,s2,i,j+1));
	}
}
string solve(string s1,string s2)
{
	
		memset(dp,-1,sizeof(dp));

		int len=find_lcsLen(s1,s2,0,0);
		

		return getLcs(s1,s2,len);


}
int main()
{
	string s,t;

	cin>>s>>t;


	cout<<solve(s,t)<<endl;


	return 0;
}