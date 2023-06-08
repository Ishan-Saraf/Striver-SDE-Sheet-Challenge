#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {

	/*
	// Approach 1: (hashing)

	unordered_map<int, int> m;

	for (int i=0; i<n; i++) {
		m[arr[i]]++;
	}

	for(auto i: m) {
		if (i.second > floor(n/2)) {
			return i.first;
		}
	}

	return -1;

	*/

	// Approach 2: (Moore's Voting algorithm):

	int cnt = 0;

	int el;

	for (int i=0; i<n; i++) {
		if (cnt == 0) {
			cnt = 1;
			el = arr[i];
		}

		else if (arr[i] == el) {
			cnt++;
		}

		else {
			cnt--;
		}
	}

	int cnt1 = 0;

	for (int i=0; i<n; i++) {
		if (arr[i]==el) {
			cnt1++;
		}
	}

	if (cnt1 > floor(n/2)) {
		return el;
	}

	return -1;
}