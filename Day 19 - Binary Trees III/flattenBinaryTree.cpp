#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

// Helper function to flatten the binary tree to a right-skewed linked list.
void flatten(TreeNode<int> *root, TreeNode<int>* &prev) {
    if (root == NULL) return;

    // Flatten the right subtree first.
    flatten(root->right, prev);

    // Flatten the left subtree.
    flatten(root->left, prev);

    // Connect the current root to the previous node (prev) in the right-skewed linked list.
    root->right = prev;

    // Make the left child NULL to form the right-skewed linked list.
    root->left = NULL;

    // Update the previous node to the current root for the next iteration.
    prev = root;
}

// Function to flatten a binary tree to a right-skewed linked list.
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
    // Initialize a pointer to keep track of the previous node during the flattening process.
    TreeNode<int>* prev = NULL;

    // Call the recursive function to flatten the binary tree in place.
    flatten(root, prev);

    // The root of the right-skewed linked list is the last node in the traversal.
    return root;
}
