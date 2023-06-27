#include <bits/stdc++.h>

struct Node {
  int key, val, freq;
  Node *prev, *next;

  Node(int _key, int _val) { key = _key, val = _val, freq = 1; }
};

struct List {
  Node *head;
  Node *tail;
  int size;

  List() {
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void addNewNode(Node *newNode) {
    Node *temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
    size++;
  }

  void deleteNode(Node *delNode) {
    delNode->next->prev = delNode->prev;
    delNode->prev->next = delNode->next;
    size--;
  }
};

class LFUCache {
  unordered_map<int, Node *> mp; // Map to store key-node pairs
  unordered_map<int, List *> freqList; // Map to store frequency-list pairs
  int minFreq, cap, currSize;

public:
  LFUCache(int capacity) {
    minFreq = 0;
    cap = capacity;
    currSize = 0;
  }

  void updateList(Node *node) {
    mp.erase(node->key); // Remove the node from the map

    freqList[node->freq]->deleteNode(node); // Delete the node from its current frequency list

    if (freqList[node->freq]->size == 0 || node->freq == minFreq)
      minFreq++; // If the previous frequency list becomes empty or the node had the minimum frequency, update minFreq

    List *newList = new List();
    if (freqList.count(node->freq + 1))
      newList = freqList[node->freq + 1]; // Check if the frequency list for node->freq + 1 already exists

    node->freq += 1; // Increment the frequency of the node
    newList->addNewNode(node); // Add the node to the new frequency list
    freqList[node->freq] = newList; // Update the frequency list in the map
    mp[node->key] = node; // Update the node in the map
  }

  int get(int key) {
    if (mp.count(key)) {
      Node *node = mp[key]; // Retrieve the node from the map
      int x = node->val; // Get the value from the node
      updateList(node); // Update the node's frequency and position in the frequency list
      return x; // Return the value
    }
    return -1; // Key not found, return -1
  }

  void put(int key, int value) {
    if (cap == 0)
      return; // If the cache capacity is zero, no operation can be performed

    else if (mp.count(key)) {
      Node *node = mp[key]; // Retrieve the existing node from the map
      node->val = value; // Update the value of the existing node
      updateList(node); // Update the node's frequency and position in the frequency list
    }

    else {
      if (currSize == cap) {
        List *list = freqList[minFreq]; // Get the frequency list with minimum frequency
        mp.erase(list->tail->prev->key); // Remove the least recently used node from the map
        list->deleteNode(list->tail->prev); // Delete the least recently used node from the frequency list
        currSize--; // Reduce the current size of the cache
      }

      currSize++; // Increase the current size of the cache
      minFreq = 1; // Reset the minimum frequency to 1

      List *list = new List();
      if (freqList.count(minFreq))
        list = freqList[minFreq]; // Check if the frequency list for minFreq already exists

      Node *newNode = new Node(key, value); // Create a new node with the given key and value
      list->addNewNode(newNode); // Add the new node to the frequency list
      freqList[minFreq] = list; // Update the frequency list in the map
      mp[key] = newNode; // Update the new node in the map
    }
  }
};
