    long long solve(TreeNode<int> *root, long long &ans, int x) {
    // If the current node is NULL, there is no floor value, so return the current ans.
    if (root == NULL) return ans;

    // If the value of the current node is less than or equal to x,
    // it means the floor value lies in the right subtree of the current node.
    if (root->val <= x) {
        // Update the ans to the current node's value (the largest value <= x found so far).
        ans = root->val;
        // Recursively search for the floor value in the right subtree of the current node.
        // The updated ans will be passed on to find the largest value <= x in the right subtree.
        return solve(root->right, ans, x);
    } else {
        // If the value of the current node is greater than x,
        // it means the floor value lies in the left subtree of the current node.
        // Recursively search for the floor value in the left subtree of the current node.
        return solve(root->left, ans, x);
    }
}

int floorInBST(TreeNode<int> *root, int x) {
    // Initialize ans to -1, which will store the floor value.
    long long ans = -1;

    // If the root is NULL, the BST is empty, so return -1 (no floor value).
    if (root == NULL) return ans;

    // Initialize a pointer variable 'node' to the root of the BST.
    TreeNode<int> *node = root;

    // Call the 'solve' function to compute the floor value of 'x' in the BST.
    // The 'solve' function will update the 'ans' variable with the floor value.
    ans = solve(node, ans, x);

    // Finally, return the computed floor value stored in 'ans'.
    return ans;
}
