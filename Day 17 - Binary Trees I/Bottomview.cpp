/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
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

*************************************************************/

// Function to get the bottom view of the binary tree
vector<int> bottomView(BinaryTreeNode<int> *root) {
    vector<int> ans; // Initialize an empty vector to store the bottom view elements

    // If the root is NULL (i.e., the binary tree is empty), return the empty answer vector
    if (root == NULL) {
        return ans;
    }

    // Create a map to store the bottom view elements with their corresponding line number
    map<int, int> mpp;

    // Create a queue to perform level-order traversal of the binary tree
    queue<pair<BinaryTreeNode<int>*, int>> q;

    // Push the root node along with its line number (0) into the queue
    q.push({root, 0});

    // Perform level-order traversal until the queue is empty
    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        BinaryTreeNode<int>* node = it.first; // Current node
        int line = it.second; // Line number of the current node

        // Update the value in the map with the current line number, which represents the bottom view
        mpp[line] = node->data;

        // Enqueue the left child of the current node along with its line number (line-1)
        if (node->left != NULL) {
            q.push({node->left, line-1});
        }

        // Enqueue the right child of the current node along with its line number (line+1)
        if (node->right != NULL) {
            q.push({node->right, line+1});
        }
    }

    // Traverse the map and add the values to the answer vector in sorted order of line numbers
    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans; // Return the vector containing the bottom view elements of the binary tree
}
