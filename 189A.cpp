#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Macros
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)(x).size()

// Solver Function
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[n + 1] = {INF};
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int result = -INF;
        if (i - a >= 0)
            result = max(result, dp[i - a] + 1);
        if (i - b >= 0)
            result = max(result, dp[i - b] + 1);
        if (i - c >= 0)
            result = max(result, dp[i - c] + 1);
        dp[i] = result;
    }
    cout << dp[n];
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
