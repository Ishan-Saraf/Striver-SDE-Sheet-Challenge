#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long ans = 1;

	while (n>0) {
		// even power:
		if (n%2==0) {
			x = ((long long)x*(long long)x)%m;
			n /= 2;
		}
		// odd power:
		else {
			ans = (ans*(long long)x)%m;
			n--;
		}
	}

	return (int)ans;
}