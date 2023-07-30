#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Initialize data structures
    vector<int> par(n+1, -1); // Parent array to store the parent of each node in the MST.
    vector<int> key(n+1, INT_MAX); // Key array to store the minimum weight edge to connect a node to the MST.
    vector<bool> mst(n+1, false); // mst array to mark nodes included in the MST.
    vector<vector<pair<int, int>>> adj(n+1); // Adjacency list to represent the graph.

    // Populate the adjacency list with the given edges.
    for (auto it : g)
    {
        adj[it.first.first].push_back({it.first.second, it.second});
        adj[it.first.second].push_back({it.first.first, it.second});
    }

    // Priority queue to select the minimum weight edge.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // Start the MST from node 1 with 0 key value.
    key[1] = 0;

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int u = node.second; // Extract the node with the minimum key value.
        mst[u] = true; // Mark the node as included in the MST.

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mst[v] == false && wt < key[v])
            {
                key[v] = wt; // Update the key value if a smaller weight edge is found to connect the node to the MST.
                par[v] = u; // Set the parent of the node in the MST.
                pq.push({key[v], v});
            }
        }
    }

    // Prepare the result with edges and their weights for the MST.
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) // Start from node 2 since node 1 is the starting node.
    {
        ans.push_back({{i, par[i]}, key[i]}); // Add the edge (i, par[i]) and its weight key[i] to the MST.
    }
    return ans;
}

