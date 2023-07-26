// Recursive function to find all possible sums of subsets of the given vector 'num'
void solve(int idx, int sum, vector<int> &num, int n, vector<int> &ans) {
	// Base case: When all elements are processed (end of the vector)
	if (idx == n) {
		// Push the current sum into the 'ans' vector as it represents a sum of a subset
		ans.push_back(sum);
		return;
	}

	// Recursive call with the current element included in the subset
	solve(idx+1, sum+num[idx], num, n, ans);

	// Recursive call with the current element excluded from the subset
	solve(idx+1, sum, num, n, ans);
}

// Function to find all possible subset sums of the given vector 'num'
vector<int> subsetSum(vector<int> &num){
	// Get the number of elements in the vector 'num'
	int n = num.size();

	// Create an empty vector 'ans' to store the subset sums
	vector<int> ans;

	// Start the recursion from the first element (index 0) with an initial sum of 0
	solve(0, 0, num, n, ans);

	// Sort the 'ans' vector in ascending order
	sort(ans.begin(), ans.end());

	// Return the vector containing all possible subset sums
	return ans;	
}
