#include<bits/stdc++.h>
using namespace std;

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

string serializeTree(TreeNode<int> *root)
{
    if (!root) return ""; // If root is null, return an empty string.
    
    queue<TreeNode<int>*> q;
    q.push(root);

    string s = "";
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        if (!curr)
            s.append("$,"); // If the current node is null, append "$" to the string.
        else
            s.append(to_string(curr->data) + ","); // Otherwise, append the current node's data to the string.

        if (curr) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if (serialized.size() == 0)
        return NULL; // If the serialized string is empty, return NULL.

    stringstream s(serialized); // Create a string stream from the serialized string to read from it.
    string str;
    getline(s, str, ','); // Read the first value from the string stream and store it in the 'str' variable. The delimiter is ','.

    TreeNode<int> *root = new TreeNode<int>(stoi(str)); // Create a new root node with the value obtained from 'str'.
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        getline(s, str, ','); // Read the next value from the string stream for the left child.
        if (str == "$") { // If 'str' is "$", the left child is null.
            curr->left = NULL;
        } else {
            auto left = new TreeNode<int>(stoi(str)); // Otherwise, create a new left child node with the value from 'str'.
            curr->left = left;
            q.push(left);
        }

        getline(s, str, ','); // Read the next value from the string stream for the right child.
        if (str == "$") { // If 'str' is "$", the right child is null.
            curr->right = NULL;
        } else {
            auto right = new TreeNode<int>(stoi(str)); // Otherwise, create a new right child node with the value from 'str'.
            curr->right = right;
            q.push(right);
        }
    }

    return root; // Return the root of the deserialized binary tree.
}
