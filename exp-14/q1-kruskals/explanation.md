# Experiment 14: Minimum Spanning Tree (Kruskal's) — Q1. Kruskal's Minimum Spanning Tree Algorithm

## Problem Statement
Given an undirected weighted graph with `n` vertices (numbered `1` to `n`) and `m` edges, find its Minimum Spanning Tree (MST) using Kruskal's algorithm. The MST is the set of `n - 1` edges that connects all vertices with the minimum possible total weight and no cycles. The program reads `n m`, followed by `m` lines `u v w`. It prints the edges selected in the MST along with their weights, and the total weight of the MST.

## Algorithm & Approach
- Treat every vertex as its own set (initially each is its own tree).
- Sort all edges in non-decreasing order of weight.
- Process edges one by one: for each edge `(u, v, w)`, check whether `u` and `v` belong to the same set using the union-find (disjoint set) data structure.
- If `u` and `v` are in different sets, the edge cannot form a cycle, so select it for the MST, add its weight to the total, and merge the two sets (union).
- Stop as soon as `n - 1` edges have been selected, since a spanning tree on `n` vertices has exactly `n - 1` edges.
- Union-find uses path compression (and union by simply linking roots) so `find` is nearly constant time.
- The greedy choice of always taking the cheapest safe edge is proven optimal for MST construction.

## Pseudocode
```
read n, m
edges = list of (u, v, w) for each of the m edges
sort edges by w in ascending order

parent[i] = i for i = 1..n     // union-find initialization

total = 0, count = 0
for each (u, v, w) in edges:
    if count == n - 1:
        break
    ru = find(u)
    rv = find(v)
    if ru != rv:                       // no cycle
        union(ru, rv)
        print u, v, w
        total = total + w
        count = count + 1

print "Total weight of MST:", total
```

## Complexity Analysis
- **Time Complexity:** O(E log E) — sorting the edges dominates; each `find`/union operation is nearly O(1) (inverse-Ackermann) with path compression, so the main loop is O(E α(V)).
- **Space Complexity:** O(V + E) — the edge list stores O(E) edges and the union-find `parent` array takes O(V).

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
Edges in MST:
1 - 2 (2)
2 - 3 (3)
2 - 5 (5)
1 - 4 (6)
Total weight of MST: 16
```
