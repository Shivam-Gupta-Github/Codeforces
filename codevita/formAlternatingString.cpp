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

int main()
{
    // FAST_IO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n);
    long totalSum = 0, toKeep = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        totalSum += v[i];
    }

    int i = 0;
    while (i < n)
    {
        int j = i, maxi = 0;
        while (s[j] == s[i])
        {
            maxi = max(maxi, v[j]);
            j++;
        }
        toKeep += maxi;
        i = j;
    }
    cout << totalSum - toKeep;
    return 0;
}
