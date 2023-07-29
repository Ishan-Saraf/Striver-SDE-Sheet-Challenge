long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Create an array 'dp' to store the number of ways to make change for each value from 0 to 'value'.
    long *dp = new long[value + 1]();
    dp[0] = 1; // There is one way to make change for value 0 (by not choosing any denomination).

    // Outer loop iterates over each denomination.
    for (int i = 0; i < n; i++)
    {
        // Inner loop starts from the current denomination and goes up to the target value.
        for (int j = denominations[i]; j <= value; j++)
        {
            // For each value 'j', update 'dp[j]' by adding the number of ways to make change for 'j - denominations[i]'.
            // This is because we can make change for 'j' by either including or excluding the current denomination 'denominations[i]'.
            dp[j] += dp[j - denominations[i]];
        }
    }

    // The final answer is stored in dp[value], which represents the number of ways to make change for the target value 'value'.
    return dp[value];
}
