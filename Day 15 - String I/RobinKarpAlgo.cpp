#include <bits/stdc++.h>

vector<int> stringMatch(string str, string pat) {
    vector<int> ans;

    // Robin Karp Algorithm
    int n = str.length();
    int m = pat.length();

    // Calculating the hash values
	
    int q = INT_MAX; // A large prime number
    int hP = 0; // Hash value of the pattern
    int hS = 0; // Hash value of the current substring in 'str'
    int h = (int) pow(256, m - 1); // Value of h for the first character

    // Calculate the initial hash values for pattern and the first substring
    for (int i = 0; i < m; i++) {
        hP = (hP * 256 + pat[i]) % q;
        hS = (hS * 256 + str[i]) % q;
    }

    // Check each substring of 'str' for a match with the pattern
    for (int i = 0; i <= n - m; i++) {
        // If the hash values match, perform a character-by-character comparison
        if (hP == hS) {
            int j = 0;
            while (j < m && str[i + j] == pat[j]) {
                j++;
            }
            if (j == m) {
                ans.push_back(i+1); // Add the starting index of the matching substring to the result
            }
        }

        // Calculate the hash value for the next substring
        if (i < n - m) {
            hS = (256 * (hS - str[i] * h) + str[i + m]) % q;
            if (hS < 0) {
                hS += q; // Ensure the hash value is positive
            }
        }
    }

    return ans;
}