#include <bits/stdc++.h> 
int f(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    // Base case: If we reach the bottom-right cell, return the value in the grid.
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
        return grid[i][j];
    }
    // Base case: If we go out of the grid boundaries, return a large value.
    if (i >= grid.size() || j >= grid[0].size()) {
        return 1e9;
    }
    // If the value for the current cell is already calculated, return it.
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    // Calculate the minimum sum path by taking the minimum of moving down and moving right.
    int down = grid[i][j] + f(grid, i + 1, j, dp);
    int right = grid[i][j] + f(grid, i, j + 1, dp);
    // Store the result in the dp table and return it.
    return dp[i][j] = min(down, right);
}

int minSumPath(vector<vector<int>> &grid) {
    // Initialize a dp table with -1 to mark that the values are not calculated yet.
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    // Start the recursive function from the top-left cell (0, 0) of the grid.
    return f(grid, 0, 0, dp);
}
