int cut(vector<int>& price, int ind, int n, vector<vector<int>>& dp) {
    // Base case: If we are at index 0, there is only one possible cut for length n.
    if (ind == 0) {
        return n * price[0];
    }

    // If dp[ind][n] is not equal to -1, it means we have already calculated this subproblem.
    if (dp[ind][n] != -1) {
        return dp[ind][n]; // Return the precalculated result.
    }

    // Recursively check two cases:
    // 1. Not picking the current rod of length price[ind].
    int notpick = cut(price, ind - 1, n, dp);

    // 2. Picking the current rod and recursively calling for the remaining length.
    int pick = INT_MIN;
    int remainingLength = ind + 1;
    if (remainingLength <= n) {
        pick = price[ind] + cut(price, ind, n - remainingLength, dp);
    }

    // Store the current result in dp to avoid redundant calculations.
    dp[ind][n] = max(pick, notpick);

    // Return the current result.
    return dp[ind][n];
}

int cutRod(vector<int> &price, int n) {
    // Initialize dp array with -1.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // Call the recursive helper function to find the maximum profit.
    return cut(price, n - 1, n, dp);
}
