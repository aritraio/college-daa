# Heap Sort

## Problem Statement
Write a C program to perform the Heap Sort technique. The program reads the array size `n` followed by `n` integers, sorts them in ascending order using Heap Sort, and prints the sorted array.

## Algorithm & Approach
Heap Sort is a comparison-based sorting algorithm that uses a binary heap:

1. **Build Max-Heap**: Rearrange the array so that it satisfies the max-heap property — every parent node is greater than or equal to its children.
2. **Heapify**: The `heapify` routine fixes a single violation of the heap property by sifting an element down to its correct position, swapping with the larger child.
3. **Extract repeatedly**: Swap the root (largest element) with the last element, reduce the heap size by one, and heapify the root. Repeat until the heap is empty. The largest elements accumulate at the end of the array, producing ascending order.

## Pseudocode
```
HEAPIFY(arr, n, i)
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[largest]: largest = left
    if right < n and arr[right] > arr[largest]: largest = right
    if largest != i:
        swap arr[i] and arr[largest]
        HEAPIFY(arr, n, largest)

HEAP-SORT(arr, n)
    for i = n/2 - 1 down to 0:
        HEAPIFY(arr, n, i)          // build max-heap
    for i = n - 1 down to 1:
        swap arr[0] and arr[i]
        HEAPIFY(arr, i, 0)          // restore heap on reduced size
```

## Complexity Analysis

### Time Complexity
- **Best case**: O(n log n)
- **Average case**: O(n log n)
- **Worst case**: O(n log n)
Building the heap takes O(n), and each of the n extraction steps performs a heapify of O(log n), giving O(n log n) overall in every case.

### Space Complexity
O(1) — Heap Sort sorts in place and only uses constant extra space (besides the implicit recursion/iteration in heapify).

## Sample Input & Output
```
Input:
6
5 2 8 1 9 3

Output:
1 2 3 5 8 9
```