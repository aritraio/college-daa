import java.util.Scanner;

public class Solution {
    // Divide and conquer: find min and max in a[lo..hi], result in res[0] (min) and res[1] (max)
    static void findMinMax(int[] a, int lo, int hi, int[] res) {
        if (lo == hi) {
            res[0] = res[1] = a[lo];
            return;
        }
        if (hi == lo + 1) {
            if (a[lo] < a[hi]) {
                res[0] = a[lo];
                res[1] = a[hi];
            } else {
                res[0] = a[hi];
                res[1] = a[lo];
            }
            return;
        }
        int mid = (lo + hi) / 2;
        int[] left = new int[2], right = new int[2];
        findMinMax(a, lo, mid, left);
        findMinMax(a, mid + 1, hi, right);
        res[0] = Math.min(left[0], right[0]);
        res[1] = Math.max(left[1], right[1]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        int[] res = new int[2];
        findMinMax(a, 0, n - 1, res);
        System.out.println("Min: " + res[0]);
        System.out.println("Max: " + res[1]);
        sc.close();
    }
}