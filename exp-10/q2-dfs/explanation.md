# Experiment 10: Graph Traversal & Representations — Q2. Depth First Search (DFS)

## Problem Statement
Write a program to implement the Depth First Search (DFS) algorithm on an undirected graph. The graph has `n` vertices numbered `1` to `n` and `m` undirected edges. The program reads `n m`, followed by `m` lines of edges `u v`, and finally the start vertex `s`. It prints the DFS traversal order of the vertices starting from `s`, using recursion.

## Algorithm & Approach
- Build an adjacency list from the edge list. The neighbors of every vertex are kept sorted in ascending order so the traversal order is deterministic.
- Maintain a `visited` array.
- Recursive function `dfs(u)`: mark `u` as visited, print it, then call `dfs(v)` for every unvisited neighbor `v` of `u`.
- DFS goes as deep as possible along one path before backtracking to explore the next neighbor, producing the depth-first order.

## Pseudocode
```
read n, m
adjacency list adj[v] for v = 1..n
for each edge (u, v):
    adj[u].add(v)
    adj[v].add(u)
sort every adj[v] in ascending order
read s

function DFS(u):
    visited[u] = true
    print u
    for each v in adj[u]:
        if not visited[v]:
            DFS(v)

DFS(s)
```

## Complexity Analysis
- **Time Complexity:** O(V + E) — every vertex is visited exactly once and every edge is examined once while scanning adjacency lists.
- **Space Complexity:** O(V + E) — the adjacency list stores all edges; the recursion stack can grow up to O(V) in the worst case, plus the `visited` array.

## Sample Input & Output
```
Input:
5 5
1 2
1 3
2 4
3 5
4 5
1

Output:
DFS Traversal: 1 2 4 5 3
```