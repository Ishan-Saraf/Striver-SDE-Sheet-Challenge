#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Approach 1: pick one and check (brute force) O(n2)

    // Approach 2: sorting and then checking

    sort(arr.begin(), arr.end());

    int ans = 1;
    int prev = arr[0];
    int cur = 1;
    
    for(int i = 1; i <n; i++){
        if(arr[i] == prev+1){
            cur++;
        }
        else if(arr[i] != prev){
            cur = 1;
        }
        prev = arr[i];
        ans = max(ans, cur);
    }
    return ans;
}