#include<bits/stdc++.h>

int singleNonDuplicate(vector<int>& arr)
{
	/*
	// Brute forcing:
	unordered_map<int, int> m;

	for (int i=0; i<arr.size(); i++) {
		m[arr[i]]++;
	}

	for (auto it: m) {
		if (it.second == 1) return it.first;
	}
	*/

	// Approach 2: Binary Search

    int lo = 0;
    int hi = arr.size()-2;

    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;

        if (arr[m] == arr[m ^ 1]) {
            // If the current element is equal to its adjacent element, the single non-duplicate element is on the right side.
            lo = m + 1;
        }
        else {
            // If the current element is not equal to its adjacent element, the single non-duplicate element is on the left side.
            hi = m - 1;
        }
    }

    return arr[lo];
}