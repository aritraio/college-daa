#include <iostream>
#include <vector>
using namespace std;

const int INF = 999999;

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m, s;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    cin >> s;

    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        bool changed = false;
        for (int j = 0; j < m; j++)
        {
            if (dist[edges[j].u] != INF &&
                dist[edges[j].u] + edges[j].w < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
                changed = true;
            }
        }
        if (!changed)
            break;
    }

    for (int j = 0; j < m; j++)
    {
        if (dist[edges[j].u] != INF &&
            dist[edges[j].u] + edges[j].w < dist[edges[j].v])
        {
            cout << "Negative cycle detected\n";
            return 0;
        }
    }

    cout << "Shortest distances from source " << s << ":\n";
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dist[i] << "\n";
    }
    return 0;
}
