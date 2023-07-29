#include<bits/stdc++.h>

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    // Custom comparator to sort activities based on finish times.
    // If finish times are equal, compare start times.
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Function to find the maximum number of non-overlapping activities.
    // Takes two vectors 'start' and 'finish' representing start and finish times of activities.

    vector<pair<int, pair<int, int>>> v;
    // Create a vector 'v' to store activities as pairs with (start, (finish, index)).
    // 'index' represents the index of the activity in the original input.

    for (int i = 0; i < start.size(); i++) {
        // Fill the 'v' vector with activities as pairs.
        v.push_back({start[i], {finish[i], i + 1}});
        // 'i + 1' is used as the index starts from 1 (not 0) in the output.
    }

    sort(v.begin(), v.end(), cmp);
    // Sort the 'v' vector using the custom comparator 'cmp'.
    // The sorting is done based on increasing finish times.
    // In case of equal finish times, activities with smaller start times are placed first.

    int l = v[0].second.first;
    // Initialize 'l' with the finish time of the first activity (activity with the earliest finish time).
    int c = 1;
    // Initialize the counter 'c' to keep track of the selected non-overlapping activities.
    // The first activity is always selected initially.

    for (int i = 1; i < start.size(); i++) {
        // Iterate through the sorted 'v' vector from the second activity onward.

        if (v[i].first >= l) {
            // If the start time of the current activity is greater than or equal to 'l',
            // it means the current activity can be selected without overlapping with the previous ones.

            c++; // Increment the counter 'c' to count the selected non-overlapping activity.
            l = v[i].second.first;
            // Update 'l' with the finish time of the current activity.
            // This ensures that the next selected activity will not overlap with the current one.
        }
    }

    return c;
    // Return the value of 'c', which represents the maximum number of non-overlapping activities that can be performed.
}
