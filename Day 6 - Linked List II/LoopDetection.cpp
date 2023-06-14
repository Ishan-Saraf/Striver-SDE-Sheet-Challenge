#include<bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

bool detectCycle(Node *head)
{
    /*

	// Approach 1: using hashing:
    map<Node *, bool> visited;

    if (head==NULL) return true;
    if (head->next == NULL) return false;

    while(head != NULL) {
        if (visited[head] == true) return true;

        visited[head] = true;

        head = head->next;
    }

    return false;
    */

    // Approach 2: using floyd's cycle detection algo:

    if (head==NULL) return true;
    if (head->next == NULL) return false;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (slow == fast) return true; // collision, loop present
    }

    return false;
}