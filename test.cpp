#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Macros
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)(x).size()

// Functions
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// class Solution {
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    int getCount(string& s, int i) {
        if (i == s.size() || !isDigit(s[i])) return 1; 
        int j = i;
        while (j < s.size() && isDigit(s[j])) {
            j++;
        }
        return stoi(s.substr(i, j - i));
    }
// public:
    string countOfAtoms(string formula) {
        return "";
        string s;
        int i = 0, n = formula.size();
        while (i < n) {
            if (formula[i] == ')') {
                int mul = getCount(formula, i + 1);
                int j = i - 1;
                while (s[j] != '(') {
                    j--;
                }
                string sub = s.substr(j + 1, i - j);
                s = s.substr(0, j);
                j = 0;
                while (j < sub.size()) {
                    s.push_back(sub[j++]);
                    while (j < sub.size() && sub[j] >= 'a' && sub[j] <= 'z') {
                        s.push_back(sub[j++]);
                    }
                    s.append(to_string(getCount(sub, j) * mul));
                    while (j < sub.size() && isDigit(sub[j])) j++;
                }
                i++;
                while (i < n && isDigit(formula[i])) i++;
            } else {
                s.push_back(formula[i]);
                i++;
            }
        }
        map<string, int> mp;
        int m = s.size();
        i = 0;
        while (i < m) {
            string elem;
            elem.push_back(s[i++]);
            while (i < m && s[i] >= 'a' && s[i] <= 'z') elem.push_back(s[i++]);
            int count = getCount(s, i);
            while (i < m && isDigit(s[i])) {
                i++;
            }
            mp[elem] += count;
        }
        string result;
        for (auto& elem: mp) {
            result.append(elem.first);
            if (elem.second > 1) {
                result.append(to_string(elem.second));
            }
        } 
        return result;
    }
// };


int main()
{
    string s = "((N42)24(OB40Li30CHe3O48LiNN26)33(C12Li48N30H13HBe31)21(BHN30Li26BCBe47N40)15(H5)16)14";
    string sol = countOfAtoms(s);
    cout << sol;
    cout << " done baby";
    return 0;
}
