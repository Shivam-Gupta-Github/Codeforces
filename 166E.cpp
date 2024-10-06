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

int MOD = 1e9 + 7;

// Solver Function
void solve(int n) {
    vector<long long> dpA(n + 1), dpD(n + 1);
    dpD[0] = 1;
    dpA[1] = 1;
    for (int i = 2; i <= n; i++) {
        dpD[i] = (3 * dpA[i - 1]) % MOD;
        dpA[i] = (2* dpA[i - 1] + dpD[i - 1]) % MOD;
    }
    cout << dpD[n];
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
    int n;
    cin >> n;
    solve(n);
    return 0;
}
