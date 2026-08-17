import java.util.Scanner;

public class Solution {
    private static final int MAX = 100;
    private static int[][] s = new int[MAX][MAX];

    static void printOrder(int i, int j) {
        if (i == j) {
            System.out.print("A" + i);
            return;
        }
        System.out.print("(");
        printOrder(i, s[i][j]);
        printOrder(s[i][j] + 1, j);
        System.out.print(")");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] p = new int[MAX];
        int[][] m = new int[MAX][MAX];

        for (int i = 0; i <= n; i++)
            p[i] = sc.nextInt();

        for (int i = 1; i <= n; i++)
            m[i][i] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (cost < m[i][j]) {
                        m[i][j] = cost;
                        s[i][j] = k;
                    }
                }
            }
        }

        System.out.println("Minimum cost: " + m[1][n]);
        System.out.print("Optimal parenthesization: ");
        printOrder(1, n);
        System.out.println();
        sc.close();
    }
}
