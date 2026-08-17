#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix subMatrix(const Matrix &M, int r0, int c0, int size)
{
    Matrix S(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            S[i][j] = M[r0 + i][c0 + j];
    return S;
}

void putQuad(const Matrix &S, Matrix &M, int r0, int c0)
{
    int size = S.size();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            M[r0 + i][c0 + j] = S[i][j];
}

Matrix addMat(const Matrix &A, const Matrix &B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix matMul(const Matrix &A, const Matrix &B, int n)
{
    if (n == 1)
    {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int s = n / 2;
    Matrix A11 = subMatrix(A, 0, 0, s);
    Matrix A12 = subMatrix(A, 0, s, s);
    Matrix A21 = subMatrix(A, s, 0, s);
    Matrix A22 = subMatrix(A, s, s, s);
    Matrix B11 = subMatrix(B, 0, 0, s);
    Matrix B12 = subMatrix(B, 0, s, s);
    Matrix B21 = subMatrix(B, s, 0, s);
    Matrix B22 = subMatrix(B, s, s, s);

    Matrix M1 = matMul(A11, B11, s);
    Matrix M2 = matMul(A12, B21, s);
    Matrix M3 = matMul(A11, B12, s);
    Matrix M4 = matMul(A12, B22, s);
    Matrix M5 = matMul(A21, B11, s);
    Matrix M6 = matMul(A22, B21, s);
    Matrix M7 = matMul(A21, B12, s);
    Matrix M8 = matMul(A22, B22, s);

    Matrix C11 = addMat(M1, M2);
    Matrix C12 = addMat(M3, M4);
    Matrix C21 = addMat(M5, M6);
    Matrix C22 = addMat(M7, M8);

    Matrix C(n, vector<int>(n));
    putQuad(C11, C, 0, 0);
    putQuad(C12, C, 0, s);
    putQuad(C21, C, s, 0);
    putQuad(C22, C, s, s);
    return C;
}

int main()
{
    int n;
    cin >> n;
    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    Matrix C = matMul(A, B, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                cout << " ";
            cout << C[i][j];
        }
        cout << "\n";
    }
    return 0;
}
