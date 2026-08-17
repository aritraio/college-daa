#include <iostream>
#include <vector>
using namespace std;

const int INF = 999999;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j)
                cout << " ";
            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];
        }
        cout << "\n";
    }
    return 0;
}
