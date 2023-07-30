bool iscycle(int node, vector<vector<int>>& adj, int parent, vector<int>& vis) {
    // Function to check if there is a cycle in the graph using DFS.

    vis[node] = 1; // Mark the current node as visited.

    for (auto child : adj[node]) {
        // Traverse through the neighbors of the current node.
        if (!vis[child]) {
            // If the neighbor is not visited, recursively check if there is a cycle starting from this neighbor.
            if (iscycle(child, adj, node, vis))
                return true;
        } else if (child != parent) {
            // If the neighbor is already visited and not the parent of the current node, there is a cycle.
            return true;
        }
    }

    // If no cycle is found starting from this node, return false.
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // Function to detect if there is any cycle in the undirected graph.

    vector<vector<int>> adj(n + 1); // Create an adjacency list to represent the graph.

    // Build the adjacency list from the given edges.
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(n + 1, 0); // Initialize the visited array.

    // Perform DFS from each unvisited node to check for cycles.
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && iscycle(i, adj, -1, vis)) {
            // If a cycle is found starting from node i, return "Yes".
            return "Yes";
        }
    }

    // If no cycle is found in the graph, return "No".
    return "No";
}
