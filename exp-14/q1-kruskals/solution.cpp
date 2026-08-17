#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, w;
};

vector<int> parent;

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    cout << "Edges in MST:" << endl;
    int total = 0, count = 0;
    for (int i = 0; i < m && count < n - 1; i++)
    {
        int ru = find(edges[i].u);
        int rv = find(edges[i].v);
        if (ru != rv)
        {
            unionSet(ru, rv);
            cout << edges[i].u << " - " << edges[i].v << " (" << edges[i].w << ")" << endl;
            total += edges[i].w;
            count++;
        }
    }

    cout << "Total weight of MST: " << total << endl;
    return 0;
}
