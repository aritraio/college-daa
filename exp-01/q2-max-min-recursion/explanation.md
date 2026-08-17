# Experiment 1: Recursion Basics — Q2. Maximum and Minimum Using Recursion

## Problem Statement
Write a program to find the maximum and minimum elements in an array using recursion. The program reads the size of the array `n` followed by `n` elements, and prints the minimum and maximum values found.

## Algorithm & Approach
- The array is scanned element by element using recursion.
- **Base case:** when only one element remains, it is both the min and max.
- **Recursive step:** find min and max for the first `n-1` elements, then compare the `n`-th element against both and update them if needed.
- After the recursion completes, the accumulated min and max are printed.

## Pseudocode
```
function findMinMax(arr, n):
    if n == 1:
        return (arr[0], arr[0])
    (min, max) = findMinMax(arr, n - 1)
    if arr[n-1] < min: min = arr[n-1]
    if arr[n-1] > max: max = arr[n-1]
    return (min, max)

read n
read arr[0..n-1]
(min, max) = findMinMax(arr, n)
print "Min: min"
print "Max: max"
```

## Complexity Analysis
- **Time Complexity:** O(n) — each array element is examined exactly once across `n` recursive calls.
- **Space Complexity:** O(n) — the recursion stack grows to depth `n`.

## Sample Input & Output
```
Input:
5
3 7 1 9 2

Output:
Min: 1
Max: 9
```