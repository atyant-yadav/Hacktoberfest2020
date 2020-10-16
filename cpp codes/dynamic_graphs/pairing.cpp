#include<iostream>
#include<vector>
using namespace std;
class dsu
{
	public:
	vector<long long> par;
	vector<long long> sz;
    long long totalComp;
	dsu(long long n)
	{
		par.resize(n);
		sz.resize(n);
		for(long long i=0;i<n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		totalComp=n;
	}

	long long get_superparent(long long x)
	{
		if(x==par[x])
		{
			return x;
		}
		else
		{
			return par[x]=get_superparent(par[x]);
		}
	}

	void combine(long long x,long long y)
	{
		long long superParent_x=get_superparent(x);
		long long superParent_y=get_superparent(y);
		if(superParent_x!=superParent_y)
		{
			par[superParent_x]=superParent_y;
            sz[superParent_y]+=superParent_x;
			sz[superParent_x] = 0;
			totalComp--;

		}
	}

};
int main()
{
	
		long long n,m;
		cin>>n>>m;
		dsu G(n);
		for(long long i=0;i<m;i++)
		{
			long long x,y;
			cin>>x>>y;
           G.combine(x,y);
		}
		long long ans=0;
		for(long long i=0;i<n;i++)
		{
			long long superParent=G.get_superparent(i);
			ans+=(n-G.sz[superParent]);
		}
		cout<<ans/2<<endl;
	
	return 0;
}