#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n) {
    /*
    // Approach 1:
    long water = 0;

    for (int i = 1; i < n - 1; i++) {
        long lmax = 0;
        long rmax = 0;

        // Find the maximum arr on the left side of the current element
        for (int j = 0; j < i; j++) {
            lmax = max(lmax, arr[j]);
        }

        // Find the maximum arr on the right side of the current element
        for (int j = i + 1; j < n; j++) {
            rmax = max(rmax, arr[j]);
        }

        // Calculate the trapped water for the current element
        long currentWater = min(lmax, rmax) - arr[i];
        
        if (currentWater > 0) {
            water += currentWater;
        }
    }

    return water;

    // Approach 2: use hash arrays to get the max vals instead of loops
    // (same can also be achieved using stack);

    */

    // Approach 3: (2ptr)

    int left = 0;
    int right = n - 1;

    long res = 0;
    long maxLeft = 0, maxRight = 0;

    while (left <= right) {
        // If the height at the left pointer is smaller or equal
        if (arr[left] <= arr[right]) {

            if (arr[left] >= maxLeft) {
                // Update the maximum height encountered so far on the left
                maxLeft = arr[left];
            }
            
            else {
                // Calculate the trapped water at the current position
                res += maxLeft - arr[left];
            }

            left++;
        }
        
        else {
            // If the height at the right pointer is smaller
            if (arr[right] >= maxRight) {
                // Update the maximum height encountered so far on the right
                maxRight = arr[right];
            }
            
            else {
                // Calculate the trapped water at the current position
                res += maxRight - arr[right];
            }
            right--;
        }
    }

    return res;
}