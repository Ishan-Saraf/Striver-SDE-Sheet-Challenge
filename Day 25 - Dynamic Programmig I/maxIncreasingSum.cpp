#include <bits/stdc++.h> 

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    int ans = arr[0];
    vector<int> dp = arr; // Initialize a DP array with the elements of the input array

    // Loop through the array from the second element
    for (int i = 1; i < n; i++)
    {
        // Check for all previous elements to find if they can form an increasing dumbbell with the current element
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                // If the current element can be included in the increasing dumbbell starting at index j,
                // update the maximum sum ending at index i.
                if (dp[j] + arr[i] > dp[i])
                {
                    dp[i] = dp[j] + arr[i];
                }
            }
        }

        // Update the overall maximum sum of increasing dumbbells
        ans = max(ans, dp[i]);
    }

    // The final result is the maximum sum of increasing dumbbells.
    return ans;
}
