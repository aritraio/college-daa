# Merge Sort

## Problem Statement
Write a program which can sort n numbers of elements using the Merge sort technique. The program reads the array size `n` followed by `n` integers, sorts them in ascending order using Merge sort, and prints the sorted array.

## Algorithm & Approach
Merge Sort is a divide-and-conquer algorithm:

1. **Divide**: Recursively split the array into two halves until each subarray has a single element (a single element is always sorted).
2. **Conquer**: Each half is sorted independently by the recursion.
3. **Combine**: Merge the two sorted halves into one sorted array by repeatedly comparing the front elements of the two halves and placing the smaller one into the result.

The merge step uses two temporary arrays for the left and right halves, then copies the merged result back into the original array.

## Pseudocode
```
MERGE-SORT(arr, left, right)
    if left < right then
        mid = left + (right - left) / 2
        MERGE-SORT(arr, left, mid)
        MERGE-SORT(arr, mid + 1, right)
        MERGE(arr, left, mid, right)

MERGE(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid
    create L[0..n1-1] and R[0..n2-1] from arr
    i = 0, j = 0, k = left
    while i < n1 and j < n2:
        if L[i] <= R[j]: arr[k++] = L[i++]
        else: arr[k++] = R[j++]
    while i < n1: arr[k++] = L[i++]
    while j < n2: arr[k++] = R[j++]
```

## Complexity Analysis

### Time Complexity
- **Best case**: O(n log n)
- **Average case**: O(n log n)
- **Worst case**: O(n log n)
Merge Sort always divides the array into two halves (log n levels) and merges n elements at each level, so the total time is O(n log n) in every case.

### Space Complexity
O(n) — the merge step requires two temporary arrays whose total size is proportional to n, in addition to the O(log n) recursion stack.

## Sample Input & Output
```
Input:
6
5 2 8 1 9 3

Output:
1 2 3 5 8 9
```