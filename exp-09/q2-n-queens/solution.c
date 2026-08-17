#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n, count = 0;
int board[MAX];

int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                printf(" ");
            printf("%d", board[i] + 1);
        }
        printf("\n");
        count++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    solve(0);
    printf("Total solutions: %d\n", count);
    return 0;
}
