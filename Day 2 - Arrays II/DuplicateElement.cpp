#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	/*
	
	Approach 1:
		1. Sort the array
		2. return the element who satisfy the condition arr[i] == arr[i+1]

	Approach 2:
		1. Create a frequency array
		2. add frequency of all elements
		3. return element whose frequency > 1

	*/

	// Approach 3:

	int fast = arr[0];
	int slow = arr[0];

	// Traverse in a cyclic order till slow & fast pointer collides:
	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while (slow != fast);

	// after collision set fast to initial position:
	fast = arr[0];

	while (slow != fast) {
		slow = arr[slow];
		fast = arr[fast]; // moving at same speed
	}

	return slow; // The repeating element will be this one;
}
