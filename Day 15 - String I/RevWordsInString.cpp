#include<bits/stdc++.h>

string reverseString(string &str){
	// Approach 1: using a stack:

	stack<string> st;

	for (int i=0; i<str.length(); i++) {

		string word = ""; // to store words of sentence

		// adding word:
		while(str[i]!=' ' && i<str.size()){
			word+=str[i];
			i++;
		}

		// word finished, put into stack:
		if(!word.empty()){
			st.push(word);
		}
	}

	string ans = "";

	while (!st.empty()) {
		ans += st.top() + " ";
		st.pop();
	}

	// ans += st.top(); // so that last element doesn't have space.

	return ans;
	
	/*
	// Approach 2: without using stack:

	reverse(str.begin(), str.end());

    int start = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }

    // Reverse the last word
    reverse(str.begin() + start, str.end());

    // Remove leading and trailing spaces
    int left = 0, right = str.length() - 1;

    while (left < str.length() && str[left] == ' ') {
        left++;
    }
    while (right >= 0 && str[right] == ' ') {
        right--;
    }

	string ans = str.substr(left, right - left + 1);

    return ans;
	*/
}