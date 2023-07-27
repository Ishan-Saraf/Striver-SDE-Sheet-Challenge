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

// Helper function to perform inorder traversal of the binary tree
void inorder(TreeNode *root, vector<int> &ans) {
    // base case: if the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Recursively traverse the left subtree
    inorder(root->left, ans);

    // Add the current node's data to the answer vector
    ans.push_back(root->data);

    // Recursively traverse the right subtree
    inorder(root->right, ans);
}

// Function to get the inorder traversal of the binary tree
vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> ans;
    inorder(root, ans); // Call the helper function to perform inorder traversal
    return ans; // Return the vector containing the inorder traversal of the binary tree
}
