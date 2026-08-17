#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 100

int n, solutions = 0;
int board[MAX];

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << " ";
            cout << board[i] + 1;
        }
        cout << endl;
        solutions++;
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
    cin >> n;
    solve(0);
    cout << "Total solutions: " << solutions << endl;
    return 0;
}
