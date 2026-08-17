# Experiment 4.q4 — Selection Sort (Brute-Force)

## Problem Statement

Write a brute-force program to sort `n` numbers using the selection sort technique. The program reads `n` followed by `n` integers and prints the array in non-decreasing (ascending) order.

## Algorithm & Approach

1. Read `n` and the `n` array elements.
2. Repeatedly select the smallest element from the unsorted portion and place it at the front:
   - For each position `i` from `0` to `n - 2`, find the index `minIdx` of the minimum element in `a[i..n-1]`.
   - Swap `a[i]` with `a[minIdx]`.
3. After `n - 1` passes, the array is fully sorted.
4. Print the sorted array on one line.

Selection sort is a simple brute-force style sort: it always scans the remaining unsorted part to locate the minimum.

## Pseudocode

```
function SELECTION-SORT(a, n):
    for i = 0 to n - 2:
        minIdx = i
        for j = i + 1 to n - 1:
            if a[j] < a[minIdx]:
                minIdx = j
        swap(a[i], a[minIdx])

main:
    read n
    read a[0..n-1]
    SELECTION-SORT(a, n)
    print a[0..n-1]
```

## Complexity Analysis

- **Time Complexity:** `O(n²)` — the inner loop runs `n - 1 - i` times for each `i`, giving `n(n-1)/2` comparisons in all cases (best, average, and worst).
- **Space Complexity:** `O(1)` extra space — sorting is done in-place (plus `O(n)` for the input array storage).

## Sample Input & Output

**Input:**

```
6
64 25 12 22 11 9
```

**Output:**

```
9 11 12 22 25 64
```