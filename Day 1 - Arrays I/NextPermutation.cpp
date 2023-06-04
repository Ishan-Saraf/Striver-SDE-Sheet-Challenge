/* 

Brute force approach will be:
    1. Find all the possible permutations of the arr.
    2. find the index of the given arr.
    3. return the next index present in the range.

*/

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &a, int n)
{
    // checking edge case:
    int idx = -1;

    for (int i=n-2; i>=0; i--) {
        if (a[i] < a[i+1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        reverse(a.begin(), a.end());
        return a;
    }

    // finding the smallest greatest element:
    for (int i=n-1; i>idx; i--) {
        if (a[i] > a[idx]) {
            swap(a[i], a[idx]);
            break;
        }
    }

    reverse(a.begin()+idx+1, a.end()); // reverse the arr after the next smallest greatest element
    
    return a;
}

// can also be done using the next_permutation(arr.begin(), arr.end()) STL;

