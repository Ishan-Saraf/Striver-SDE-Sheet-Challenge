int editDistance(string str1, string str2)
{
    string s1 = str1;
    string s2 = str2;
    int n1 = str1.size();
    int n2 = str2.size();

    // Create a DP array to store the edit distances between substrings of str1 and str2.
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    // Initialize the base cases: edit distance between an empty string and a non-empty string.
    for (int i = 0; i <= n1; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n2; i++) {
        dp[0][i] = i;
    }

    // Fill the DP array to calculate the edit distance for all substrings of str1 and str2.
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If the current characters are the same, no operation is needed.
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // If the current characters are different, choose the minimum of three operations:
                // 1. Insert a character from str2 into str1.
                // 2. Delete a character from str1.
                // 3. Replace a character in str1 with a character from str2.
                dp[i][j] = min((1 + dp[i - 1][j]), min((1 + dp[i - 1][j - 1]), (1 + dp[i][j - 1])));
            }
        }
    }

    // The edit distance between str1 and str2 is stored in dp[n1][n2].
    return dp[n1][n2];
}
