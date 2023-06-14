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

Node *findIntersection(Node *h1, Node *h2)
{
    /*
    // Approach 1: brute force:

    while (h2 != NULL) {
        Node *temp = h1;
        while (temp != NULL) {
            if (temp == h2) return h2; // found intersecting node
            temp = temp->next;
        }
        h2 = h2->next;
    }

    return NULL; // not found;

    // Approach 2: 2 pointer:

    Node *dummy1 = h1;
    Node *dummy2 = h2;

    int len1 = 0, len2 = 0;

    // getting the length of 2 LLs:
    while (dummy1 != NULL || dummy2 != NULL) {
        if (dummy1 != NULL) {
            len1++;
            dummy1 = dummy1->next;
        }

        if (dummy2 != NULL) {
            len2++;
            dummy2 = dummy2->next;
        }
    }

    Node* smaller = NULL;
    Node* bigger = NULL;

    int diff = 0;

    // setting the bigger & smaller LLs:
    if (len1 > len2) {
        bigger = h1;
        smaller = h2;
        diff = len1-len2;
    }
    
    else {
        bigger = h2;
        smaller = h1;
        diff = len2 - len1;
    }

    // moving bigger ll diff times
    while (diff--) {
        bigger = bigger->next;
    }

    // now moving both at same pace:
    while(bigger != NULL || smaller != NULL) {
        if(bigger == smaller) return bigger; // collision, return ans
        bigger = bigger->next;
        smaller = smaller->next;
    }
    // no collision, not found
    return NULL;

    */

    // Approach 3: similar to above but shorter:

    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }

    Node *d1 = h1;
    Node *d2 = h2;

    while (d1 != d2) {
        /*
            working:
                1. At first keep moving the pointer till it reaches NULL
                2. When the pointer reach Null, move it to the head of other list.
                3. do this for both of the dummies and eventually they will collide
        */
        d1 = d1 == NULL ? h2 : d1->next;
        d2 = d2 == NULL ? h1 : d2->next;
    }

    return d1; // returning the collision value
}