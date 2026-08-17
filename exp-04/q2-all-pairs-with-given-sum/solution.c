#include <stdio.h>

int main()
{
    int n, s;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &s);
    int found = 0;
    // Brute force: try every pair (i, j) with i < j
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == s)
            {
                printf("(%d, %d)\n", i, j);
                found = 1;
            }
        }
    }
    if (!found)
        printf("No pairs found\n");
    return 0;
}