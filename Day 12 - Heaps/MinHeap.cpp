#include <bits/stdc++.h>

// Function to perform operations on a min heap
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap; // Vector to store the elements of the min heap
    vector<int> temp; // Temporary vector to store elements for insert operation

    auto element = temp.begin(); // Iterator to track the minimum element in the temp vector
    
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0) // Insert operation
        {
            temp.push_back(q[i][1]); // Add the element to the temp vector
            element = min_element(temp.begin(),temp.end()); // Find the minimum element in the temp vector
        }
        else // Extract-min operation
        {
            heap.push_back(*element); // Add the minimum element to the heap vector
            temp.erase(element); // Remove the minimum element from the temp vector
        }
    }

    return heap; // Return the min heap vector
}
