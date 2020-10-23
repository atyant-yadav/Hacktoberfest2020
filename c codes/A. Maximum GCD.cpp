#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q, i, n;
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>n;
		if(n%2==0) cout<<n/2<<endl;
			else cout<<(n-1)/2<<endl;
	}
}
