# Experiment 15.q2 — KMP String Matching Algorithm

## Problem Statement

Implement the Knuth–Morris–Pratt (KMP) String Matching Algorithm. Given a text string and a pattern string (one per line), print the index (0-based) of every occurrence of the pattern in the text, or print `not found` if the pattern does not occur. The KMP algorithm avoids re-comparing already matched characters by using the LPS (Longest Proper Prefix which is also a Suffix) table of the pattern.

## Algorithm & Approach

1. Read the text `T` (length `n`) and the pattern `P` (length `m`).
2. Preprocess the pattern to build the LPS array:
   - `lps[i]` = length of the longest proper prefix of `P[0..i]` that is also a suffix.
3. Scan the text left to right with two pointers `i` (text) and `j` (pattern):
   - If `P[j] == T[i]`, advance both `i` and `j`.
   - If `j == m`, a full match is found at index `i - j`; continue using `j = lps[j-1]`.
   - On a mismatch, instead of restarting, shift the pattern using `j = lps[j-1]` (or advance `i` when `j == 0`).
4. If no match was found, print `not found`.

The LPS table guarantees no character of the text is compared more than once, giving linear worst-case behaviour.

## Pseudocode

```
computeLPS(P, m):
    lps[0] = 0
    len = 0, i = 1
    while i < m:
        if P[i] == P[len]:
            len = len + 1
            lps[i] = len
            i = i + 1
        else if len != 0:
            len = lps[len - 1]
        else:
            lps[i] = 0
            i = i + 1
    return lps

main:
    read text T[0..n-1]
    read pattern P[0..m-1]
    lps = computeLPS(P, m)
    i = 0, j = 0, found = false
    while i < n:
        if P[j] == T[i]:
            i = i + 1
            j = j + 1
        if j == m:
            print "Pattern found at index (i - j)"
            found = true
            j = lps[j - 1]
        else if i < n and P[j] != T[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i = i + 1
    if found == false:
        print "not found"
```

## Complexity Analysis

- **Time Complexity:** `O(n + m)` — `O(m)` for building the LPS table and `O(n)` for scanning the text; each character of the text is processed at most once.
- **Space Complexity:** `O(m)` for the LPS array of the pattern (plus `O(n + m)` for storing the input strings).

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
