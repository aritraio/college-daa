# Experiment 7: Greedy Algorithms — Q1. Fractional Knapsack

## Problem Statement
Given `n` items, each with a weight and a profit, and a knapsack of capacity `W`, fill the knapsack so that the total profit is maximized. Unlike the 0/1 knapsack, fractions of an item may be taken. The program reads `n`, the capacity `W`, and then `weight profit` for each of the `n` items, and prints the maximum obtainable total profit with two decimal places.

## Algorithm & Approach
- Compute the profit-to-weight ratio (profit per unit weight) for every item.
- Sort the items by this ratio in descending order — the greedy choice is to always pick the item with the highest value per unit weight first.
- Iterate through the sorted items: if an item's weight fits in the remaining capacity, take it completely; otherwise take only the fraction that fills the remaining capacity.
- Accumulate the total profit and stop once the knapsack is full.

## Pseudocode
```
read n, W
for i = 1 to n:
    read weight[i], profit[i]
sort items by profit[i] / weight[i] in descending order
total = 0
for each item in sorted order:
    if weight[i] <= W:
        total = total + profit[i]
        W = W - weight[i]
    else:
        total = total + profit[i] * (W / weight[i])
        W = 0
print total with 2 decimal places
```

## Complexity Analysis
- **Time Complexity:** O(n log n) — dominated by sorting the items by ratio.
- **Space Complexity:** O(n) — for storing the `n` items.

## Sample Input & Output
```
Input:
3 50
10 60
20 100
30 120

Output:
240.00
```