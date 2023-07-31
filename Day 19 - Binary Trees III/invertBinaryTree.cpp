#include <bits/stdc++.h> 
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

bool storParents(TreeNode<int> *root, stack<TreeNode<int> *> &parents, TreeNode<int> *leaf) {
  // Push the current node into the stack.
  parents.push(root);

  // If the current node is a leaf node, check if it is the target leaf node.
  if (!root->left && !root->right) {
    if (root->data == leaf->data)
      return true;
    else
      parents.pop();
    return false;
  }

  // Recursively search for the leaf node in the left and right subtrees.
  if (root->left) {
    if (storParents(root->left, parents, leaf))
      return true;
  }

  if (root->right) {
    if (storParents(root->right, parents, leaf))
      return true;
  }

  // If the leaf node is not found in the current subtree, backtrack by popping the current node from the stack.
  parents.pop();
  return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
  if (!root)
    return NULL;

  stack<TreeNode<int> *> parents;

  // Find the path from the root to the target leaf node and store the nodes in the stack.
  storParents(root, parents, leaf);

  // The head node is the top node of the stack, which is the target leaf node.
  TreeNode<int> *head = parents.top();
  parents.pop();

  // Invert the binary tree using the stored path of parent nodes.
  TreeNode<int> *par = head;
  while (!parents.empty()) {
    auto p = parents.top();
    parents.pop();

    // Swap the left and right children of the current parent node.
    if (p->right == head) {
      p->right = p->left;
      p->left = NULL;
    } else {
      p->left = NULL;
    }

    // Connect the current parent node to the previous parent node in the path.
    head->left = p;
    head = p;
  }

  // Return the new root of the inverted binary tree.
  return par;
}
