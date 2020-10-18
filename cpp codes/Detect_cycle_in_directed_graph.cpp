// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

void dfs(vector<int> adj[],vector<bool> &vis,int src,int V,bool &cycle,vector<bool> &rec)
{
    vis[src]=1;
    rec[src]=1;
    for(int i=0;i<adj[src].size();++i)
    {
        if(rec[adj[src][i]]==0 && cycle==0)
        {
            if(vis[adj[src][i]]==0)
            dfs(adj,vis,adj[src][i],V,cycle,rec);
        }
        else
            {
                cycle=1;
                return;
            }
    }
    rec[src]=0;   
}

bool isCyclic(int V, vector<int> graph[])
{
    
    bool cycle=0;
    vector<bool> vis(V,0);
    vector<bool> rec(V,0);
    
    
    for(int i=0;i<V;++i)
    {
        if(cycle==0 && vis[i]==0)
        {
            dfs(graph,vis,i,V,cycle,rec);
        }
    }
    return cycle;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
