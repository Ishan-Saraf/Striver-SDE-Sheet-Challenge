#include <bits/stdc++.h>

// Function to add the solution to the answer vector
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;

    // Flatten the board to a 1D vector
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    // Add the solution to the answer vector
    ans.push_back(temp);
}

// Function to check if it is safe to place a queen at a specific position
bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // Check the column above the current position
    while (y >= 0) {
        if (board[x][y] == 1) return false; // If a queen is already placed, it's not safe
        y--;
    }

    x = row;
    y = col;

    // Check the upper-left diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) return false; // If a queen is already placed, it's not safe
        x--;
        y--;
    }

    x = row;
    y = col;

    // Check the lower-left diagonal
    while (x < n && y >= 0) {
        if (board[x][y] == 1) return false; // If a queen is already placed, it's not safe
        x++;
        y--;
    }

    // If it's safe to place a queen at the current position, return true
    return true;
}

// Recursive function to solve the N-Queens problem
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    // Base case: If all columns are processed, add the solution to the answer vector
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            // If it's safe to place a queen, mark the position as occupied
            board[row][col] = 1;

            // Recursively move to the next column
            solve(col + 1, ans, board, n);

            // Backtrack and remove the queen from the current position
            board[row][col] = 0;
        }
    }
}

// Function to find all possible solutions for the N-Queens problem
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize an empty board
    vector<vector<int>> ans; // Vector to store all possible solutions

    // Start the recursion to find solutions, starting from column 0
    solve(0, ans, board, n);

    return ans;
}