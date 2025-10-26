#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000 // infinity
// Utility function to print a matrix
void printMatrix(const vector<vector<int>> &mat, int V, string msg)
{
cout << "\n" << msg << "\n";
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
if (mat[i][j] == INF)
cout << "INF ";
else
cout << mat[i][j] << " ";
}
cout << "\n";
}
}
void floydWarshall(vector<vector<int>> &graph, int V, int source)
{
vector<vector<int>> dist = graph;
// Print the initial adjacency matrix
printMatrix(dist, V, "Initial Adjacency Matrix:");
// Run Floyd–Warshall
for (int k = 0; k < V; k++) {
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (dist[i][k] != INF && dist[k][j] != INF)
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
}
// Print matrix after each iteration
string msg = "Matrix after considering vertex " + to_string(k) + ":";
printMatrix(dist, V, msg);
}
// Final result
printMatrix(dist, V, "Final Shortest Distance Matrix:");
// Print shortest distances from source
cout << "\nShortest distances from source vertex " << source << ":\n";
for (int j = 0; j < V; j++)
{
if (dist[source][j] == INF)
cout << "To " << j << " = INF\n";
else
cout << "To " << j << " = " << dist[source][j] << "\n";
}
}
int main()
{
int V, E, source;
cout << "Enter number of vertices: ";
cin >> V;
cout << "Enter number of edges: ";
cin >> E;
// initialize adjacency matrix with INF, and 0 on diagonals
vector<vector<int>> graph(V, vector<int>(V, INF));
for (int i = 0; i < V; i++) graph[i][i] = 0;
cout << "Enter edges in format (u v w):\n";
cout << "u = from vertex, v = to vertex, w = weight\n";
for (int i = 0; i < E; i++)
{
int u, v, w;
cin >> u >> v >> w;
graph[u][v] = w; // directed edge u -> v
}
cout << "Enter source vertex: ";
cin >> source;
floydWarshall(graph, V, source);
return 0;
}