int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Create a 2D matrix to store the shortest distances between all pairs of nodes.
    vector<vector<int>> mat(n, vector<int>(n, 1e9));

    // Initialize the diagonal elements of the matrix to 0.
    for (int i = 0; i < n; i++)
        mat[i][i] = 0;

    // Populate the matrix with the weights of the edges.
    for (auto i : edges) {
        int u = i[0] - 1, v = i[1] - 1, wt = i[2];
        mat[u][v] = wt;
    }

    // Apply the Floyd-Warshall algorithm to find the shortest distances.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If there is a shorter path from i to k and from k to j, update the distance.
                if (mat[i][k] != 1e9 && mat[k][j] != 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    // Return the shortest distance from the source to the destination.
    return mat[src - 1][dest - 1];
}
