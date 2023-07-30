#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Initialize a vector to store the distance from the source to each node.
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0; // Distance from the source node to itself is 0.

    // Relax edges repeatedly (n-1 times) to find the shortest paths.
    for (int i = 0; i < n - 1; ++i) {
        // Iterate through all the edges.
        for (auto it : edges) {
            int u = it[0]; // Source node of the edge.
            int v = it[1]; // Destination node of the edge.
            int wt = it[2]; // Weight of the edge.

            // If the distance to u is not infinity (1e9) and the distance to v can be reduced
            // by going through u, update the distance to v.
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist[dest]; // Return the distance from the source to the destination.
}
