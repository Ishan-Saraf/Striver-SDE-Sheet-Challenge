bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsvis) {
    // Recursive function to perform DFS and check for cycles.

    vis[i] = 1; // Mark the current node as visited.
    dfsvis[i] = 1; // Mark the current node as part of the current DFS traversal.

    for (auto child : adj[i]) {
        // Traverse through the neighbors of the current node.

        if (!vis[child]) {
            // If the neighbor is not visited, recursively check for cycles starting from this neighbor.
            if (dfs(child, adj, vis, dfsvis))
                return true;
        } else if (dfsvis[child]) {
            // If the neighbor is already part of the current DFS traversal, there is a cycle.
            return true;
        }
    }

    dfsvis[i] = 0; // Mark the current node as not part of the current DFS traversal.

    return false; // No cycle found starting from this node.
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Function to detect cycles in a directed graph.

    vector<vector<int>> adj(n + 1); // Create an adjacency list to represent the graph.

    // Build the adjacency list from the given edges.
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].first].push_back(edges[i].second);
    }

    vector<int> vis(n + 1, 0); // Initialize the visited array.
    vector<int> dfsvis(n + 1, 0); // Initialize the array to track nodes in the current DFS traversal.

    // Perform DFS from each unvisited node to check for cycles.
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, dfsvis)) {
                // If a cycle is found starting from node i, return true.
                return true;
            }
        }
    }

    // If no cycle is found in the graph, return false.
    return false;
}
