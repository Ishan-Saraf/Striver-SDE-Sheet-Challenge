#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
public:
    stack<int> st;

    // Recursive function to perform in-order traversal and push elements into the stack.
    void inorder(TreeNode<int>* root)
    {
        if (root == NULL)
            return;

        inorder(root->right); // Recur on the right subtree.
        st.push(root->data); // Push the current node's value into the stack.
        inorder(root->left); // Recur on the left subtree.
    }

    // Constructor of the iterator class that initializes the stack by performing in-order traversal.
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root); // Call the 'inorder' function to populate the stack.
    }

    // Function to get the next element in the BST.
    int next()
    {
        if (st.empty())
            return -1; // If the stack is empty, there are no more elements to iterate, return -1.

        int z = st.top(); // Get the top element of the stack (current smallest element in BST).
        st.pop(); // Pop the top element to move to the next smallest element.
        return z; // Return the current smallest element.
    }

    // Function to check if there are more elements in the BST to iterate.
    bool hasNext()
    {
        return !st.empty(); // Return true if the stack is not empty (there are more elements to iterate), false otherwise.
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/