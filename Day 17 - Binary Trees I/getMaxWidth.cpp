#include<bits/stdc++.h>
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

// Function to calculate the maximum width of a binary tree
int getMaxWidth(TreeNode<int> *root)
{
    // If the tree is empty, the maximum width is 0
    if (root == NULL)
        return 0;

    // Create a queue for level order traversal
    queue<TreeNode<int>*> q;
    q.push(root);

    // Initialize the maximum width as 1 (for the root node)
    int maxWidth = 1;

    // Perform level order traversal
    while (!q.empty())
    {
        // Get the current size of the queue (number of nodes at the current level)
        int size = q.size();

        // Update the maximum width with the maximum of the current width and the number of nodes at the current level
        maxWidth = max(maxWidth, size);

        // Process all nodes at the current level
        while (size--)
        {
            // Dequeue the front node
            auto frontNode = q.front();
            q.pop();

            // Enqueue the left child (if exists)
            if (frontNode->left)
                q.push(frontNode->left);

            // Enqueue the right child (if exists)
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }

    // Return the calculated maximum width of the binary tree
    return maxWidth;
}
