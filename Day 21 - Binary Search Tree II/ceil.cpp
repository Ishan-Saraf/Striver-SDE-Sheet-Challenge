#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x) {
    // Initialize 'ans' to -1, which will store the ceil value.
    int ans = -1;

    // Loop until the current node is not NULL.
    while (node) {
        // If the value of the current node is less than 'x',
        // it means the ceil value lies in the right subtree of the current node.
        if (node->data < x) {
            // Move to the right child to search for the ceil value.
            node = node->right;
        } else {
            // If the value of the current node is greater than or equal to 'x',
            // it means the ceil value lies in the left subtree of the current node.
            // Update 'ans' to the current node's value (the smallest value >= x found so far).
            ans = node->data;
            // Move to the left child to continue searching for the ceil value.
            node = node->left;
        }
    }

    // Finally, return the computed ceil value stored in 'ans'.
    return ans;
}
