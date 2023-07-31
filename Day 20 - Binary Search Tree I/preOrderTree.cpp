#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* help(vector<int> &pre, int &i, int bound) {
    // Base case: If the index i is out of bounds or the current value in pre-order
    // is greater than or equal to the bound, return NULL.
    if (i >= pre.size() || pre[i] >= bound) return NULL;

    // Create a new TreeNode with the value at index i in the pre-order vector.
    TreeNode<int>* root = new TreeNode<int>(pre[i++]);

    // Recursively construct the left subtree with the bound being the value of the current root.
    root->left = help(pre, i, root->data);

    // Recursively construct the right subtree with the same bound as the parent.
    root->right = help(pre, i, bound);

    // Return the root of the constructed BST.
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &pre) {
    // Initialize the index i to 0, starting from the first element of the pre-order vector.
    int i = 0;

    // Call the recursive helper function 'help' to construct the BST from the pre-order vector.
    // The initial bound for the entire BST is INT_MAX.
    return help(pre, i, INT_MAX);
}
