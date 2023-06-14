#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Iterative approach:

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    while(curr != NULL) {
        // make a temp node which the current will point to
        LinkedListNode<int> *forward = curr->next;
        // now make the current node point to the previous node
        curr->next = prev;
        // replace previous with current
        prev = curr;
        // replace current with next one
        curr = forward;
    }

    return prev;
}