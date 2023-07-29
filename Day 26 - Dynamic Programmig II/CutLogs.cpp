#include<bits/stdc++.h>

int cutLogs(int k, int n) {
    // Initialize a 1D vector dp of size k+1, where dp[i] represents the number of logs of length i or larger.
    vector<int> dp(k + 1, 0);

    int moves = 0; // Initialize a variable to keep track of the number of moves.

    // Keep cutting logs until we have at least n pieces of log of length k or larger.
    while (dp[k] < n) {
        moves++; // Increment the number of moves.

        // Starting from the longest log (length k), we divide the logs into two equal halves at each step.
        // For example, if we have 5 logs of length 8, we can cut them into 10 logs of length 4.
        // We add 1 + dp[i-1] to dp[i] for all i from k to 1.
        // This way, dp[i] will represent the number of logs of length i or larger after each move.
        for (int i = k; i > 0; i--) {
            dp[i] += 1 + dp[i - 1];
        }
    }

    return moves; // Return the minimum number of moves required to obtain at least n pieces of log of length k or larger.
}
