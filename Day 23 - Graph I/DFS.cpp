void dfs(int i, vector<int>& vis, vector<int>& ans, vector<vector<int>>& adj) {
    // Depth First Search (DFS) function to traverse the graph starting from vertex i.
    // It marks the visited nodes, stores them in the 'ans' vector, and recursively explores adjacent nodes.

    if (vis[i] == 1)
        return; // If the vertex is already visited, return.

    vis[i] = 1; // Mark the current vertex as visited.
    ans.push_back(i); // Add the current vertex to the 'ans' vector.

    for (auto node : adj[i]) {
        if (!vis[node]) {
            // If the adjacent node is not visited, recursively call DFS on that node.
            dfs(node, vis, ans, adj);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    // Function to find connected components in an undirected graph.

    vector<vector<int>> adj(V); // Create an adjacency list to represent the graph.
    for (int i = 0; i < edges.size(); i++) {
        // Add edges to the adjacency list for both directions (undirected graph).
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(V, 0); // Initialize a visited array to keep track of visited vertices.
    vector<vector<int>> res; // Create a vector to store the connected components.

    for (int i = 0; i < adj.size(); i++) {
        // Iterate through all vertices and find connected components.
        vector<int> ans; // Create a vector to store the vertices of the current connected component.

        if (!vis[i]) {
            // If the vertex is not visited, it means it belongs to a new connected component.
            // Perform DFS from this vertex to find all vertices in this connected component.
            dfs(i, vis, ans, adj);

            // Add the current connected component to the result vector.
            res.push_back(ans);
        }
    }

    return res; // Return the vector containing all connected components.
}
