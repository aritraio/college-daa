import sys

INF = 999999


def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1

    dist = []
    for _ in range(n):
        row = []
        for _ in range(n):
            row.append(int(data[idx])); idx += 1
        dist.append(row)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != INF and dist[k][j] != INF and \
                   dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    for i in range(n):
        for j in range(n):
            if j > 0:
                print(" ", end="")
            if dist[i][j] == INF:
                print("INF", end="")
            else:
                print(dist[i][j], end="")
        print()


if __name__ == "__main__":
    main()
