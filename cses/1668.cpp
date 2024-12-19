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
    int componentCount;

public:
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

    int n, m;
    cin >> n >> m;

    vector<pii> friends(m, pii());
    for (int i = 0; i < m; i++)
    {
        cin >> friends[i].F >> friends[i].S;
    }

    UnionFind dsu(n);
    for (auto &f : friends)
    {
        dsu.Union(f.F, f.S);
    }

    int a = friends[0].F, b = friends[0].S;

    bool impossible = false;
    vector<char> team(n + 1, '_');
    for (int i = 1; i <= n; i++)
    {
        if (i == a || i == b)
            continue;
        if (dsu.Find(i) != dsu.Find(a))
        {
            team[i] = '1';
        }
        else if (dsu.Find(i) != dsu.Find(b))
        {
            team[i] = '2';
        }
        else
        {
            impossible = true;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << team[i] << " ";
    }

    if (impossible)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << team[i] << " ";
        }
    }
    return 0;
}
