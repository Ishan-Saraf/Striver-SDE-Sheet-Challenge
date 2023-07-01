#include <bits/stdc++.h> 

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    // Approach: using deque:

    deque<int> dq; // Deque to store the indices of elements in the current window
    vector<int> ans; // Vector to store the maximum elements for each window

    for (int i=0; i<nums.size(); i++) {
        if (!dq.empty() && dq.front() == i-k) {
            dq.pop_front(); // Remove the index that is outside the current window
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back(); // Remove indices of elements that are smaller than or equal to the current element
        }

        dq.push_back(i); // Add the current index to the deque

        if (i >= k-1) {
            ans.push_back(nums[dq.front()]); // If the window is of size k, add the maximum element in the window to the result vector
        }
    }

    return ans; // Return the vector containing the maximum elements for each window
}
