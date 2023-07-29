int helper(vector<int> &arr, int n, int k, vector<vector<int>> &memo) {
    // Base condition: If 'n' becomes 0, we have considered all elements.
    if (n <= 0) {
        // If 'k' is reduced to 0, it means we have found a subset with sum 'k'.
        if (k == 0) {
            return 1; // Found a subset with sum 'k'.
        } else {
            return 0; // 'k' is not reduced to 0, hence no subset with sum 'k'.
        }
    }

    // If memo[n][k] is not equal to -1, it means we have already calculated this subproblem.
    if (memo[n][k] != -1) {
        return memo[n][k]; // Return the precalculated result.
    }

    // Recursively check two cases:
    // 1. Exclude the current element arr[n-1].
    int x = helper(arr, n - 1, k, memo);

    // 2. Include the current element arr[n-1].
    int y = 0;
    if (k - arr[n - 1] >= 0) {
        y = helper(arr, n - 1, k - arr[n - 1], memo);
    }

    // Store the current result in memo to avoid redundant calculations.
    memo[n][k] = x || y;

    // Return the current result.
    return memo[n][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize memo array with -1.
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    // Call the recursive helper function to find if there exists a subset with sum 'k'.
    int ans = helper(arr, n, k, memo);

    // If ans is 1, it means there exists a subset with sum 'k', so return true.
    // Otherwise, return false.
    return ans == 1;
}
