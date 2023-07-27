#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

// Helper function to perform postorder traversal of the binary tree
void postorder(TreeNode *root, vector<int> &ans) {
    // base case: if the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Recursively traverse the left subtree
    postorder(root->left, ans);

    // Recursively traverse the right subtree
    postorder(root->right, ans);

    // Add the current node's data to the answer vector
    ans.push_back(root->data);
}

// Function to get the postorder traversal of the binary tree
vector<int> getPostOrderTraversal(TreeNode *root) {
    vector<int> ans;
    postorder(root, ans); // Call the helper function to perform postorder traversal
    return ans; // Return the vector containing the postorder traversal of the binary tree
}
