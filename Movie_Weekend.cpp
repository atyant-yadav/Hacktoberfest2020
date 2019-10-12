#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	int l[100],r[100],x,y,z;  
	cin>>t;
	while(t--)
	{
		x=0;
		y=0;
		z=0;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>l[i];
		for(int i=0;i<n;i++)
		cin>>r[i];
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				x=r[i]*l[i];                     //storing and comparing ratings * length
				z=i;
				y=r[i];
			}
			else
			{
			if(l[i]*r[i]>x)
			{
				y=r[i];
				x=l[i]*r[i];
				z=i;
			}
			else if(l[i]*r[i]==x)
			{
			    if(r[i]>y)
			    {
			        y=r[i];
			        z=i;
			    }
			}
			}
		}
		cout<<z+1<<endl;         //printing final output
	}
	return 0;
}
