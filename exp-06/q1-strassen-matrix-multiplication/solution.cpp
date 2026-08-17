#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Mat;

Mat alloc(int n)
{
    return Mat(n, vector<int>(n, 0));
}

// C = A + B
void add(int n, const Mat &A, const Mat &B, Mat &C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// C = A - B
void sub(int n, const Mat &A, const Mat &B, Mat &C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// C = A * B using Strassen's algorithm (n must be a power of 2)
void strassen(int n, const Mat &A, const Mat &B, Mat &C)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int h = n / 2;
    Mat A11 = alloc(h), A12 = alloc(h), A21 = alloc(h), A22 = alloc(h);
    Mat B11 = alloc(h), B12 = alloc(h), B21 = alloc(h), B22 = alloc(h);
    Mat P1 = alloc(h), P2 = alloc(h), P3 = alloc(h), P4 = alloc(h);
    Mat P5 = alloc(h), P6 = alloc(h), P7 = alloc(h);
    Mat t1 = alloc(h), t2 = alloc(h);

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

    sub(h, B12, B22, t2);
    strassen(h, A11, t2, P1);        // P1 = A11 * (B12 - B22)
    add(h, A11, A12, t1);
    strassen(h, t1, B22, P2);        // P2 = (A11 + A12) * B22
    add(h, A21, A22, t1);
    strassen(h, t1, B11, P3);        // P3 = (A21 + A22) * B11
    sub(h, B21, B11, t2);
    strassen(h, A22, t2, P4);        // P4 = A22 * (B21 - B11)
    add(h, A11, A22, t1);
    add(h, B11, B22, t2);
    strassen(h, t1, t2, P5);         // P5 = (A11 + A22) * (B11 + B22)
    sub(h, A12, A22, t1);
    add(h, B21, B22, t2);
    strassen(h, t1, t2, P6);         // P6 = (A12 - A22) * (B21 + B22)
    sub(h, A11, A21, t1);
    add(h, B11, B12, t2);
    strassen(h, t1, t2, P7);         // P7 = (A11 - A21) * (B11 + B12)

    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++)
        {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + h] = P1[i][j] + P2[i][j];
            C[i + h][j] = P3[i][j] + P4[i][j];
            C[i + h][j + h] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
}

int main()
{
    int n;
    cin >> n;
    Mat A = alloc(n), B = alloc(n), C = alloc(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    strassen(n, A, B, C);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
    return 0;
}