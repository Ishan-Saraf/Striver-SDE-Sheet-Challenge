#include <bits/stdc++.h> 

class Stack {
    queue<int> q1, q2; // Two queues to implement stack

    int size; // Variable to keep track of stack size

public:
    Stack() {
        size = 0; // Initialize stack size to 0
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size; // Return the size of the stack
    }

    bool isEmpty() {
        if(size == 0) {
            return true; // If size is 0, stack is empty
        }
        else {
            return false; // If size is not 0, stack is not empty
        }
    }

    void push(int element) {
        // Step 1 : Push Element into q2
        q2.push(element);

        // Step 2 : Push all the elements of q1 into q2
        while(!q1.empty()) {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }

        // Step 3 : Swap q1 and q2
        swap(q1, q2);

        // Step 4 : Update the value of size
        size++;
    }

    int pop() {
        // Simply Pop from q1
        if(!q1.empty()) {
            int val = q1.front();
            q1.pop();

            // Update the value of size
            size--;
            return val; // Return the popped element
        }
        else {
            return -1; // If stack is empty, return -1
        }
    }

    int top() {
        // Return front of q1
        if(!q1.empty()) {
            return q1.front(); // Return the top element of the stack
        }
        else {
            return -1; // If stack is empty, return -1
        }
    }
};