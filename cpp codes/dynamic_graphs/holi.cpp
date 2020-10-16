#include<bits/stdc++.h>
using namespace std;
class Graph
{
	long long V;
	list<pair<long long,long long> > *l;
	public:
	Graph(long long V)
	{
	this->V=V;
	l=new list<pair<long long,long long> >[V];
	}
	void addEdge(long long x,long long y,long long wt)
	{
	l[x].push_back(make_pair(y,wt));
	l[y].push_back(make_pair(x,wt));
	
	}


	long long dfs()
	{
			
		bool *visited=new bool[V];
		long long *count =new long long[V];
		for(long long i=0;i<V;i++)
		{
			count[i]=0;
			visited[i]=false;
		}
		long long ans=0;
		dfs_helper(0,visited,count,ans);
	    return ans;
	}
	long long dfs_helper(long long node,bool visited[],long long count[],long long &ans)
	{
		visited[node]=true;
		count[node]=1;
         
		for(auto nbr_pair:l[node])
		{
			long long nbr=nbr_pair.first;

			long long wt=nbr_pair.second;
			
			if(!visited[nbr])
			{
			count[node]+=dfs_helper(nbr,visited,count,ans);
			long long nx=count[nbr];
			long long ny=V-nx;
			
			ans+=2*min(nx,ny)*wt;
			
			}
       
		}
		return count[node];
	}
};



int main()
{
	long long t;
	cin>>t;
	long long count=1;
	while(t--)
	{
	long long n;
	
	cin>>n;
	Graph G(n);
	long long x,y,wt;
	for(long long i=0;i<n-1;i++)
	{
     cin>>x>>y>>wt;
     G.addEdge(x,y,wt);
	}
	cout<<"Case #"<<count<<" "<<G.dfs()<<endl;
	count++;
	}
	return 0;
}