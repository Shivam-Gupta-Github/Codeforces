#include <bits/stdc++.h>
using namespace std;

// Solver Function
void solve()
{
    int a, b;
    string s;
    cin >> s;
    cin >> a >> b;
    int zero = 0, one = 0;
    for (auto &ch : s)
    {
        if (ch == '0')
        {
            zero++;
        }
        else if (ch == '1')
        {
            one++;
        }
        else
        {
            cout << "INVALID";
            return;
        }
    }

    if (zero && one)
    {
        string s2 = s;
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;
        sort(s2.begin(), s2.end());

        for (int i = 0; i < n; i++)
        {
            if (s[i] != s2[i])
                cnt1++;
        }
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s2[i])
                cnt2++;
        }
        if (a < b)
        {
            cout << cnt1;
        }
        else if (b < a)
        {
            cout << cnt2;
        }
        else
        {
            cout << min(cnt1, cnt2);
        }
    }
    else
    {
        cout << 0;
    }
}

int main()
{
    int t;
    cin >> t; // for multi-test case problems.
    while (t--)
    {
        solve();
        if (t)
            cout << endl;
    }
    return 0;
}
