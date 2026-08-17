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

    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");
    int first = 1;
    while (front < rear)
    {
        int u = queue[front++];
        if (!first)
            printf(" ");
        first = 0;
        printf("%d", u);
        for (int i = 0; i < deg[u]; i++)
        {
            int v = adj[u][i];
            if (!visited[v])
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}