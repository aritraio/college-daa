# Experiment 10: Graph Traversal & Representations — Q3. Represent Graph using Adjacency Matrix

## Problem Statement
Write a program to represent an undirected graph using an adjacency matrix. The graph has `n` vertices numbered `1` to `n` and `m` undirected edges. The program reads `n m`, followed by `m` lines of edges `u v`, and prints the `n × n` adjacency matrix where the entry `(i, j)` is `1` if there is an edge between vertex `i` and vertex `j`, and `0` otherwise. Since the graph is undirected, the matrix is symmetric.

## Algorithm & Approach
- Initialize an `(n + 1) × (n + 1)` matrix with all entries `0`.
- For every edge `(u, v)`, set `mat[u][v] = 1` and `mat[v][u] = 1` (undirected edge stored in both directions).
- Print the submatrix `mat[1..n][1..n]`, with entries of each row separated by a single space.

## Pseudocode
```
read n, m
mat[n+1][n+1] initialized to 0
for each edge (u, v):
    mat[u][v] = 1
    mat[v][u] = 1
for i = 1 to n:
    for j = 1 to n:
        print mat[i][j]
    print newline
```

## Complexity Analysis
- **Time Complexity:** O(V² + E) — setting an edge takes O(1), and printing the matrix requires O(V²) entries.
- **Space Complexity:** O(V²) — the adjacency matrix itself.

## Sample Input & Output
```
Input:
5 5
1 2
1 3
2 4
3 5
4 5

Output:
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
0 0 1 1 0
```