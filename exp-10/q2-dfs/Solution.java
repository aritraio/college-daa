import java.util.*;

public class Solution {
    static List<List<Integer>> adj;
    static boolean[] visited;
    static boolean first = true;

    static void dfs(int u) {
        if (!first)
            System.out.print(" ");
        first = false;
        System.out.print(u);
        visited[u] = true;
        for (int v : adj.get(u)) {
            if (!visited[v])
                dfs(v);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        adj = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        int s = sc.nextInt();

        for (int i = 1; i <= n; i++)
            Collections.sort(adj.get(i));

        visited = new boolean[n + 1];
        System.out.print("DFS Traversal: ");
        dfs(s);
        System.out.println();
        sc.close();
    }
}