#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    // Step 1: Create two priority queues, one max-heap and one min-heap
    std::priority_queue<int> maxh; // max-heap to store the smaller half of elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minh; // min-heap to store the larger half of elements

    // Step 2: Iterate through the array
    for(int i = 0; i < n; i++)
    {
        // Step 3: Insert the current element into the appropriate heap
        if(maxh.empty() || maxh.top() >= arr[i])
            maxh.push(arr[i]);
        else
            minh.push(arr[i]);

        // Step 4: Balance the heaps by moving elements between them
        if(maxh.size() > minh.size() + 1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size() < minh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }

        // Step 5: Calculate and print the median
        if(minh.size() < maxh.size())
            std::cout << maxh.top() << " ";
        else
            std::cout << (minh.top() + maxh.top()) / 2 << " ";
    }
}
