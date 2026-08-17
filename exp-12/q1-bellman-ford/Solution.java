import java.util.Scanner;

public class Solution {

    static class Edge {
        int u, v, w;

        Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        Edge[] edges = new Edge[m];
        for (int i = 0; i < m; i++)
            edges[i] = new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt());
        int s = sc.nextInt();

        final int INF = 999999;
        int[] dist = new int[n + 1];
        for (int i = 1; i <= n; i++)
            dist[i] = INF;
        dist[s] = 0;

        for (int i = 1; i <= n - 1; i++) {
            boolean changed = false;
            for (Edge e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    changed = true;
                }
            }
            if (!changed)
                break;
        }

        for (Edge e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                System.out.println("Negative cycle detected");
                return;
            }
        }

        System.out.println("Shortest distances from source " + s + ":");
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF)
                System.out.println(i + ": INF");
            else
                System.out.println(i + ": " + dist[i]);
        }
    }
}
