#include <algorithm>

class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap to store the k largest elements
public:
    // Constructor that initializes the min heap with the first k elements of the input array
    Kthlargest(int k, vector<int> &arr) {
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
    }

    // Function to add a new element to the stream and return the kth largest element
    int add(int num) {
        if (num > pq.top()) {
            pq.pop(); // Remove the smallest element (top) from the min heap
            pq.push(num); // Add the new element to the min heap
        }
        return pq.top(); // Return the current kth largest element (top of the min heap)
    }
};
