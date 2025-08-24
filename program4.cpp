#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
struct Edge {
    int u, v, weight;
};
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}
// Disjoint Set Union for Kruskal
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;
        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};  // semicolon after class
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    vector<vector<pair<int,int>>> adj(V); // adjacency list for Prim
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    // Kruskal's MST
    sort(edges.begin(), edges.end(), compare);
    DSU dsu(V);
    int kruskalCost = 0;
    cout << "\nEdges in MST (Kruskal's):\n";
    for (Edge e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            kruskalCost += e.weight;
            cout << e.u << " - " << e.v << " : " << e.weight << endl;
        }
    }
    cout << "Minimum Cost (Kruskal): " << kruskalCost << endl;
    // Prim's MST
    vector<bool> inMST(V, false);
    typedef pair<int, int> pii; // (weight, vertex)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int primCost = 0;
    int src = 0; // starting vertex for Prim
    pq.push({0, src});
    cout << "\nEdges in MST (Prim's):\n";
    vector<int> parent(V, -1); // to track edges included in MST
    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        primCost += weight;
        if (parent[u] != -1) {
            cout << parent[u] << " - " << u << " : " << weight << endl;
        }
        for (auto [w, v] : adj[u]) {
            if (!inMST[v]) {
                pq.push({w, v});
                if (parent[v] == -1) {
                    parent[v] = u;
                }
            }
        }
    }
    cout << "Minimum Cost (Prim): " << primCost << endl;
    return 0;
}
