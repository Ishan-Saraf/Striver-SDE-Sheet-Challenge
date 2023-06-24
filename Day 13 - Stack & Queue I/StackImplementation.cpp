#include <bits/stdc++.h> 
// Stack class.
class Stack {
    private:
        int *arr;
        int tail;
        int size;

    public:
        
        // constructor:
        Stack(int capacity) {
            arr = new int[capacity];
            tail = 0;
            size = capacity;
        }

        void push(int num) {
            if (tail != size) {
                arr[tail] = num;
                tail++;
            }
        }

        int pop() {
            if (tail != 0) {
                    tail--;
                    return arr[tail];
            }

            else return -1;
        }
        
        int top() {
            if (tail != 0) {
                return arr[tail-1];
            }
            else {
                return -1;
            }
        }
        
        int isEmpty() {
            if (tail == 0) return 1;
            else return 0;
        }
        
        int isFull() {
            if (tail == size) return 1;
            else return 0;
        }
    
};