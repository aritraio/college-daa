#include <stdio.h>

#define MAXN 100
#define INF 999999

typedef struct
{
    int u, v, w;
} Edge;

int main()
{
    int n, m, s;
    Edge edges[MAXN * MAXN];
    int dist[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    scanf("%d", &s);

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        int changed = 0;
        for (int j = 0; j < m; j++)
        {
            if (dist[edges[j].u] != INF &&
                dist[edges[j].u] + edges[j].w < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
                changed = 1;
            }
        }
        if (!changed)
            break;
    }

    for (int j = 0; j < m; j++)
    {
        if (dist[edges[j].u] != INF &&
            dist[edges[j].u] + edges[j].w < dist[edges[j].v])
        {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", s);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }
    return 0;
}
