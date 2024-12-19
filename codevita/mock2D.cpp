#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n)), dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cin >> k;
    bool noAnswer = true;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && grid[i][j] >= grid[i - 1][j])
            {
                dp[i][j] += dp[i - 1][j] + 1;
            }
            if (j > 0 && grid[i][j] >= grid[i][j - 1])
            {
                dp[i][j] += dp[i][j - 1] + 1;
            }
            if (dp[i][j] == k)
            {
                noAnswer = false;
                cnt++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == k)
            {
                cout << i << ' ' << j;
                if (cnt-- > 1)
                {
                    cout << endl;
                }
            }
        }
    }
    if (noAnswer)
    {
        cout << "NO";
    }
    return 0;
}
