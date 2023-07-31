// Helper function to convert the Binary Search Tree (BST) to Doubly Linked List (DLL)
void help(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev, BinaryTreeNode<int>*& head) {
    if (root == NULL)
        return;
    
    // In-order traversal of BST to build the DLL
    help(root->left, prev, head);

    // Link the current node to the previous node (prev)
    root->left = prev;
    
    // If head is not set, this is the first node, so update the head to the current node
    if (head == NULL)
        head = root;
    
    // Link the previous node (if exists) to the current node (next pointer in DLL)
    if (prev != NULL)
        prev->right = root;
    
    // Update the previous node to the current node for the next iteration
    prev = root;

    // Continue the in-order traversal
    help(root->right, prev, head);
}

// Main function to convert BST to DLL
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL; // Pointer to track the previous node during in-order traversal
    BinaryTreeNode<int>* head = NULL; // Pointer to store the head of the DLL
    
    // Call the helper function to build the DLL
    help(root, prev, head);
    
    return head; // Return the head of the DLL
}
