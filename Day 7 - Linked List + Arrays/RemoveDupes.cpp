#include<bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n) {
	// arr.erase(unique(arr.begin(), arr.end()), arr.end());
	// return arr.size();

	// Approach 1: using set<int> : TC: O(nlogn) + O(n), SC: O(n)

	// Approach 2: 2 pointer:

	int i=0;
	int j=1;

	for (j=1; j<arr.size(); j++) {
		if (arr[j] != arr[i]) {
			arr[i+1] = arr[j]; // shifting uniques to front;
			i++;
		}
	}

	arr.erase(arr.begin()+i, arr.begin()+j); // delete dupes from back;

	return arr.size()+1;
}