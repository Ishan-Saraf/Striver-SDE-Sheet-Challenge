bool isPalindrome(string s) {
    int st=0;
    int ed=s.length()-1;

    while (st<=ed) {
        if (s[st++] != s[ed--]) return false;
    }

    return true;
}

string longestPalinSubstring(string s)
{
    int n = s.length();
    int maxLength = 0;
    string longestPalindrome;

    // Generate all possible substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            if (isPalindrome(sub) && sub.length() > maxLength) {
                maxLength = sub.length();
                longestPalindrome = sub;
            }
        }
    }

    return longestPalindrome;
}