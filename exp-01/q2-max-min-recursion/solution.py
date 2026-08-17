def find_min_max(arr, n):
    if n == 1:
        return arr[0], arr[0]
    cur_min, cur_max = find_min_max(arr, n - 1)
    cur_min = min(cur_min, arr[n - 1])
    cur_max = max(cur_max, arr[n - 1])
    return cur_min, cur_max


n = int(input())
arr = list(map(int, input().split()))
min_val, max_val = find_min_max(arr, n)
print(f"Min: {min_val}")
print(f"Max: {max_val}")