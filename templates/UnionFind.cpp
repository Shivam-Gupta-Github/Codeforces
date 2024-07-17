class UnionFind {
    vector<int> parent, size;
    int componentCount;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        componentCount = n;
        iota(parent.begin(), parent.end(), 0); // [0,1,...,n]
    }

    int Find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y) {
        x = Find(x), y = Find(y);

        if (x == y)
            return false;

        if (size[x] > size[y]) {
            size[x] += size[y];
            parent[y] = x;
        } else {
            size[y] += size[x];
            parent[x] = y;
        }
        componentCount--;
        return true;
    }

    bool IsConnected() {
        return componentCount == 1;
    }
};
