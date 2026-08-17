#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux, int *count)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        (*count)++;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to, count);
    printf("Move disk %d from %c to %c\n", n, from, to);
    (*count)++;
    towerOfHanoi(n - 1, aux, to, from, count);
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B', &count);
    printf("Total moves: %d\n", count);
    return 0;
}