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

Node *firstNode(Node *head)
{
    /*
        Approach 1: can be done using map<Node *, bool> visited to
        keep track of visited nodes.
    */

    // Approach 2: using Floyd cycle detection algo:
    if (head == NULL) return NULL;
    if (head->next == NULL) return NULL;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && slow != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if (fast == slow) {
            break;
        }
    }

    // No loop exists in the LL
    if (fast == NULL) return NULL;

    slow = head;

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}