#include<bits/stdc++.h>

bool isValidParenthesis(string expression)
{
    // Approach: using stack

    // If the expression length is odd, it cannot be balanced
    if (expression.length() % 2 != 0)
        return false;

    stack<char> st;

    for (int i = 0; i < expression.length(); i++) {
        // If an opening bracket is encountered, push it onto the stack
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            st.push(expression[i]);
        }
        else {
            // If there are no opening brackets in the stack, it is not balanced
            if (st.empty())
                return false;

            // Get the topmost opening bracket from the stack
            char top = st.top();
            st.pop();

            // If the current closing bracket matches the top opening bracket, continue to the next iteration
            if ((expression[i] == ')' && top == '(') ||
                (expression[i] == ']' && top == '[') ||
                (expression[i] == '}' && top == '{')) {
                    continue;
                }
            
            // If the current closing bracket does not match the top opening bracket, the expression is not balanced
            else
                return false;
        }
    }

    // If there are still opening brackets left in the stack, the expression is not balanced
    if (!st.empty())
        return false;

    // If all brackets are matched and the stack is empty, the expression is balanced
    else
        return true;
}
