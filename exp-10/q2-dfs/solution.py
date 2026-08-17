import sys

sys.setrecursionlimit(1000000)


def dfs(u):
    visited[u] = True
    order.append(u)
    for v in adj[u]:
        if not visited[v]:
            dfs(v)


n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
s = int(input())

for i in range(1, n + 1):
    adj[i].sort()

visited = [False] * (n + 1)
order = []
dfs(s)
print("DFS Traversal:", " ".join(map(str, order)))