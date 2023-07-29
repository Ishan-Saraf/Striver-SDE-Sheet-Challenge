bool wordBreak(vector<string> &arr, int n, string &s) {
    // Create a set 'st' to store all the words from the given list 'arr'.
    set<string> st;
    for (int i = 0; i < arr.size(); i++)
        st.insert(arr[i]);

    int i = 0; // Initialize a pointer 'i' to traverse the string 's'.
    string temp; // Initialize an empty string 'temp' to store the current substring being checked for being a word.
    int idx = -1; // Initialize 'idx' to keep track of the index where a word is found in 's'.

    while (i < s.size()) {
        temp += s[i]; // Append the character at index 'i' to 'temp'.
        if (st.find(temp) != st.end()) {
            // If the substring 'temp' is found in the set 'st', it is a valid word.
            idx = i; // Update 'idx' to the current index 'i'.
            temp = ""; // Reset 'temp' to an empty string for the next substring.
        }
        i++; // Move to the next character in 's'.
    }

    // If the last valid word ends at the last index of 's', then the entire string 's' can be segmented into words.
    if (idx == s.size() - 1)
        return true;
    return false;
}
