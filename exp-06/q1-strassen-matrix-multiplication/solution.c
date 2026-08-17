#include <stdio.h>
#include <stdlib.h>

int **alloc(int n)
{
    int **m = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        m[i] = (int *)calloc(n, sizeof(int));
    return m;
}

void freeMat(int **m, int n)
{
    for (int i = 0; i < n; i++)
        free(m[i]);
    free(m);
}

// C = A + B
void add(int n, int **A, int **B, int **C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// C = A - B
void sub(int n, int **A, int **B, int **C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// C = A * B using Strassen's algorithm (n must be a power of 2)
void strassen(int n, int **A, int **B, int **C)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int h = n / 2;
    int **A11 = alloc(h), **A12 = alloc(h), **A21 = alloc(h), **A22 = alloc(h);
    int **B11 = alloc(h), **B12 = alloc(h), **B21 = alloc(h), **B22 = alloc(h);
    int **P1 = alloc(h), **P2 = alloc(h), **P3 = alloc(h), **P4 = alloc(h);
    int **P5 = alloc(h), **P6 = alloc(h), **P7 = alloc(h);
    int **t1 = alloc(h), **t2 = alloc(h);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + h];
            A21[i][j] = A[i + h][j];
            A22[i][j] = A[i + h][j + h];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + h];
            B21[i][j] = B[i + h][j];
            B22[i][j] = B[i + h][j + h];
        }

    // P1 = A11 * (B12 - B22)
    sub(h, B12, B22, t2);
    strassen(h, A11, t2, P1);
    // P2 = (A11 + A12) * B22
    add(h, A11, A12, t1);
    strassen(h, t1, B22, P2);
    // P3 = (A21 + A22) * B11
    add(h, A21, A22, t1);
    strassen(h, t1, B11, P3);
    // P4 = A22 * (B21 - B11)
    sub(h, B21, B11, t2);
    strassen(h, A22, t2, P4);
    // P5 = (A11 + A22) * (B11 + B22)
    add(h, A11, A22, t1);
    add(h, B11, B22, t2);
    strassen(h, t1, t2, P5);
    // P6 = (A12 - A22) * (B21 + B22)
    sub(h, A12, A22, t1);
    add(h, B21, B22, t2);
    strassen(h, t1, t2, P6);
    // P7 = (A11 - A21) * (B11 + B12)
    sub(h, A11, A21, t1);
    add(h, B11, B12, t2);
    strassen(h, t1, t2, P7);

    // C11 = P5 + P4 - P2 + P6
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++)
        {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + h] = P1[i][j] + P2[i][j];
            C[i + h][j] = P3[i][j] + P4[i][j];
            C[i + h][j + h] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }

    freeMat(A11, h); freeMat(A12, h); freeMat(A21, h); freeMat(A22, h);
    freeMat(B11, h); freeMat(B12, h); freeMat(B21, h); freeMat(B22, h);
    freeMat(P1, h); freeMat(P2, h); freeMat(P3, h); freeMat(P4, h);
    freeMat(P5, h); freeMat(P6, h); freeMat(P7, h);
    freeMat(t1, h); freeMat(t2, h);
}

int main()
{
    int n;
    scanf("%d", &n);
    int **A = alloc(n), **B = alloc(n), **C = alloc(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    strassen(n, A, B, C);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    freeMat(A, n);
    freeMat(B, n);
    freeMat(C, n);
    return 0;
}