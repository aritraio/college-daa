# Experiment 9: Dynamic Programming & Backtracking — Q1. Matrix Chain Multiplication

## Problem Statement
Given a chain of `n` matrices `A1, A2, ..., An` with dimensions given as a sequence `p0, p1, ..., pn` (matrix `Ai` has dimensions `p[i-1] x p[i]`), find the minimum number of scalar multiplications needed to compute the product `A1 x A2 x ... x An`. Since matrix multiplication is associative but not commutative, different parenthesizations yield the same result but with different costs. The program reads `n` followed by the `n+1` dimensions, prints the minimum cost and one optimal parenthesization (e.g. `((A1(A2A3))A4)`).

## Algorithm & Approach
- Uses **Dynamic Programming** with a table `m[i][j]` = minimum cost to multiply matrices `Ai..Aj`.
- Base case: `m[i][i] = 0` — a single matrix needs no multiplication.
- Recurrence: for every split point `k` between `i` and `j`:

  `m[i][j] = min(m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j])`

- The extra cost `p[i-1] * p[k] * p[j]` is the cost of multiplying the two result matrices `(Ai..Ak)` and `(A(k+1)..Aj)`.
- A second table `s[i][j]` records the split point `k` that gives the minimum, used to reconstruct the optimal parenthesization by recursion.
- Tables are filled in increasing order of chain length (bottom-up), so every subproblem is solved before it is needed.

## Pseudocode
```
read n
read p[0..n]                 // n + 1 dimensions
for i = 1 to n: m[i][i] = 0

for len = 2 to n:
    for i = 1 to n - len + 1:
        j = i + len - 1
        m[i][j] = infinity
        for k = i to j - 1:
            cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
            if cost < m[i][j]:
                m[i][j] = cost
                s[i][j] = k

function PrintOrder(i, j):
    if i == j:
        print "A" + i
        return
    print "("
    PrintOrder(i, s[i][j])
    PrintOrder(s[i][j] + 1, j)
    print ")"

print "Minimum cost: " + m[1][n]
print "Optimal parenthesization: "
PrintOrder(1, n)
```

## Complexity Analysis
- **Time Complexity:** O(n³) — three nested loops over chain length, start index, and split point `k`.
- **Space Complexity:** O(n²) — the `m` and `s` tables each hold `n x n` entries.

## Sample Input & Output
```
Input:
4
5 4 6 2 7

Output:
Minimum cost: 158
Optimal parenthesization: ((A1(A2A3))A4)
```
