#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    /*

        Approach 1: 4 loop approach
            O(n4)

    */

    // Approach 2: 4 pointer approach:

    sort(arr.begin(), arr.end());

    bool flag = false;

    for (int i=0; i<n; i++) {
        // if there is dup, increment:
        if (i>0 && arr[i] == arr[n-1])
            continue;
        
        for (int j=i+1; j<n; j++) {
            // if there is dup, increment:
            if (j>i+1 && arr[j] == arr[j-1])
                continue;

            int k = j+1; // left pointer
            int l = n-1; // right pointer

            while (k<=l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if (sum == target) {
                    flag = true;
                    k++;
                    l--;
                    
                    // if there is dup, increment:
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--;
                }

                else if (sum < target) k++;

                else l--;
            }
        }
    }

    if (flag == true) return "Yes";
    else return "No";
}
