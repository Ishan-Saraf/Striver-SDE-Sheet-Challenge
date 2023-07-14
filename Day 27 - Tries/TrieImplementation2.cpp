#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];   // Array of pointers to child TrieNodes for each character
    int endwith;              // Number of words ending at this TrieNode
    int countprefix;          // Number of words with this TrieNode as prefix

    TrieNode() {
        endwith = 0;
        countprefix = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();  // Create the root TrieNode
    }

    void InsertWord(TrieNode* root, string word) {
        // Base Case: If the word is empty, increment countprefix and endwith and return
        if (word.length() == 0) {
            root->countprefix++;
            root->endwith++;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            TrieNode* newTrieNode = new TrieNode();
            root->children[index] = newTrieNode;
            child = root->children[index];
        }

        root->countprefix++;

        // Recursive Call
        InsertWord(child, word.substr(1));
    }

    int CountWords(TrieNode* root, string word) {
        // Base Case: If the word is empty, return the value of endwith
        if (word.length() == 0) {
            return root->endwith;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return 0;
        }

        // Recursive Call
        return CountWords(child, word.substr(1));
    }

    int CountWord_withPrefix(TrieNode* root, string word) {
        // Base Case: If the word is empty, return the value of countprefix
        if (word.length() == 0) {
            return root->countprefix;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return 0;
        }

        // Recursive Call
        return CountWord_withPrefix(child, word.substr(1));
    }

    void RemoveWords(TrieNode* root, string word) {
        // Base Case: If the word is empty, decrement countprefix and endwith and return
        if (word.length() == 0) {
            root->countprefix--;
            root->endwith--;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            root->countprefix--;
            child = root->children[index];
        } else {
            return;
        }

        // Recursive Call
        RemoveWords(child, word.substr(1));
    }

    void insert(string& word) {
        InsertWord(root, word);
    }

    int countWordsEqualTo(string& word) {
        return CountWords(root, word);
    }

    int countWordsStartingWith(string& word) {
        return CountWord_withPrefix(root, word);
    }

    void erase(string& word) {
        RemoveWords(root, word);
    }
};
