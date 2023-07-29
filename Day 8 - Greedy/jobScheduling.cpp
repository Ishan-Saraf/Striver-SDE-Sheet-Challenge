#include<bits/stdc++.h>

bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[2] > job2[2]; // Sort in descending order of profit
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare); // Sort the jobs in non-increasing order of profit

    int maxProfit = 0; // Variable to store the maximum profit earned
    int numberOfJobs = 0; // Variable to store the number of jobs scheduled
    int maxDeadline = 0; // Variable to store the maximum deadline among all jobs

    // Find the maximum deadline among all the jobs
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }

    // Create a set "slots" to keep track of available time slots in descending order
    set<int, greater<int>> slots;

    // Insert all the elements from maxDeadline to 1 into the set
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }

    vector<int> ans; // Vector to store the result

    for (int i = 0; i < jobs.size(); i++)
    {
        // If the set is empty or the deadline is less than the last element of the set,
        // then ignore this job as there is no available time slot to schedule it.
        if (slots.size() == 0 || jobs[i][1] < *slots.rbegin())
        {
            continue;
        }

        // Find the first available time slot that is greater than or equal to the job's deadline
        int availableSlot = *slots.lower_bound(jobs[i][1]);

        // Add the job's profit to the maxProfit
        maxProfit = maxProfit + jobs[i][2];

        // Increment the numberOfJobs
        numberOfJobs += 1;

        // Remove the scheduled time slot from the set as it is now occupied
        slots.erase(availableSlot);
    }

    // Store the numberOfJobs and maxProfit in the result vector
    ans.push_back(numberOfJobs);
    ans.push_back(maxProfit);

    // Return the result vector
    return ans;
}
