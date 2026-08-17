# Experiment 4.q1 — Find Maximum and Minimum Element using Divide and Conquer

## Problem Statement

Write a program to find the maximum and minimum element in an array of `n` integers using the divide and conquer technique.

## Algorithm & Approach

1. Read `n` and the `n` array elements.
2. Apply divide and conquer:
   - **Base case 1:** If the segment has only one element (`lo == hi`), that element is both the min and max.
   - **Base case 2:** If the segment has two elements (`hi == lo + 1`), compare them directly and assign min and max.
   - **Divide:** Otherwise split the segment at `mid = (lo + hi) / 2` into two halves.
   - **Conquer:** Recursively find (min, max) of the left half and the right half.
   - **Combine:** The overall min is the smaller of the two mins, and the overall max is the larger of the two maxes.
3. Print `Min` and `Max`.

## Pseudocode

```
function FIND-MIN-MAX(a, lo, hi):
    if lo == hi:
        return (a[lo], a[lo])
    if hi == lo + 1:
        if a[lo] < a[hi]: return (a[lo], a[hi])
        else:             return (a[hi], a[lo])
    mid = (lo + hi) / 2
    (minL, maxL) = FIND-MIN-MAX(a, lo, mid)
    (minR, maxR) = FIND-MIN-MAX(a, mid + 1, hi)
    return (min(minL, minR), max(maxL, maxR))

main:
    read n
    read a[0..n-1]
    (min, max) = FIND-MIN-MAX(a, 0, n - 1)
    print "Min:", min
    print "Max:", max
```

## Complexity Analysis

- **Time Complexity:** `O(n)` — each element is visited a constant number of times, and the recurrence `T(n) = 2T(n/2) + O(1)` solves to `O(n)`. Note: only about `3n/2 - 2` comparisons are needed, which is better than the `2n - 2` comparisons of a naive scan.
- **Space Complexity:** `O(log n)` — recursion stack depth for a balanced split (plus `O(n)` for the input array storage).

## Sample Input & Output

**Input:**

```
5
3 8 1 9 2
```

**Output:**

```
Min: 1
Max: 9
```