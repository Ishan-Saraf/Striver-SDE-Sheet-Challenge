#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

void rec(TreeNode<int>* root, int& k, int& cnt, int& ans) {
    if (root == NULL) return; // Base case: If the current node is NULL, return.

    rec(root->right, k, cnt, ans); // Recur on the right subtree.

    cnt++; // Increment the count of visited nodes.

    if (cnt == k) // If the current count matches the kth element.
        ans = root->data; // Update the 'ans' with the value of the kth largest element.

    rec(root->left, k, cnt, ans); // Recur on the left subtree.
}

int KthLargestNumber(TreeNode<int>* root, int k) {
    int ans = -1; // Initialize 'ans' to store the kth largest element.
    int cnt = 0; // Initialize 'cnt' to store the count of visited nodes.
    rec(root, k, cnt, ans); // Perform the in-order traversal to find the kth largest element.
    return ans; // Return the kth largest element.
}

