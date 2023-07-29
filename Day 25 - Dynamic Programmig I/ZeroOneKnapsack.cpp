#include<bits/stdc++.h>

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Creating a 2D DP array to store the maximum profit for different item counts and weight limits.
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    // Filling the DP array using a bottom-up approach.
    for (int i = 1; i <= n; i++) { // Loop over the items.
        for (int j = 1; j <= w; j++) { // Loop over the weight limits.
            if (weights[i - 1] <= j) { // If the current item can fit within the current weight limit.
                // Choose the maximum of two possibilities:
                // 1. Do not include the current item and use the maximum profit from the previous row (previous item count).
                // 2. Include the current item and use the maximum profit from the previous row and reduce the weight limit by the weight of the current item.
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                // If the current item's weight exceeds the current weight limit, then we cannot include it. So, use the maximum profit from the previous row (previous item count).
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The maximum profit is stored in dp[n][w], which represents the maximum profit for using all items (n) and a weight limit (w).
    return dp[n][w];
}
