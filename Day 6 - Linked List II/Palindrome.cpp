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
// function to reverse a LL:
LinkedListNode<int> *rev(LinkedListNode<int> *head) {

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    while (curr != NULL) {
        LinkedListNode<int> *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

// Function to get the middle of list:
LinkedListNode<int> *getMid(LinkedListNode<int> *head) {
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool isPalindrome(LinkedListNode<int> *head) {
    /*
        Approach 1:
            1. Make a full copy of original LL.
            2. reverse the copy
            3. check if LL == copy (palindrome condition)
    */
    
    // Approach 2:
    if (head == NULL || head->next == NULL) return true;

    // getting the middle of the ll:
    LinkedListNode<int> *mid = getMid(head);

    // Now from head to mid make LL1:
    LinkedListNode<int> *curr1 = head;
    LinkedListNode<int> *tail1 = mid;

    // form mid+1 to NULL, make LL2:
    LinkedListNode<int> *curr2 = mid->next;
    LinkedListNode<int> *tail2 = mid->next;

    mid->next = NULL;
    
    // moving the tail of LL2 to correct pos:
    while (tail2->next != NULL) {
        tail2 = tail2->next;
    }

    // reverse LL2:
    curr2 = rev(curr2);

    // now simply check for palindrome condition:
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data != curr2->data) return false;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;

}