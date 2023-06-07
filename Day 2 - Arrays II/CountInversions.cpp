#include <bits/stdc++.h> 

// modified merge sort algorithm:
long long merge(long long *arr, int low, int mid, int high) {

    int left = low;
    int right = mid + 1;

    long long count = 0;

    vector<long long> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;

        } else {
            temp.push_back(arr[right]);
            right++;
            count += (mid - left + 1);  // Increment the count for inversions
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return count;
}

long long merges(long long *arr, int low, int high) {

    long long count = 0;

    if (low < high) {

        int mid = (low + high) / 2;

        count += merges(arr, low, mid);
        count += merges(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }

    return count;
}

long long mergesort(long long *arr, int n) {
    return merges(arr, 0, n - 1);
}

long long getInversions(long long *arr, int n){

    /*
    Approach 1:
        Run 2 loops to check if (a[i] > a[j])
    */

    // Approach 2 (using merge sort):

    return mergesort(arr, n);
}