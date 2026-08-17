# Experiment 11: Single Source Shortest Path — Q1. Dijkstra's Shortest Path Algorithm

## Problem Statement
Implement Dijkstra's algorithm to find the shortest path distances from a single source vertex to all other vertices in a directed graph with non-negative edge weights. The graph has `n` vertices numbered `1` to `n` and `m` directed edges. The program reads `n m`, followed by `m` lines of edges `u v w` (edge from `u` to `v` with weight `w`), and finally the source vertex `s`. It prints the shortest distance from `s` to every vertex.

## Algorithm & Approach
- Represent the graph using an adjacency matrix `adj[u][v]` holding the weight of the edge `u → v`, with `INF` where no edge exists.
- Maintain a `dist` array (shortest distance from source, initially `INF`, with `dist[s] = 0`) and a `visited` array.
- Repeat `n` times (or until all reachable vertices are finalized):
  1. Select the unvisited vertex `u` with the smallest `dist` value (greedy choice — O(V) scan).
  2. Mark `u` as visited; its distance is now final.
  3. Relax every outgoing edge `u → v`: if `dist[u] + adj[u][v] < dist[v]`, update `dist[v]`.
- The greedy choice is correct because all edge weights are non-negative: the smallest unsettled distance can never be improved later.
- Uses an O(V²) vertex-selection loop instead of a priority queue; the matrix is scanned directly so no adjacency list is needed.

## Pseudocode
```
read n, m
adj[n][n] initialized to INF
for i = 1 to m:
    read u, v, w
    adj[u][v] = w
read s

for i = 1 to n:
    dist[i] = INF
    visited[i] = false
dist[s] = 0

for count = 1 to n:
    u = unvisited vertex with minimum dist[i]
    if no such u: break
    visited[u] = true
    for v = 1 to n:
        if not visited[v] and adj[u][v] < INF and dist[u] + adj[u][v] < dist[v]:
            dist[v] = dist[u] + adj[u][v]

for i = 1 to n:
    print "Distance from s to i: dist[i]"
```

## Complexity Analysis
- **Time Complexity:** O(V²) — the inner O(V) selection of the minimum and the O(V) relaxation are both repeated for each of the V vertices; edges are handled through the matrix, giving O(V²) overall (independent of E).
- **Space Complexity:** O(V²) — the adjacency matrix of size V × V, plus the O(V) `dist` and `visited` arrays.

## Sample Input & Output
```
Input:
5 7
1 2 10
1 3 3
2 3 1
2 4 2
3 2 4
3 4 8
4 5 7
1

Output:
Distance from 1 to 1: 0
Distance from 1 to 2: 7
Distance from 1 to 3: 3
Distance from 1 to 4: 9
Distance from 1 to 5: 16
```
