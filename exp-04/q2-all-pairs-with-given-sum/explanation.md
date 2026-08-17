# Experiment 4.q2 — Find All Pairs with a Given Sum (Brute-Force)

## Problem Statement

Given an array of `n` integers and a target sum `S`, write a brute-force program to find and print all pairs of indices `(i, j)` with `i < j` such that `a[i] + a[j] == S`.

## Algorithm & Approach

1. Read `n`, the `n` array elements, and the target sum `S`.
2. Use two nested loops to generate every possible pair `(i, j)` with `i < j`:
   - For each pair, check whether `a[i] + a[j]` equals `S`.
   - If it does, print the pair of indices `(i, j)`.
3. If no pair matches, print `No pairs found`.

This is the classic brute-force approach that examines all `n(n-1)/2` pairs.

## Pseudocode

```
main:
    read n
    read a[0..n-1]
    read S
    found = false
    for i = 0 to n - 2:
        for j = i + 1 to n - 1:
            if a[i] + a[j] == S:
                print "(i, j)"
                found = true
    if found == false:
        print "No pairs found"
```

## Complexity Analysis

- **Time Complexity:** `O(n²)` — the two nested loops examine all `n(n-1)/2` pairs.
- **Space Complexity:** `O(n)` — only the input array needs to be stored.

## Sample Input & Output

**Input:**

```
5
1 5 7 -1 5
6
```

**Output:**

```
(0, 1)
(0, 4)
(2, 3)
```

(Note: `1+5=6` at indices `(0,1)` and `(0,4)`, and `7+(-1)=6` at indices `(2,3)`.)