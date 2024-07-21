// Ee can find topological sort only of a directed acyclic graph (DAG).
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
void dfs(vector<vector<int>> &adj, int u, vector<int> &visited, stack<int> &stk, bool &cycle) {
    visited[u] = 0;
    for (auto &v : adj[u]) {
        if (visited[v] == 0) { // element found in current recursion.
            cycle = true;
            return;
        }
        else if (visited[v] == -1) {
            dfs(adj, v, visited, stk, cycle);
        }
    }
    visited[u] = 1;
    stk.push(u);
}
vector<int> topoSort(vector<vector<int>> &edges, int n) {
    // this function return topological sorted order of graph where elements are from 1 to n.
    // if cycle exist, it will return an empty array.
    vector<vector<int>> adj(n + 1);
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    stack<int> stk;
    // -1 : not visited
    //  0 : visited in current recursion
    //  1 : visited in older dfs
    vector<int> visited(n + 1, -1);
    bool cycle = false;
    for (int u = 1; u <= n; u++) {
        if (visited[u] == -1) {
            dfs(adj, u, visited, stk, cycle);
        }
        if (cycle) {
            return {};
        }
    }
    vector<int> result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    return result;
}