import java.util.Scanner;

public class Solution {

    static int[][] subMatrix(int[][] M, int r0, int c0, int size) {
        int[][] S = new int[size][size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                S[i][j] = M[r0 + i][c0 + j];
        return S;
    }

    static void putQuad(int[][] S, int[][] M, int r0, int c0) {
        int size = S.length;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                M[r0 + i][c0 + j] = S[i][j];
    }

    static int[][] addMat(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }

    static int[][] matMul(int[][] A, int[][] B, int n) {
        if (n == 1) {
            int[][] C = new int[1][1];
            C[0][0] = A[0][0] * B[0][0];
            return C;
        }
        int s = n / 2;
        int[][] A11 = subMatrix(A, 0, 0, s);
        int[][] A12 = subMatrix(A, 0, s, s);
        int[][] A21 = subMatrix(A, s, 0, s);
        int[][] A22 = subMatrix(A, s, s, s);
        int[][] B11 = subMatrix(B, 0, 0, s);
        int[][] B12 = subMatrix(B, 0, s, s);
        int[][] B21 = subMatrix(B, s, 0, s);
        int[][] B22 = subMatrix(B, s, s, s);

        int[][] M1 = matMul(A11, B11, s);
        int[][] M2 = matMul(A12, B21, s);
        int[][] M3 = matMul(A11, B12, s);
        int[][] M4 = matMul(A12, B22, s);
        int[][] M5 = matMul(A21, B11, s);
        int[][] M6 = matMul(A22, B21, s);
        int[][] M7 = matMul(A21, B12, s);
        int[][] M8 = matMul(A22, B22, s);

        int[][] C11 = addMat(M1, M2);
        int[][] C12 = addMat(M3, M4);
        int[][] C21 = addMat(M5, M6);
        int[][] C22 = addMat(M7, M8);

        int[][] C = new int[n][n];
        putQuad(C11, C, 0, 0);
        putQuad(C12, C, 0, s);
        putQuad(C21, C, s, 0);
        putQuad(C22, C, s, s);
        return C;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] A = new int[n][n];
        int[][] B = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = sc.nextInt();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = sc.nextInt();
        int[][] C = matMul(A, B, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0)
                    System.out.print(" ");
                System.out.print(C[i][j]);
            }
            System.out.println();
        }
    }
}
