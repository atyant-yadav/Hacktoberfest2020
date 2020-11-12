/*Given a graph, the task is to check if it contains a negative weight cycle or not.

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains 2 lines the first line contains two space 
separated integers v and e denoting the no of vertices and no of edges respectively. 
Then in the next line are 3*e space separated values x,y,z denoting an edge from x to y 
with a weight of z.

Output:
For each test case in a new line print 0 if there is no negative weight cycle else print 1.
*/

#include <iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

typedef pair<int,int> ipair;

void addEdge(vector<ipair> graph[],int u,int v,int w)
{
    graph[u].push_back(make_pair(w,v));
}

bool shortestPath(vector<ipair> graph[],int V)
{
  
    vector<int> dist1(V,INT_MAX),dist2(V,INT_MAX);
    
    dist1[0]=dist2[0]=0;
    
    
    for(int i=0;i<V-1;++i)
    {
        for(int j=0;j<V;++j)
        {
            for(int k=0;k<graph[j].size();++k)
            {
              
                if(dist2[j]!=INT_MAX &&dist2[j]+graph[j][k].first<dist2[graph[j][k].second])
                {
                    dist2[graph[j][k].second]=dist2[j]+graph[j][k].first;
                }
            }
        }
    }
  
    
        for(int j=0;j<V;++j)
        {
            for(int k=0;k<graph[j].size();++k)
            {
               
                if(dist2[j]!=INT_MAX && dist2[j]+graph[j][k].first<dist2[graph[j][k].second])
                {
                    
                    return 1;
                }
            }
        }
    
    return 0;
}


int main() {
    int T,E,V,u,v,w;
    cin>>T;
    
    while(T)
    {
        
        cin>>V>>E;
        vector<ipair> graph[V];
        for(int i=0;i<E;++i)
        {
            cin>>u>>v>>w;
            addEdge(graph,u,v,w);
        }
        
        cout<<shortestPath(graph,V)<<"\n";
        
        T--;
    }
    
}
