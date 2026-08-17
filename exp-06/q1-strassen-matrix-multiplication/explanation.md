# Experiment 6.q1 — Strassen's Matrix Multiplication Algorithm

## Problem Statement

Write a program to multiply two `n x n` matrices `A` and `B` using Strassen's matrix multiplication algorithm. The program reads `n`, followed by the `n*n` elements of matrix `A` (row by row) and the `n*n` elements of matrix `B` (row by row), and prints the resulting product matrix `C = A * B` row by row. The algorithm assumes `n` is a **power of 2** (i.e., `1, 2, 4, 8, ...`); matrices of other sizes are padded to the next power of 2 before applying the algorithm.

## Algorithm & Approach

Strassen's algorithm is a divide and conquer method that multiplies two `n x n` matrices using only **7 recursive multiplications** instead of the 8 used by the classical divide and conquer approach.

1. If `n == 1`, the product is the single scalar product `C[0][0] = A[0][0] * B[0][0]`.
2. Otherwise, split `A` and `B` each into four sub-matrices of size `n/2 x n/2`:
   ```
   A = | A11  A12 |        B = | B11  B12 |
       | A21  A22 |            | B21  B22 |
   ```
3. Compute the **7 products** using only additions and subtractions (18 additions/subtractions) instead of 8 multiplications:
   - **P1 = A11 * (B12 − B22)**
   - **P2 = (A11 + A12) * B22**
   - **P3 = (A21 + A22) * B11**
   - **P4 = A22 * (B21 − B11)**
   - **P5 = (A11 + A22) * (B11 + B22)**
   - **P6 = (A12 − A22) * (B21 + B22)**
   - **P7 = (A11 − A21) * (B11 + B12)**
4. Recombine the products to form the four quadrants of `C`:
   - **C11 = P5 + P4 − P2 + P6**
   - **C12 = P1 + P2**
   - **C21 = P3 + P4**
   - **C22 = P5 + P1 − P3 − P7**
5. Assemble `C11, C12, C21, C22` into the final `n x n` result matrix and print it row by row.

Each of the 7 products is itself computed by a recursive call to Strassen's algorithm.

## Pseudocode

```
STRASSEN(A, B, n):
    if n == 1:
        return A[0][0] * B[0][0]
    h = n / 2
    split A into A11, A12, A21, A22   (size h x h)
    split B into B11, B12, B21, B22   (size h x h)

    P1 = STRASSEN(A11, B12 - B22, h)
    P2 = STRASSEN(A11 + A12, B22, h)
    P3 = STRASSEN(A21 + A22, B11, h)
    P4 = STRASSEN(A22, B21 - B11, h)
    P5 = STRASSEN(A11 + A22, B11 + B22, h)
    P6 = STRASSEN(A12 - A22, B21 + B22, h)
    P7 = STRASSEN(A11 - A21, B11 + B12, h)

    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7
    return C assembled from C11, C12, C21, C22

main:
    read n
    read A[0..n-1][0..n-1]
    read B[0..n-1][0..n-1]
    C = STRASSEN(A, B, n)
    print C row by row
```

## Complexity Analysis

- **Time Complexity:** `O(n^log2 7) ≈ O(n^2.81)`. Each level of recursion performs 7 multiplications of `n/2 x n/2` matrices plus `O(n^2)` additions/subtractions, giving the recurrence `T(n) = 7T(n/2) + O(n^2)`, which solves to `T(n) = O(n^log2 7) ≈ O(n^2.81)`. This is asymptotically faster than the classical `O(n^3)` multiplication.
- **Space Complexity:** `O(n^2)` — at each recursion level we store the sub-matrices, temporary matrices and the 7 products, and the recursion depth is `O(log n)`; the dominant term is the `O(n^2)` storage for the matrices themselves.

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