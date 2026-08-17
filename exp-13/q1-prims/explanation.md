# Experiment 13: Minimum Spanning Tree (Prim's) — Q1. Prim's Minimum Spanning Tree Algorithm

## Problem Statement
Write a program to implement Prim's algorithm to find the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph. The graph has `n` vertices numbered `1` to `n` and `m` edges. The program reads `n m`, followed by `m` lines of weighted edges `u v w` (1-indexed, with edge weight `w`). It starts from vertex `1` and prints every edge selected in the MST along with its weight, followed by the total weight of the MST.

## Algorithm & Approach
- Represent the graph using an `n x n` adjacency matrix, filling both `graph[u][v]` and `graph[v][u]` with the weight of each edge.
- Maintain three arrays: `key[v]` (minimum edge weight to connect vertex `v` to the tree so far, initialized to infinity), `parent[v]` (the vertex that connects `v` to the tree), and `mstSet[v]` (whether `v` is already in the MST).
- Set `key[1] = 0` (0-indexed: `key[0] = 0`) and `parent[1] = -1` so the algorithm starts from vertex `1`.
- Repeat `n - 1` times:
  - Pick the unvisited vertex `u` with the smallest `key` value (linear scan — the O(V²) version, no heap).
  - Mark `u` as part of the MST and add `key[u]` to the total weight.
  - For every neighbor `v` of `u` not yet in the MST, if the edge `(u, v)` is cheaper than `key[v]`, update `key[v]` and set `parent[v] = u`.
- Finally, print each edge `(parent[v], v)` with its weight for `v = 2 .. n`, and print the total weight.

## Pseudocode
```
read n, m
graph = n x n matrix initialized to 0
for i = 1 to m:
    read u, v, w
    graph[u][v] = w
    graph[v][u] = w

key[v] = infinity, parent[v] = -1, mstSet[v] = false  for v = 1..n
key[1] = 0
totalWeight = 0

for count = 1 to n:
    u = vertex not in mstSet with minimum key[u]
    mstSet[u] = true
    totalWeight = totalWeight + key[u]
    for v = 1 to n:
        if graph[u][v] != 0 and not mstSet[v] and graph[u][v] < key[v]:
            parent[v] = u
            key[v] = graph[u][v]

for v = 2 to n:
    print "Edge parent[v]-v weight key[v]"
print "Total weight of MST: totalWeight"
```

## Complexity Analysis
- **Time Complexity:** O(V²) — the main loop runs `n - 1` times, and each iteration scans up to `n` vertices to pick the minimum key (O(n)) and scans `n` vertices to relax keys (O(n)), giving O(n) + O(n) per iteration and O(n²) overall.
- **Space Complexity:** O(V²) — the adjacency matrix stores the graph; the `key`, `parent`, and `mstSet` arrays take O(V). Without the matrix (using a cost array of size V only), it would be O(V), but the matrix-based version uses O(V²).

## Sample Input & Output
```
Input:
5 7
1 2 2
1 4 6
2 3 3
2 4 8
2 5 5
3 5 7
4 5 9

Output:
Edge 1-2 weight 2
Edge 2-3 weight 3
Edge 1-4 weight 6
Edge 2-5 weight 5
Total weight of MST: 16
```
