#include<bits/stdc++.h>

/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

// Custom Node class to store TreeNode along with X and Y coordinates
class Node{
public:
    TreeNode<int>* node;
    int X;
    int Y;
    Node(TreeNode<int>* _node, int _x, int _y){
        node = _node;
        X = _x;
        Y = _y;
    }
};

// Function to perform vertical order traversal of a binary tree
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<Node> q; // Create a queue of custom Node class
    vector<int> ans; // Initialize an empty vector to store the vertical order elements
    map<int, vector<int>> traversal; // Create a map to store elements at each vertical level

    // Create a Node with the root, horizontal distance (X) 0, and vertical distance (Y) 0
    Node n(root, 0, 0);
    q.push(n); // Enqueue the root node

    // Perform BFS using the queue
    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();
        TreeNode<int> *temp = curr.node;
        int x = curr.X; // Horizontal distance (X) of the current node
        int y = curr.Y; // Vertical distance (Y) of the current node

        // Store the data of the current node in the map at the corresponding horizontal distance
        traversal[x].push_back(temp->data);

        // Enqueue the left child with horizontal distance (X-1) and vertical distance (Y+1)
        if (temp->left != NULL)
        {
            Node tempL = Node(temp->left, x - 1, y + 1);
            q.push(tempL);
        }

        // Enqueue the right child with horizontal distance (X+1) and vertical distance (Y+1)
        if (temp->right != NULL)
        {
            Node tempR = Node(temp->right, x + 1, y + 1);
            q.push(tempR);
        }
    }

    // Traverse the map and add the elements to the answer vector in vertical order
    for (auto it : traversal)
    {
        for (auto i : it.second)
        {
            ans.push_back(i);
        }
    }

    return ans; // Return the vector containing the elements in vertical order
}
