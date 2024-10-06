#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

bool isPrime(int N) {
    if (N <= 1) {
        return false;
    }
    if (N <= 3) {
        return true;
    }

    if (N % 2 == 0 || N % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


// Solver Function
void solve() {
    int l, r;
    cin >> l >> r;
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    cout << min(count, (r - l + 1) / 3);
}

int main() {
    int t;
    cin >> t; // for multi-test case problems.
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
