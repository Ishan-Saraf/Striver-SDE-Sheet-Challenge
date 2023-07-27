/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// Helper function to perform the left traversal of the boundary.
void traversalLeft(TreeNode<int> *root, vector<int> &ans) {
    // Base case: If the node is NULL or it is a leaf node, return.
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    // Add the data of the current node to the answer.
    ans.push_back(root->data);

    // Continue the left traversal if left child exists; otherwise, proceed with the right child.
    if (root->left)
        traversalLeft(root->left, ans);
    else
        traversalLeft(root->right, ans);
}

// Helper function to perform the traversal of the leaf nodes of the binary tree.
void traversalLeaf(TreeNode<int> *root, vector<int> &ans) {
    // Base case: If the node is NULL, return.
    if (root == NULL)
        return;

    // If the node is a leaf node, add its data to the answer.
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    // Traverse the left and right subtrees to find the leaf nodes.
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

// Helper function to perform the right traversal of the boundary.
void traversalRight(TreeNode<int> *root, vector<int> &ans) {
    // Base case: If the node is NULL or it is a leaf node, return.
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    // Continue the right traversal if right child exists; otherwise, proceed with the left child.
    if (root->right)
        traversalRight(root->right, ans);
    else
        traversalRight(root->left, ans);

    // Add the data of the current node to the answer.
    ans.push_back(root->data);
}

// Function to perform boundary traversal of a binary tree.
vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> ans;

    // If the tree is empty, return an empty vector.
    if (root == NULL)
        return ans;

    // 1. Enter the root node in the answer.
    ans.push_back(root->data);

    // 2. Perform left traversal of the boundary, excluding the leftmost leaf node.
    traversalLeft(root->left, ans);

    // 3. Perform the traversal of leaf nodes in both left and right subtrees.
    traversalLeaf(root->left, ans);  // Traverse the leaf nodes in the left subtree.
    traversalLeaf(root->right, ans); // Traverse the leaf nodes in the right subtree.

    // 4. Perform right traversal of the boundary, excluding the rightmost leaf node.
    traversalRight(root->right, ans);

    return ans;
}
