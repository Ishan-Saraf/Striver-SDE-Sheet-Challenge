/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = start;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = start;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    /*

    // Approach 1:
    if (head == start) return start;

    int length = 0;

    Node *temp = head;

    while (temp != start) {
        temp = temp->next;
        length++;
    }

    temp = head;

    if (K == length) {
        Node *toBeDeleted = head;
        head = head->next;
        delete(toBeDeleted);
        return head;
    }

    int n = length - K;

    int i = 0;

    while (i != n) {
        temp = temp->next;
        i++;
    }

    temp->data = temp->next->data;
    Node *toBeDeleted = temp->next;
    temp->next = temp->next->next;
    delete(toBeDeleted);

    return head;
    */

    // Approach 2: (2 pointer)

    if (head == NULL) {
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;
    Node *prev = NULL;

    // moving fast K times ahead:
    for (int i=0; i<K; i++) {
        if (fast == NULL) {
            return head; // k is greater than the length of the list
        }

        fast=fast->next;
    }

    // moving both at same pace now:
    while (fast != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // if prev is NULL then we need to remove head node:
    if (prev == NULL) {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}
