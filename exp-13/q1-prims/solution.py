import sys

INF = float('inf')


def min_key(key, mst_set, n):
    min_val = INF
    min_index = -1
    for v in range(n):
        if not mst_set[v] and key[v] < min_val:
            min_val = key[v]
            min_index = v
    return min_index


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    n = int(next(it))
    m = int(next(it))

    graph = [[0] * n for _ in range(n)]

    for _ in range(m):
        u = int(next(it))
        v = int(next(it))
        w = int(next(it))
        graph[u - 1][v - 1] = w
        graph[v - 1][u - 1] = w

    parent = [-1] * n
    key = [INF] * n
    mst_set = [False] * n

    key[0] = 0

    total_weight = 0
    for _ in range(n):
        u = min_key(key, mst_set, n)
        mst_set[u] = True
        total_weight += key[u]

        for v in range(n):
            if graph[u][v] and not mst_set[v] and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]

    for v in range(1, n):
        print(f"Edge {parent[v] + 1}-{v + 1} weight {key[v]}")
    print(f"Total weight of MST: {total_weight}")


if __name__ == "__main__":
    main()
