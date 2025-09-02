#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()
// Function to implement Dijkstra's Algorithm
void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, INF);   // Distance array
    dist[src] = 0;
    // Min-heap priority queue: (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) 
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue; // Skip outdated entry
        // Traverse all adjacent vertices
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}
int main() 
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v w) where u->v has weight w:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if directed graph
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(V, adj, src);
    return 0;
}