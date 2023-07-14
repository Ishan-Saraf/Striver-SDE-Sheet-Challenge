// Optimal approach using bit shifting:
vector<vector<int>> pwset(vector<int>& v) {
    int n = v.size();
    int subsets = 1 << n; // Total number of subsets is 2^n

    vector<vector<int>> powerSet;
    for (int i = 0; i < subsets; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(v[j]); // Include the element in the subset if its corresponding bit is set
            }
        }
        powerSet.push_back(subset); // Add the subset to the power set
    }

    return powerSet;
}