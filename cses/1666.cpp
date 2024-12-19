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

class UnionFind
{
    vector<int> parent, size;

public:
    int componentCount;
    UnionFind(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        componentCount = n;
        iota(parent.begin(), parent.end(), 0); // [0,1,...,n]
    }

    int Find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y)
    {
        x = Find(x), y = Find(y);

        if (x == y)
            return false;

        if (size[x] > size[y])
        {
            size[x] += size[y];
            parent[y] = x;
        }
        else
        {
            size[y] += size[x];
            parent[x] = y;
        }
        componentCount--;
        return true;
    }

    bool IsConnected()
    {
        return componentCount == 1;
    }
};

int main()
{
    // FAST_IO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // cout << "Hello World";
    int m, n;
    cin >> n >> m;
    vector<pii> edges(m);

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].F >> edges[i].S;
    }

    UnionFind dsu(n);
    vector<pii> need;

    for (auto &edge : edges)
    {
        dsu.Union(edge.F, edge.S);
    }

    for (int i = 2; i <= n; i++)
    {
        if (dsu.Find(i) != dsu.Find(1))
        {
            need.push_back({1, i});
            dsu.Union(i, 1);
        }
    }

    cout << need.size();
    for (auto &edge : need)
    {
        cout << endl
             << edge.F << " " << edge.S;
    }
    return 0;
}
