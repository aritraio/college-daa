import sys

INF = 999999


def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1
    m = int(data[idx]); idx += 1

    edges = []
    for _ in range(m):
        u = int(data[idx]); v = int(data[idx + 1]); w = int(data[idx + 2])
        idx += 3
        edges.append((u, v, w))
    s = int(data[idx])

    dist = [INF] * (n + 1)
    dist[s] = 0

    for _ in range(n - 1):
        changed = False
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                changed = True
        if not changed:
            break

    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            print("Negative cycle detected")
            return

    print(f"Shortest distances from source {s}:")
    for i in range(1, n + 1):
        if dist[i] == INF:
            print(f"{i}: INF")
        else:
            print(f"{i}: {dist[i]}")


if __name__ == "__main__":
    main()
