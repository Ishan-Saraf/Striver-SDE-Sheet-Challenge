#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int n = arr.size();
  /*
  // Approach 1: Brute force:

  int ans = 0;

  for (int i=0; i<n; i++) {
    int temp = 0;
    for (int j=i; j<n; j++) {
      temp += arr[j];
      if (temp == 0) {
          ans = max(ans, j-i+1);
      }
    }
  }

  return ans;
  */

  // Approach 2: using hashing (prefixsum):

  int k = 0;
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;

  for (int i=0; i<n; i++) {
    sum += arr[i];

    if (sum == k) {
      maxLen = max(maxLen, i+1);
    }

    // remaining
    long long rem = sum - k;

    if (preSumMap.find(rem) != preSumMap.end()) {
      int len = i - preSumMap[sum];
      maxLen = max(maxLen, len);
    }

    if (preSumMap.find(sum) == preSumMap.end()) {
      preSumMap[sum] = i;
    }
  }

  return maxLen;

  // Approach 3: 2 pointer approach (won't work if negatives are involved):

  /*
  int k = 0;

  int left = 0, right = 0;

  long long sum = arr[0];
  int maxLen = 0;

  while (right < n) {
    // if sum is greater than the target:
    while (left <= right && sum > k) {
      sum -= arr[left];
      left++;
    }

    if (sum == k) {
      maxLen = max(maxLen, right-left+1);
    }

    right++;
    if (right < n) {
      sum += arr[right];
    }
  }

  return maxLen;

  */
}