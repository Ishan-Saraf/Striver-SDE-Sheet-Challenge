#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){

    // Simply applying kadane's algo:
    int n = prices.size();

    int mini = prices[0];
    int profit = 0;

    for (int i=0; i<n; i++) {
        int cost = prices[i] - mini;
        profit = max(profit, cost);

        mini = min(mini, prices[i]);
    }

    return profit;
}