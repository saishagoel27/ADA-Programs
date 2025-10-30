 **EXPERIMENT 2: Coin Change Problem (Dynamic Programming)**

Aim: Find the minimum number of coins needed to make a given amount using Dynamic Programming.

Theory:
Given an infinite supply of coin denominations and a target amount, find the minimum number of coins needed to make that amount.
Example: Amount = 11, Coins = {1, 5, 6, 9}
Answer: 2 coins (5 + 6 = 11)
We use Dynamic Programming to build a table where dp[i] stores the minimum coins needed to make amount i.
Real-world Applications:

Making change in retail stores
Vending machines
Currency exchange systems
ATM cash dispensing


Time Complexity:
Best, Average, Worst Case: O(n × amount) where n = number of coin types


Algorithm:

1. Read number of coin types n and their denominations
2. Read target amount amount
3. Create DP array dp[amount+1] and initialize:
dp[0] = 0 (0 coins needed for amount 0)
dp[i] = INF for all other amounts (initially impossible)
4. For each amount from 1 to target:
For each coin denomination:
If coin ≤ current amount and dp[amount - coin] + 1 < dp[amount]:
Update dp[amount] = dp[amount - coin] + 1
5. If dp[amount] == INF, print "Not possible"
6. Otherwise, print minimum coins = dp[amount]
7. Trace back to find which coins were used

Graph: Time Complexity Analysis of Coin Change Problem (DP)

Observation:
The graph illustrates the execution time of the Coin Change algorithm 
using Dynamic Programming for varying target amounts from 50 to 5000.

The time increases almost linearly from approximately 20 microseconds 
(for amount 50) to 900 microseconds (for amount 5000), demonstrating 
O(n × amount) time complexity where n = 4 (number of coin denominations).

The smooth upward curve confirms the predictable and efficient nature 
of the DP approach, which builds solutions incrementally by solving 
subproblems for smaller amounts and reusing those solutions.

Unlike greedy approaches that may fail to find optimal solutions, 
this DP method guarantees finding the minimum number of coins needed 
for any target amount.

Conclusion:
The Dynamic Programming solution efficiently solves the Coin Change 
problem with predictable performance that scales linearly with the 
target amount, making it suitable for real-world applications like 
vending machines and retail cash registers.