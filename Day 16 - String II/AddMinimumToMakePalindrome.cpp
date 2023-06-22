#include<bits/stdc++.h>

// bool isPalindrome(string& str) {
//     int left = 0;
//     int right = str.length() - 1;

//     while (left < right) {
//         if (str[left] != str[right]) {
//             return false;
//         }
//         left++;
//         right--;
//     }

//     return true;
// }

int minCharsforPalindrome(string& str) {
	
	/*
	// Brute force solution:
    int cnt = 0;
    while (!isPalindrome(str)) {
        str.pop_back();
        cnt++;
    }
    return cnt;
	*/

	// Approach 2: using 2 pointers:

	int cnt = 0;
    int i = 0;
    int j = str.length()-1;
    int k = j;

    while (i<j) {
        if (str[i] == str[j]) {
            i++;
            j--;
        }
        else {
            cnt++;
            i = 0;
            k--;
            j = k; 
        }
    }

    return cnt;
}
