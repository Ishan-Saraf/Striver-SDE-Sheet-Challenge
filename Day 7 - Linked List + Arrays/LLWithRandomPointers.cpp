#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
void insertAtTail(LinkedListNode<int> *&head, LinkedListNode<int> *&tail, int d) {
    LinkedListNode<int> *newNode = new LinkedListNode<int> (d);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    else {
        tail->next = newNode;
        tail = newNode;
    }
}

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    /*
    
    // Approach 1:
        1. create a clone list using nxt of original list;
        2. see how far is random pointer from current node
        3. move the random pointer to that node

        O(n2);

    // Approach 2: using map;

    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> map;
    LinkedListNode<int> *temp = head;

    // making a clone list:
    while(temp != NULL){
        map[temp] = new LinkedListNode<int> (temp->data);
        temp = temp->next;
    }

    temp = head;
    // setting pointer of clone using original list:
    while(temp != NULL){
        map[temp]->next = map[temp->next];
        map[temp]->random = map[temp->random];
        temp = temp->next;
    }

    return map[head];

    */

    // Approach 3: changing links:

    // step1: make clone LL:
    LinkedListNode<int> *cloneHead = NULL;
    LinkedListNode<int> *cloneTail = NULL;

    LinkedListNode<int> *temp = head;

    while (temp!= NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step2: cloneNodes add inbetween original list:
    LinkedListNode<int> *originalNode = head;
    LinkedListNode<int> *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL) {
        LinkedListNode<int> *nxt = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = nxt;

        nxt = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = nxt;
    }

    // step3: random pointer copy:
    temp = head;

    while (temp != NULL) {
        if (temp->next != NULL) {
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }

        temp = temp->next->next;
    }

    // step4: revert changes made in step2:
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
            
        if (originalNode != NULL) {
            cloneNode->next = originalNode->next;
        }

        cloneNode = cloneNode->next;
    }

    // step5: return ans
    return cloneHead;
}
