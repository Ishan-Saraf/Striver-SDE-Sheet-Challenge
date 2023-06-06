#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// initilize left & right pointer:
	int left = 0;
	int right =0;

	vector<int> ans;

	// inserting smaller of two arrays:
	while (left<m && right<n) {
		if (arr1[left] <= arr2[right]) {
			ans.push_back(arr1[left++]);
		}
		else {
			ans.push_back(arr2[right++]);

		}
	}

	// inserting the remaining elements:
	while (left<m) {
		ans.push_back(arr1[left++]);
	}

	while (right<n) {
		ans.push_back(arr2[right++]);
	}

	return ans;
}