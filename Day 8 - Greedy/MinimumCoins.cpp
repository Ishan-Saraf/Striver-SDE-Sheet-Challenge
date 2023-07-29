vector<int> MinimumCoins(int amount) {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // Available denominations of coins.
    vector<int> ans; // Vector to store the minimum number of coins needed.
    
    for (int i = 8; i >= 0; i--) {
        // Starting from the highest denomination (1000) and going down to the smallest (1).
        // Check if the current coin denomination can be used to reduce the given amount.
        while (amount >= coins[i]) {
            amount -= coins[i]; // Reduce the amount by the coin denomination.
            ans.push_back(coins[i]); // Add the coin denomination to the result vector.
        }
    }
    
    return ans; // Return the vector containing the minimum number of coins needed to represent the given amount.
}
