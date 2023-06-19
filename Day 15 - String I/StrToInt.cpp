#include <bits/stdc++.h> 
int atoi(string str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handling the sign if present
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    // Checking & Converting each character to integer and forming the number
    while (i < str.length()) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        
        else {
            i++;
        }
    }

    // Applying the sign to the result
    result *= sign;

    return result;
}