#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < (int)adj[i].size(); j++)
        {
            if (j > 0)
                cout << " ";
            cout << adj[i][j];
        }
        cout << endl;
    }
    return 0;
}