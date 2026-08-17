import java.util.*;

public class Solution {

    static int[] parent;

    static int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    static void unionSet(int a, int b) {
        parent[a] = b;
    }

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

        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < m; i++)
            edges.add(new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt()));

        edges.sort(Comparator.comparingInt(e -> e.w));

        parent = new int[n + 1];
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        System.out.println("Edges in MST:");
        int total = 0, count = 0;
        for (Edge e : edges) {
            if (count == n - 1) break;
            int ru = find(e.u);
            int rv = find(e.v);
            if (ru != rv) {
                unionSet(ru, rv);
                System.out.println(e.u + " - " + e.v + " (" + e.w + ")");
                total += e.w;
                count++;
            }
        }

        System.out.println("Total weight of MST: " + total);
        sc.close();
    }
}
