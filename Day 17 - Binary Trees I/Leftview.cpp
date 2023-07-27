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

// Helper function to perform left view traversal of the binary tree
void leftview(TreeNode<int> *root, vector<int> &ans, int lvl) {
    // Base case: if the current node is NULL, return
    if (root == NULL) return;

    // If the level of the current node is equal to the current size of the answer vector,
    // it means we have not seen any node at this level yet.
    // So, we add the data of the current node to the answer vector.
    if (lvl == ans.size()) {
        ans.push_back(root->data);
    }

    // Recursively traverse the left subtree with an increased level (lvl+1)
    leftview(root->left, ans, lvl+1);

    // Recursively traverse the right subtree with an increased level (lvl+1)
    // Note that we traverse the right subtree before the left subtree to ensure that
    // we only consider the leftmost node at each level in the binary tree.
    leftview(root->right, ans, lvl+1);
}

// Function to get the left view of the binary tree
vector<int> getLeftView(TreeNode<int> *root) {
    vector<int> ans; // Initialize an empty vector to store the left view elements
    int lvl = 0; // Initialize the current level to 0
    leftview(root, ans, lvl); // Call the helper function to perform the left view traversal
    return ans; // Return the vector containing the left view elements of the binary tree
}
