#include <bits/stdc++.h> 

// Using a modified version of mergeSort() to solve this problem:
int Merge(vector <int> & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;

  // increasing count when the condition is satisfied:
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}

int MergeSort(vector <int> & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}

int reversePairs(vector<int> &arr, int n){
	/*
	Approach 1:
		find all possible pairs and return count of those who satisfy
		TC: O(n2), SC: O(1)

	*/

	// Approach 2: using modified mergesort():

	return MergeSort(arr, 0, n-1);
}