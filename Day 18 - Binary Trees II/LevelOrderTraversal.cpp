/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

// Function to perform level-order traversal of a binary tree
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans; // Initialize an empty vector to store the node values
    queue<BinaryTreeNode<int>*> q; // Initialize a queue for level-order traversal

    if (!root) // If the tree is empty (root is NULL), return an empty vector
        return ans;

    q.push(root); // Enqueue the root node into the queue (start from the root)

    // Perform level-order traversal using a while loop
    while (!q.empty())
    {
        BinaryTreeNode<int>* t = q.front(); // Dequeue the front node from the queue
        int val = t->val; // Get the value of the current node (front node)
        ans.push_back(val); // Push the value to the ans vector to store the node values

        q.pop(); // Dequeue the front node as it has been processed

        // Enqueue the left child (if exists) to continue the traversal
        if (t->left)
            q.push(t->left);

        // Enqueue the right child (if exists) to continue the traversal
        if (t->right)
            q.push(t->right);
    }

    return ans; // Return the vector containing the node values in level-order
}
