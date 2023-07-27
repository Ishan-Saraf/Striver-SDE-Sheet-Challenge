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

// Helper function to perform preorder traversal of the binary tree
void preorder(TreeNode *root, vector<int> &ans) {
    // base case: if the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Add the current node's data to the answer vector
    ans.push_back(root->data);

    // Recursively traverse the left subtree
    preorder(root->left, ans);

    // Recursively traverse the right subtree
    preorder(root->right, ans);
}

// Function to get the preorder traversal of the binary tree
vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> ans;
    preorder(root, ans); // Call the helper function to perform preorder traversal
    return ans; // Return the vector containing the preorder traversal of the binary tree
}
