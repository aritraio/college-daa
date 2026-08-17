# Experiment 10: Graph Traversal & Representations — Q1. Breadth First Search (BFS)

## Problem Statement
Write a program to implement the Breadth First Search (BFS) algorithm on an undirected graph. The graph has `n` vertices numbered `1` to `n` and `m` undirected edges. The program reads `n m`, followed by `m` lines of edges `u v`, and finally the start vertex `s`. It prints the BFS traversal order of the vertices starting from `s`, using a queue (iterative approach).

## Algorithm & Approach
- Build an adjacency list from the edge list. The neighbors of every vertex are kept sorted in ascending order so the traversal order is deterministic.
- Use a FIFO queue and a `visited` array.
- Mark the start vertex `s` as visited and enqueue it.
- While the queue is not empty: dequeue a vertex `u`, print it, and enqueue every unvisited neighbor of `u`, marking each as visited the moment it is enqueued.
- BFS explores the graph level by level: all vertices at distance `d` are printed before any vertex at distance `d + 1`.

## Pseudocode
```
read n, m
adjacency list adj[v] for v = 1..n
for each edge (u, v):
    adj[u].add(v)
    adj[v].add(u)
sort every adj[v] in ascending order
read s

visited[s] = true
queue.enqueue(s)
while queue is not empty:
    u = queue.dequeue()
    print u
    for each v in adj[u]:
        if not visited[v]:
            visited[v] = true
            queue.enqueue(v)
```

## Complexity Analysis
- **Time Complexity:** O(V + E) — every vertex is enqueued and dequeued at most once, and every edge is examined once while scanning adjacency lists.
- **Space Complexity:** O(V + E) — the adjacency list stores all edges, and the queue plus `visited` array take O(V).

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
BFS Traversal: 1 2 3 4 5
```