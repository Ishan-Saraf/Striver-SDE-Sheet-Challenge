int maximumProduct(vector<int> &arr, int n) {
    int maxi = INT_MIN; // To store the maximum product found so far
    int mul = 1; // To store the current product of elements in the subarray

    // Traverse the array from left to right and calculate the maximum product ending at each element
    for (int i = 0; i < n; i++) {
        mul = mul * arr[i]; // Calculate the current product by multiplying the current element
        maxi = max(maxi, mul); // Update the maximum product found so far
        if (mul == 0) // If the current product becomes zero, reset it to 1
            mul = 1;
    }

    mul = 1; // Reset the product to 1 for the next traversal

    // Traverse the array from right to left and calculate the maximum product starting at each element
    for (int i = n - 1; i >= 0; i--) {
        mul = mul * arr[i]; // Calculate the current product by multiplying the current element
        maxi = max(maxi, mul); // Update the maximum product found so far
        if (mul == 0) // If the current product becomes zero, reset it to 1
            mul = 1;
    }

    return maxi; // Return the maximum product subarray
}
