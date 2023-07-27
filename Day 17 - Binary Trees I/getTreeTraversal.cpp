#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void solve(BinaryTreeNode<int> *root,vector<int>&inord,vector<int>&pre,vector<int>&post){
    if(root==NULL) return;

    pre.push_back(root->data);

    solve(root->left,inord,pre,post);

    inord.push_back(root->data);

    solve(root->right,inord,pre,post);

    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<int> inord;
    vector<int> pre;
    vector<int> post;

    solve(root,inord,pre,post);

    vector<vector<int>> ans={inord,pre,post};
    
    return ans;
}