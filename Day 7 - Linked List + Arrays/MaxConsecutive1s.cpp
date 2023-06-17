int longestSubSeg(vector<int> &arr , int n, int k){
    /*

    // Approach 1: brute forcing:

    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int zeros = 0; // Count of zeros encountered so far

        for (int j = i; j < n; j++) {

            // Increment the count of zeros
            if (arr[j] == 0) {
                zeros++;

                // If the count of zeros exceeds k, break out of the loop
                if (zeros > k) {
                    break;
                }
            }

            // Length of the current sequence of ones
            int length = j - i + 1;
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;

    */

    // Approach 2: using sliding window technique:
    int maxLength = 0;
    int zerosCount = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (arr[right] == 0) {
            zerosCount++; // Increment the count of zeros
        }

        while (zerosCount > k) {
            if (arr[left] == 0) {
                zerosCount--; // Decrement the count of zeros
            }

            // Move the left pointer to slide the window
            left++;
        }

        // Length of the current window
        int length = right - left + 1;

        // Update the maximum length if needed
        maxLength = max(maxLength, length);
    }

    return maxLength;
}
