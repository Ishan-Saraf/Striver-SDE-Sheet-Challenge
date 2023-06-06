#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // if only single row|col is there:
    if (n==1 || m==1) {
        return;
    }

    int top = 0, bottom = n-1, left = 0, right = m-1;

    while (top <bottom && left < right) {
        int temp = mat[left][top];

        // top:
        for(int i=top; i<bottom; i++) {
            mat[i][left] = mat[i+1][left];
        }

        // left:
        for(int i=left; i<right; i++) {
            mat[bottom][i] = mat[bottom][i+1];
        }

        // bottom:
        for(int i=bottom; i>top; i--)
            mat[i][right] = mat[i-1][right];
            
        // right:
        for(int i=right; i>left+1; i--)
            mat[top][i] = mat[top][i-1];


        mat[top][left+1] = temp;

        // moving inside:
        top++, bottom--,left++,right--;
    }
}