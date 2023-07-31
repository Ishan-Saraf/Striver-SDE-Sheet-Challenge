#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int f(TreeNode<int> *root, long long int &ans, int &cnt) {
    if (!root)
        return 0;

    if (root->left == NULL && root->right == NULL)
        cnt++;

    // Recursive calls to calculate the sum of the left and right subtrees
    long long int left = f(root->left, ans, cnt);
    long long int right = f(root->right, ans, cnt);

    // The maximum sum path can be one of the following:
    // 1. The current node itself (alone)
    // 2. The current node and its left subtree
    // 3. The current node and its right subtree
    // 4. The current node, its left subtree, and its right subtree
    ans = max(ans, left + right + 1ll * root->val);

    // The return value for this recursive call is the sum of the current node and the maximum sum of its subtrees.
    return 1ll * root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root) {
    int cnt = 0; // To count the number of leaf nodes in the tree
    long long int ans = 0; // To store the maximum sum path
    f(root, ans, cnt);

    // If there are less than two leaf nodes in the tree, return -1 as per the problem statement.
    if (cnt <= 1)
        return -1;

    return ans; // Return the maximum sum path
}
