#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

// Solver Function
void solve() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int dp[x + 1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int& coin: coins) {
            if (i - coin >= 0) {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
    }
    cout << dp[x];
}

int main()
{
    // int t;
    // cin >> t; // for multi-test case problems.
    // while (t--)
    // {
    //     solve();
    //     cout << endl;
    // }
    solve();
    return 0;
}
