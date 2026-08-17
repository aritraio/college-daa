#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int deg[MAX];
int visited[MAX];
int first = 1;

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

void dfs(int u)
{
    if (!first)
        printf(" ");
    first = 0;
    printf("%d", u);
    visited[u] = 1;
    for (int i = 0; i < deg[u]; i++)
    {
        int v = adj[u][i];
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, m, s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);
    printf("\n");
    return 0;
}