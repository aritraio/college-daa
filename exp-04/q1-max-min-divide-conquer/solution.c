#include <stdio.h>

// Divide and conquer: find min and max in a[lo..hi]
void findMinMax(int a[], int lo, int hi, int *min, int *max)
{
    if (lo == hi)
    {
        *min = *max = a[lo];
        return;
    }
    if (hi == lo + 1)
    {
        if (a[lo] < a[hi])
        {
            *min = a[lo];
            *max = a[hi];
        }
        else
        {
            *min = a[hi];
            *max = a[lo];
        }
        return;
    }
    int mid = (lo + hi) / 2;
    int minL, maxL, minR, maxR;
    findMinMax(a, lo, mid, &minL, &maxL);
    findMinMax(a, mid + 1, hi, &minR, &maxR);
    *min = minL < minR ? minL : minR;
    *max = maxL > maxR ? maxL : maxR;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int min, max;
    findMinMax(a, 0, n - 1, &min, &max);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    return 0;
}