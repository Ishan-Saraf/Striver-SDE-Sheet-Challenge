#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
// modifying the reverse in kgroup function to use arr values for grouping:
Node *kgroup(Node *head, int n, int b[], int i) {
	// base case:
	if (n<1 || head == NULL || head->next == NULL) {
		return head;
	}

	Node *prev = NULL;
	Node *curr = head;
	Node *nxt = NULL;

	int cnt = 0;

	// starting bit will be done using iteration:
	while (b[i] == 0 && i<n) i++;

	while (curr != NULL && cnt < b[i] && i<n) {
		nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
	}

	if (i >= n && curr != NULL) {
		return head;
	}

	// remaining part will be done by recursion:
	if (curr != NULL) {
		head -> next = kgroup(nxt, n, b, i+1);
	}

	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node *ans = kgroup(head, n, b, 0); // solving using a recursive approach
	return ans;
}