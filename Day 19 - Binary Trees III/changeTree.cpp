int dfs(BinaryTreeNode<int>* node) {
    if (node) {
        int sum = 0;
        // Recursively calculate the sum of data values in the left and right subtrees.
        sum += dfs(node->left);
        sum += dfs(node->right);

        // If the sum is zero, update the node's data value to a very large positive integer (1e6).
        if (!sum) {
            sum = 1e6;
        }

        // Update the node's data value to the calculated sum.
        node->data = sum;
        return sum;
    } else {
        // If the node is NULL (empty), return 0.
        return 0;
    }
}

void changeTree(BinaryTreeNode<int>* root) {
    // Call the dfs function to update the data values of all nodes in the binary tree.
    dfs(root);
}
