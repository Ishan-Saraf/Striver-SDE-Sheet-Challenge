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

// Function to perform zigzag traversal on a binary tree.
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    // If the tree is empty, return an empty vector.
    if (root == NULL) {
        return ans;
    }

    bool leftToRight = true; // Flag to indicate the direction of traversal.

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        // Process each level:
        int size = q.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int> *frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            temp[index] = frontNode->data;

            // Add the left and right children to the queue for the next level.
            if (frontNode->left) {
                q.push(frontNode->left);
            }

            if (frontNode->right) {
                q.push(frontNode->right);
            }
        }

        // Add the elements of the current level in the required order to the answer vector.
        for (auto i : temp) {
            ans.push_back(i);
        }

        // Change the direction for the next level.
        leftToRight = !leftToRight;
    }

    return ans;
}
