from collections import deque

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
q = deque([s])
visited[s] = True

order = []
while q:
    u = q.popleft()
    order.append(u)
    for v in adj[u]:
        if not visited[v]:
            visited[v] = True
            q.append(v)

print("BFS Traversal:", " ".join(map(str, order)))