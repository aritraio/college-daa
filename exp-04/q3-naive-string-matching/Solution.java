import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        String pattern = sc.nextLine();
        int n = text.length(), m = pattern.length();
        boolean found = false;
        // Naive string matching: slide pattern over text
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && text.charAt(i + j) == pattern.charAt(j))
                j++;
            if (j == m) {
                System.out.println("Pattern found at index " + i);
                found = true;
            }
        }
        if (!found)
            System.out.println("not found");
        sc.close();
    }
}