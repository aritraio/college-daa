#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 1000000000;

int main()
{
    int n, m, s;
    cin >> n >> m;

    int adj[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
    cin >> s;

    int dist[MAX], visited[MAX];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[s] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1, min = INF;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && adj[u][v] < INF &&
                dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << "Distance from " << s << " to " << i << ": " << dist[i] << endl;
    return 0;
}
