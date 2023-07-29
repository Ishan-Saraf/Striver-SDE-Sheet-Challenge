int calculateMinPatforms(int at[], int dt[], int n) {
    // Sort the arrays of arrival and departure times in ascending order.
    sort(at, at + n);
    sort(dt, dt + n);

    int i = 0, j = 0; // Pointers to track the current positions in the sorted arrays.
    int ans = 0; // Variable to keep track of the number of platforms required at a given moment.
    int res = 0; // Variable to keep track of the minimum number of platforms required.

    // Traverse through the sorted arrays to calculate the number of platforms required at each moment.
    while (i < n && j < n) {
        // If the current train arrives before or at the same time as the current train departs,
        // it means a new platform is required for the arriving train.
        if (at[i] <= dt[j]) {
            ans++;
            i++;
        } else { // If the current train departs before the next train arrives,
                 // it means one platform can be freed up as the train has departed.
            ans--;
            j++;
        }

        // Update the minimum number of platforms required at any moment.
        res = max(res, ans);
    }

    return res; // Return the minimum number of platforms required.
}
