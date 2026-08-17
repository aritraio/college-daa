import sys

data = list(map(int, sys.stdin.read().split()))
n = data[0]
arr = data[1 : n + 1]
key = data[n + 1]

for i in range(n):
    if arr[i] == key:
        print(f"Element found at index {i}")
        break
else:
    print("Element not found")