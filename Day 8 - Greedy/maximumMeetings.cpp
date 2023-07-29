#include<bits/stdc++.h>

int maximumMeetings(vector<int> &start, vector<int> &finish) {
    vector<pair<int, pair<int, int>>> ans;

    // Create a vector of pairs containing the finish time as the first element,
    // and a pair of the meeting's index and start time as the second element.
    for (int i = 0; i < start.size(); i++) {
        ans.push_back({finish[i], {i + 1, start[i]}});
    }

    // Sort the vector in ascending order based on the finish time.
    sort(ans.begin(), ans.end());

    int e = -1; // Initialize the previous meeting's finish time to -1.
    int count = 0; // Initialize the count of meetings to 0.

    // Iterate through the sorted vector of meetings.
    for (auto val : ans) {
        // If the start time of the current meeting is greater than the previous meeting's finish time,
        // it means this meeting can be scheduled as there is no overlap with the previous one.
        if (val.second.second > e) {
            count++; // Increment the count of meetings.
            e = val.first; // Update the previous meeting's finish time to the current meeting's finish time.
        }
    }
    return count; // Return the maximum number of meetings that can be scheduled.
}
