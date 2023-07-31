/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

// Global variable to keep track of the current position in the postOrder vector.
int posts;

// Recursive function to construct the binary tree from its postorder and inorder traversals.
TreeNode<int>* f(vector<int>& postOrder, vector<int>& inOrder, int is, int ie) {
     // Base case: If the inorder range is empty or posts has reached the beginning of postOrder vector, return NULL.
     if (is > ie || posts < 0) return NULL;
     
     // Create a new TreeNode with the value at the current position in the postOrder vector.
     TreeNode<int>* root = new TreeNode<int>(postOrder[posts--]);
     
     // Find the index of the root's data in the inorder vector.
     int inIn;
     for (int i = is; i <= ie; i++) {
          if (root->data == inOrder[i]) {
               inIn = i;
               break;
          }
     }
     
     // Recursively build the right and left subtrees.
     root->right = f(postOrder, inOrder, inIn + 1, ie);
     root->left = f(postOrder, inOrder, is, inIn - 1);
     
     // Return the root of the constructed binary tree.
     return root;
}

// Function to construct a binary tree from its postorder and inorder traversals.
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     // Initialize the posts variable to the last index of the postOrder vector.
     posts = postOrder.size() - 1;
     
     // Initialize the starting and ending indices for the inorder traversal.
     int is = 0;
     int ie = inOrder.size() - 1;
     
     // Call the recursive function to construct the binary tree.
     return f(postOrder, inOrder, is, ie);
}
