#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

// Helper function to calculate the height of the binary tree rooted at 'root'.
// It returns the height of the tree rooted at 'root'.
int solve(BinaryTreeNode<int> *root) {
    // Base case: If the current node is NULL, the height is 0.
    if (root == NULL)
        return 0;

    // Recursively calculate the height of the left and right subtrees.
    int left = 1 + solve(root->left);
    int right = 1 + solve(root->right);

    // Return the maximum of the heights of the left and right subtrees, 
    // which gives the height of the current node.
    return max(left, right);
}

// Function to check if a binary tree is balanced or not.
bool isBalancedBT(BinaryTreeNode<int> *root) {
    // Base case: If the current node is NULL, it is balanced (height is 0).
    if (root == NULL)
        return true;

    int from_left = 0;
    int from_right = 0;

    // Calculate the heights of the left and right subtrees of the current node.
    if (root->left != NULL)
        from_left = solve(root->left);
    if (root->right != NULL)
        from_right = solve(root->right);

    // If the difference in heights of the left and right subtrees is greater than 1,
    // the tree is not balanced, so return false.
    if (abs(from_left - from_right) > 1)
        return false;

    // Otherwise, recursively check if both left and right subtrees are balanced.
    return isBalancedBT(root->left) && isBalancedBT(root->right);
}
