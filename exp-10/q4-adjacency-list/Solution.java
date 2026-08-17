import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        for (int i = 1; i <= n; i++)
            Collections.sort(adj.get(i));
        for (int i = 1; i <= n; i++) {
            System.out.print(i + ": ");
            for (int j = 0; j < adj.get(i).size(); j++) {
                if (j > 0)
                    System.out.print(" ");
                System.out.print(adj.get(i).get(j));
            }
            System.out.println();
        }
        sc.close();
    }
}