# Experiment 9: Dynamic Programming & Backtracking — Q2. N-Queens Problem

## Problem Statement
Place `n` queens on an `n x n` chessboard such that no two queens attack each other. Two queens attack each other if they share the same row, column, or diagonal. The program reads `n` and prints every valid placement: each solution is printed as a single line of `n` integers giving the column position (1-indexed) of the queen in each row from 1 to `n`. After all solutions, the total count is printed.

## Algorithm & Approach
- Uses **Backtracking** — place queens row by row, and whenever a queen cannot be placed safely, backtrack and try the next column.
- The board is stored in an array `board[row] = col`, so only one queen exists per row.
- A candidate position `(row, col)` is safe if:
  - no earlier queen is in the same column: `board[i] != col`
  - no earlier queen is on the same diagonal: `|board[i] - col| != |i - row|`
- When `row == n`, a complete valid placement has been found: print the column positions and increment the solution counter.
- The recursion explores all safe columns at each row, guaranteeing every solution is discovered exactly once.

## Pseudocode
```
read n
count = 0
board[0..n-1]

function IsSafe(row, col):
    for i = 0 to row - 1:
        if board[i] == col or |board[i] - col| == |i - row|:
            return false
    return true

function Solve(row):
    if row == n:
        print board[0] + 1, board[1] + 1, ..., board[n-1] + 1
        count += 1
        return
    for col = 0 to n - 1:
        if IsSafe(row, col):
            board[row] = col
            Solve(row + 1)
            // backtrack: try next column

Solve(0)
print "Total solutions: " + count
```

## Complexity Analysis
- **Time Complexity:** O(n!) worst case — up to `n` choices per row and backtracking prunes unsafe branches; the first queen has `n` choices, the next at most `n-1`, and so on.
- **Space Complexity:** O(n) — the recursion stack holds at most `n` frames and the board array holds `n` entries.

## Sample Input & Output
```
Input:
4

Output:
2 4 1 3
3 1 4 2
Total solutions: 2
```
