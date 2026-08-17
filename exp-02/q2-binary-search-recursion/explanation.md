# Binary Search (Recursion)

## Problem Statement

Implement Binary Search using recursion. Given a sorted array of `n` elements and a key element, find and return the index of the key using the divide and conquer technique. If the key is not present, indicate that it was not found.

## Algorithm & Approach

Binary search works on a sorted array. The array is repeatedly divided into halves. The middle element is compared with the key:

- If the middle element equals the key, its index is returned.
- If the key is smaller than the middle element, the search continues recursively in the left half.
- If the key is larger than the middle element, the search continues recursively in the right half.
- The recursion terminates when the search range becomes invalid (`low > high`), meaning the key is not present.

Steps:

1. Read the size `n` of the sorted array.
2. Read `n` elements into the array.
3. Read the key to search.
4. Call the recursive function `binarySearch(arr, 0, n - 1, key)`.
5. Print the returned index, or "Element not found" if the key is absent.

## Pseudocode

```
procedure BinarySearch(arr, low, high, key)
    if low > high then
        return -1
    end if

    mid = low + (high - low) / 2

    if arr[mid] == key then
        return mid
    else if arr[mid] > key then
        return BinarySearch(arr, low, mid - 1, key)
    else
        return BinarySearch(arr, mid + 1, high, key)
    end if
end procedure

main:
    read n
    read arr[0..n-1]
    read key
    index = BinarySearch(arr, 0, n - 1, key)
    if index == -1 then
        print "Element not found"
    else
        print "Element found at index", index
    end if
```

## Complexity Analysis

- **Time Complexity**: O(log n) in the best, average, and worst cases, since the search space is halved at every recursive call.
- **Space Complexity**: O(log n) due to the recursion stack used by the recursive calls. (An iterative version would use O(1) space.)

## Sample Input & Output

```
Input:
5
10 20 30 40 50
30

Output:
Element found at index 2
```