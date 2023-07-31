#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> ans; // Vector to store the medians at each step

    // Two heaps to maintain the elements larger and smaller than the current median
    priority_queue<int> maxheap; // Max heap for the left half of the elements
    priority_queue<int, vector<int>, greater<int>> minheap; // Min heap for the right half of the elements

    for (int i = 0; i < n; i++) {
        if (i == 0)
            maxheap.push(arr[i]); // For the first element, simply add it to the max heap
        else if (arr[i] < maxheap.top())
            maxheap.push(arr[i]); // If the current element is smaller than the top element of max heap, add it to max heap
        else
            minheap.push(arr[i]); // Otherwise, add it to min heap

        // Balancing the heaps such that the difference in their sizes is at most 1
        if ((i + 1) % 2 == 0) {
            if (maxheap.size() > minheap.size()) {
                minheap.push(maxheap.top());
                maxheap.pop();
            } else if (minheap.size() > maxheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }

            // Calculate and add the median to the answer vector
            ans.push_back((minheap.top() + maxheap.top()) / 2);
        } else {
            if (maxheap.size() < minheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }

            // For an odd number of elements, median is the top element of max heap
            ans.push_back(maxheap.top());
        }
    }
    return ans; // Return the vector containing medians at each step
}
