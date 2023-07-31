#include<bits/stdc++.h>

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
    int iniColor = image[x][y]; // Initial color of the cell at (x, y)
    int n = image.size(); // Number of rows in the image
    int m = image[0].size(); // Number of columns in the image

    vector<vector<int>> ans = image; // Create a copy of the image to store the result

    queue<pair<int, int>> q; // Queue to perform BFS
    vector<vector<int>> vis(n, vector<int>(m, 0)); // 2D vector to keep track of visited cells

    vis[x][y] = 1; // Mark the starting cell as visited
    q.push({x, y}); // Push the starting cell into the queue

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        ans[row][col] = newColor; // Set the new color for the current cell

        int drow[] = {-1, 0, +1, 0}; // Possible directions to move in row
        int dcol[] = {0, +1, 0, -1}; // Possible directions to move in column

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i]; // New row after moving in the i-th direction
            int ncol = col + dcol[i]; // New column after moving in the i-th direction

            // Check if the new position is within the bounds of the image,
            // not visited before, and has the same initial color as the starting cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == iniColor) {
                q.push({nrow, ncol}); // Push the new position into the queue for further processing
                vis[nrow][ncol] = 1; // Mark the new position as visited
            }
        }
    }

    return ans; // Return the modified image after flood fill
}
