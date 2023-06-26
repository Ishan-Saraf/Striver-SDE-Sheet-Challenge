void sortedInsert(stack<int> &stack, int num) {
	// Base case: if stack is empty or top element is smaller than num, push num
	if (stack.empty() || (!stack.empty() && stack.top() < num)) {
		stack.push(num);
		return;
	}

	int temp = stack.top();
	stack.pop();

	// Recursive call: recursively insert num in the correct position
	sortedInsert(stack, num);

	stack.push(temp);
}

void sortStack(stack<int> &stack) {
	// Solving through recursive approach:

	// Base case: if stack is empty, no further sorting needed
	if (stack.empty()) return;

	int num = stack.top();
	stack.pop();

	// Recursive calling: sort the remaining stack
	sortStack(stack);

	// Insert the current element in the sorted stack
	sortedInsert(stack, num);
}
