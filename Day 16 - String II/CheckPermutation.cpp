#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    /*
    // Apprach 1: using hashmap

    if (str1.length() != str2.length())
        return false;

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    for (int i=0; i<str1.length(); i++) {
        count1[str1[i]-'a'] += 1;
    }

    for (int i=0; i<str2.length(); i++) {
        count2[str2[i]-'a'] += 1;
    }

    for (int i=0; i<26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;

    // Approach 2: using sorting:
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i=0; i<str1.length(); i++) {
        if (str1[i] != str2[i]) return false;
    }

    return true;

    */

    // Approach 3: optimizing approach 1:
    if (str1.length() != str2.length())
        return false;

    int count[26] = {0};

    for (int i = 0; i < str1.length(); i++) {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}