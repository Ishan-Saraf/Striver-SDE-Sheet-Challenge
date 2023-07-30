#include<bits/stdc++.h>

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    // Function to perform Breadth-First Search (BFS) on a graph.

    vector<vector<int>> adj(vertex); // Create an adjacency list to represent the graph.
    for (int i = 0; i < edges.size(); i++) {
        // Add edges to the adjacency list for both directions (undirected graph).
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    for (int i = 0; i < vertex; i++) {
        // Sort the adjacency list of each vertex in ascending order.
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> vis(vertex, 0); // Initialize a visited array to keep track of visited vertices.
    queue<int> q; // Create a queue to perform BFS.
    q.push(0); // Start BFS from vertex 0.
    vis[0] = 1; // Mark the starting vertex as visited.
    vector<int> ans; // Create a vector to store the vertices in the order they are visited.

    while (!q.empty()) {
        int it = q.front(); // Get the front element from the queue.
        q.pop(); // Remove the front element from the queue.

        ans.push_back(it); // Add the current vertex to the 'ans' vector.

        for (auto child : adj[it]) {
            // Iterate through the neighbors of the current vertex.
            if (vis[child] == 0) {
                // If the neighbor is not visited, mark it as visited and add it to the queue for further exploration.
                vis[child] = 1;
                q.push(child);
            }
        }
    }

    // After the BFS is complete, add any unvisited vertices to the 'ans' vector.
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i] == 0)
            ans.push_back(i);
    }

    return ans; // Return the vector containing the vertices in the order they are visited.
}
