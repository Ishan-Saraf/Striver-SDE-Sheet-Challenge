#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*

    // Approach 1:
        - Find all possible subarrays
        - Return the maximum subarray

    // Approach 2:

    long long maxi = LONG_MIN;

    for (int i=0; i<n; i++) {
        long long sum = 0;
        for (int j=i; j<n; j++) {
            sum+=arr[j];
            maxi = max(sum, maxi);
        }
    }

    if (maxi < 0) maxi = 0;

    return maxi;
    */

    // Approach 3 (Kadane's Algorithm):

    long long sum = 0, maxi = LONG_MIN;

    for (int i=0; i<n; i++) {
        sum += arr[i];
        maxi = max(sum, maxi);

        if (sum<0)
            sum = 0;
    }

    if (maxi < 0) maxi = 0;

    return maxi;
}