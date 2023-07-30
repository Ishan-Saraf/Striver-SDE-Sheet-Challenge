#include <bits/stdc++.h> 
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
            vector<graphNode *> neighbours;
            graphNode()
            {
                data = 0;
                neighbours = vector<graphNode *>();
            }

            graphNode(int val)
            {
                data = val;
                neighbours = vector<graphNode *>();
            }

            graphNode(int val, vector<graphNode *> neighbours)
            {
                data = val;
                this->neighbours = neighbours;
            }
    };

******************************************************************************/
// The provided custom class for representing a graph node.

graphNode *help(graphNode *node, unordered_map<graphNode *, graphNode *> &mp) {
    // Recursive helper function for cloning the graph.
    // It takes the current node and a map to keep track of already cloned nodes.

    // Create a new node with the same data value as the current node.
    graphNode *newnode = new graphNode(node->data);

    // Store the current node and its corresponding clone in the map.
    mp[node] = newnode;

    // Vector to store cloned neighbors of the current node.
    vector<graphNode *> v;

    // Iterate through the neighbors of the current node.
    for (auto i : node->neighbours) {
        // Check if the neighbor has already been cloned (present in the map).
        if (mp.find(i) != mp.end()) {
            // If already cloned, use the corresponding clone from the map.
            v.push_back(mp[i]);
        } else {
            // If not cloned, recursively clone the neighbor and add it to the vector.
            v.push_back(help(i, mp));
        }
    }

    // Set the cloned neighbors vector for the new node.
    newnode->neighbours = v;

    // Return the cloned node.
    return newnode;
}

graphNode *cloneGraph(graphNode *node) {
    // Main function to clone the graph.
    // It takes the root node of the original graph.

    // Initialize an unordered map to store the mapping between original nodes and their clones.
    unordered_map<graphNode *, graphNode *> mp;

    // Call the helper function to start the cloning process from the root node.
    return help(node, mp);
}
