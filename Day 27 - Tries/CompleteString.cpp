class TierNode {
public:
    TierNode* child[26]; // Array of child nodes representing letters 'a' to 'z'
    bool isEnd; // Flag to indicate the end of a word
};

// Function to insert a word into the trie
void insert(string& w, TierNode* node) {
    TierNode* curr = node;
    for (auto c : w) {
        if (curr->child[c - 'a'] == NULL)
            curr->child[c - 'a'] = new TierNode(); // Create a new node if the current character doesn't exist
        curr = curr->child[c - 'a'];
    }
    curr->isEnd = true; // Mark the end of the word
}

// Function to check if a word is a complete string in the trie
bool isCompStr(string& w, TierNode* node) {
    TierNode* curr = node;
    for (auto c : w) {
        if (curr->child[c - 'a'] == NULL)
            return false; // If a character is not found in the trie, the word is not a complete string
        curr = curr->child[c - 'a'];
        if (curr->isEnd == false)
            return false; // If a character is not marked as the end of a word, the word is not a complete string
    }
    return true; // If all characters are found and marked as the end of a word, the word is a complete string
}

string completeString(int n, vector<string>& a) {
    TierNode* node = new TierNode(); // Create the root node of the trie

    // Insert each word into the trie
    for (auto w : a)
        insert(w, node);

    string ans = "";
    for (auto w : a) {
        if (isCompStr(w, node)) {
            if (ans.length() <= w.length()) {
                ans = ans.length() == w.length() ? min(ans, w) : w; // Update the answer with the longest complete string
            }
        }
    }

    return ans.length() == 0 ? "None" : ans; // Return the longest complete string or "None" if no complete string exists
}
