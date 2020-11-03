// Dijkstra implementation to find the shortest path and print it........

#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
using ii= pair<ll,ll>;
#define F first
#define S second
#define MP make_pair

vector<ii> v[100];
ll dist[100];
ll vst[100];
vector<ll> parent;

class prioritize{                                     // comparator design of priority queue...
    public: bool operator()(ii &p1,ii &p2){
        return p1.S>p2.S;     // S -> second element of the pair ii...  p-> (node,weight)
    }    
};

void dijkstra(ll s,ll n)
{
    for(ll i=0;i<n;i++)    // initialize the global variables so that they are reset after each function call...
    {
        dist[i]=1e18;      // give infinite distance to the node3s initially....
        vst[i]=0;          // mark all as unvisited initially.....
    }

    dist[s]=0;             // set the distance of the source node to be zero....
    parent[s]=-1;          // set parent of source node as -1.....
    priority_queue<ii,vector<ii>,prioritize > pq;      // use a priority queue if a pair...its internally wrapped in a vector..hence the 
    pq.push(MP(s,0));                                  // vector<ii> in the expression.....// push the source node ......

    while(!pq.empty())     // loop untill the pq is empty...
    {
        ii h=pq.top();    // pop the top most element in the ascending order of the weights...
        pq.pop();         
        ll node=h.F;
       
        if(vst[node])continue;   // if the node is already visited , we need not do anything....else...
      else
      {
        vst[node]=1;            // mark it visited.....
        for(auto u: v[node])    // loop on all its neighbours in its adjacency list.....
        {
            ll neigh=u.F;       // let neigh be a node in its adjacency list and wt be its distance from the parent node 'node'
            ll wt=u.S;
            if(dist[neigh]>dist[node]+wt)   // if the distance of neigh from souce is > distance of it via the 'node', update the distance....
            {
                dist[neigh]=dist[node]+wt;  // min distance updated...
                parent[neigh]=node;         // push node as the parent of neigh as it get its shortst distance when accessed through 'node '...
                pq.push(make_pair(neigh,dist[neigh]));   // now push the neigh into the pq, so that its neighbours can be analysed...
            }
            
        }
      }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        for(ll i=0;i<n;i++){   // clearing the adjacency list before addressing each testcase coz the global list may have the data from a 
            v[i].clear();      // previous test case..
        }

        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                ll x;
                cin>>x;
               // wt[i][j]=x;
                if(x!=0)
                {
                    v[i].push_back(MP(j,x));   // creating our adjacency list.we push a pair of (node,weight) in the adjac. list of another node
                }
            }
        }

        ll s,g;       // s-> source g-> destination....
        cin>>s>>g;
        parent.resize(n,-1);    // must resize the parent vector otherwise u may get runtime (t)error....
        dijkstra(s,n);          // calling dijkstra....
        ll j=dist[g];           // j-> shortest path of g from s...accesing it using the  distance array
        cout<<j<<"\n";
        
        vector<ll> path;       // vector to store the shortest path nodes.....
        ll dest=g;
        while(dest!=-1)        // in the end.. only the source will have a parent as -1,
        {
            path.push_back(dest);
            dest=parent[dest];       // -1->0->1->4->8->9->7
        }
        reverse(path.begin(),path.end());  // reverse the path vector....
        for(auto no: path)          // loop on the path vector and print the node elements.....
        {
            cout<<no<<" ";
        }
        cout<<"\n";
    }
}