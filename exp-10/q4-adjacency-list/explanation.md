# Experiment 10: Graph Traversal & Representations — Q4. Represent Graph using Adjacency List

## Problem Statement
Write a program to represent an undirected graph using an adjacency list. The graph has `n` vertices numbered `1` to `n` and `m` undirected edges. The program reads `n m`, followed by `m` lines of edges `u v`, and prints the adjacency list of every vertex — the list of all neighbors of each vertex, sorted in ascending order.

## Algorithm & Approach
- Create `n + 1` empty lists, one per vertex.
- For every edge `(u, v)`, add `v` to the list of `u` and add `u` to the list of `v` (undirected edge stored in both directions).
- Sort each vertex's neighbor list in ascending order for a deterministic output.
- Print, for each vertex `i` from `1` to `n`, the line `i: v1 v2 ...` where `v1, v2, ...` are the sorted neighbors of `i`.

## Pseudocode
```
read n, m
adjacency list adj[v] = empty list for v = 1..n
for each edge (u, v):
    adj[u].add(v)
    adj[v].add(u)
for i = 1 to n:
    sort adj[i] in ascending order
    print i followed by ": "
    print all elements of adj[i] separated by spaces
    print newline
```

## Complexity Analysis
- **Time Complexity:** O(V + E) — each edge is stored once in each direction in O(1); sorting each list takes O(Σ dᵢ log dᵢ) ≤ O(E log V) in the worst case, and printing takes O(V + E).
- **Space Complexity:** O(V + E) — the adjacency lists store 2E neighbor entries plus the list headers.

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
1: 2 3
2: 1 4
3: 1 5
4: 2 5
5: 3 4
```