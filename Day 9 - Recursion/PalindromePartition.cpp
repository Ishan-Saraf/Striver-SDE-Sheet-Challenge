#include <bits/stdc++.h>

// Function to check if a substring from 'start' to 'end' is a palindrome
bool isPalin(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--]) return false;
    }

    return true;
}

// Recursive function to find all possible palindrome partitionings
void solve(int idx, string s, vector<string> &path, vector<vector<string>> &ans) {
    // Base case: If the index 'idx' reaches the end of the string, add the current partition 'path' to the result 'ans'
    if (idx == s.length()) {
        ans.push_back(path);
        return;
    }

    // Loop through the string from the current index 'idx' to the end
    for (int i = idx; i < s.length(); i++) {
        // Check if the substring from 'idx' to 'i' is a palindrome
        if (isPalin(s, idx, i)) {
            // If it is a palindrome, add the substring to the current partition 'path'
            path.push_back(s.substr(idx, i - idx + 1));

            // Recursively call the function for the remaining part of the string
            solve(i + 1, s, path, ans);

            // Backtrack: Remove the last added substring from 'path' to explore other partitions
            path.pop_back();
        }
    }
}

// Function to find all possible palindrome partitionings of the input string 's'
vector<vector<string>> partition(string &s) {
    vector<vector<string>> ans;

    vector<string> path;

    // Start the recursion from index 0 and an empty partition 'path'
    solve(0, s, path, ans);

    // Return the 2D vector containing all possible palindrome partitionings of 's'
    return ans;
}
