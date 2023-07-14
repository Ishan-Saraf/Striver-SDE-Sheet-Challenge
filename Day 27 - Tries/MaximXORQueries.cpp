#include<bits/stdc++.h>

struct Node {       
    Node* links[2];        

    // Check if the child node exists for a given bit
    bool containsKey(int bit) {
        return links[bit] != NULL;        
    }        

    // Set the child node for a given bit
    void put(int bit, Node* node) {            
        links[bit] = node;                    
    }        

    // Get the child node for a given bit
    Node* get(int bit) {
        return links[bit];        
    }    
};

class Trie {    
    private:        
        Node* root;    
    public:        
        Trie() {            
            root = new Node();        
        }        

        // Insert a number into the trie
        void insert(int num) {            
            Node* node = root;            

            for (int i = 30; i >= 0; i--) {                
                int bit = (num >> i) & 1;                

                if (!node->containsKey(bit)) {                    
                    node->put(bit, new Node());                
                }                

                node = node->get(bit);            
            }        
        }        

        // Get the maximum XOR value with a given number
        int max_XOR(int num) {            
            Node* node = root;            
            int ans = 0;            

            for (int i = 30; i >= 0; i--) {                
                int bit = (num >> i) & 1;                

                if (node->containsKey(!bit)) {                    
                    ans = ans ^ (1 << i);                    
                    node = node->get(!bit);                
                } else {                    
                    node = node->get(bit);                
                }            
            }            

            return ans;        
        }    
};

// Comparator function to sort the queries based on the second element
static bool cmp(vector<int> a, vector<int> b) {        
    return a[1] < b[1];    
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {             
    int n = queries.size(), m = arr.size(), j = 0;        
    Trie node;        
    vector<int> ans(n, -1);        

    // Add an index to each query for tracking the corresponding answer position
    for (int i = 0; i < n; i++) {            
        queries[i].push_back(i);        
    }        

    // Sort the array and queries based on the second element of each query
    sort(arr.begin(), arr.end());        
    sort(queries.begin(), queries.end(), cmp);        

    for (int i = 0; i < n; i++) {            
        while (j < m && arr[j] <= queries[i][1]) {                
            node.insert(arr[j++]);            
        }            

        if (j > 0)                
            ans[queries[i][2]] = node.max_XOR(queries[i][0]);        
    }        

    return ans;    
}
