import java.util.Scanner;

public class Solution {
    static int fib(int n) {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }

    static long fact(int n) {
        if (n <= 1)
            return 1;
        return n * fact(n - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print("Fibonacci series (" + n + " terms): ");
        for (int i = 0; i < n; i++) {
            if (i > 0)
                System.out.print(" ");
            System.out.print(fib(i));
        }
        System.out.println();
        System.out.println("Factorial of " + n + ": " + fact(n));
        sc.close();
    }
}