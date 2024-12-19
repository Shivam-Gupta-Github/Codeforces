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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> c(n);
    c[0] = max(a[0], b[0]);
    c[1] = max(a[1], b[1]);

    int cnt = 0;

    for (int i = 2; i < n; i++)
    {
        int maxi = max(a[i], b[i]), mini = min(a[i], b[i]);
        if (maxi <= c[i - 1] + c[i - 2])
        {
            c[i] = maxi;
            cnt++;
        }
        else
        {
            if (mini <= c[i - 1] + c[i - 2])
            {
                cnt++;
                c[i] = mini;
            }
            else
            {
                c[i] = maxi;
            }
        }
    }
    // for (int i : c)
    //     cout << i << " ";
    cout << cnt;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}