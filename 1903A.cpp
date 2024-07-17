#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int n, int k) {
    if (is_sorted(nums.begin(), nums.end()) || k >= 2)
        cout << "YES" << endl;
    else  
        cout << "NO" << endl;
}

int main() {
    int test = 0;
    cin >> test;
    for (int t = 0; t < test; t++) {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        solve(nums, n, k);
    }
}