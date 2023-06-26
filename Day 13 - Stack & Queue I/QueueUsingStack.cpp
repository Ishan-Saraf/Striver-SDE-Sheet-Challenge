#include<bits/stdc++.h>

class Queue {
    // Define the data members(if any) here.
    private:
    stack<int> first;  // First stack for enqueue operation
    stack<int> second; // Second stack for dequeue operation

    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        first.push(val); // Push the value to the first stack
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (!second.empty()) {
            // If the second stack is not empty, pop the top element and return it
            int data = second.top();
            second.pop();
            return data;
        }
        else {
            if (first.empty()) {
                return -1; // If both stacks are empty, return -1 (indicating empty queue)
            }
            else {
                // Transfer elements from the first stack to the second stack
                while(!first.empty()) {
                    second.push(first.top());
                    first.pop();
                }

                int data = second.top(); // Get the front element from the second stack
                second.pop(); // Pop the front element
                return data; // Return the front element
            }
        }
    }

    int peek() {
        // Implement the peek() function here.
        if (!second.empty()) {
            // If the second stack is not empty, return the top element
            return second.top();
        }
        else {
            if (first.empty()) {
                return -1; // If both stacks are empty, return -1 (indicating empty queue)
            }
            else {
                // Transfer elements from the first stack to the second stack
                while (!first.empty()) {
                    second.push(first.top());
                    first.pop();
                }

                return second.top(); // Return the front element from the second stack
            }
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if (first.empty() && second.empty()) {
            return true; // If both stacks are empty, the queue is empty
        }
        else {
            return false; // Otherwise, the queue is not empty
        }
    }
};
