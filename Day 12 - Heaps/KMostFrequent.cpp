#include <bits/stdc++.h> 

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> ans;
    map<int, int> m;

    // Step 1: Count the frequency of each element
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    priority_queue<pair<int, int>> pq;

    // Step 2: Create a max-heap (priority_queue) of pairs (frequency, element)
    for (auto i : m)
    {
        pq.push({i.second, i.first});
    }

    // Step 3: Extract the top k frequent elements from the max-heap
    for (int i = 1; i <= k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    // Step 4: Sort the result in ascending order
    sort(ans.begin(), ans.end());

    return ans;
}
