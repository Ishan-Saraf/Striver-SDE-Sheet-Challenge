// Recursive function to find unique subsets
void solve(int idx, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
    // Add the current subset 'ds' to the 'ans' vector
    ans.push_back(ds);

    // Iterate over the remaining elements in 'arr'
    for (int i = idx; i < arr.size(); i++) {
        // Check if the current element is a duplicate
        // If it is a duplicate and not the first occurrence (i != idx), skip it
        if (i != idx && arr[i] == arr[i - 1])
            continue;

        // Include the current element in the current subset 'ds'
        ds.push_back(arr[i]);

        // Recursive call to find subsets starting from the next index (i+1)
        solve(i + 1, arr, ds, ans);

        // Backtrack: Remove the last element from the current subset 'ds'
        ds.pop_back();
    }
}

// Function to find all unique subsets of a given vector 'arr'
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> ds;

    // Sort the input vector to handle duplicates easily
    sort(arr.begin(), arr.end());

    // Start the recursion from index 0 and an empty subset 'ds'
    solve(0, arr, ds, ans);

    // Return the 2D vector containing all unique subsets
    return ans;
}
