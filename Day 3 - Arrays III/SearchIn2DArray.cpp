bool searchMatrix(vector<vector<int>>& mat, int target) {
    /*

    Approach 1:
        Use linear search to traverse whole matrix to find the target value.
        TC=O(n*m), SC=O(1)

    Approach 2:
        Use binary search in each row to find the target value.
        TC=O(n*logm), SC=O(1)

    */

    // Approach 3:

    /*
    int i = 0;
    int j = mat.size()-1;

    while (i<mat.size() && j>=0) {
        if (mat[i][j] == target) {
            return true;
        }

        if (mat[i][j] > target) {
            j--;
        }

        else {
            i++;
        }
    }

    return false;
    */

    // Approach 4: (using modified binary searching)

    int n = mat.size();
    int m = mat[0].size();

    if (n==0) return false;

    int lo = 0;
    int hi = (n*m) - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if (mat[mid/m][mid%m] == target) {
            return true;
        }

        if (mat[mid/m][mid%m] < target) {
            lo = mid + 1;
        }

        else {
            hi = mid - 1;
        }
    }

    return false;
}