import java.util.Scanner;

public class Solution {

    static int[][] alloc(int n) {
        return new int[n][n];
    }

    static void add(int n, int[][] A, int[][] B, int[][] C) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
    }

    static void sub(int n, int[][] A, int[][] B, int[][] C) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
    }

    // C = A * B using Strassen's algorithm (n must be a power of 2)
    static void strassen(int n, int[][] A, int[][] B, int[][] C) {
        if (n == 1) {
            C[0][0] = A[0][0] * B[0][0];
            return;
        }
        int h = n / 2;
        int[][] A11 = alloc(h), A12 = alloc(h), A21 = alloc(h), A22 = alloc(h);
        int[][] B11 = alloc(h), B12 = alloc(h), B21 = alloc(h), B22 = alloc(h);
        int[][] P1 = alloc(h), P2 = alloc(h), P3 = alloc(h), P4 = alloc(h);
        int[][] P5 = alloc(h), P6 = alloc(h), P7 = alloc(h);
        int[][] t1 = alloc(h), t2 = alloc(h);

        for (int i = 0; i < h; i++)
            for (int j = 0; j < h; j++) {
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
            for (int j = 0; j < h; j++) {
                C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
                C[i][j + h] = P1[i][j] + P2[i][j];
                C[i + h][j] = P3[i][j] + P4[i][j];
                C[i + h][j + h] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
            }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] A = alloc(n), B = alloc(n), C = alloc(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = sc.nextInt();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = sc.nextInt();
        strassen(n, A, B, C);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(C[i][j] + " ");
            System.out.println();
        }
        sc.close();
    }
}