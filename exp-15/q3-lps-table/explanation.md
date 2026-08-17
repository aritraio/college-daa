# Experiment 15.q3 — Construct LPS Table for a Given Pattern

## Problem Statement

Construct the LPS (Longest Proper Prefix which is also a Suffix) table for a given pattern. Given a pattern string, print the LPS array values for each position of the pattern, space-separated on a single line prefixed by `LPS:`.

## Algorithm & Approach

1. Read the pattern `P` of length `m`.
2. `lps[0] = 0` always (a proper prefix cannot equal the whole string).
3. Iterate `i` from `1` to `m - 1` while maintaining `len`, the length of the current longest proper prefix-suffix:
   - If `P[i] == P[len]`, extend the match: `len++`, `lps[i] = len`, `i++`.
   - Else if `len != 0`, fall back: `len = lps[len - 1]` (retry with a shorter border).
   - Else `lps[i] = 0` and `i++`.
4. Print the resulting array as `LPS: 0 0 1 ...`.

For example, for pattern `ABABCABAB` the LPS table is `0 0 1 2 0 1 2 3 4` (the prefix `ABAB` of length 4 equals the suffix `ABAB`).

## Pseudocode

```
main:
    read pattern P[0..m-1]
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
    print "LPS:" followed by lps[0..m-1] space separated
```

## Complexity Analysis

- **Time Complexity:** `O(m)` — each `i` advances at most `m` times and the fallback `len = lps[len-1]` also happens at most `m` times overall.
- **Space Complexity:** `O(m)` for the LPS array (plus `O(m)` for storing the pattern string).

## Sample Input & Output

**Input:**

```
ABABCABAB
```

**Output:**

```
LPS: 0 0 1 2 0 1 2 3 4
```
