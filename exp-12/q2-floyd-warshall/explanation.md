# Experiment 12: Shortest Paths — Q2. Floyd-Warshall Algorithm

## Problem Statement
Implement the Floyd-Warshall algorithm to find the shortest path distances between every pair of vertices in a weighted directed graph. The graph has `n` vertices numbered `0` to `n - 1`. The program reads `n`, followed by the `n x n` weight matrix where `dist[i][j]` is the weight of edge `i → j`, `0` on the diagonal, and `INF` (999999) where no edge exists. It prints the all-pairs shortest path distance matrix, with unreachable pairs shown as `INF`.

## Algorithm & Approach
- Start with the given weight matrix as the current distance matrix.
- Consider each vertex `k` as an intermediate vertex: for every pair `(i, j)`, check if going from `i` to `k` and then `k` to `j` is shorter than the current distance `dist[i][j]`; if so, update `dist[i][j] = dist[i][k] + dist[k][j]`.
- After processing all `k = 0 .. n-1`, `dist[i][j]` holds the length of the shortest path from `i` to `j` (paths may pass through any subset of intermediate vertices).
- The matrix is updated in place: `dist[i][k]` and `dist[k][j]` are never improved in iteration `k` after use, so in-place updates are safe.

## Pseudocode
```
read n
dist = n x n weight matrix (0 on diagonal, INF for no edge)

for k = 0 to n - 1:
    for i = 0 to n - 1:
        for j = 0 to n - 1:
            if dist[i][k] != INF and dist[k][j] != INF:
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

for i = 0 to n - 1:
    print dist[i][j] for j = 0 to n - 1 (INF if unreachable)
```

## Complexity Analysis
- **Time Complexity:** O(V³) — three nested loops over all `V` vertices, each iterating `V` times.
- **Space Complexity:** O(V²) — the `V x V` distance matrix is stored in place.

## Sample Input & Output
```
Input:
4
0 5 999999 10
999999 0 3 999999
999999 999999 0 1
999999 999999 999999 0

Output:
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0
```
