#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Approach: solving using stack:

    vector<int> ans;
    stack<int> s;
    
    s.push(-1);

    for (int i=0; i<price.size(); i++) {
        while (s.top() != -1 && price[s.top()] <= price[i]) {
            s.pop();
        }

        if (s.top() == -1) {
            ans.push_back(i+1);
        }

        else {
            ans.push_back(i - s.top());
        }

        s.push(i);
    }

    return ans;
}