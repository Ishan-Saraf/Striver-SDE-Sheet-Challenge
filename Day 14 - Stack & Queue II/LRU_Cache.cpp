#include<bits/stdc++.h>

using namespace std;

 

class LRUCache
{
    // Data members
    int capacity; // Maximum capacity of the cache
    unordered_map<int, list<pair<int,int>>::iterator> m; // Map to store key-value pairs and their corresponding iterators in the list
    list<pair<int,int>> l; // Doubly linked list to maintain the order of recently used elements

public:
    // Constructor
    LRUCache(int capacity)
    {
        this->capacity = capacity; // Initialize the maximum capacity
    }

    // Get the value for a given key
    int get(int key)
    {
        if(m.find(key) == m.end())
            return -1; // Key not found, return -1
        else{
            auto element = m[key]; // Get the iterator to the key-value pair in the list
            int val = element->second; // Get the value
            l.erase(element); // Remove the key-value pair from the list
            l.push_front({key, val}); // Move the key-value pair to the front of the list (recently used)
            m[key] = l.begin(); // Update the iterator in the map
            return val; // Return the value
        }
    }

    // Insert or update the value for a given key
    void put(int key, int value)
    {
        if(m.find(key) != m.end()){
            l.erase(m[key]); // Remove the existing key-value pair from the list
            m.erase(key); // Remove the existing key from the map
        }

        if(capacity == l.size()){
            pair<int, int> last = l.back(); // Get the least recently used key-value pair (at the back of the list)
            l.erase(m[last.first]); // Remove the least recently used key-value pair from the list
            m.erase(last.first); // Remove the least recently used key from the map
        }

        l.push_front({key, value}); // Insert the new key-value pair at the front of the list (recently used)
        m[key] = l.begin(); // Update the iterator in the map
    }
};
