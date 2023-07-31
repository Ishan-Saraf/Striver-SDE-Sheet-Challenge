#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// Data structure to store the information of the node:
class node {
public:
    int size;
    int maxi;
    int mini;
    node(int s, int mx, int mn) {
        size = s;
        maxi = mx;
        mini = mn;
    } 
};

// Helper function to find the size of the largest BST in the binary tree rooted at 'root'.
node help(TreeNode<int>* root) {
    if (root == nullptr) {
        // If the node is null, return a node with size=0, and min and max values as INT_MIN and INT_MAX, respectively.
        node n(0, INT_MIN, INT_MAX);
        return n;
    }

    // Recursively call 'help' on the left and right subtrees.
    node l = help(root->left);
    node r = help(root->right);

    if (l.maxi < root->data && r.mini > root->data) {
        // If the left subtree's maximum value is less than the root's data,
        // and the right subtree's minimum value is greater than the root's data,
        // it forms a valid BST with 'root' as the root node.

        // Calculate the size of the BST formed by the current node 'root'.
        int s = l.size + r.size + 1;
        // Update the maximum value in the subtree rooted at 'root'.
        int mx = max(root->data, r.maxi);
        // Update the minimum value in the subtree rooted at 'root'.
        int mn = min(root->data, l.mini);

        // Return the node representing the valid BST formed by 'root'.
        node n(s, mx, mn);
        return n;
    }

    // If 'root' doesn't form a valid BST, return the node representing the larger subtree.
    return node(max(r.size, l.size), INT_MAX, INT_MIN);
}

// Function to find the size of the largest BST in a binary tree.
int largestBST(TreeNode<int>* root) {
    // Call the 'help' function to find the node representing the largest BST in the binary tree rooted at 'root'.
    node i = help(root);
    // Return the size of the largest BST.
    return i.size;
}

