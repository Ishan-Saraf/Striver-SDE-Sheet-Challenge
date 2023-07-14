#include <bits/stdc++.h>

struct Node {
    Node* child[2];

    // Check if the child node exists for a given bit
    bool contains(int bit) {
        return child[bit] != NULL;
    }

    // Get the child node for a given bit
    Node* get(int bit) {
        return child[bit];
    }

    // Set the child node for a given bit
    Node* put(int bit, Node* node) {
        child[bit] = node;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    // Insert a number into the trie
    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->contains(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    // Get the maximum XOR value with a given number
    int getmax(int num) {
        Node* node = root;
        int maxnum = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->contains(1 - bit)) {
                // If the opposite bit exists, update the maxnum
                maxnum = (1 << i) | maxnum;
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxnum;
    }
};

int maximumXor(vector<int> A) {
    Trie trie;

    // Insert all numbers into the trie
    for (auto it : A) {
        trie.insert(it);
    }

    int maxi = 0;

    // Find the maximum XOR value for each number
    for (auto it : A) {
        maxi = max(maxi, trie.getmax(it));
    }

    return maxi;
}
