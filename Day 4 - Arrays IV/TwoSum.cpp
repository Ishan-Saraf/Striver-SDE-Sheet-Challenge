#include <bits/stdc++.h>

/*
    Approach 1:
        find all possible pairs and return those who match the target sum.
        O(n2), O(1)
    
    Approach 2:
        using a hash map to store the values and using the hashmap to check
        if the current value matches the target value.
        O(n), O(n)
*/

vector<vector<int>> pairSum(vector<int> &arr, int s){

   // using 2 pointer approach:
   sort(arr.begin(), arr.end());

   vector<vector<int>> ans;

   int j = 0;

   for (int i = 0; i<arr.size(); i++) {
      int currSum = arr[i]+arr[j];

      if (currSum == s) {
        ans.push_back({arr[j], arr[i]});
      }

      /* using a modified approach that handles cases where multiple
      pairs have the same value and finds all valid pairs that sum up
      to the target sum
      */

      if (currSum > s || (i == arr.size()-1) && j < arr.size()) {
         j++;
         i = j;
      }
   }

   return ans;
}