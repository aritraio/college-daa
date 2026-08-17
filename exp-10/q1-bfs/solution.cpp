#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, s;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    vector<int> visited(n + 1, 0);
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    cout << "BFS Traversal: ";
    bool first = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (!first)
            cout << " ";
        first = false;
        cout << u;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}