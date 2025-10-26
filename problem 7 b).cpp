#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
int n, W;
cout << "Enter number of items: ";
cin >> n;
int val[n], wt[n];
cout << "Enter profit of items:\n";
for (int i = 0; i < n; i++) cin >> val[i];
cout << "Enter weights of items:\n";
for (int i = 0; i < n; i++) cin >> wt[i];
cout << "Enter capacity of knapsack: ";
cin >> W;
// DP table
int dp[n + 1][W + 1];
// Fill DP table
for (int i = 0; i <= n; i++) {
for (int w = 0; w <= W; w++) {
if (i == 0 || w == 0)
dp[i][w] = 0;
else if (wt[i - 1] <= w)
dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
else
dp[i][w] = dp[i - 1][w];
}
}
// Print DP matrix
cout << "\nDP Matrix (rows=items, cols=capacity):\n";
for (int i = 0; i <= n; i++) {
for (int w = 0; w <= W; w++) {
cout << setw(3) << dp[i][w] << " ";
}
cout << endl;
}
cout << "\nMaximum value in Knapsack = " << dp[n][W] << endl;
// Traceback to find selected items
int w = W;
cout << "Items included (index starting from 1): ";
for (int i = n; i > 0 && w > 0; i--) {
if (dp[i][w] != dp[i - 1][w]) {
cout << i << " ";
w -= wt[i - 1];
}
}
cout << endl;
return 0;
}