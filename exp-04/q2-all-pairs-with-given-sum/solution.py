n = int(input())
a = list(map(int, input().split()))
s = int(input())

found = False
for i in range(n):
    for j in range(i + 1, n):
        if a[i] + a[j] == s:
            print(f"({i}, {j})")
            found = True

if not found:
    print("No pairs found")