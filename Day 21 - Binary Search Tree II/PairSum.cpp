#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

bool solve(BinaryTreeNode<int> *root, unordered_set<int>& st, int k) {
    if (!root)
        return false; // Base case: If the current node is NULL, return false.

    int diff = k - root->data; // Calculate the difference between the target value 'k' and the current node's value.

    if (st.find(diff) != st.end()) {
        return true; // If the difference is present in the unordered_set, a pair of nodes with sum 'k' is found.
    }

    st.insert(root->data); // Insert the current node's value into the unordered_set.

    // Recur on the left and right subtrees to find a pair with sum 'k'.
    return solve(root->left, st, k) || solve(root->right, st, k);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k) {
    unordered_set<int> st; // Create an unordered_set to store the values of visited nodes.

    // Call the 'solve' function to check if there exists a pair with sum 'k'.
    return solve(root, st, k);
}
