#include<bits/stdc++.h>

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

// Function to get the top view of the binary tree
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans; // Initialize an empty vector to store the top view elements

    // If the root is NULL (i.e., the binary tree is empty), return the empty answer vector
    if (root == NULL) {
        return ans;
    }

    // Create a map to store the top view elements with their corresponding line number
    map<int, int> mpp;

    // Create a queue to perform level-order traversal of the binary tree
    queue<pair<TreeNode<int>*, int>> q;

    // Push the root node along with its line number (0) into the queue
    q.push({root, 0});

    // Perform level-order traversal until the queue is empty
    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode<int>* node = it.first; // Current node
        int line = it.second; // Line number of the current node

        // If the line number is not present in the map, add the current node's value to the map
        if (mpp.find(line) == mpp.end()) {
            mpp[line] = node->val;
        }

        // Enqueue the left child of the current node along with its line number (line-1)
        if (node->left != NULL) {
            q.push({node->left, line-1});
        }

        // Enqueue the right child of the current node along with its line number (line+1)
        if (node->right != NULL) {
            q.push({node->right, line+1});
        }
    }

    // Traverse the map and add the values to the answer vector in sorted order of line numbers
    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans; // Return the vector containing the top view elements of the binary tree
}
