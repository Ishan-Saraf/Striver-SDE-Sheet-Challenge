int search(int* arr, int n, int key) {
    
    /*
    // Brute force:
        Just apply linear search.
        TC => O(n)
    */

    // Approach 2: Binary Search

    int lo = 0;
    int hi = n-1;

    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;

        if (arr[m] == key) {
            // If the middle element is equal to the key, return its index.
            return m;
        }
        else if (arr[lo] <= arr[m]) {
            // If the left half of the array is sorted in non-decreasing order.

            if (key >= arr[lo] && key <= arr[m]) {
                // If the key is within the range of the left half, update the high pointer to search the left half.
                hi = m - 1;
            }
            else {
                // If the key is outside the range of the left half, update the low pointer to search the right half.
                lo = m + 1;
            }
        }
        else {
            // If the right half of the array is sorted in non-decreasing order.

            if (key >= arr[m] && key <= arr[hi]) {
                // If the key is within the range of the right half, update the low pointer to search the right half.
                lo = m + 1;
            }
            else {
                // If the key is outside the range of the right half, update the high pointer to search the left half.
                hi = m - 1;
            }
        }
    }

    // If the key is not found, return -1.
    return -1;
}