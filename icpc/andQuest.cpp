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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int temp = k, mask = 1;
    vector<bool> b(n, false);
    while (temp)
    {
        if (temp & 1)
        {
            for (int i = 0; i < n; i++)
            {
                if ((a[i] & mask) != 1)
                {
                    b[i] = false;
                }
            }
        }
        temp >>= 1;
        mask <<= 1;
    }
    vector<int> arr;
    int x = pow(2, 30) - 1;
    for (int i = 0; i < n; i++)
    {
        if (b[i])
        {
            x &= a[i];
            arr.push_back(a[i]);
        }
    }
    if (x == k)
    {
        cout << "YES" << endl
             << arr.size() << endl;
        for (int &i : arr)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "NO";
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
