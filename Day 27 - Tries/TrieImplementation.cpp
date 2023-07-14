# include<iostream>
# include<bits/stdc++.h>

using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode {
public:
    char data;                          // Data of the TrieNode
    TrieNode *child[26];                // Array of child pointers for each letter of the alphabet
    bool isTerminal;                    // Flag to mark the end of a word

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;         // Initialize child pointers to nullptr
        }
        isTerminal = false;             // Initialize isTerminal flag as false
    }
};

class Trie {
public:
    TrieNode *root;                     // Root node of the Trie

    Trie() {
        root = new TrieNode('\0');       // Create the root node with null character data
    }

    void insertUtil(TrieNode *root, string word) {
        // Base case: If the word is empty, mark the current node as terminal and return
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';       // Calculate the index for the child pointer based on the character

        TrieNode *child;
        // Present case: If the child node already exists for the character, set child pointer to it
        if (root->child[index] != nullptr) {
            child = root->child[index];
        }
        // Absent case: If the child node does not exist, create a new node and set child pointer to it
        else {
            child = new TrieNode(word[0]);
            root->child[index] = child;
        }

        // Recursive call: Move to the next character in the word and call insertUtil on the child node
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);          // Call insertUtil starting from the root node
    }

    bool searchUtil(TrieNode *root, string word) {
        // Base case: If the word is empty, return the value of isTerminal flag of the current node
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';       // Calculate the index for the child pointer based on the character

        TrieNode *child;
        // Present case: If the child node already exists for the character, set child pointer to it
        if (root->child[index] != nullptr) {
            child = root->child[index];
        }
        // Absent case: If the child node does not exist, the word is not present in the Trie
        else {
            return false;
        }

        // Recursive call: Move to the next character in the word and call searchUtil on the child node
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);    // Call searchUtil starting from the root node
    }

    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for (auto ch : prefix) {
            int index = ch - 'a';        // Calculate the index for the child pointer based on the character

            // If the child node does not exist for the character, the prefix is not present in the Trie
            if (temp->child[index] == nullptr) {
                return false;
            }

            temp = temp->child[index];   // Move to the child node for the next character
        }

        return true;                     // All characters of the prefix are present in the Trie
    }
};
