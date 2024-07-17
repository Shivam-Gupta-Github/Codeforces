#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int n, int x) {
    int maxi = 0;
    for (int i = 0; i < n-1; i++) {
        maxi = max(maxi, nums[i + 1] - nums[i]);
    }
    cout << max(nums[0], max((x-nums[n-1])*2, maxi)) << endl;
}

int main() {
    int test = 0;
    cin >> test;
    for (int t = 0; t < test; t++) {
        int n = 0, x = 0;
        cin >> n >> x;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        solve(nums, n, x);
    }
}