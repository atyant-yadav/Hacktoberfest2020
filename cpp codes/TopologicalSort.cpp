// Author: Adarsh Kishore Mehra
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* This program demonstrates the working of Topological Sort.
 * Topological Sort only works for a directed acyclic graph.
 * I have implemented this algorithm with the help of BFS.
 * Therefore, the overall time complexity is simply O(|V| + |E|)
 */

const int numVertices = 6; // 6 vertices (0,1,2,3,4,5)
int source;
vector <bool> visitedVertex(numVertices, false); // Mark everything as unvisited
vector <int> inDegree(numVertices, 0); // Initialize all in-Degrees to 0
vector <int> T; // This will store the vertices that TopologicalSort visits in order.
void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
} // To create adjacency list

void TopologicalSort(vector <int> adjList[]){
  queue <int> Q; //set up Queue for BFS
  int v;

  for (int i = 0; i < numVertices; i++) // for all vertices in the graph
    for (vector <int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++) // visit it's neighbors
      inDegree.at(*it)++; //increment inDegree of that child

  for (int i = 0; i < numVertices; i++)
    if (inDegree.at(i) == 0){
      source = i;
      Q.push(source); // Push it onto the queue as a starting point for BFS
      visitedVertex.at(source) = true; // Mark it true
      break;
    } // Found a vertex with 0 inDegree -> This will be our source for Topological Sort

  while (!Q.empty()){
    v = Q.front(); // Get v
    Q.pop();
    T.push_back(v); // Add to T-Vector

    /* Now to proceed with Topological Sort, we remove the vertex and all its corresponding edges.
     * Which means, the in-degree's of all it's neighbors will be reduced by 1
     */

    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Visit all neighbors
      if (!visitedVertex.at(*it)){
        inDegree.at(*it)--; // Decrement inDegree of the neighbor, because its parent vertex has been removed
        if (inDegree.at(*it) == 0){
          Q.push(*it); // Push the vertex with least inDegree -> New Source
          visitedVertex.at(*it) = true; // Mark it to be true
        } // Find new source
      } // if not visited
  } // While Queue is not empty
} // TopologicalSort(vector <int> adjList[])

int main (void){
  vector<int> adjList[numVertices]; // Create an array of vectors
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 3);
  createAndAddEdge(adjList, 1, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 2, 5);
  createAndAddEdge(adjList, 3, 4);
  createAndAddEdge(adjList, 3, 5);
  createAndAddEdge(adjList, 4, 5);
  TopologicalSort(adjList); // Topological Sort for a given DAG
  cout << "Topological Sort for the given DAG: ";
  for (int i = 0; i < T.size(); i++)
    cout << T.at(i) << " ";
  cout << endl;
  //Should Print: 0 1 2 3 4 5

} // main()
