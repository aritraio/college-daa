# Experiment 4.q3 — Naïve String Matching (Brute-Force)

## Problem Statement

Write a brute-force program for naïve string matching. Given a text string and a pattern string (one per line), print the index (0-based) of every occurrence of the pattern in the text, or print `not found` if the pattern does not occur.

## Algorithm & Approach

1. Read the text `T` (length `n`) and the pattern `P` (length `m`).
2. Slide the pattern over the text, one character at a time, from position `0` to `n - m`:
   - Compare `P[0..m-1]` with `T[i..i+m-1]` character by character.
   - If all `m` characters match, the pattern occurs at index `i`; print it.
3. If no match was found, print `not found`.

This is the simplest (naïve) pattern-matching algorithm that checks every possible alignment.

## Pseudocode

```
main:
    read text T[0..n-1]
    read pattern P[0..m-1]
    found = false
    for i = 0 to n - m:
        j = 0
        while j < m and T[i + j] == P[j]:
            j = j + 1
        if j == m:
            print "Pattern found at index i"
            found = true
    if found == false:
        print "not found"
```

## Complexity Analysis

- **Time Complexity:** `O(n·m)` in the worst case (e.g. pattern and text of all same characters); `O(n)` in the best case when the first character of the pattern never matches.
- **Space Complexity:** `O(1)` extra space — only the input strings are stored (plus `O(n + m)` for storing text and pattern).

## Sample Input & Output

**Input:**

```
ABABDABACDABABCABAB
ABABCABAB
```

**Output:**

```
Pattern found at index 10
```

(If the pattern does not occur, the program prints `not found`.)