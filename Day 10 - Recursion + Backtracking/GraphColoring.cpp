#include <bits/stdc++.h>

// Function to check if it is safe to color vertex 'u' with color 'c'
bool isSafe(int u, vector<vector<int>> mat, int c, int V, int m, vector<int>& color) {
    color[u] = c; // Assign color 'c' to vertex 'u'

    // Check all adjacent vertices of 'u'
    for (int i = 0; i < V; i++) {
        if (mat[u][i] == 1) {
            // If the adjacent vertex 'i' has the same color as 'c', then coloring is not safe
            if (color[i] == c) {
                color[u] = -1; // Reset the color of vertex 'u' to -1
                return false;
            }
        }
    }

    return true; // If all adjacent vertices are safely colored, return true
}

// Backtracking function to find a valid graph coloring
bool mColoring(vector<vector<int>>& mat, int u, vector<int>& color, int V, int m) {
    if (u == V) {
        return true; // All vertices have been colored, return true
    }

    // Try all colors for vertex 'u'
    for (int i = 0; i < m; i++) {
        if (isSafe(u, mat, i, V, m, color)) {
            // If it is safe to color vertex 'u' with color 'i', proceed to the next vertex
            bool flag = mColoring(mat, u + 1, color, V, m);
            if (flag) {
                return true; // If coloring is successful, return true
            }
        }
    }

    color[u] = -1; // If none of the colors worked for vertex 'u', reset its color to -1
    return false; // Return false as coloring is not possible
}

// Main function to check if the graph can be colored with 'm' colors
string graphColoring(vector<vector<int>>& mat, int m) {
    int V = mat[0].size(); // Number of vertices in the graph

    vector<int> color(V, -1); // Create an array to store the color of each vertex, initialized to -1 (not colored)

    // Check each vertex and color if it is not yet colored
    for (int j = 0; j < V; j++) {
        if (color[j] == -1) {
            // If graph coloring for vertex 'j' is not possible, return "NO"
            if (!mColoring(mat, j, color, V, m)) {
                return "NO";
            }
        }
    }

    return "YES"; // If graph coloring for all vertices is successful, return "YES"
}
