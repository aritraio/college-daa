#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
bool first = true;

void dfs(int u)
{
    if (!first)
        cout << " ";
    first = false;
    cout << u;
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m;
    adj.assign(n + 1, {});
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

    visited.assign(n + 1, 0);
    cout << "DFS Traversal: ";
    dfs(s);
    cout << endl;
    return 0;
}