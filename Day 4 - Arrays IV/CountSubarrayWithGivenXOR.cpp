#include <bits/stdc++.h>

int subarraysXor(vector<int> &a, int k)
{
    // Approach 1: brute force with 2 loops to find the cnt;

    // Approach 2: using hashing:

    int xr = 0; // this will keep track of the overall xor value

    map<int, int> mpp;

    mpp[xr]++; // starting with (0, 1)

    int cnt = 0;

    for (int i = 0; i < a.size(); i++) {
      xr = xr ^ a[i]; // updating xr each iteration

      int x = xr ^ k; //This represents the value that if XORed with xr would give k
      cnt += mpp[x];
      mpp[xr]++;
    }

    return cnt;
}