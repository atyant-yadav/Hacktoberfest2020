#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
	map<int,list<int> >L;

	public:
	void addEdge(int x,int y)
	{
	 L[x].push_back(y);
	 L[y].push_back(x);
	}

	void bfs(int src)
	{
	queue<int> q;
	map<int,bool>visited;
	q.push(src);

	

	
	while(!q.empty())
	{
		int node=q.front();
	visited[node]=true;
	q.pop();
	cout<<node<<" ";

	for(int nbr:L[node])
	{
		if(!visited[nbr])
		{
		 q.push(nbr);
		 visited[nbr]=true;
		}
	}

	}
	}
};

int main()
{
	Graph G;
	G.addEdge(0,1);
	G.addEdge(0,3);
	G.addEdge(1,2);
	G.addEdge(2,3);
	G.addEdge(3,4);
	G.addEdge(4,5);

	G.bfs(0);

	return 0;
}