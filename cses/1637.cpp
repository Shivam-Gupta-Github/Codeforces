#include <bits/stdc++.h>
using namespace std;
 
// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;
 
// Solver Function
void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        int num = i;
        while (num) {
            int digit = num % 10;
            num /= 10;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
        }
    }
    cout << dp[n];
}
 
int main() {
    solve();
    return 0;
}