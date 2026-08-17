import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        final int INF = 999999;
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = sc.nextInt();

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0)
                    System.out.print(" ");
                if (dist[i][j] == INF)
                    System.out.print("INF");
                else
                    System.out.print(dist[i][j]);
            }
            System.out.println();
        }
    }
}
