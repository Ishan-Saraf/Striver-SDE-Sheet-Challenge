#include <bits/stdc++.h> 

// Function to check if it is possible to complete tasks within the given time duration and number of ninjas
bool ispossible(long long & hpd, int& limit, vector<int> &times){
    long long count = 1, sum = 0;
    for(int &time: times){
        // Check if the current time duration exceeds the maximum time duration a ninja can work
        if(time > hpd)
            return false;
        
        // Check if the cumulative time and current time duration can be handled by the current ninja
        if(sum + time <= hpd)
            sum += time;
        else {
            // Increment the count to represent the usage of an additional ninja
            count++;
            // Reset the cumulative time to the current time duration as a new ninja needs to handle the task
            sum = time;
        }
    }
    // Check if the number of ninjas used is less than or equal to the maximum limit
    return count <= limit;
}

// Function to find the minimum possible time duration that allows all tasks to be completed within the given number of ninjas
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{   
    long long l = 1, r = LLONG_MAX, mid;
    while(l < r){
        // Calculate the midpoint for binary search
        mid = l + (r - l) / 2;
        
        // Check if it is possible to complete tasks within the current time duration
        if(ispossible(mid, n, time))
            r = mid;
        else
            l = mid + 1;
    }
    // Return the minimum possible time duration
    return l;
}
