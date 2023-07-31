#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store the K largest elements

    for (auto ele : arr) {
        pq.push(ele); // Add each element to the min-heap

        if (pq.size() > K) {
            pq.pop(); // If the size of the min-heap becomes greater than K, remove the smallest element
        }
    }

    return pq.top(); // The top of the min-heap will be the Kth largest element
}
