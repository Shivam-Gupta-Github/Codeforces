#include <bits/stdc++.h>
using namespace std;

// edges[i] = {from[i], to[i], cost[i]}
// node are from [0,1..n-1]
vector<vector<int>> getAPSP(int n, vector<vector<int>> edges) { // Get All Pair Shortest Path.
    int INF = INT_MAX;
    vector<vector<int>> shortestPath(n, vector<int>(n, INF));

    // Filling table with initial values
    for (auto &edge : edges) {
        shortestPath[edge[0]][edge[1]] = min(shortestPath[edge[0]][edge[1]], edge[2]);
        // shortestPath[edge[1]][edge[0]] = min(shortestPath[edge[1]][edge[0]], edge[2]); // For undirected edges.
    }
    for (int i = 0; i < n; i++) {
        shortestPath[i][i] = 0;
    }

    // Floyd Warshalls's algorithm
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (shortestPath[i][via] != INF && shortestPath[via][j] != INF) {
                    shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][via] + shortestPath[via][j]);
                }
            }
        }
    }

    return shortestPath;
}