// Recursive function to find subsets with the sum 'k'
void rec(int ind, vector<int>& arr, int k, vector<vector<int>>& ans, vector<int>& ds) {
    // Base case: If the current index 'ind' reaches the size of the array
    if (ind == arr.size()) {
        // Check if the sum of the current subset 'ds' is equal to 'k'
        if (accumulate(ds.begin(), ds.end(), 0) == k) {
            // If yes, add the current subset 'ds' to the result vector 'ans'
            ans.push_back(ds);
        }
        return;
    }

    // Include the current element in the subset 'ds'
    ds.push_back(arr[ind]);

    // Recursive call to include the next element and continue exploring
    rec(ind + 1, arr, k, ans, ds);

    // Backtrack: Remove the last element from the current subset 'ds'
    ds.pop_back();

    // Recursive call to exclude the current element and continue exploring
    rec(ind + 1, arr, k, ans, ds);
}

// Function to find all subsets that sum up to 'k'
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> ans;
    vector<int> ds;

    // Start the recursion from index 0 and an empty subset 'ds'
    rec(0, arr, k, ans, ds);

    // Return the 2D vector containing subsets with the sum 'k'
    return ans;
}
