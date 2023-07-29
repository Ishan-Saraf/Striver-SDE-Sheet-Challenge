#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    // Create a vector 'dp' to store the current increasing subsequence.
    vector<int> dp;
    
    // Add the first element of the array to 'dp'.
    dp.push_back(arr[0]);
    
    // Iterate through the array starting from the second element.
    for (int i = 1; i < n; i++)
    {
        // Find the position in 'dp' where the current element 'arr[i]' can be inserted.
        // Lower bound returns an iterator pointing to the first element in 'dp' that is not less than 'arr[i]'.
        // The position where 'arr[i]' can be inserted will be 'it - dp.begin()'.
        int it = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        
        // If the iterator 'it' is equal to the size of 'dp', it means 'arr[i]' is the largest element so far.
        // Hence, add it to the end of 'dp'.
        if (it == dp.size())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            // If 'it' is less than the size of 'dp', update the value at 'it' with 'arr[i]'.
            // This ensures that 'dp' remains sorted and only contains increasing elements.
            dp[it] = arr[i];
        }
    }
    
    // The size of 'dp' gives the length of the longest increasing subsequence.
    return dp.size();
}
