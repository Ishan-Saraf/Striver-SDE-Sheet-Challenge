#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int> *solve(Node<int> *first, Node<int> *second) {

    // if only one element:
    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    Node<int> *current1 = first; // pointing towards first's ll head
    Node<int> *next1 = current1->next;

    Node<int> *current2 = second; // pointing towards second ll head
    Node<int> *next2 = current2->next;

    while (next1 != NULL && current2 != NULL) {

        if ((current2->data >= current1->data) && (current2->data <= next1->data)) {
            
            current1->next = current2;
            next2 = current2->next; // to ensure we don't loose the second ll
            current2->next = next1;

            // incrementing both:
            current1 = current2;
            current2 = next2;
        }

        // incrementing both;
        else {
            current1 = current1->next;
            next1 = next1->next;

            // if the first ll has ended
            if (next1 == NULL) {
                current1->next = current2; // this will put the remaining elements in the end;
                return first;
            }
        }
    }

    return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if (first == NULL) return second;
    if (second == NULL) return first;

    // taking the larger one as the first list:
    if (first->data <= second->data) {
        return solve(first, second);
    }

    else {
        return solve(second, first);
    }
}
