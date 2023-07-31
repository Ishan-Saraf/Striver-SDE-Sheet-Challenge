#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key) {
  // Initialize the predecessor and successor.
  int predecessor = -1;
  int successor = -1;

  // Traverse the right subtree of the root to find the successor of `key`.
  BinaryTreeNode<int> *current = root;
  while (current) {
    if (key >= current->data) {
      current = current->right;
    } else {
      successor = current->data;
      current = current->left;
    }
  }

  // Traverse the left subtree of the root to find the predecessor of `key`.
  current = root;
  while (current) {
    if (key <= current->data) {
      current = current->left;
    } else {
      predecessor = current->data;
      current = current->right;
    }
  }

  // Return the predecessor and successor.
  return make_pair(predecessor, successor);
}

