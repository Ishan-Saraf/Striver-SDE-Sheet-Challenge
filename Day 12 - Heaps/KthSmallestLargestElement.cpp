#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	/*
	// Approach 1: using sorting:
	sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
	*/

	// Approach 2: using Heaps:
	
	// Create a minHeap and maxHeap using priority_queue
	priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
	priority_queue<int, vector<int>> maxHeap(nums.begin(), nums.end());

	// Remove the top k-1 elements from both heaps
	for(int i=0; i<k-1; i++)
	{
		minHeap.pop();
		maxHeap.pop();
	}

	// The top element of minHeap is the k-th smallest element
	// The top element of maxHeap is the k-th largest element
	return {minHeap.top(), maxHeap.top()};
}
