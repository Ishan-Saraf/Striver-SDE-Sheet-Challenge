#include<bits/stdc++.h>

// Function to find the next smaller element
vector<int> nextSmallerElement(vector<int> arr, int n) {
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);

  for (int i=n-1; i>=0; i--) {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr) {
      s.pop();
    }

    ans[i] = s.top();
    s.push(i);
  }

  return ans;
}

// Function to find the previous smaller element
vector<int> previousSmallerElement(vector<int> arr, int n) {
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);

  for (int i=0; i<n; i++) {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr) {
      s.pop();
    }

    ans[i] = s.top();
    s.push(i);
  }

  return ans;
}

// Function to calculate the largest rectangle area
int largestRectangle(vector<int> & heights) {

  // Calculate the next smaller and previous smaller elements
  int n = heights.size();
  vector<int> next(n);
  next = nextSmallerElement(heights, n);

  vector<int> prev (n);
  prev = previousSmallerElement(heights, n);

  int max_area = INT_MIN;

  // Calculate the area for each rectangle and find the maximum
  for (int i=0; i<n; i++) {
    int length = heights[i];

    // If there is no next smaller element, consider it as the end of the array
    if (next[i] == -1) {
      next[i] = n;
    }

    int breadth = next[i] - prev[i] - 1;

    int curr_area = length * breadth;

    max_area = max(curr_area, max_area);
  }

  return max_area;
}
