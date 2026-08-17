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
        int s = sc.nextInt();

        for (int i = 1; i <= n; i++)
            Collections.sort(adj.get(i));

        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        visited[s] = true;
        q.add(s);

        System.out.print("BFS Traversal: ");
        boolean first = true;
        while (!q.isEmpty()) {
            int u = q.poll();
            if (!first)
                System.out.print(" ");
            first = false;
            System.out.print(u);
            for (int v : adj.get(u)) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.add(v);
                }
            }
        }
        System.out.println();
        sc.close();
    }
}