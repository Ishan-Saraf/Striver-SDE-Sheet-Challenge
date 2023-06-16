#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	/*
	Approach 1:
		find all possible pairs using 3 loops
		add those triplet in ans whose sum is equal to K

	vector<vector<int>> ans;

	set<vector<int>> st;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int sum = 0;
			for (int k=j+1; k<n; k++) {
				if (arr[i]+arr[j]+arr[k] == K) {
					vector<int> temp = {arr[i], arr[j], arr[k]};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
			}
		}
	}

	ans.insert(ans.end(), st.begin(), st.end());

	return ans;

	// Approach 2: using a hashset:

	vector<vector<int>> ans;

	set<vector<int>> st;

	for (int i=0; i<n; i++) {
		set<int> hashset;
		for (int j=i+1; j<n; j++) {
			int target = K-arr[i]-arr[j];
			if (hashset.find(target) != hashset.end()) {
				vector<int> temp = {arr[i], arr[j], target};
				sort(temp.begin(), temp.end());
				st.insert(temp);
			}
			
			hashset.insert(arr[j]);
		}
	}

	ans.insert(ans.end(), st.begin(), st.end());

	return ans;

	*/

	// Approach 3: (2 pointer approach)
	sort(arr.begin(), arr.end());

	vector<vector<int>> ans;

	for (int i=0; i<n; i++) {
		// same element, move pointer:
		if (i>0 && arr[i] == arr[i-1]) continue;

		int j = i+1;
		int k = n-1;

		while (j < k) {

			if (arr[i] + arr[j] + arr[k] == K) {
				ans.push_back({arr[i], arr[j], arr[k]});

				// update pointers
				j++;
				k--;

				// same element, move pointer:
				while (j<k && arr[j] == arr[j-1]) j++;
				while (j<k && arr[k] == arr[k+1]) k++;
			}

			else if (arr[i] + arr[j] + arr[k] < K) {
				j++;
			}

			else {
				k--;
			}
		}
	}

	return ans;
}