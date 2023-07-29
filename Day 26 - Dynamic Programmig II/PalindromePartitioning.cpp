// Function to check if a given substring is a palindrome or not.
bool isPalindrome(int i, int j, string a) {
    while (i < j) {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to find the minimum cuts required to partition the string into palindromic substrings.
int f(int i, int n, string& a, vector<int>& dp) {
    // Base case: If we reach the end of the string, no cuts needed.
    if (i == n)
        return 0;
    
    // If the result for this index is already calculated, return it from the dp array.
    if (dp[i] != -1)
        return dp[i];
    
    int mincost = INT_MAX;
    // Iterate through all possible substrings starting from index i.
    for (int j = i; j < n; j++) {
        // If the substring from index i to j is a palindrome,
        // update the minimum cuts required using the recursive call for the next substring.
        if (isPalindrome(i, j, a)) {
            int cost = 1 + f(j + 1, n, a, dp);
            mincost = min(cost, mincost);
        }        
    }
    // Store the result for this index in the dp array and return it.
    return dp[i] = mincost;
}

// Main function to find the minimum cuts required to partition the input string into palindromic substrings.
int palindromePartitioning(string str) {
    int n = str.length();
    // Initialize a dp array with -1 for memoization.
    vector<int> dp(n, -1);
    // Call the recursive function and subtract 1 from the final result to get the correct answer.
    return f(0, n, str, dp) - 1;
}
