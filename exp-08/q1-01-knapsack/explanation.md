# Experiment 8: 0/1 Knapsack (Dynamic Programming) — Q1. 0/1 Knapsack

## Problem Statement
Given `n` items, each with a weight and a profit, and a knapsack of capacity `W`, find the maximum total profit that can be obtained by selecting a subset of items such that the total weight does not exceed `W`. Each item can be taken at most once (0/1 property — either the item is fully included or not at all). The program reads `n` and `W` followed by `n` lines of `weight profit`, and prints the maximum profit.

## Algorithm & Approach
- Use Dynamic Programming with a 2D table `dp[i][w]` that stores the maximum profit achievable using the first `i` items with a capacity of `w`.
- **Base case:** `dp[0][w] = 0` and `dp[i][0] = 0` — with no items or no capacity, profit is 0.
- For each item `i` (1-based) and each capacity `w`:
  - If the item's weight exceeds `w`, it cannot be taken: `dp[i][w] = dp[i-1][w]`.
  - Otherwise, take the better of two choices:
    - **Exclude** the item: `dp[i-1][w]`
    - **Include** the item: `val[i-1] + dp[i-1][w - wt[i-1]]`
  - `dp[i][w] = max(exclude, include)`
- The answer is `dp[n][W]`.

## Pseudocode
```
function Knapsack(n, W, wt[], val[]):
    create dp of size (n+1) x (W+1) initialized to 0
    for i = 1 to n:
        for w = 1 to W:
            if wt[i-1] <= w:
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]
    return dp[n][W]

read n, W
read wt[i], val[i] for i = 1 to n
print Knapsack(n, W, wt, val)
```

## Complexity Analysis
- **Time Complexity:** O(n\*W) — the 2D table has `(n+1) × (W+1)` cells, each filled in constant time.
- **Space Complexity:** O(n\*W) — a 2D DP table of size `(n+1) × (W+1)` is maintained.

## Sample Input & Output
```
Input:
3 50
10 60
20 100
30 120

Output:
220
```

Explanation: Items (weight, profit) = (10, 60), (20, 100), (30, 120) with capacity 50. Selecting items 2 and 3 (weights 20 + 30 = 50 ≤ 50) gives profit 100 + 120 = 220, which is optimal.