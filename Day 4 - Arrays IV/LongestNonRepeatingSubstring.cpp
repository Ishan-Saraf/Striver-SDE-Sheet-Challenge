#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    /*

    // Approach 1: Brute force:
    int n = input.size();

    if (n==0) return 0;

    int maxLen = INT_MIN;

    for (int i=0; i<n; i++) {
        unordered_set<int> set;

        for (int j=i; j<n; j++) {
            if (set.find(input[j]) != set.end()) {
                maxLen = max(maxLen, j-i);
                break;
            }

            set.insert(input[j]);
        }
    }

    return maxLen;

    // Approach 2: sliding window using set:

    if(input.size()==0)
      return 0;

    int maxans = INT_MIN;
    unordered_set < int > set;

    int l = 0; // initialize left pointer
    
    for (int r = 0; r < input.length(); r++)
    {
        //if duplicate element is found
        if (set.find(input[r]) != set.end()) {
            while (l < r && set.find(input[r]) != set.end()) {
                set.erase(input[l]);
                l++;
            }
        }

        // if not present:
        set.insert(input[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;

    */

    // Approach 3: sliding window using a map:

    int maxLen = 0;
    int right = 0;
    int left = 0;

    int n = input.size();
    vector<int> map(256, -1);

    while(right < n) {

        // instead of moving left one by one, we put it to the position where
        // repeating bit is present:
        if(map[input[right]] != -1) {
            left = max(map[input[right]]+1, left); // updating left pointer;
        }

        map[input[right]] = right;
        maxLen = max(maxLen, right-left+1);
        right++;
    }

    return maxLen;
}