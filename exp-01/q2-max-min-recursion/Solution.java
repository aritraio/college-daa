import java.util.Scanner;

public class Solution {
    static void findMinMax(int[] arr, int n, int[] result) {
        if (n == 1) {
            result[0] = result[1] = arr[0];
            return;
        }
        findMinMax(arr, n - 1, result);
        if (arr[n - 1] < result[0])
            result[0] = arr[n - 1];
        if (arr[n - 1] > result[1])
            result[1] = arr[n - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        int[] result = new int[2];
        result[0] = Integer.MAX_VALUE;
        result[1] = Integer.MIN_VALUE;
        findMinMax(arr, n, result);
        System.out.println("Min: " + result[0]);
        System.out.println("Max: " + result[1]);
        sc.close();
    }
}