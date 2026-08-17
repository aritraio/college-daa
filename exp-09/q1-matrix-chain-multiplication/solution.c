#include <stdio.h>
#include <limits.h>

#define MAX 100

int s[MAX][MAX];

void printOrder(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);
    printf(")");
}

int main()
{
    int n, p[MAX], m[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum cost: %d\n", m[1][n]);
    printf("Optimal parenthesization: ");
    printOrder(1, n);
    printf("\n");
    return 0;
}
