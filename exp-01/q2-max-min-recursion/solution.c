#include <stdio.h>
#include <limits.h>

void findMinMax(int arr[], int n, int *min, int *max)
{
    if (n == 1)
    {
        *min = *max = arr[0];
        return;
    }
    findMinMax(arr, n - 1, min, max);
    if (arr[n - 1] < *min)
        *min = arr[n - 1];
    if (arr[n - 1] > *max)
        *max = arr[n - 1];
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int min = INT_MAX, max = INT_MIN;
    findMinMax(arr, n, &min, &max);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    return 0;
}