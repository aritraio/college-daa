#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    int totalWeight = 0;
    for (int count = 0; count < n; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    for (int v = 1; v < n; v++)
        printf("Edge %d-%d weight %d\n", parent[v] + 1, v + 1, key[v]);
    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}
