#include <bits/stdc++.h> 

vector<int> maxMinWindow(vector<int> a, int n) {
    
    /* 
        Approach 1:
            1. find all the possible subarrays
            2. for every window traverse and get the maximum from it

        Time Complexity : O(n^3)
    */

    // Approach 2: using stack:

    stack<int> s; // Stack to store the indices of elements
    vector<int> left(n); // Vector to store the left boundary index of each element
    vector<int> right(n); // Vector to store the right boundary index of each element
    vector<int> ans(n, INT_MIN); // Vector to store the maximum elements in each window

    left[0] = -1; // Set the left boundary of the first element as -1

    s.push(0); // Push the index of the first element into the stack

    // Calculate the left boundary for each element
    for (int i=1; i<n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop(); // Remove indices of elements that are greater than or equal to the current element
        }

        left[i] = s.empty() ? -1 : s.top(); // Store the left boundary index for the current element

        s.push(i); // Push the index of the current element into the stack
    }

    while (!s.empty()) {
        s.pop(); // Clear the stack
    }

    right[n-1] = n; // Set the right boundary of the last element as n

    s.push(n-1); // Push the index of the last element into the stack

    // Calculate the right boundary for each element
    for (int i=n-2; i>=0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop(); // Remove indices of elements that are greater than or equal to the current element
        }

        right[i] = s.empty() ? n : s.top(); // Store the right boundary index for the current element

        s.push(i); // Push the index of the current element into the stack
    }

    // Calculate the maximum elements in each window
    for (int i=0; i<n; i++) {
        int len = right[i] - left[i] - 1; // Calculate the length of the current window
        ans[len-1] = max(ans[len-1], a[i]); // Update the maximum element for the current window
    }

    // Update the maximum elements for smaller window sizes
    for (int i=n-2; i>=0; i--) {
        ans[i] = max(ans[i], ans[i+1]); // Take the maximum between the current maximum and the maximum of the next window size
    }

    return ans; // Return the vector containing the maximum elements for each window
}
