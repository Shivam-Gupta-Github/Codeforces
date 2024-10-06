#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

int n;
vector<vector<int>> f1Tbl;
int f1(int i, int x, vector<int> &coins)
{
    if (x == 0)
    {
        return 1;
    }
    if (i == n)
    {
        return 0;
    }
    if (f1Tbl[i][x] != -1)
        return f1Tbl[i][x];
    int take = 0, notTake = 0;
    notTake = f1(i + 1, x, coins);
    if (coins[i] <= x)
        take = f1(i, x - coins[i], coins);
    return f1Tbl[i][x] = (take + notTake) % MOD;
}

int change(int amount, vector<int> &coins)
{
    n = coins.size();
    f1Tbl.resize(n + 1, vector<int>(amount + 1, -1));
    return f1(0, amount, coins);
}

// Solver Function
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << change(x, coins);
}

int main()
{
    solve();
    return 0;
}
