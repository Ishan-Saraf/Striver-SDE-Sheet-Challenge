#include<bits/stdc++.h>

// Function to check if the graph is bipartite starting from the given start node using BFS.
bool solve(vector<vector<int>> &edges, int start, vector<int> &color) {
  queue<int> q;
  q.push(start);

  color[start] = 0; // Color the start node with 0.

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    // Loop through all the adjacent nodes of the current node.
	for (int i = 0; i < edges.size(); i++) {
		if (edges[node][i]) {
			if (color[i] == -1) {
				color[i] = !color[node]; // Color the adjacent node with the opposite color of the current node.
				q.push(i);
			} else if (color[i] == color[node]) {
				return false; // If an adjacent node has the same color as the current node, the graph is not bipartite.
			}
		}
    }
  }

  return true; // If all nodes are successfully colored without any conflict, the graph is bipartite.
}

// Function to check if the given graph is bipartite or not.
bool isGraphBirpatite(vector<vector<int>> &edges) {
	vector<int> color(edges.size(), -1); // Initialize the color array with -1 (representing uncolored).

	for (int i = 0; i < edges.size(); i++) {
		if (color[i] == -1) {
			if (!solve(edges, i, color)) return false; // Check each connected component of the graph for bipartiteness.
		}
	}

	return true; // If all connected components are bipartite, the graph is bipartite.
}
