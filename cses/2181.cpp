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

int f1(int n, int m)
{
    // if (n % 2 == 1 && m % 2 == 1)
    //     return 0;
    if (n == 1 && m == 2)
        return 1;
    if (m == 1 && n == 2)
        return 1;
    if (n < 1 || m < 1)
        return 0;
    return f1(n, m - 2) + f1(n - 1, 2) +
           f1(n - 2, m) + f1(2, m - 1);
}

int main()
{
// FAST_IO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> n >> m;
    cout << f1(n, m);
    return 0;
}
