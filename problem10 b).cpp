#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;
struct Node {
    int level;
    int profit;
    int weight;
    double bound;
    vector<int> taken;
    Node(int n = 0) : level(-1), profit(0), weight(0), bound(0.0), taken(n, -1) {}
};
double boundFrac(const Node &u, int n, int W, const vector<int>& wt, const vector<int>& val) {
    if (u.weight >= W) return 0.0;
    double b = u.profit;
    int totw = u.weight;
    int i = u.level + 1;
    while (i < n && totw + wt[i] <= W) {
        totw += wt[i];
        b += val[i];
        ++i;
    }
    if (i < n && wt[i] > 0) b += (double)(W - totw) * ((double)val[i] / wt[i]);
    return b;
}
struct Compare {
    bool operator()(const Node &a, const Node &b) const {
        return a.bound < b.bound; // Max-heap by bound
    }
};

int main() {
    int n, W;
    cout << "Enter number of items: " << flush;
    if (!(cin >> n)) return 0;
    vector<int> wt(n), val(n);
    cout << "Enter weights of items (space separated): " << flush;
    for (int i = 0; i < n; ++i) cin >> wt[i];
    cout << "Enter values of items (space separated): " << flush;
    for (int i = 0; i < n; ++i) cin >> val[i];
    cout << "Enter knapsack capacity: " << flush;
    cin >> W;
    // Sort by value/weight ratio for better pruning (keep original index map)
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        double ra = (wt[a] > 0) ? (double)val[a] / wt[a] : (double)val[a] + 1e9;
        double rb = (wt[b] > 0) ? (double)val[b] / wt[b] : (double)val[b] + 1e9;
        return ra > rb;
    });

    vector<int> wt2(n), val2(n);
    for (int i = 0; i < n; ++i) { wt2[i] = wt[idx[i]]; val2[i] = val[idx[i]]; }
    priority_queue<Node, vector<Node>, Compare> pq;
    Node root(n);
    root.bound = boundFrac(root, n, W, wt2, val2);
    pq.push(root);

    int maxProfit = 0;
    vector<int> bestTaken(n, 0);

    while (!pq.empty()) {
        Node u = pq.top(); pq.pop();
        if (u.bound <= maxProfit) continue;
        int lvl = u.level + 1;
        if (lvl >= n) continue;

        // include item
        Node v = u;
        v.level = lvl;
        v.weight = u.weight + wt2[lvl];
        v.profit = u.profit + val2[lvl];
        v.taken = u.taken;
        v.taken[lvl] = 1;
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
            bestTaken = v.taken;
        }
        v.bound = boundFrac(v, n, W, wt2, val2);
        if (v.bound > maxProfit) pq.push(v);
        // exclude item
        v = u;
        v.level = lvl;
        v.taken = u.taken;
        v.taken[lvl] = 0;
        v.bound = boundFrac(v, n, W, wt2, val2);
        if (v.bound > maxProfit) pq.push(v);
    }
    // Map back to original item order
    vector<int> resultTaken(n, 0);
    for (int i = 0; i < n; ++i)
        if (bestTaken[i] == 1) resultTaken[idx[i]] = 1;

    cout << "Maximum Profit: " << maxProfit << "\n";
    cout << "Items included (0-based indices): ";
    for (int i = 0; i < n; ++i) if (resultTaken[i]) cout << i << " ";
    cout << "\n";
    return 0;
}




