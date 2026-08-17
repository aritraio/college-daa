import java.util.Scanner;

public class Solution {

    static int minKey(int[] key, boolean[] mstSet, int n) {
        int min = Integer.MAX_VALUE, minIndex = -1;
        for (int v = 0; v < n; v++)
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        return minIndex;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] graph = new int[n][n];

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            graph[u - 1][v - 1] = w;
            graph[v - 1][u - 1] = w;
        }

        int[] parent = new int[n];
        int[] key = new int[n];
        boolean[] mstSet = new boolean[n];

        for (int i = 0; i < n; i++) {
            key[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }

        key[0] = 0;

        int totalWeight = 0;
        for (int count = 0; count < n; count++) {
            int u = minKey(key, mstSet, n);
            mstSet[u] = true;
            totalWeight += key[u];

            for (int v = 0; v < n; v++)
                if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
        }

        for (int v = 1; v < n; v++)
            System.out.println("Edge " + (parent[v] + 1) + "-" + (v + 1)
                    + " weight " + key[v]);
        System.out.println("Total weight of MST: " + totalWeight);
    }
}
