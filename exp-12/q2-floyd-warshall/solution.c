#include <stdio.h>

#define MAXN 100
#define INF 999999

int main()
{
    int n;
    int dist[MAXN][MAXN];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j)
                printf(" ");
            if (dist[i][j] == INF)
                printf("INF");
            else
                printf("%d", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
