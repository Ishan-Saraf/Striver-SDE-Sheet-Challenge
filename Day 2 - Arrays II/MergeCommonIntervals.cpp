#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    // sorting the intervals:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    /*

    for (int i=0; i<n; i++) {

        // initializing start & end:
        int start = intervals[i][0];

        int end = intervals[i][1];

        // continue expanding the interval till there is a bigger ending value:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        for (int j = i+1; j<n; j++) {
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            }
            else {
                break;
            }
        }

        ans.push_back({start, end});
    }

    */

    // Approach 2: Doing in a single pass:

    for (int i=0; i<n; i++) {
        // insert if answer array is empty or a new interval value is found:
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        }

        // expanding to merge common intervals:
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}
