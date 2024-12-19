#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

// Type Aliases
using ll = long long;
using pii = pair<int, int>;

// Macros
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

// Fast I/O
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    FAST_IO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

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
    vector<int> prev(n + 1, INF);
    queue<int> q;
    q.push(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            break;
        }
        for (auto &v : adj[node])
        {
            if (!visited[v])
            {
                visited[v] = true;
                prev[v] = node;
                q.push(v);
            }
        }
    }
    vector<int> route;
    int i = n;
    while (prev[i] != INF)
    {
        route.push_back(i);
        i = prev[i];
    }
    if (route.empty())
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        route.push_back(1);
        reverse(all(route));
        cout << route.size() << endl;
        for (auto &r : route)
        {
            cout << r << " ";
        }
    }
    return 0;
}
