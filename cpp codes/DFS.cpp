#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

bool vis[MAX];
vector<int> adj[MAX];

void dfs(int v){

	vis[v]=true;
	cout << v << " ";

	for(int i = 0; i < adj[v].size(); i++){
		if(!vis[adj[v][i]])
			dfs(adj[v][i]);
	}
	return;
}

int main(){

	int vertices = 4, edges = 6;

	// creating a graph
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(3);

	cout << "Depth First Traversal for the above graph starting from vertex 2: ";

	dfs(2);

	return 0;
}
