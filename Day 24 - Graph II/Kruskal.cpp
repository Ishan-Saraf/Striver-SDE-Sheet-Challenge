#include <bits/stdc++.h>

// Function to update the parent and rank arrays for disjoint-set data structure.
void update(vector<int> &rank, vector<int> &parent, int n) {
	for(int i = 1; i <= n; i++) {
		rank[i] = 0;
		parent[i] = i;
	}
}

// Function to find the parent of a node using path compression technique.
int findParent(int node, vector<int> &parent) {
	if(parent[node] == node) {
		return node;
	}

	return parent[node] = findParent(parent[node], parent);
}

// Function to perform union of two sets using rank-based merging technique.
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
	u = findParent(u, parent);
	v = findParent(v, parent);

	if(rank[u] > rank[v]) {
		parent[v] = u;
	}
	else if(rank[u] < rank[v]) {
		parent[u] = v;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}

// Function to find the total weight of the Minimum Spanning Tree using Kruskal's algorithm.
int kruskalMST(int n, vector<vector<int>> &graph) {
	// Sort the edges of the graph in increasing order of their weights.
	sort(graph.begin(), graph.end(), [&](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});
	
	// Initialize the parent and rank arrays for the disjoint-set data structure.
	vector<int> rank(n + 1);
	vector<int> parent(n + 1);
	update(rank, parent, n);
	
	int ans = 0; // Variable to store the total weight of the MST.

	for(int i = 0; i < graph.size(); i++) {
		int u = findParent(graph[i][0], parent);
		int v = findParent(graph[i][1], parent);
		int w = graph[i][2];

		// If the source node and destination node are not in the same connected component,
		// add the edge to the Minimum Spanning Tree and merge their components.
		if(u != v) {
			ans += w;
			unionSet(u, v, parent, rank);
		}
	}

	// Return the total weight of the Minimum Spanning Tree.
	return ans;
}
