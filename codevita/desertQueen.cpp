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
    // FAST_IO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n, s = 0, e = 0, inf = 1e5;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                s = i * n + j;
            }
            else if (grid[i][j] == 'E')
            {
                e = i * n + j;
            }
        }
    }

    vector<vector<pair<int, int>>> adj(n * n);
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int current_index = i * n + j;
            for (auto d : directions)
            {
                int di = d.F, dj = d.S;
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n)
                {
                    int neighbor_index = ni * n + nj, wt = 1;
                    if (grid[i][j] == 'T' && grid[ni][nj] == 'T')
                    {
                        wt = 0;
                    }
                    else if (grid[ni][nj] == 'M')
                    {
                        wt = inf;
                    }
                    adj[current_index].push_back(
                        {neighbor_index, wt});
                }
            }
        }
    }

    vector<int> dist(n * n, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto cur = pq.top();

        int current_dist = cur.F, current_node = cur.S;
        pq.pop();

        if (current_dist > dist[current_node])
            continue;

        for (auto v : adj[current_node])
        {
            int neighbor = v.F, weight = v.S;
            int new_dist = current_dist + weight;
            if (new_dist < dist[neighbor])
            {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }
    cout << dist[e];
    return 0;
}
