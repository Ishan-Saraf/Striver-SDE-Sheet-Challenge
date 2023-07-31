void help(TreeNode<int> *root, int &k, int &res) {
    if (root == NULL)
        return; // Base case: If the current node is NULL, return.

    help(root->left, k, res); // Recur on the left subtree.

    if (k != 0) {
        k--; // Decrement the value of 'k'.
        res = root->data; // Update 'res' with the value of the kth smallest element.
    }

    help(root->right, k, res); // Recur on the right subtree.
}

int kthSmallest(TreeNode<int> *root, int k) {
    int res = 0; // Initialize 'res' to store the kth smallest element.
    help(root, k, res); // Perform the in-order traversal to find the kth smallest element.
    return res; // Return the kth smallest element.
}
