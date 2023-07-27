#include<bits/stdc++.h>
/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

// Recursive helper function to check if the left subtree of a node is a mirror image of its right subtree.
bool solve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Base case: If both nodes are NULL, they are considered symmetric.
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // Base case: If either node is NULL (but not both), they are not symmetric.
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check if the data at the nodes is equal.
    if (root1->data != root2->data) {
        return false;
    }

    // Recursively check if the left subtree of root1 is a mirror image of the right subtree of root2,
    // and if the right subtree of root1 is a mirror image of the left subtree of root2.
    return solve(root1->left, root2->right) && solve(root1->right, root2->left);
}

// Function to check if the binary tree is symmetric.
bool isSymmetric(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return true; // An empty tree is considered symmetric.
    }

    // Call the recursive helper function to check if the left and right subtrees are mirror images of each other.
    return solve(root->left, root->right);
}
