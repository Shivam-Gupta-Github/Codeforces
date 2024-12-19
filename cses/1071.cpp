#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

long long calc(long long x, long long y)
{
    if (x >= y)
    {
        long long ans = 0;
        if (x % 2 == 0)
        {
            ans = x * x;
            ans -= (y - 1);
        }
        else
        {
            ans = 1 + (x - 1) * (x - 1);
            ans += (y - 1);
        }

        return ans;
    }
    long long ans = 0;
    if (y % 2 == 0)
    {
        ans = 1 + (y - 1) * (y - 1);
        ans += (x - 1);
    }
    else
    {
        ans = y * y;
        ans -= (x - 1);
    }
    return ans;
}

// Solver Function
void solve()
{
    long long x, y;
    cin >> x >> y;
    cout << calc(x, y);
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
