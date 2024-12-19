#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

    void buildTree(const vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int queryTree(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftSum = queryTree(2 * node + 1, start, mid, l, r);
        int rightSum = queryTree(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

    void updateTree(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            tree[node] = value;
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
            {
                updateTree(2 * node + 1, start, mid, idx, value);
            }
            else
            {
                updateTree(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    int query(int l, int r)
    {
        return queryTree(0, 0, n - 1, l, r);
    }

    void update(int idx, int value)
    {
        updateTree(0, 0, n - 1, idx, value);
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    segTree.update(1, 10);
    cout << "After update, sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    return 0;
}
