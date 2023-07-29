#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // 'dp' is a 2D array to store the minimum scalar multiplications needed for matrix chain multiplication.
    int dp[N][N];

    // Initialize the diagonal elements of 'dp' with 0 as the cost of multiplying one matrix is 0.
    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    // Run a loop from length 2 to N-1 to consider all possible matrix chain lengths.
    for (int l = 2; l < N; l++)
    {
        for (int i = 1; i < N - l + 1; i++)
        {
            int j = i + l - 1;

            // Initialize the dp[i][j] with a maximum value.
            dp[i][j] = INT_MAX;

            // Try all possible partitions to find the minimum number of scalar multiplications needed.
            for (int k = i; k <= j - 1; k++)
            {
                // Calculate the temporary cost (scalar multiplications) of multiplying two matrix chains.
                int temp = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                // Update dp[i][j] with the minimum cost.
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }

    // The final answer is stored in dp[1][N-1], which represents the minimum number of scalar multiplications needed for the entire matrix chain.
    return dp[1][N - 1];
}