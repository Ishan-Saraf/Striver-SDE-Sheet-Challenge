double median(vector<int>& nums1, vector<int>& nums2) {
    // Optimized approach using binary searching:

    if (nums2.size() < nums1.size()) {
        // Ensure nums1 is smaller or equal in size to nums2 for ease of implementation
        return median(nums2, nums1);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0;
    int high = n1;

    while (low <= high) {
        int cut1 = (low + high) >> 1;  // Calculate the cut point for nums1
        int cut2 = (n1 + n2 + 1) / 2 - cut1;  // Calculate the cut point for nums2

        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];  // Left element of cut1 in nums1
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];  // Left element of cut2 in nums2

        int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];  // Right element of cut1 in nums1
        int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];  // Right element of cut2 in nums2

        if (l1 <= r2 && l2 <= r1) {
            // Correct partition is found

            if ((n1 + n2) % 2 == 0) {
                // If the total number of elements is even, calculate the average of the two middle elements
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else {
                // If the total number of elements is odd, return the maximum of the two middle elements
                return max(l1, l2);
            }
        }
        else if (l1 > r2) {
            // If the left elements are too large, adjust the cut point for nums1 towards the left
            high = cut1 - 1;
        }
        else {
            // If the right elements are too large, adjust the cut point for nums1 towards the right
            low = cut1 + 1;
        }
    }

    // Edge case: If the arrays are not sorted or valid, return 0.0 as the median
    return 0.0;
}
