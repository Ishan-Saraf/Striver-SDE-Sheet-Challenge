/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     /*
          Approach 1:
               1. go to last node
               2. put last node to front
               3. repeat 1 & 2 k no. of times
               O(n*k) -> yuck!
     */

     // Approach 2:

     if (head == NULL || head->next == NULL || k==0) {
          return head;
     }

     // step1: get length of ll:
     Node *temp = head;
     int len = 1;

     while (temp->next != NULL) {
          len++;
          temp = temp->next;
     }

     // step2: put the last pointer to head (make circular LL):
     temp->next = head;

     k = k%len; // since, rotating the list in multiples of len will return same ll;
     k = len-k;

     // step3: break the circle and return the ans:
     while (k--) {
          temp = temp->next;
     }

     head = temp->next;
     temp->next = NULL;

     return head;
}