#include <bits/stdc++.h>

// Creating a data structure to store the information of the array of arrays:
class Node {
public:
    int data;
    int i;
    int j;

    Node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class Compare {
public:
    bool operator()(const Node* a, const Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k)
{
    /*
    // Approach 1: (Brute force)
    vector<int> ans;
    for (auto i: kArrays) {
        ans.insert(ans.end(), i.begin(), i.end());
    }
    sort(ans.begin(), ans.end());
    return ans;
    */

    // Approach 2:

    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    vector<int> ans;

    // Step 1: Compare the first element of each array
    for (int i = 0; i < k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    // Step 2: Merge the arrays
    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp->data);

        int row = temp->i;
        int col = temp->j;

        // If there are more elements in the current row
        if (col + 1 < kArrays[row].size()) {
            Node* next = new Node(kArrays[row][col + 1], row, col + 1);
            minHeap.push(next);
        }
    }

    return ans;
}
