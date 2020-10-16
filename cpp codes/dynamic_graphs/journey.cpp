#include<bits/stdc++.h>
using namespace std;
long long countries;
class Graph{
    map<long long,list<long long> >l;
    public:
    void addEdge(long long x,long long y)
    {
        l[x].push_back(y);
        
    }
    
    vector<long long> dfs()
    {
        map<long long,bool>visited;
        vector<long long>v;
        long long k=0;
        countries=0;
        
        for(auto p:l)
        {
            long long node=p.first;
            visited[node]=false;
        }
       
        for(auto p:l)
        {
            long long node=p.first;
            long long count=0;
            
            if(!visited[node])
            {
                
                
                dfs_helper(node,visited,count);
                
                v.push_back(count);
                countries++;
            }
        }
        return v;
    }
    void dfs_helper(long long src,map<long long,bool> &visited,long long &count)
    {
        
        visited[src]=true;
        
        count++;
        for(long long nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited,count);
            }
        }
    }
};
long long main()
{
    long long n,p;
    cin>>n>>p;
    long long a,b;
    Graph G;
    for(long long i=0;i<p;i++)
    {
     cin>>a>>b;
     G.addEdge(a,b);
    }
    
    vector<long long> V;
    V=G.dfs();
    long long sum=(n*(n-1))/2;
    for(long long i=0;i<countries;i++)
    {
     sum-=(V[i]*(V[i]-1))/2;
    }
    cout<<sum;
}

