#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    // Function to perform topological sorting for a Directed Acyclic Graph (DAG).

    vector<vector<int>> adj(v); // Create an adjacency list to represent the graph.
    vector<int> indegree(v, 0); // Create an array to store the in-degree of each vertex.

    // Build the adjacency list and calculate the in-degree of each vertex from the given edges.
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }

    vector<int> ans; // Initialize a vector to store the sorted order of vertices.
    queue<int> q; // Initialize a queue for BFS traversal.

    // Push all vertices with in-degree 0 into the queue.
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS traversal to find the topological order.
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            auto f = q.front(); // Get the front element from the queue.
            q.pop();
            ans.push_back(f); // Add the front element to the result.

            // Reduce the in-degree of each neighbor of the front element and push them to the queue if in-degree becomes 0.
            for (auto child : adj[f]) {
                if (--indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
    }

    return ans; // Return the topological order of vertices.
}
