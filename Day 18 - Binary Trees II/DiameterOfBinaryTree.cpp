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

// Helper function to calculate the maximum depth of the binary tree rooted at 'root'
// and also update the diameter of the binary tree.
int maxDepth(TreeNode<int> *root, int &dia) {
    // Base case: If the current node is NULL, return 0.
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate the maximum depth of the left and right subtrees.
    int left = maxDepth(root->left, dia);
    int right = maxDepth(root->right, dia);

    // Update the diameter by taking the maximum of the current diameter and the sum
    // of the maximum depths of the left and right subtrees.
    dia = max(dia, left + right);

    // Return the depth of the current node as 1 plus the maximum of the left and right depths.
    return 1 + max(left, right);
}

// Function to find the diameter of a binary tree.
int diameterOfBinaryTree(TreeNode<int> *root) {
    // Initialize a variable 'diameter' to store the diameter of the binary tree.
    int diameter = 0;

    // Call the maxDepth function to calculate the maximum depth of the binary tree
    // and update the 'diameter' variable with the diameter of the tree.
    maxDepth(root, diameter);

    // Return the calculated diameter as the final result.
    return diameter;
}
