def find_min_max(a, lo, hi):
    if lo == hi:
        return a[lo], a[lo]
    if hi == lo + 1:
        return (a[lo], a[hi]) if a[lo] < a[hi] else (a[hi], a[lo])
    mid = (lo + hi) // 2
    min_l, max_l = find_min_max(a, lo, mid)
    min_r, max_r = find_min_max(a, mid + 1, hi)
    return min(min_l, min_r), max(max_l, max_r)


n = int(input())
a = list(map(int, input().split()))
min_val, max_val = find_min_max(a, 0, n - 1)
print(f"Min: {min_val}")
print(f"Max: {max_val}")