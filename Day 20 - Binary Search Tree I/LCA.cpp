#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

TreeNode<int> *rec(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q) {
  // Base case: If the tree is empty, `p` and `q` are not in the tree.
  if (root == nullptr) {
    return nullptr;
  }

  // Check if the root is the lowest common ancestor of `p` and `q`.
  if (root->data >= p->data && root->data <= q->data) {
    return root;
  }

  // If the root is less than `p`, then the lowest common ancestor of `p` and `q` must be in the right subtree.
  if (root->data < p->data) {
    return rec(root->right, p, q);
  }

  // Otherwise, the lowest common ancestor of `p` and `q` must be in the left subtree.
  return rec(root->left, p, q);
}

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q) {
  // Check if `p` is less than `q`. If so, we call the `rec()` function with `p` as the first argument and `q` as the second argument. Otherwise, we call the `rec()` function with `q` as the first argument and `p` as the second argument.
  if (p->data < q->data) {
    return rec(root, p, q);
  } else {
    return rec(root, q, p);
  }
}
