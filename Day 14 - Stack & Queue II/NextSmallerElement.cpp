#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Approach using stack:

    stack<int> st;
    st.push(-1); // Initialize stack with -1

    vector<int> ans(n);

    // Traverse the array from back
    for (int i = n-1; i >= 0; i--) {
        int curr = arr[i]; // Current element

        // Pop elements from stack until we find an element smaller than the current element
        while (st.top() >= curr) {
            st.pop();
        }

        // Store the next smaller element in the result vector
        ans[i] = st.top();
        
        // Push the current element into the stack
        st.push(curr); 
    }

    return ans;
}
