/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *child;
 * 		Node *child;
 *		Node() : data(0), child(nullptr), child(nullptr){};
 *		Node(int x) : data(x), child(nullptr), child(nullptr) {}
 *		Node(int x, Node *child, Node *child) : data(x), child(child), child(child) {}
 * };
 */

// function for merging 2 sorted LLs:
Node *merge(Node *head1, Node *head2) {

	// we are basically using the merge logic from mergeSort():
	Node *temp = new Node(0);
	Node *curr = temp;

	// so the links doesn't get lost:
	Node *node1 = head1;
	Node *node2 = head2;

	// ATQ:
	head1->next = NULL;
	head2->next = NULL;

	while (node1 != NULL && node2 != NULL) {
		if (node1->data <= node2->data) {
			curr->child = node1;
			curr = node1;
			node1 = node1->child;
		}

		else {
			curr->child = node2;
			curr = node2;
			node2 = node2->child;
		}
	}

	// just attach the remaining elements in front of the shorter LL;
	if(node1 != NULL) curr->child = node1;

	if(node2 != NULL) curr->child = node2;

	return temp->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Recursive approach:

	// base case:
	if(head == NULL || head->next == NULL) return head;

	return merge(head, flattenLinkedList(head->next));
}
