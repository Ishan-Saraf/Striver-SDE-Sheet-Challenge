#include<bits/stdc++.h>

int lcs(string s, string t)
{
    // Create a 2D DP table to store the lengths of LCS for substrings of 's' and 't'.
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    
    // Base case: LCS of any string with an empty string is 0.
    for (int i = 0; i <= s.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= t.size(); j++)
    {
        dp[0][j] = 0;
    }
    
    // Fill the DP table using bottom-up approach.
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                // If the characters at current positions match, LCS includes the current character.
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                // If the characters at current positions do not match, take the maximum LCS from the previous states.
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    
    // The value at dp[s.size()][t.size()] contains the length of the LCS of 's' and 't'.
    return dp[s.size()][t.size()];
}
