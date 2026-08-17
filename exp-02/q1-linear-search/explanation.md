# Linear Search

## Problem Statement

Write a program to perform Linear Search. Given an array of `n` elements and a key element, find and return the index of the key in the array. If the key is not present, indicate that it was not found.

## Algorithm & Approach

Linear search scans the array element by element from the first index to the last. At each position, the current element is compared with the key. If a match is found, the index is returned immediately. If the entire array is scanned without a match, the search reports that the element is not found.

Steps:

1. Read the size `n` of the array.
2. Read `n` elements into the array.
3. Read the key to search.
4. Loop from index `0` to `n - 1`:
   - If `arr[i] == key`, print the index and stop.
5. If no match is found after the loop, print "Element not found".

## Pseudocode

```
procedure LinearSearch(arr, n, key)
    for i = 0 to n - 1 do
        if arr[i] == key then
            return i
        end if
    end for
    return -1
end procedure

main:
    read n
    read arr[0..n-1]
    read key
    index = LinearSearch(arr, n, key)
    if index == -1 then
        print "Element not found"
    else
        print "Element found at index", index
    end if
```

## Complexity Analysis

- **Time Complexity**: Best case O(1) (key at first position), Worst case O(n) (key at last position or absent). Average case O(n).
- **Space Complexity**: O(1), since only a constant amount of extra memory is used (apart from the input array).

## Sample Input & Output

```
Input:
5
10 20 30 40 50
30

Output:
Element found at index 2
```