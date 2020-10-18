#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}


/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    bool visited[N];
    for(int i=0;i<N;i++)
    visited[i]=false;
    queue <int> q;
    vector <int> v;
    visited[0]=true;
    q.push(0);
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        v.push_back(a);
        for(int x:g[a])
        
        {
            if(visited[x]==false){
            visited[x]=true;
            q.push(x);}
        }
     }
     return v;
}
