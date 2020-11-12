#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
	ll n,array[100000],i,k,length[100000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>array[i];
	}
	for(i=0;i<n;i++)
	{
		length[i]=1;
		//longest increasing subsequence that ends at i
		for(k=0;k<i;k++)
		{
			if(array[k]<array[i])
			{
				length[i]=max(length[i],length[k]+1);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<length[i]<<" ";
	}
}
