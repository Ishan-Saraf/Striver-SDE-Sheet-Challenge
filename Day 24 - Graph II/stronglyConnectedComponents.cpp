#include<bits/stdc++.h>

// Depth-first search to add nodes to the stack in the order of their finishing times in the first pass.
void dfs(int i, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[i] = 1; // Mark the current node as visited.
    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(it, vis, adj, st); // Recursively explore the unvisited adjacent nodes.
        }
    }
    st.push(i); // Push the current node to the stack when all its adjacent nodes have been processed.
}

// Depth-first search to get nodes of a strongly connected component in the second pass.
void dfs2(int i, vector<int> &vis, vector<int> adjrev[], vector<int> &topush){
    vis[i] = 1; // Mark the current node as visited.
    for(auto it: adjrev[i]){
        if(!vis[it]){
            dfs2(it, vis, adjrev, topush); // Recursively explore the unvisited adjacent nodes.
        }
    }
    topush.push_back(i); // Push the current node to the vector to represent the strongly connected component.
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Create adjacency list representation of the directed graph.
    vector<int> adj[n];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }

    // Step 1: Perform DFS and store nodes in the stack in the order of their finishing times.
    stack<int> st;
    vector<int> vis(n,0);
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }

    // Step 2: Reverse the edges to create the transposed graph for the second pass.
    vector<int> adjrev[n];
    for(int i = 0; i < n; i++){
        vis[i] = 0; // Reset the visited array for the second pass.
        for(auto it: adj[i]){
            adjrev[it].push_back(i); // Add reversed edges for each edge in the original graph.
        }
    }

    // Step 3: Perform DFS on the transposed graph and get the strongly connected components.
    vector<vector<int>> ans;
    while(!st.empty()){
        int a = st.top();
        st.pop();
        vector<int> topush;
        if(!vis[a]){
            dfs2(a,vis,adjrev,topush); // Get the nodes of the strongly connected component.
        }
        ans.push_back(topush); // Push the strongly connected component to the result.
    }
    
    return ans;
}
