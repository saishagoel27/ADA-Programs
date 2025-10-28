#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

void coinChange(int coins[], int n, int amount) {
    // Step 1: Create DP array
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // 0 coins needed for amount 0
    
    // To track which coin was used for each amount
    vector<int> usedCoin(amount + 1, -1);
    
    // Step 2: Fill DP table
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            // If this coin can be used
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    usedCoin[i] = coins[j];
                }
            }
        }
    }
    
    // Step 3: Print result
    cout << "\n--- RESULT ---\n";
    if (dp[amount] == INT_MAX) {
        cout << "Not possible to make amount " << amount << "\n";
        return;
    }
    
    cout << "Minimum coins needed: " << dp[amount] << "\n";
    
    // Step 4: Trace back to find which coins were used
    cout << "Coins used: ";
    int remaining = amount;
    while (remaining > 0) {
        cout << usedCoin[remaining] << " ";
        remaining -= usedCoin[remaining];
    }
    cout << "\n";
}

int main() {
    int n = 4;
    int coins[] = {1, 5, 6, 9};  // Fixed coin denominations
    
    cout << "========================================\n";
    cout << "   COIN CHANGE PROBLEM (DP)\n";
    cout << "========================================\n";
    cout << "Coin denominations: 1, 5, 6, 9\n";
    cout << "========================================\n";
    
    int counter = 5;  // Run 5 times with different amounts
    
    while (counter > 0) {
        int amount;
        cout << "\n\n>>> RUN " << (6 - counter) << " <<<\n";
        cout << "Enter target amount: ";
        cin >> amount;
        
        //  START TIMING
        auto start = high_resolution_clock::now();
        
        coinChange(coins, n, amount);
        
        auto stop = high_resolution_clock::now();
        //  STOP TIMING
        
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "\n TIME TAKEN: " << duration.count() << " microseconds\n";
        cout << "========================================\n";
        
        counter--;
    }
    
    cout << "\n ALL RUNS COMPLETED!\n";
    cout << "Now use the time data to create your graph.\n";
    
    return 0;
}