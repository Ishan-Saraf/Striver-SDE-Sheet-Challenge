#include <bits/stdc++.h>

// Function to check if it is possible to assign players to the given number of boards with the minimum distance 'mid'
bool canAssign(int c, int mid, vector<int> &positions) {
  int allot = 1, player = positions[0];
  for (int i = 1; i < positions.size(); i++) {
    if (positions[i] - player >= mid) { // Check if the distance between the current player and the previous player is greater than or equal to 'mid'
      allot++; // Increment the count of assigned players to a board
      player = positions[i]; // Update the current player
    }

    if (allot == c) // Check if all boards have been assigned players
      return true;
  }

  return false; // Not possible to assign players to all boards
}

// Function to find the minimum distance needed to assign players to boards such that each board has 'c' players
int chessTournament(vector<int> &positions, int n, int c) {
  sort(positions.begin(), positions.end()); // Sort the positions of players in ascending order
  int low = 1, high = positions[n - 1] - positions[0]; // Initialize the range of distances to search
  int ans = -1; // Initialize the answer to store the minimum distance

  while (low <= high) {
    int mid = low + (high - low) / 2; // Calculate the midpoint for binary search
    if (canAssign(c, mid, positions)) { // Check if it is possible to assign players with the minimum distance 'mid'
      ans = mid; // Update the answer to the current minimum distance
      low = mid + 1; // Search for a smaller distance in the higher range
    } else {
      high = mid - 1; // Search for a larger distance in the lower range
    }
  }
  return ans; // Return the minimum distance required
}
