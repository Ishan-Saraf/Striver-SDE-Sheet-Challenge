#include <bits/stdc++.h>

// Helper function to find all possible word break combinations
void fun(vector<string>& ans, int mx, string w, unordered_set<string>& s, string str) {
    if (w.size() == 0 && str.size() > 0) {
        ans.push_back(str); // If the input string is empty and 'str' is not empty, add 'str' to the answer vector
        return;
    } else {
        int N = w.size();
        string str1 = "";

        for (int i = 0; i < N; i++) {
            str1 += w[i];
            if (str1.size() > mx) break; // Optimization: If the length of 'str1' exceeds the maximum word length 'mx', break the loop
            if (s.count(str1)) {
                // If 'str1' is a valid word (present in the dictionary 's')
                string new_str = (str == "") ? str1 : str + " " + str1; // Append 'str1' to 'str' to form a new string 'new_str'
                fun(ans, mx, w.substr(i + 1), s, new_str); // Recursively call 'fun' with the remaining part of the string 'w' and the updated 'new_str'
            }
        }
    }
}

vector<string> wordBreak(string& w, vector<string>& dict) {
    // Write your code here
    unordered_set<string> st;
    int n = dict.size();
    int mx = INT_MIN;

    // Insert all words from the dictionary into the unordered_set 'st'
    for (int i = 0; i < n; i++) {
        st.insert(dict[i]);
        int siz = dict[i].size();
        mx = max(mx, siz); // Calculate the maximum word length in the dictionary
    }

    vector<string> ans;
    fun(ans, mx, w, st, ""); // Call the helper function 'fun' to find all word break combinations

    return ans; // Return the vector containing all possible word break combinations
}
