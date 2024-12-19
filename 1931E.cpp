#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

int leadingZeroCnt(int i)
{
    int cnt = 0;
    while (i % 10 == 0)
    {
        cnt++;
        i /= 10;
    }
    return cnt;
}

int digitCnt(int i)
{
    int c = 0;
    while (i)
    {
        c++;
        i /= 10;
    }
    return c;
}

// Solver Function
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int annaCnt = 0, cnt = 0;

    priority_queue<int> pq;

    for (int &i : a)
    {
        cnt += digitCnt(i);
        pq.push(leadingZeroCnt(i));
    }

    while (pq.size() >= 2)
    {
        annaCnt += pq.top();
        pq.pop();
        pq.pop();
    }

    annaCnt += pq.top();

    cout << cnt << " " << annaCnt << " ";
    if (cnt - annaCnt > m)
    {
        cout << "Shasha";
    }
    else
    {
        cout << "Anna";
    }
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
