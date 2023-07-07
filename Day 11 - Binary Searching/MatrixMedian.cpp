# include<bits/stdc++.h>

// Helper function to count the number of elements smaller than or equal to 'mid' in a row
int countSmallerThanMid(vector<int> &row, int mid) {
    int l = 0;
    int h = row.size() - 1;

    // Binary search to find the count of elements smaller than or equal to 'mid'
    while (l <= h) {
        int m = (l + h) / 2;

        if (row[m] <= mid)
            l = m + 1;
        else
            h = m - 1;
    }

    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    /*
    // Approach 1: brute forcing:

    vector<int> temp;

    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            temp.push_back(matrix[i][j]);
        }
    }

    sort(temp.begin(), temp.end());

    if (temp.size()%2 != 0)
        return temp[temp.size()/2];
    else return temp[temp.size()/2 + 1];
    */

    // Approach 2: using binary searching:

    int start = INT_MAX;
    int end = INT_MIN;

    int n = matrix.size();
    int m = matrix[0].size();

    // Finding the minimum and maximum values in the matrix
    for (int i = 0; i < n; i++) {
        start = min(start, matrix[i][0]);
        end = max(end, matrix[i][m - 1]);
    }

    // Calculating the position of the median element in the flattened matrix
    int midPos = (n * m - 1) / 2;

    // Binary search on the range of values between 'start' and 'end'
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int cnt = 0;

        // Counting the number of elements smaller than or equal to 'mid' in each row
        for (int i = 0; i < n; i++) {
            cnt += countSmallerThanMid(matrix[i], mid);
        }

        // Updating 'start' or 'end' based on the count
        if (cnt <= (n * m) / 2)
            start = mid + 1;
        else
            end = mid - 1;
    }

    // 'start' holds the median element value
    return start;
}