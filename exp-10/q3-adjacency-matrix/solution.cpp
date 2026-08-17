#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j > 1)
                cout << " ";
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}