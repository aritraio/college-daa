#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int u, v, w;
} Edge;

int parent[MAX];

int find(int x)
{
    while (parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int cmp(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[MAX];
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    qsort(edges, m, sizeof(Edge), cmp);

    printf("Edges in MST:\n");
    int total = 0, count = 0;
    for (int i = 0; i < m && count < n - 1; i++)
    {
        int ru = find(edges[i].u);
        int rv = find(edges[i].v);
        if (ru != rv)
        {
            unionSet(ru, rv);
            printf("%d - %d (%d)\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
        }
    }

    printf("Total weight of MST: %d\n", total);
    return 0;
}
