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
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;
    bool flag = false;
    for (int i = 0; i < 6; i++) {
        if (x.find(s) != string::npos) {
            cout << i;
            flag = true;
            break;
        }
        x += x;
    }
    if (!flag) cout << -1;
}

int main()
{
    int t;
    cin >> t; // for multi-test case problems.
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
