#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int deg[MAX];

void addEdge(int u, int v)
{
    int i = deg[u];
    while (i > 0 && adj[u][i - 1] > v)
    {
        adj[u][i] = adj[u][i - 1];
        i--;
    }
    adj[u][i] = v;
    deg[u]++;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < deg[i]; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}