import java.util.Scanner;

public class Solution {
    private static final int MAX = 100;
    private static int n;
    private static int count = 0;
    private static int[] board = new int[MAX];

    static boolean isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || Math.abs(board[i] - col) == Math.abs(i - row))
                return false;
        }
        return true;
    }

    static void solve(int row) {
        if (row == n) {
            for (int i = 0; i < n; i++) {
                if (i > 0)
                    System.out.print(" ");
                System.out.print(board[i] + 1);
            }
            System.out.println();
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row] = col;
                solve(row + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        solve(0);
        System.out.println("Total solutions: " + count);
        sc.close();
    }
}
