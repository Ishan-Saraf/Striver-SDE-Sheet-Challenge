#include <bits/stdc++.h> 
class Queue {
    private:
        int *arr;
        int Front;
        int rear;
        int size;

    public:
        Queue() {
            size = 10001;
            arr = new int[size];
            Front = 0;
            rear = 0;
        }

        /*----------------- Public Functions of Queue -----------------*/

        bool isEmpty() {
            if (Front == rear) return true;
            else return false;
        }

        void enqueue(int data) {
            if (rear != size) {
                arr[rear] = data;
                rear++;
            }
        }

        int dequeue() {
            if (rear != Front) {
                int temp = arr[Front++];
                if (Front == rear) {
                    Front = 0;
                    rear = 0;
                }

                return temp;
            }

            else return -1;
        }

        int front() {
            if (Front != rear) return arr[Front];
            else return -1;
        }
};