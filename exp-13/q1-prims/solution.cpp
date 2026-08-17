#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet, int n)
{
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    key[0] = 0;

    int totalWeight = 0;
    for (int count = 0; count < n; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    for (int v = 1; v < n; v++)
        cout << "Edge " << parent[v] + 1 << "-" << v + 1
             << " weight " << key[v] << "\n";
    cout << "Total weight of MST: " << totalWeight << "\n";

    return 0;
}
