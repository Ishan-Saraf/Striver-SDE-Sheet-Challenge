#include <bits/stdc++.h>
using namespace std;

class Temp {
public:
    int height;
    int leftIndex;
    int rightIndex;

    Temp(int h, int li, int ri) {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    int maxHeight = 0; // Initialize the maximum height of the binary tree

    queue<Temp> q; // Queue for level-order traversal

    // If the number of nodes is greater than or equal to 1, create the root node (entire binary tree)
    if(N >= 1) {
        Temp temp(0, 0, N - 1);
        q.push(temp);
    }

    unordered_map<int, int> map; // Map to store indices of elements in the inorder traversal

    // Populate the map with each element's index in the inorder traversal
    for(int i = 0; i < N; i++) {
        map[inorder[i]] = i;
    }

    // Perform level-order traversal
    for(int i = 0; i < N; i++) {
        Temp temp = q.front(); // Dequeue the front element
        q.pop();

        maxHeight = max(temp.height, maxHeight); // Update the maximum height

        int li = temp.leftIndex; // Left index of the current subtree
        int ri = temp.rightIndex; // Right index of the current subtree
        int rootIndex; // Index of the root element in the inorder traversal

        rootIndex = map[levelOrder[i]]; // Get the index of the current level-order element in the inorder traversal

        // Check if left sub-tree exists and enqueue it
        if(rootIndex - 1 >= li) {
            Temp leftSubTree(temp.height + 1, li, rootIndex - 1);
            q.push(leftSubTree);
        }

        // Check if right sub-tree exists and enqueue it
        if(rootIndex + 1 <= ri) {
            Temp rightSubTree(temp.height + 1, rootIndex + 1, ri);
            q.push(rightSubTree);
        }
    }

    return maxHeight; // Return the maximum height of the binary tree
}
