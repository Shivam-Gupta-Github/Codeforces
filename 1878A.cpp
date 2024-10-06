#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

// Solver Function
void solve()
{
    int n, k, num;
    bool res = false;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == k)
            res = true;
    }
    if (res)
        cout << "YES";
    else
        cout << "NO";
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
