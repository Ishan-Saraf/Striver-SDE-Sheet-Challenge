#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s - 1; i++) {
            BinaryTreeNode<int> *x = q.front();
            q.pop();

            // Connect the current node to the node that appears next in the queue.
            x->next = q.front();

            // Add the left and right children of the current node to the queue.
            if (x->left) q.push(x->left);
            if (x->right) q.push(x->right);
        }

        // Handle the last node in the current level.
        BinaryTreeNode<int> *y = q.front();
        q.pop();

        // Add the left and right children of the last node to the queue for the next level.
        if (y->left) q.push(y->left);
        if (y->right) q.push(y->right);
    }
}
