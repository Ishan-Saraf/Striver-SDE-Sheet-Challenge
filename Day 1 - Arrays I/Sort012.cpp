#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   /*

   // Approach 1:
   sort(arr, arr+n);

   // Approach 2:

   int count0 = 0;
   int count1 = 0;
   int count2 = 0;

   for (int i=0; i<n; i++) {
      if (arr[i] == 0) count0++;
      if (arr[i] == 1) count1++;
      if (arr[i] == 2) count2++;
   }

   for (int i = 0; i < count0; i++) arr[i] = 0; // replacing 0's

   for (int i = count0; i < count0 + count1; i++) arr[i] = 1; // replacing 1's

   for (int i = count0 + count1; i < n; i++) arr[i] = 2; // replacing 2's

   */

   // Approach 3 (Dutch National Flag Algo):

   int low=0, mid=0, high=n-1;

   while (mid<=high) {
      // case 1:
      if (arr[mid] == 0) {
         swap(arr[low++], arr[mid++]);
      }

      // case 2:
      else if (arr[mid] == 1) {
         mid++;
      }

      // case 3:
      else {
         swap(arr[mid], arr[high--]);
      }
   }
}