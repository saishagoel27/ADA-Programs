#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; // large value for infinity
struct Node 
{
    vector<vector<int>> mat;
    int cost;
    int level;
    int vertex;
    vector<int> path;
};
void printMatrix(const vector<vector<int>>& m) 
{
    int n = (int)m.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] >= INF / 2) cout << setw(5) << "INF";
            else cout << setw(5) << m[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
int reduceRows(vector<vector<int>>& m) 
{
    int n = (int)m.size(), red = 0;
    for (int i = 0; i < n; ++i) {
        int rmin = INF;
        for (int j = 0; j < n; ++j) rmin = min(rmin, m[i][j]);
        if (rmin == INF || rmin == 0) continue;
        red += rmin;
        for (int j = 0; j < n; ++j) if (m[i][j] < INF) m[i][j] -= rmin;
    }
    return red;
}
int reduceCols(vector<vector<int>>& m) 
{
    int n = (int)m.size(), red = 0;
    for (int j = 0; j < n; ++j) {
        int cmin = INF;
        for (int i = 0; i < n; ++i) cmin = min(cmin, m[i][j]);
        if (cmin == INF || cmin == 0) continue;
        red += cmin;
        for (int i = 0; i < n; ++i) if (m[i][j] < INF) m[i][j] -= cmin;
    }
    return red;
}
int reduceMatrix(vector<vector<int>>& m) {
    return reduceRows(m) + reduceCols(m);
}
Node createChild(const Node& parent, int u, int v) {
    int n = (int)parent.mat.size();
    Node child;
    child.mat = parent.mat;
    int edgeCost = parent.mat[u][v];
    if (edgeCost >= INF / 2) edgeCost = INF;
    child.cost = parent.cost + (edgeCost == INF ? 0 : edgeCost);
    for (int j = 0; j < n; ++j) child.mat[u][j] = INF;
    for (int i = 0; i < n; ++i) child.mat[i][v] = INF;
    child.mat[v][0] = INF;
    child.cost += reduceMatrix(child.mat);
    child.level = parent.level + 1;
    child.vertex = v;
    child.path = parent.path;
    child.path.push_back(v);
    return child;
}
struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        return a.cost > b.cost;
    }
};
int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter cost matrix (use 'i' or 'I' for infinity):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string x;
            cin >> x;
            if (x == "i" || x == "I") cost[i][j] = INF;
            else cost[i][j] = stoi(x);
        }
    }
    cout << "\nInitial Cost Matrix:\n";
    printMatrix(cost);
    vector<vector<int>> rootMat = cost;
    int rootBound = reduceMatrix(rootMat);
    cout << "Root Reduced Matrix (Lower Bound = " << rootBound << "):\n";
    printMatrix(rootMat);
    priority_queue<Node, vector<Node>, Compare> pq;
    Node root;
    root.mat = rootMat;
    root.cost = rootBound;
    root.level = 0;
    root.vertex = 0;
    root.path = {0};

    pq.push(root);
    int finalCost = INF;
    vector<int> finalPath;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (cur.cost >= finalCost) continue;
        if (cur.level == n - 1) {
            int lastToStart = cost[cur.vertex][0];
            if (lastToStart >= INF / 2) continue;
            int tourCost = cur.cost + lastToStart;
            if (tourCost < finalCost) {
                finalCost = tourCost;
                finalPath = cur.path;
                finalPath.push_back(0);
            }
            continue;
        }
        for (int v = 0; v < n; ++v) {
            if (cur.mat[cur.vertex][v] < INF / 2) {
                bool visited = false;
                for (int x : cur.path) if (x == v) visited = true;
                if (visited) continue;

                Node child = createChild(cur, cur.vertex, v);
                cout << "Expanding: path = ";
                for (int x : child.path) cout << x << " ";
                cout << ", level = " << child.level << ", bound = " << child.cost << "\n";
                cout << "Reduced matrix for this node:\n";
                printMatrix(child.mat);

                if (child.cost < finalCost) pq.push(child);
            }
        }
    }
    if (finalCost >= INF / 2) {
        cout << "No Hamiltonian tour exists.\n";
    } else {
        cout << "Optimal TSP Tour Cost = " << finalCost << "\n";
        cout << "Tour: ";
        for (int i = 0; i < (int)finalPath.size(); ++i) {
            cout << finalPath[i];
            if (i + 1 != (int)finalPath.size()) cout << " -> ";
        }
        cout << "\n";
    }
    return 0;
}
