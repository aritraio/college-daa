#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int s[MAX][MAX];

void printOrder(int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);
    cout << ")";
}

int main()
{
    int n, p[MAX], m[MAX][MAX];
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> p[i];

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

    cout << "Minimum cost: " << m[1][n] << endl;
    cout << "Optimal parenthesization: ";
    printOrder(1, n);
    cout << endl;
    return 0;
}
