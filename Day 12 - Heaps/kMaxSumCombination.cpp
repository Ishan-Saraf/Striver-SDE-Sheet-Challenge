#include <bits/stdc++.h> 

#include<queue>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){

    // Create a max heap
    priority_queue<int> pq;

    // Generate all possible combinations of sum of elements from arrays a and b
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i]+b[j]);
        }   
    }

    vector<int> ans;

    // Extract the k largest sums from the max heap
    while(k--){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
