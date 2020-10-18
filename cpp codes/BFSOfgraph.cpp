//not memory efficient since it push elements in queue that are already pushed in queue
//see gfg for memory efficient version


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    
    queue<int> q;
    q.push(s);
    
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        if(vis[s]==0)
        {
        vis[s]=1;
        cout<<s<<" ";
        }
        for(int i=0;i<adj[s].size();++i)
        {
            if(vis[adj[s][i]]==0)
            {
                q.push(adj[s][i]);
            }
        }
    }
    
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

  // } Driver Code Ends
