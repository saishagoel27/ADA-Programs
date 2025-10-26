#include <iostream>
#include <vector>
using namespace std;

int maxProfit = 0;
// Backtracking function
void knapsack(int i, int weight, int profit, int W, vector<int>& wt, vector<int>& val, int n) 
{
    if (weight > W) return;  // Invalid case
    if (i == n) {            // Reached end
        if (profit > maxProfit) maxProfit = profit;
        return;
    }

    // Include current item
    knapsack(i + 1, weight + wt[i], profit + val[i], W, wt, val, n);
    // Exclude current item
    knapsack(i + 1, weight, profit, W, wt, val, n);
}

int main() 
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    knapsack(0, 0, 0, W, wt, val, n);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
