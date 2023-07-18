#include <bits/stdc++.h>

// Helper function to solve the problem
void solve(int i, int j, int n, vector<vector<int>>& maze, vector<vector<int>>& visited, vector<vector<int>>& ans) {
  // Base condition:
  // If the current position is out of bounds or is a blocked cell (maze[i][j] == 0), return
  if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0) {
    return;
  }

  // Reaching destination:
  // If the current position is the destination (bottom-right cell), add the current path to the result
  else if (i == n - 1 && j == n - 1) {
    vector<int> temp;
    visited[i][j] = 1;

    // Store the visited cells in the current path
    for (int k = 0; k < n; k++) {
      for (int l = 0; l < n; l++) {
        temp.push_back(visited[k][l]);
      }
    }

    visited[i][j] = 0;
    ans.push_back(temp);
    return;
  }

  // Moving the mouse:
  else {
    maze[i][j] = 0;  // Mark the current cell as visited

    // Explore possible moves in all four directions

    // Down:
    visited[i][j] = 1;  // Mark the current cell as visited
    solve(i + 1, j, n, maze, visited, ans);
    visited[i][j] = 0;  // Backtrack: Mark the current cell as unvisited

    // Left:
    visited[i][j] = 1;
    solve(i, j - 1, n, maze, visited, ans);
    visited[i][j] = 0;

    // Right:
    visited[i][j] = 1;
    solve(i, j + 1, n, maze, visited, ans);
    visited[i][j] = 0;

    // Up:
    visited[i][j] = 1;
    solve(i - 1, j, n, maze, visited, ans);
    visited[i][j] = 0;

    maze[i][j] = 1;  // Reset the current cell to unvisited for other paths
  }
}

vector<vector<int>> ratInAMaze(vector<vector<int>>& maze, int n) {
  vector<vector<int>> ans;

  vector<vector<int>> visited(n, vector<int>(n, 0));  // Matrix to keep track of visited cells

  solve(0, 0, n, maze, visited, ans);  // Call the helper function to solve the maze

  return ans;  // Return the result
}
