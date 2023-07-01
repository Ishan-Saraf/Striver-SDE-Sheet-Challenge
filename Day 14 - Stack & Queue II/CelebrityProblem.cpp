# include<bits/stdc++.h>

/*
    This is the signature of the helper function 'knows'.
    You should not implement it or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will return "true" if the person having
    ID 'A' knows the person having ID 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {

    stack<int> s;

    // Step 1: Push all elements into the stack.
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities by pairwise comparison.
    while (s.size() > 1) {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(a, b)) {
            // If 'a' knows 'b', 'a' cannot be the celebrity, push 'b' back to the stack.
            s.push(b);
        } else {
            // If 'a' does not know 'b', 'b' cannot be the celebrity, push 'a' back to the stack.
            s.push(a);
        }
    }

    // Step 3: The single element in the stack is a potential celebrity, verifying:
    int candidate = s.top();

    int celecount = 0;

    // Count the number of people who know the candidate.
    for (int i = 0; i < n; i++) {
        if (knows(candidate, i))
            celecount++;
    }

    // If the candidate is known by someone, it is not a celebrity.
    if (celecount != 0) return -1;

    int peoplecount = 0;

    // Count the number of people the candidate knows.
    for (int i = 0; i < n; i++) {
        if (knows(i, candidate))
            peoplecount++;
    }

    // If the candidate does not know everyone except themselves, it is not a celebrity.
    if (peoplecount != n - 1) return -1;

    return candidate; // Return the ID of the celebrity.
}
