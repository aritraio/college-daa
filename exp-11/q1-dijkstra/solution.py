import sys

INF = 1000000000
MAX = 100


def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    n, m = data[idx], data[idx + 1]
    idx += 2

    adj = [[INF] * MAX for _ in range(MAX)]
    for _ in range(m):
        u, v, w = data[idx], data[idx + 1], data[idx + 2]
        idx += 3
        adj[u][v] = w
    s = data[idx]

    dist = [INF] * MAX
    visited = [False] * MAX
    dist[s] = 0

    for _ in range(n):
        u = -1
        min_dist = INF
        for i in range(1, n + 1):
            if not visited[i] and dist[i] < min_dist:
                min_dist = dist[i]
                u = i
        if u == -1:
            break
        visited[u] = True
        for v in range(1, n + 1):
            if not visited[v] and adj[u][v] < INF and dist[u] + adj[u][v] < dist[v]:
                dist[v] = dist[u] + adj[u][v]

    for i in range(1, n + 1):
        print(f"Distance from {s} to {i}: {dist[i]}")


if __name__ == "__main__":
    main()
