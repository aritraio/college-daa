# Experiment 12: Shortest Paths — Q1. Bellman-Ford Algorithm

## Problem Statement
Implement the Bellman-Ford algorithm to find the shortest distances from a given source vertex `s` to all other vertices in a weighted directed graph that may contain negative edge weights. The graph has `n` vertices numbered `1` to `n` and `m` edges. The program reads `n m`, followed by `m` lines of edges `u v w`, and finally the source vertex `s`. It prints the shortest distance from `s` to every vertex, or `Negative cycle detected` if the graph contains a negative-weight cycle reachable from `s`. Unreachable vertices are printed as `INF`.

## Algorithm & Approach
- Initialize `dist[s] = 0` and `dist[v] = INF` (999999) for all other vertices.
- Repeat `n - 1` times: relax every edge `(u, v, w)` — if `dist[u] + w < dist[v]`, update `dist[v]`. Each pass guarantees that the shortest path using at most `i` edges has been found after pass `i`; since any simple path has at most `n - 1` edges, `n - 1` passes suffice.
- After the passes, run one more full relaxation pass. If any edge can still be relaxed, a negative-weight cycle exists, so print `Negative cycle detected`.
- Otherwise print the final distances from `s` to all vertices.

## Pseudocode
```
read n, m
edges = list of (u, v, w) tuples
read s

dist[1..n] = INF
dist[s] = 0

for i = 1 to n - 1:
    changed = false
    for each edge (u, v, w):
        if dist[u] != INF and dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            changed = true
    if not changed: break

for each edge (u, v, w):
    if dist[u] != INF and dist[u] + w < dist[v]:
        print "Negative cycle detected"
        return

print "Shortest distances from source s:"
for i = 1 to n:
    print i, ": ", dist[i] (or INF if unreachable)
```

## Complexity Analysis
- **Time Complexity:** O(V × E) — each of the `V - 1` passes relaxes all `E` edges, and the negative-cycle check costs one extra pass over all edges.
- **Space Complexity:** O(V + E) — the `dist` array takes O(V) and storing the `m` edges takes O(E).

## Sample Input & Output
```
Input:
5 10
1 2 6
1 4 7
2 3 5
2 4 8
2 5 -4
3 2 -2
4 3 -3
4 5 9
5 1 2
5 3 7
1

Output:
Shortest distances from source 1:
1: 0
2: 2
3: 4
4: 7
5: -2
```

With a negative-weight cycle (1 → 2 → 3 → 1 has weight 1 + 1 - 3 = -1):
```
Input:
3 3
1 2 1
2 3 1
3 1 -3
1

Output:
Negative cycle detected
```
