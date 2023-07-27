#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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

***********************************************************/

// Function to check if two binary trees rooted at root1 and root2 are identical.
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // If both trees are empty, they are identical.
    if (!root1 && !root2)
        return true;
    
    // If one of the trees is empty while the other is not, they are not identical.
    if (root1 && !root2 || root2 && !root1)
        return false;

    // Check if the data of the current nodes is the same.
    if (root1->data != root2->data)
        return false;

    // Recursively check the left and right subtrees for identity.
    return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}
