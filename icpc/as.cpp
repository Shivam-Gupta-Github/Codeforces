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
    long long n, k;
    cin >> n >> k;

    vector<long long> costs(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    sort(costs.begin(), costs.end());

    vector<long long> prek(n, 0);
    prek[k] = costs[0];

    for (int i = k + 1; i < n; i++)
    {
        prek[i] = costs[i - k] + prek[i - k - 1];
    }

    vector<long long> prefixSum(n + 1, 0);
    prefixSum[0] = costs[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + costs[i];
    }

    vector<long long> result(n);

    for (int i = 0; i < n; i++)
    {
        result[i] = prefixSum[i] - prek[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    // FAST_IO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
