#include <stdio.h>

int main() {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0)
    return 0;

  int A[2][2], B[2][2], C[2][2];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &A[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &B[i][j]);

  int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
  int m2 = (A[1][0] + A[1][1]) * B[0][0];
  int m3 = A[0][0] * (B[0][1] - B[1][1]);
  int m4 = A[1][1] * (B[1][0] - B[0][0]);
  int m5 = (A[0][0] + A[0][1]) * B[1][1];
  int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
  int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

  C[0][0] = m1 + m4 - m5 + m7;
  C[0][1] = m3 + m5;
  C[1][0] = m2 + m4;
  C[1][1] = m1 - m2 + m3 + m6;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d%c", C[i][j], (j == n - 1) ? '\n' : ' ');
    }
  }

  return 0;
}
