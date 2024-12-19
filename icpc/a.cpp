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

// Fast I/O
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> pre(v);
    for (int i = 1; i < n; i++)
    {
        pre[i] += pre[i - 1];
    }

    vector<int> s(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i - k - 1 >= 0)
        {
            s[i] = s[i - k - 1] + v[i - k - 1];
        }
        cout << pre[i] - s[i] << " ";
    }
}

int main()
{
// FAST_IO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
