#include <bits/stdc++.h> 

vector<int> prefix_function(string s) {
    int n = s.length();

    vector<int> p(n, 0);

    for (int i=1; i<n; i++) {
        int j = p[i-1];

        while (j>0 && s[i] != s[j]) {
            j = p[j-1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        p[i] = j;
    }

    return p;
}

bool findPattern(string p, string s)
{
    /*
    // brute force:
    bool flag = false;

    for (int i=0; i<=s.length()-p.length(); i++) {
        string temp = "";
        for (int j=i; j<i+p.length(); j++) {
            temp.push_back(s[j]);
        }

        if (temp == p){
            flag = true;
            break;
        }
    }

    return flag;
    */

    // Approach 2: Using KMP algorithm:

    vector<int> prefix = prefix_function(p);

    bool flag = false;

    int i(0), j(0);

    while (i<s.length()) {
        if (s[i] == p[j]) {
            i++;
            j++;
        }

        else {
            if (j != 0) {
                j = prefix[j-1];
            }

            else {
                i++;
            }
        }

        if (j == p.length()) {
            flag = true;
            break;
        }
    }

    return flag;
}