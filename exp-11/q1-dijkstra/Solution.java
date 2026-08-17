import java.util.Scanner;

public class Solution {
    static final int MAX = 100;
    static final int INF = 1000000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] adj = new int[MAX][MAX];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = INF;

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            adj[u][v] = w;
        }
        int s = sc.nextInt();

        int[] dist = new int[MAX];
        boolean[] visited = new boolean[MAX];
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[s] = 0;

        for (int count = 0; count < n; count++) {
            int u = -1, min = INF;
            for (int i = 1; i <= n; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }
            if (u == -1)
                break;
            visited[u] = true;
            for (int v = 1; v <= n; v++) {
                if (!visited[v] && adj[u][v] < INF &&
                    dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        for (int i = 1; i <= n; i++)
            System.out.println("Distance from " + s + " to " + i + ": " + dist[i]);
        sc.close();
    }
}
