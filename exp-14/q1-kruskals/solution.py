import sys

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1
    m = int(data[idx]); idx += 1

    edges = []
    for _ in range(m):
        u = int(data[idx]); idx += 1
        v = int(data[idx]); idx += 1
        w = int(data[idx]); idx += 1
        edges.append((w, u, v))

    edges.sort()

    parent = list(range(n + 1))

    print("Edges in MST:")
    total = 0
    count = 0
    for w, u, v in edges:
        if count == n - 1:
            break
        ru = find(parent, u)
        rv = find(parent, v)
        if ru != rv:
            parent[ru] = rv
            print(f"{u} - {v} ({w})")
            total += w
            count += 1

    print(f"Total weight of MST: {total}")

if __name__ == "__main__":
    main()
