#include<iostream>
#include<list>
#include<map>
using namespace std;
class Graph{
	map<int,list<int> >L;

	public:
	void addEdge(int x,int y)
	{
		L[x].push_back(y);
		L[y].push_back(x);
	}

    void dfs_helper(int src,map<int,bool> &visited)
    {
    	cout<<src<<" ";
        visited[src]=true;
    	for(auto nbr:L[src])
    	{
    	if(!visited[nbr])
    	{
    		dfs_helper(nbr,visited);
    	}
    	}
    }
	void dfs(int src)
	{
	map<int,bool>visited;

	for(auto pair:L)
	{
		 int node=pair.first;
		 visited[node]=false;
	}
	dfs_helper(src,visited);
	}

};

int main()
{
	Graph G;
	G.addEdge(0,1);
	G.addEdge(0,3);
	G.addEdge(1,2);
	G.addEdge(3,2);
	G.addEdge(3,4);
	G.addEdge(4,5);

    G.dfs(0);
	return 0;
}