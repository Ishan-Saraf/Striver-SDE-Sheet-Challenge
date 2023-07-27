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

// Function to find the lowest common ancestor of nodes with values 'x' and 'y' in the binary tree rooted at 'root'.
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    // Base case: If the current node is NULL or if it has the value of 'x' or 'y',
    // then it is the lowest common ancestor of itself.
    if (root == NULL) {
        return -1;
    }
    
    if (root->data == x || root->data == y)
    {
        return root->data;
    }

    // Recursively find the lowest common ancestor in the left and right subtrees.
    int leftAns = lowestCommonAncestor(root->left, x, y);
    int rightAns = lowestCommonAncestor(root->right, x, y);

    // If both 'x' and 'y' are found in the left and right subtrees,
    // then the current node is the lowest common ancestor.
    if (leftAns != -1 && rightAns != -1)
    {
        return root->data;
    }
    // If only one of 'x' and 'y' is found in the left or right subtree,
    // then that node is the lowest common ancestor.
    else if (leftAns != -1)
    {
        return leftAns;
    }
    else if (rightAns != -1)
    {
        return rightAns;
    }
    // If 'x' and 'y' are not found in the left or right subtree,
    // return -1 to indicate that the lowest common ancestor is not found yet.
    else
    {
        return -1;
    }
}
