#include <bits/stdc++.h> 

bool comp(pair<int, int>& a, pair<int, int>& b) {
    // Custom comparator to sort items based on their value per unit weight (value/weight) in non-increasing order.
    return ((double) a.second / a.first) > ((double) b.second / b.first);
}

double maximumValue(vector<pair<int, int>>& items, int n, int w) {
    // Function to find the maximum value that can be obtained from a given set of items
    // with a total weight constraint 'w'.
    // Takes a vector 'items' containing pairs of (weight, value) of each item,
    // 'n' as the number of items, and 'w' as the total weight constraint.

    double ans = 0;
    // Initialize 'ans' to store the total value of selected items.

    sort(items.begin(), items.end(), comp);
    // Sort the 'items' vector in non-increasing order based on the value per unit weight using the custom comparator 'comp'.

    for (int i = 0; i < n; i++) {
        // Iterate through the sorted 'items' vector.

        if (items[i].first <= w) {
            // If the weight of the current item is less than or equal to the remaining weight 'w',
            // the entire item can be selected.

            ans += items[i].second;
            // Add the value of the selected item to the total 'ans'.

            w -= items[i].first;
            // Reduce the remaining weight 'w' by the weight of the selected item.
        } else {
            // If the weight of the current item is greater than the remaining weight 'w',
            // only a fraction of the item can be selected.

            double temp = (double)(w / (double) items[i].first) * (double)(items[i].second);
            // Calculate the value of the fraction of the item that can be selected based on the remaining weight 'w'.

            ans += temp;
            // Add the value of the selected fraction to the total 'ans'.

            break;
            // Break the loop as the remaining weight is fully utilized, and no more items can be selected.
        }
    }

    return ans;
    // Return the total value 'ans' of the selected items.
}
