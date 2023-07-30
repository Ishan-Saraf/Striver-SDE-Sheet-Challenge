// Function to check if a given row and column indices are valid (within the grid bounds).
bool isValid(int row, int col, int n, int m) {
    return row >= 0 && col >= 0 && row < n && col < m;
}

// Depth-First Search (DFS) function to explore the island starting from the given row and column.
void dfs(int row, int col, int** arr, int n, int m, vector<vector<int>>& vis) {
    vis[row][col] = 1; // Mark the current cell as visited.

    // Explore all neighbors of the current cell in all 8 directions (horizontally, vertically, and diagonally).
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;

            // Check if the new row and column indices are valid and if the cell is unvisited and part of the island.
            if (isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 0 && arr[newRow][newCol] == 1) {
                // Recursively call dfs for the new cell.
                dfs(newRow, newCol, arr, n, m, vis);
            }
        }
    }
}

// Function to get the total number of islands in the given 2D grid represented by a 2D array.
int getTotalIslands(int** arr, int n, int m) {
    int ans = 0; // Initialize the count of islands.

    // Create a 2D vector to store visited cells and initialize it with all zeros.
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Loop through all cells in the grid.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is part of an unvisited island, increment the count of islands and perform DFS to explore the island.
            if (arr[i][j] == 1 && vis[i][j] == 0) {
                ans++; // Increment the count of islands.
                dfs(i, j, arr, n, m, vis); // Perform DFS to explore the island.
            }
        }
    }

    return ans; // Return the total number of islands found.
}

