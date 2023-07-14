class Node {
public:
    Node* links[26]; // Array of child nodes representing letters 'a' to 'z'
};

// Function to insert a substring into the trie and count the distinct substrings
void insert(Node* root, string& s, int& cnt) {
    int n = s.length();
    Node* cur = root;

    for (int i = 0; i < n; i++) {
        if (cur->links[s[i] - 'a'] == NULL) {
            cnt++; // Increment the count if a new substring is found
            cur->links[s[i] - 'a'] = new Node(); // Create a new node if the current character doesn't exist
        }
        cur = cur->links[s[i] - 'a'];
    }
}

int distinctSubstring(string& word) {
    int n = word.length();
    Node* root = new Node(); // Create the root node of the trie
    int cnt = 0; // Count of distinct substrings

    // Generate all possible substrings and insert them into the trie
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = i; j < n; j++) {
            s += word[j];
            insert(root, s, cnt); // Insert the substring into the trie and update the count
        }
    }

    return cnt; // Return the count of distinct substrings
}
