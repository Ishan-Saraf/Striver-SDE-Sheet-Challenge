#include<bits/stdc++.h>

// Function to find the k-th permutation of integers from 1 to 'n'
string kthPermutation(int n, int k) {
    int fact = 1; // Initialize factorial to 1

    vector<int> numbers; // Vector to store the numbers from 1 to 'n'

    // Calculate factorial of 'n' and populate the 'numbers' vector
    for (int i = 1; i < n; i++) {
        fact = fact * i; // Calculate factorial for each i from 1 to (n-1)
        numbers.push_back(i); // Populate the vector with integers from 1 to (n-1)
    }

    numbers.push_back(n); // Add 'n' to the 'numbers' vector

    string ans = ""; // Initialize the result string

    k = k - 1; // Adjust k to work with 0-based indexing

    // Find the k-th permutation
    while (true) {
        ans = ans + to_string(numbers[k / fact]); // Add the selected number to the result string
        numbers.erase(numbers.begin() + k / fact); // Remove the selected number from the vector

        if (numbers.size() == 0) {
            break; // If all numbers have been used, break the loop
        }

        k = k % fact; // Update k for the next iteration
        fact = fact / numbers.size(); // Update factorial for the next iteration
    }

    return ans; // Return the k-th permutation as a string
}
