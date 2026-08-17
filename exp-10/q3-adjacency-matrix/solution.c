#include <stdio.h>

#define MAX 100

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int mat[MAX][MAX] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j > 1)
                printf(" ");
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}