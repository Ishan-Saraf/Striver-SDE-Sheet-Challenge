#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

// Helper function for preorder traversal to find the path to the target node
void preorder(TreeNode<int> *root, int target, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);

    // If the target node is found, stop further traversal
    if (root->data == target)
        return;

    // Recursively traverse the left and right subtrees
    preorder(root->left, target, ans);
    preorder(root->right, target, ans);

    // If the target node is not present in the current subtree, remove the last node from the path
    if (ans[ans.size() - 1] != target)
        ans.pop_back();
}

// Function to find the path from the root to the target node in a binary tree
vector<int> pathInATree(TreeNode<int> *root, int target)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    // Call the preorder function to find the path
    preorder(root, target, ans);

    return ans; // Return the path as a vector of integers
}
