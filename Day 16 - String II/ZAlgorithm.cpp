int zAlgorithm(string s, string p, int n, int m)
{
	/*
	// Approach 1: brute force:
    int cnt = 0;

    for (int i=0; i<=s.length()-p.length(); i++) {
        string temp = "";
        for (int j=i; j<i+p.length(); j++) {
            temp.push_back(s[j]);
        }

        if (temp == p){
            cnt++;
        }
    }

    return cnt;
	*/

	// Approach 2: Using Z algorithm

	// Create a vector to store the Z-values
    vector<int> z(n + m + 1, 0);

    // Concatenate the pattern and string with a separator '$'
    string str = p + "$" + s;
    int len = n + m + 1;

    int l = 0, r = 0;
    for (int i = 1; i < len; i++) {
        if (i > r) {
            // If i is outside the rightmost boundary, do a naive comparison
            l = r = i;
            while (r < len && str[r - l] == str[r]) {
                r++;
            }
            z[i] = r - l;
            r--;
        } else {
            // Use the previously computed Z-values
            int k = i - l;
            if (z[k] < r - i + 1) {
                // Z-value is less than the remaining right boundary
                z[i] = z[k];
            } else {
                // Z-value is at least the remaining right boundary
                l = i;
                while (r < len && str[r - l] == str[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }

    // Count the occurrences of the pattern
    int occurrences = 0;
    for (int i = m + 1; i < len; i++) {
        if (z[i] == m) {
            occurrences++;
        }
    }

    return occurrences;
}