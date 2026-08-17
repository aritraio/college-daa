#include <stdio.h>
#include <stdlib.h>

void copyQuad(int *src, int n, int r0, int c0, int size, int *dst)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dst[i * size + j] = src[(r0 + i) * n + (c0 + j)];
}

void placeQuad(int *src, int size, int *dst, int n, int r0, int c0)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dst[(r0 + i) * n + (c0 + j)] = src[i * size + j];
}

void addMat(int *A, int *B, int size, int *C)
{
    for (int i = 0; i < size * size; i++)
        C[i] = A[i] + B[i];
}

void matMul(int *A, int *B, int n, int *C)
{
    if (n == 1)
    {
        C[0] = A[0] * B[0];
        return;
    }
    int s = n / 2;
    int *A11 = malloc(s * s * sizeof(int));
    int *A12 = malloc(s * s * sizeof(int));
    int *A21 = malloc(s * s * sizeof(int));
    int *A22 = malloc(s * s * sizeof(int));
    int *B11 = malloc(s * s * sizeof(int));
    int *B12 = malloc(s * s * sizeof(int));
    int *B21 = malloc(s * s * sizeof(int));
    int *B22 = malloc(s * s * sizeof(int));
    int *C11 = malloc(s * s * sizeof(int));
    int *C12 = malloc(s * s * sizeof(int));
    int *C21 = malloc(s * s * sizeof(int));
    int *C22 = malloc(s * s * sizeof(int));
    int *M1 = malloc(s * s * sizeof(int));
    int *M2 = malloc(s * s * sizeof(int));
    int *M3 = malloc(s * s * sizeof(int));
    int *M4 = malloc(s * s * sizeof(int));
    int *M5 = malloc(s * s * sizeof(int));
    int *M6 = malloc(s * s * sizeof(int));
    int *M7 = malloc(s * s * sizeof(int));
    int *M8 = malloc(s * s * sizeof(int));

    copyQuad(A, n, 0, 0, s, A11);
    copyQuad(A, n, 0, s, s, A12);
    copyQuad(A, n, s, 0, s, A21);
    copyQuad(A, n, s, s, s, A22);
    copyQuad(B, n, 0, 0, s, B11);
    copyQuad(B, n, 0, s, s, B12);
    copyQuad(B, n, s, 0, s, B21);
    copyQuad(B, n, s, s, s, B22);

    matMul(A11, B11, s, M1);
    matMul(A12, B21, s, M2);
    matMul(A11, B12, s, M3);
    matMul(A12, B22, s, M4);
    matMul(A21, B11, s, M5);
    matMul(A22, B21, s, M6);
    matMul(A21, B12, s, M7);
    matMul(A22, B22, s, M8);

    addMat(M1, M2, s, C11);
    addMat(M3, M4, s, C12);
    addMat(M5, M6, s, C21);
    addMat(M7, M8, s, C22);

    placeQuad(C11, s, C, n, 0, 0);
    placeQuad(C12, s, C, n, 0, s);
    placeQuad(C21, s, C, n, s, 0);
    placeQuad(C22, s, C, n, s, s);

    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(C11); free(C12); free(C21); free(C22);
    free(M1); free(M2); free(M3); free(M4);
    free(M5); free(M6); free(M7); free(M8);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *A = malloc(n * n * sizeof(int));
    int *B = malloc(n * n * sizeof(int));
    int *C = malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n * n; i++)
        scanf("%d", &B[i]);
    matMul(A, B, n, C);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", C[i * n + j]);
        }
        printf("\n");
    }
    free(A);
    free(B);
    free(C);
    return 0;
}
