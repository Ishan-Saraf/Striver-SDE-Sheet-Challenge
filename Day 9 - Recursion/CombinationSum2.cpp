#include<algorithm>

// Recursive function to find unique combinations with the sum 'target'
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    // Base case: If the target sum becomes zero, add the current combination 'ds' to the result vector 'ans'
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++) {
        // Skip duplicate elements to avoid duplicate combinations
        if (i > ind && arr[i] == arr[i - 1]) continue;

        // If the current element is greater than the remaining target, break the loop
        if (arr[i] > target) break;

        // Include the current element in the combination 'ds'
        ds.push_back(arr[i]);

        // Recursive call to include the next element and continue exploring
        findCombination(i + 1, target - arr[i], arr, ans, ds);

        // Backtrack: Remove the last element from the current combination 'ds'
        ds.pop_back();
    }
}

// Function to find all unique combinations that sum up to 'target'
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
    // Sort the input vector to avoid duplicate combinations
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> ds;

    // Start the recursion from index 0 and an empty combination 'ds'
    findCombination(0, target, arr, ans, ds);

    // Return the 2D vector containing unique combinations with the sum 'target'
    return ans;
}
