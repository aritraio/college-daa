n, m = map(int, input().split())
mat = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    mat[u][v] = 1
    mat[v][u] = 1

for i in range(1, n + 1):
    print(" ".join(str(mat[i][j]) for j in range(1, n + 1)))