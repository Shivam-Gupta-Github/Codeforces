#include <bits/stdc++.h>
using namespace std;

void reverseSort(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
}

int main() {
    vector<int> nums = {8, 7, 1, 6, 2, 3, 4, 5};
    reverseSort(nums);
    for (auto& i: nums) {
        cout << i << " ";
    }
    return 0;
}