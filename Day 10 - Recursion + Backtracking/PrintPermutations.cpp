#include <bits/stdc++.h>

// Function to find all permutations of a given string 's'
void permutations(string &s, string &ds, vector<string> &ans, int freq[]) {
    // Base case: If the current permutation 'ds' has the same size as 's',
    // add it to the result 'ans' and return
    if (ds.size() == s.size()) {
        ans.push_back(ds);
        return;
    }

    // Try all characters of 's' to form the permutations
    for (int i = 0; i < s.size(); i++) {
        // If the character at index 'i' of 's' has not been used in the current permutation
        if (!freq[i]) {
            // Choose the character and add it to the current permutation 'ds'
            ds.push_back(s[i]);

            // Mark the character at index 'i' as used in the frequency array 'freq'
            freq[i] = 1;

            // Recursively call permutations function to find permutations with the updated 'ds'
            permutations(s, ds, ans, freq);

            // Backtrack: Remove the last added character to explore other possibilities
            ds.pop_back();

            // Mark the character at index 'i' as unused in the frequency array 'freq'
            freq[i] = 0;
        }
    }
}

// Function to find all permutations of a given string 's'
vector<string> findPermutations(string &s) {
    string ds; // Empty string to store the current permutation
    vector<string> ans; // Vector to store all permutations
    int freq[s.size()]; // Frequency array to keep track of characters used in each permutation

    // Initialize the frequency array to 0 for all characters
    for (int i = 0; i < s.size(); i++)
        freq[i] = 0;

    // Call the permutations function to find all permutations of the string 's'
    permutations(s, ds, ans, freq);

    return ans; // Return the vector containing all permutations
}
