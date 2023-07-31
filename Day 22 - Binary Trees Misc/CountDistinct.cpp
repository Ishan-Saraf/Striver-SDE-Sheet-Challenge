#include <bits/stdc++.h> 

vector<int> countDistinctElements(vector<int> &arr, int k) {
    vector<int> distinctCount; // Vector to store the count of distinct elements in the sliding window
    map<int, int> mpp; // Map to store the frequency of elements in the sliding window

    for (int i = 0; i < arr.size(); i++) {
        mpp[arr[i]]++; // Increment the count of the current element in the map

        if (i >= k) {
            // If the window size becomes greater than k, remove the first element from the window
            // Reduce its frequency in the map, and if its frequency becomes 0, remove it from the map
            if (--mpp[arr[i - k]] == 0) {
                mpp.erase(arr[i - k]);
            }
        }

        if (i >= k - 1) {
            // If the window size becomes equal to k or larger, calculate the count of distinct elements
            // in the current window and store it in the distinctCount vector
            distinctCount.push_back(mpp.size());
        }
    }

    return distinctCount;
}

