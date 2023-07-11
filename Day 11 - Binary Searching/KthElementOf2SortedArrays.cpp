#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &nums1, vector<int> &nums2, int m, int n, int k) {
    /*

		// Approach 1: using the merge operation of mergeSort();
		(can further optimize the SC by using the specific elements only by using a counter)

		TC = O(m+n), SC = O(1);

	*/

    // Optimized approach using binary searching:

    if (nums2.size() < nums1.size()) {
        // Ensure nums1 is smaller or equal in size to nums2 for ease of implementation
        return ninjaAndLadoos(nums2, nums1, n, m, k);
    }

    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high) {
        int cut1 = (low + high) >> 1;  // Calculate the cut point for nums1
        int cut2 = k - cut1;  // Calculate the cut point for nums2

        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];  // Left element of cut1 in nums1
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];  // Left element of cut2 in nums2

        int r1 = cut1 == m ? INT_MAX : nums1[cut1];  // Right element of cut1 in nums1
        int r2 = cut2 == n ? INT_MAX : nums2[cut2];  // Right element of cut2 in nums2

        if (l1 <= r2 && l2 <= r1) {
            // Correct partition is found
            return max(l1, l2);
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
    return 1;
}
