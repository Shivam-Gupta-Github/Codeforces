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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    int ai, aj, bi, bj;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (grid[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({ai, aj});
    grid[ai][aj] = '#';

    vector<vector<char>> dir(m, vector<char>(n, ' '));

    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        // cout << i << " " << j << " " << path << endl;
        q.pop();
        if (i == bi && j == bj)
        {
            break;
        }

        if (i > 0 && grid[i - 1][j] != '#')
        {
            // parent[{i - 1, j}] = {i, j};
            dir[i - 1][j] = 'U';
            grid[i - 1][j] = '#';
            q.push({i - 1, j});
        }
        if (i < m - 1 && grid[i + 1][j] != '#')
        {
            // parent[{i + 1, j}] = {i, j};
            dir[i + 1][j] = 'D';
            grid[i + 1][j] = '#';
            q.push({i + 1, j});
        }
        if (j > 0 && grid[i][j - 1] != '#')
        {
            // parent[{i, j - 1}] = {i, j};
            dir[i][j - 1] = 'L';
            grid[i][j - 1] = '#';
            q.push({i, j - 1});
        }
        if (j < n - 1 && grid[i][j + 1] != '#')
        {
            // parent[{i, j + 1}] = {i, j};
            dir[i][j + 1] = 'R';
            grid[i][j + 1] = '#';
            q.push({i, j + 1});
        }
    }

    // for (auto &v : dir)
    // {
    //     for (auto &i : v)
    //     {
    //         if (i == ' ')
    //             i = '#';
    //         cout << i << ' ';
    //     }
    //     cout << endl;
    // }
    int i = bi, j = bj;
    string path = "";
    while (dir[i][j] != ' ')
    {
        path.push_back(dir[i][j]);
        if (dir[i][j] == 'U')
        {
            i++;
        }
        else if (dir[i][j] == 'D')
        {
            i--;
        }
        else if (dir[i][j] == 'R')
        {
            j--;
        }
        else
        {
            j++;
        }
    }

    if (path.empty())
    {
        cout << "NO";
    }
    else
    {
        reverse(path.begin(), path.end());
        cout << "YES" << endl
             << path.size() << endl
             << path;
    }

    return 0;
}