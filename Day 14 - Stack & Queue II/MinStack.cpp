#include <bits/stdc++.h> 

// Implement class for minStack.
class minStack
{
	// Approach 1: using pairs to store element + min element (O(1)+O(2N))

	// Approach 2:
	
	stack<int> s; // Main stack to store the elements
	int mini; // Variable to store the current minimum element

	public:
		
		// Constructor
		minStack() {}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if (s.empty()) {
				mini = num; // First element becomes the current minimum
				s.push(num);
			}

			else {
				if (mini <= num) {
					s.push(num); // If num is not smaller than the current minimum, push it directly
				}
				else {
					int prev = num;
					num = 2 * num - mini; // Adjust num to store the difference between num and the current minimum
					mini = prev; // Update the current minimum to prev
					s.push(num);
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(!s.empty()){
				int data = s.top();
				if(data >= mini){
					s.pop(); // If data is greater than or equal to the current minimum, simply pop it
					return data;
				}
				else{
					int prev = mini;
					mini = 2 * mini - data; // Recover the previous minimum using the stored difference
					s.pop();
					return prev; // Return the previous minimum
				}
			}
			return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(!s.empty()){
				int data = s.top();
				if(data >= mini) return data; // If data is greater than or equal to the current minimum, return it
				else return mini; // Otherwise return the current minimum
			}
			else return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(!s.empty()){
				return mini; // Return the current minimum
			}
			else return -1;
		}
};
