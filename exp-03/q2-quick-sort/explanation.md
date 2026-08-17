# Quick Sort

## Problem Statement
Write a program which can sort n numbers of elements using the Quick sort technique. The program reads the array size `n` followed by `n` integers, sorts them in ascending order using Quick sort, and prints the sorted array.

## Algorithm & Approach
Quick Sort is a divide-and-conquer algorithm that works in-place:

1. **Partition**: Choose a pivot (here, the last element). Rearrange the array so that all elements smaller than or equal to the pivot come before it, and all larger elements come after it. The pivot is placed in its final sorted position.
2. **Divide**: Recursively apply the same process to the subarray left of the pivot and the subarray right of the pivot.
3. **Combine**: No explicit combine step is needed — the array is sorted in place.

The partition routine scans the array with a pointer `i` keeping track of the boundary between elements smaller than the pivot and the rest, swapping as needed.

## Pseudocode
```
QUICK-SORT(arr, low, high)
    if low < high then
        pi = PARTITION(arr, low, high)
        QUICK-SORT(arr, low, pi - 1)
        QUICK-SORT(arr, pi + 1, high)

PARTITION(arr, low, high)
    pivot = arr[high]
    i = low - 1
    for j = low to high - 1:
        if arr[j] <= pivot:
            i = i + 1
            swap arr[i] and arr[j]
    swap arr[i + 1] and arr[high]
    return i + 1
```

## Complexity Analysis

### Time Complexity
- **Best case**: O(n log n) — partition splits the array into two equal halves.
- **Average case**: O(n log n)
- **Worst case**: O(n²) — pivot is always the smallest/largest element (e.g., already sorted input with last-element pivot).

### Space Complexity
O(log n) on average for the recursion stack; O(n) in the worst case (unbalanced partitions).

## Sample Input & Output
```
Input:
6
5 2 8 1 9 3

Output:
1 2 3 5 8 9
```