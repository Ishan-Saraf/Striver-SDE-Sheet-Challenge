#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // If the root is NULL, the value 'x' does not exist in the BST.
    if (root == NULL) return false;

    // If the root's data is equal to 'x', the value 'x' is found in the BST.
    if (root->data == x) return true;

    // If 'x' is greater than the root's data, search in the right subtree.
    if (root->data < x) return searchInBST(root->right, x);

    // If 'x' is smaller than the root's data, search in the left subtree.
    return searchInBST(root->left, x);
}
