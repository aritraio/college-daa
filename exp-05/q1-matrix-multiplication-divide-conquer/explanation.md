# Experiment 5.q1 — Matrix Multiplication using Divide and Conquer

## Problem Statement

Given two `n x n` matrices `A` and `B`, compute their product matrix `C = A x B` using the divide and conquer technique. The dimension `n` is assumed to be a power of 2 (`1, 2, 4, 8, ...`), which allows the matrices to be repeatedly split into equal-sized quadrants until they become `1 x 1` blocks.

## Algorithm & Approach

1. Read `n`, then the `n*n` elements of matrix `A` in row-major order, then the `n*n` elements of matrix `B` in row-major order.
2. Apply divide and conquer:
   - **Base case:** If `n == 1`, the product is `C[0][0] = A[0][0] * B[0][0]`.
   - **Divide:** Partition both `A` and `B` into four quadrants of size `(n/2) x (n/2)`:
     `A11, A12, A21, A22` and `B11, B12, B21, B22`.
   - **Conquer:** Recursively compute the 8 sub-products:
     `M1 = A11*B11`, `M2 = A12*B21`, `M3 = A11*B12`, `M4 = A12*B22`,
     `M5 = A21*B11`, `M6 = A22*B21`, `M7 = A21*B12`, `M8 = A22*B22`.
   - **Combine:** Assemble the result quadrants by matrix addition:
     `C11 = M1 + M2`, `C12 = M3 + M4`, `C21 = M5 + M6`, `C22 = M7 + M8`.
3. Print the product matrix `C` row by row.

This is the classic divide-and-conquer matrix multiplication (8 recursive multiplications of size `n/2` plus `O(n^2)` additions). It is correct but slower than Strassen's algorithm, which reduces the number of recursive multiplications to 7.

## Pseudocode

```
MATRIX-MULTIPLY-DC(A, B, n):
    if n == 1:
        return [[A[0][0] * B[0][0]]]
    s = n / 2
    Partition A into A11, A12, A21, A22 (each s x s)
    Partition B into B11, B12, B21, B22 (each s x s)

    M1 = MATRIX-MULTIPLY-DC(A11, B11, s)
    M2 = MATRIX-MULTIPLY-DC(A12, B21, s)
    M3 = MATRIX-MULTIPLY-DC(A11, B12, s)
    M4 = MATRIX-MULTIPLY-DC(A12, B22, s)
    M5 = MATRIX-MULTIPLY-DC(A21, B11, s)
    M6 = MATRIX-MULTIPLY-DC(A22, B21, s)
    M7 = MATRIX-MULTIPLY-DC(A21, B12, s)
    M8 = MATRIX-MULTIPLY-DC(A22, B22, s)

    C11 = M1 + M2
    C12 = M3 + M4
    C21 = M5 + M6
    C22 = M7 + M8

    Place C11, C12, C21, C22 into C (n x n)
    return C

main:
    read n
    read A (n*n elements, row-major)
    read B (n*n elements, row-major)
    C = MATRIX-MULTIPLY-DC(A, B, n)
    print C row by row
```

## Complexity Analysis

- **Time Complexity:** `O(n^3)`. The recurrence is `T(n) = 8T(n/2) + O(n^2)` (8 recursive multiplications of size `n/2` and `O(n^2)` work for splitting and adding). By the Master Theorem, `a = 8, b = 2, log₂a = 3 > 2`, so `T(n) = O(n^3)` — the same asymptotic cost as the naive triple-loop method.
- **Space Complexity:** `O(n^2)` for storing the input matrices, result, and the quadrants and sub-products allocated at each level (a constant number of `n²`-sized structures overall), plus `O(log n)` recursion stack depth.

## Sample Input & Output

**Input:**

```
2
1 2
3 4
5 6
7 8
```

**Output:**

```
19 22
43 50
```
