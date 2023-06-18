#include <bits/stdc++.h> 
int romanToInt(string s) {
    unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int n = s.length();
    int prevValue = 0;

    // Traverse the string from right to left
    for (int i = n - 1; i >= 0; i--) {
        int currentValue = romanValues[s[i]];

        // If the current value is smaller than the previous value,
        // subtract it from the result
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        // Update the previous
        prevValue = currentValue;
    }

    return result;
}
