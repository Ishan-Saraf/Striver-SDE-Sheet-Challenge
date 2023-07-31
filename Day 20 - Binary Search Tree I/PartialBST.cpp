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
bool help(BinaryTreeNode<int> *root, int l, int u) {
  // Base case: If the subtree is empty, it is a BST.
  if (root == nullptr) {
    return true;
  }

  // Check if the value of the root is within the bounds of the subtree.
  if (root->data > u || root->data < l) {
    return false;
  }

  // Recursively check if the left and right subtrees are BSTs.
  return help(root->right, root->data, u) && help(root->left, l, root->data);
}

bool validateBST(BinaryTreeNode<int> *root) {
  // The lower bound of the subtree is `INT_MIN` and the upper bound is `INT_MAX`.
  return help(root, INT_MIN, INT_MAX);
}