#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	/*
	Approach 1:
		iterate over every element to find the missing & repeating no.
		TC - O(n2) & SC = O(1)

	Approach 2:
		use hashing to find the missing & repeating no.
		TC-O(2n) & SC - O(n)

	*/

	// Approach 3: (using Mathematical equasions)

	/*
	long long S = 0;
    long long S2 = 0;

    long long Sn = ((long long)n * ((long long)n + 1)) / 2;
    long long S2n = ((long long)n * ((long long)n + 1) * ((2 * (long long)n) + 1)) / 6;

    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S - Sn; // x-y
    long long val2 = S2 - S2n;

    val2 = val2 / val1; // x + y

    long long x = (val1 + val2) / 2;

    long long y = x - val1;

    return { (int)y, (int)x };
	*/

	// Approach 4: (XOR)

	int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {one, zero};
    return {zero, one};
}
