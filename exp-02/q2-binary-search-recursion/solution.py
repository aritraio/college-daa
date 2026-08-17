import sys

def binary_search(arr, low, high, key):
    if low > high:
        return -1

    mid = low + (high - low) // 2

    if arr[mid] == key:
        return mid
    elif arr[mid] > key:
        return binary_search(arr, low, mid - 1, key)
    else:
        return binary_search(arr, mid + 1, high, key)


data = list(map(int, sys.stdin.read().split()))
n = data[0]
arr = data[1 : n + 1]
key = data[n + 1]

index = binary_search(arr, 0, n - 1, key)

if index == -1:
    print("Element not found")
else:
    print(f"Element found at index {index}")