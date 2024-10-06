#include <bits/stdc++.h>
using namespace std;

// Constants
const int MOD = 1e9 + 7;
const long long LINF = 1e18 + 7;

// Solver Function
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n));
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if (i + 1 < n) {
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
                } 
                if (j + 1 < n) {
                    dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
                }
            }
        }
    }
    cout << dp[0][0];
}

int main() {
    solve();
}
