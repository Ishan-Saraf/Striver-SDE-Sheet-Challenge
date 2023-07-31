string longestPalinSubstring(string str)
{
    int n = str.length();
    int mx = 1; // Variable to store the length of the longest palindromic substring found so far.
    int start = 0; // Variable to store the starting index of the longest palindromic substring.

    // Iterate over the string, considering each character as the center of the palindrome (odd and even-length palindromes).
    for (int i = 1; i <= n; i++) {
        int l = i - 1; // Left pointer for odd-length palindrome (centered at str[i-1]).
        int r = i; // Right pointer for odd-length palindrome (centered at str[i-1]).
        
        // Check for odd-length palindromes.
        while (l >= 0 && r < n && str[l] == str[r]) {
            if (r - l + 1 > mx) {
                mx = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }

        l = i - 1; // Reset the left pointer for even-length palindrome (centered between str[i-1] and str[i]).
        r = i + 1; // Reset the right pointer for even-length palindrome (centered between str[i-1] and str[i]).
        
        // Check for even-length palindromes.
        while (l >= 0 && r < n && str[l] == str[r]) {
            if (r - l + 1 > mx) {
                mx = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    // Return the longest palindromic substring using substr() function.
    return str.substr(start, mx);
}
