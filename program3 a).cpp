#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge u → v
    }
    // BFS 
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "Reachable nodes from " << start << " (BFS): ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }
    // DFS 
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                DFSUtil(neigh, visited);
            }
        }
    }
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "Reachable nodes from " << start << " (DFS): ";
        DFSUtil(start, visited);
        cout << endl;
    }
};
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph g(V);
    cout << "Enter edges (u v) for directed graph:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int start;
    cout << "Enter starting node: ";
    cin >> start;
    g.BFS(start);
    g.DFS(start);
    return 0;
}

