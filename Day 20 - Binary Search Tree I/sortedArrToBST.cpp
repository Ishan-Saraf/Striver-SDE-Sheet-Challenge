#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

TreeNode<int>* sbt(vector<int>& arr, int s, int e) {
    // Base case: If the start index is greater than the end index, return NULL.
    if (s > e) return NULL;

    // Calculate the mid index.
    int mid = (s + e) / 2;

    // Create a new TreeNode with the data at the mid index.
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    // Recursively construct the left and right subtrees.
    root->left = sbt(arr, s, mid - 1);
    root->right = sbt(arr, mid + 1, e);

    // Return the root of the constructed BST.
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) {
    // Call the recursive function 'sbt' to construct the BST from the sorted array.
    TreeNode<int>* root = sbt(arr, 0, n - 1);

    // Return the root of the constructed BST.
    return root;
}
