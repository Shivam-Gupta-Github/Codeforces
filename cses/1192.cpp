#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

int n, m;

void dfs(int i, int j, vector<vector<char>> &grid)
{
    grid[i][j] = '#';

    if (i > 0 && grid[i - 1][j] == '.')
    {
        dfs(i - 1, j, grid);
    }
    if (i < m - 1 && grid[i + 1][j] == '.')
    {
        dfs(i + 1, j, grid);
    }
    if (j > 0 && grid[i][j - 1] == '.')
    {
        dfs(i, j - 1, grid);
    }
    if (j < n - 1 && grid[i][j + 1] == '.')
    {
        dfs(i, j + 1, grid);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cnt = 0;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j, grid);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
