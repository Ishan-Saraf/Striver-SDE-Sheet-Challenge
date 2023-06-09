#include <bits/stdc++.h> 
/*
// recursive solution:
int recCountPaths(int i, int j, int m, int n) {
	// base case:
	if (i>=m || j>=n) return 0;

	if (i==m-1 && j==n-1) return 1;

	else return recCountPaths(i+1, j, m, n) + recCountPaths(i, j+1, m, n);
}

// DP solution:
int DPCountPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
	// base case:
	if (i>=m || j>=n) return 0;

	if (i==m-1 && j==n-1) return 1;

	if (dp[i][j] != -1) return dp[i][j];

	else return dp[i][j] = DPCountPaths(i+1, j, m, n, dp) + DPCountPaths(i, j+1, m, n, dp);
}
*/

int uniquePaths(int m, int n) {
	/*

	// Approach 1: using recursion:
	int i = 0;
	int j = 0;

	int ans = recCountPaths(i, j, m, n);

	return ans;

	// Approach 2: using DP:
	int i = 0;
	int j = 0;

	vector<vector<int>> dp(m, vector<int>(n, -1));

	int ans = DPCountPaths(i, j, m, n, dp);

	return ans;

	*/

	// Approach 3: using maths:

	int N = m + n - 2;
	int r = n - 1;

	double result = 1;

	for (int i=1; i<=r; i++) {
		result = result * (N - r + i) / i;
	}

	return (int) result;
}