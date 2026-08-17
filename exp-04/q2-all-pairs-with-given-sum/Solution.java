import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        int s = sc.nextInt();
        boolean found = false;
        // Brute force: try every pair (i, j) with i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] == s) {
                    System.out.println("(" + i + ", " + j + ")");
                    found = true;
                }
            }
        }
        if (!found)
            System.out.println("No pairs found");
        sc.close();
    }
}