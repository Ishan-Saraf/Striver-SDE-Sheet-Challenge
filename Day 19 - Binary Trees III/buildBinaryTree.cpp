#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode<int> class structure

    template <typename T>
    class TreeNode<int> {
       public:
        T data;
        TreeNode<int><T> *left;
        TreeNode<int><T> *right;

        TreeNode<int>(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

// Helper function to create a mapping from node value to its index in the inorder sequence.
void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[inorder[i]] = i;
    }
}

// Helper function to construct the binary tree recursively using inorder and preorder traversals.
TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
    // Base case: If the index exceeds the length of the preorder or inorder sequence, or the inorderStart becomes greater than inorderEnd, return NULL.
    if (index >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    // Take the current element from the preorder sequence.
    int element = preorder[index++];
    
    // Create a new TreeNode with the current element as data.
    TreeNode<int> *root = new TreeNode<int>(element);
    
    // Find the position (index) of the current element in the inorder sequence.
    int position = nodeToIndex[element];

    // Recursively construct the left and right subtrees.
    root->left = solve(inorder, preorder, index, inorderStart, position - 1, n, nodeToIndex);
    root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

// Function to build a binary tree from its inorder and preorder traversals.
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
    int n = preorder.size();
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    
    // Create a mapping from node value to its index in the inorder sequence.
    createMapping(inorder, nodeToIndex, n);
    
    // Call the recursive function to construct the binary tree.
    TreeNode<int> *ans = solve(inorder, preorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
    
    return ans;
}
