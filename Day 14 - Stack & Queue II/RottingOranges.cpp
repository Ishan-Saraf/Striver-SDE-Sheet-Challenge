# include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Approach: Using BFS algorithm:

    queue < pair < pair < int, int > , int >> q; // Queue to store the positions of oranges and their time of rotting
    int vis[n][m]; // 2D array to track the visited status of oranges
    int cntFresh = 0; // Counter to count the number of fresh oranges
    
    // Initialize the queue, visited array, and count fresh oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If cell contains a rotten orange
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0}); 
                // Mark as visited (rotten) in the visited array
                vis[i][j] = 2;
            }
            // If the orange is not rotten
            else {
                vis[i][j] = 0;
            }
            // Count fresh oranges
            if (grid[i][j] == 1) cntFresh++;
        }
    }

    int tm = 0; // Time required for all oranges to rot
    // Delta row and delta column to traverse neighboring cells
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1}; 
    int cnt = 0; // Counter to keep track of the number of rotten oranges

    // BFS traversal (until the queue becomes empty)
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // Traverse all four neighbors
        for (int i = 0; i < 4; i++) {
            // Neighboring row and column
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            // Check for valid cell and then for unvisited fresh orange
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                // Push in the queue with the timer increased
                q.push({{nrow, ncol}, t + 1}); 
                // Mark as rotten in the visited array
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }

    // If all oranges are not rotten
    if (cnt != cntFresh) return -1;

    return tm; // Return the time required for all oranges to rot
}
