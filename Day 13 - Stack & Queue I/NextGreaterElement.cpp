#include<bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n) {
    
    // Approach using stack:
    
    stack<int> st;
    vector<int> ans(n, 0);
    
    // Start moving from the back of the array:
    for (int i = 0; i < n; i++) {

        // Pop elements smaller than or equal to the current element
        while (!st.empty() && st.top() <= arr[n - i - 1]) {
            st.pop();
        }

        if (!st.empty()) {

            // Set the next greater element from the stack
            ans[n - i - 1] = st.top();
        }
        
        else {

            // No greater element found, assign -1
            ans[n - i - 1] = -1;
        }

        // Push the current element to the stack for comparison
        st.push(arr[n - i - 1]);
    }

    return ans;
}
