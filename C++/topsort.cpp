#include<bits/stdc++.h>
#define Graph unordered_map<int, vector<int>>
#define vi vector<int>
#define vb vector<bool>
using namespace std;
//  Top sort is implemented whenever there is no cycle in DAG

bool dfs (int curr, vb visited, Graph graph) {
  if(!visited[curr]){

    visited[curr] = true;
    for(int i=0; i < graph[curr].size(); i++)
      return dfs(graph[curr][i], visited, graph);

  } else
    return true;
}

bool detectCycle(int edges, Graph graph) {

  // initialises a visited array of type bool
    vb visited(edges, false);

    for(auto it : graph) {

      visited[it.first] = true;
      int sz = it.second.size();

      for(int i=0; i<sz; i++) {
          // do dfs and check for visited is once againg visiting or not
          if(dfs( it.second[i], visited, graph))
            return true;
      }
      visited[it.first] = false;
    }
    // dfs checked for all vertices and there we found no Cycle
      return false;
}

void topSortWithDfs(int curr, vector<int> &result , Graph graph, vb &visitedarray){

  if(!visitedarray[curr]) {
    visitedarray[curr]=true;

    for(int i=0; i<graph[curr].size(); i++)
      if(!visitedarray[graph[curr][i]])
        topSortWithDfs(graph[curr][i], result, graph, visitedarray);

      result.push_back(curr);
  }
}

vi topologicalsort(int edges, Graph graph) {

    if(detectCycle(edges, graph)) {
      cout<< "Oops there is cycle in graph.";
      return {};
    }


    vector<int> result;
    vb visitedarray(edges, false);

    for(auto item : graph)
          topSortWithDfs(item.first, result, graph, visitedarray);

    reverse(result.begin(), result.end());
    return result;
}


int main() {

  Graph graph;
  std::cout << "Enter total number of edges : " << '\n';
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int edges;
  cin>>edges;

  // Graph input from user
  int tempedges = edges;
  while(tempedges--) {
    int x;
    int y;
    cin >> x >> y;
    graph[x].push_back(y);
  }


  for( auto x : topologicalsort(edges, graph))
    cout<< x << " ";

  return 0;
}
