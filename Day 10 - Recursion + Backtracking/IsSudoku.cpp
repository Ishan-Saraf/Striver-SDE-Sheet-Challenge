// Check if it is safe to place the value 'val' at position (row, col) in the Sudoku matrix
bool isSafe(int row, int col, int matrix[9][9], int val) {
    for (int i = 0; i < 9; i++) {
        // Check if 'val' is already present in the current row or column
        if (matrix[row][i] == val || matrix[i][col] == val)
            return false;

        // Check if 'val' is already present in the 3x3 subgrid (box)
        if (matrix[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }

    // It is safe to place 'val' at position (row, col)
    return true;
}

// Recursive function to solve the Sudoku puzzle using backtracking
bool isItSudoku(int matrix[9][9]) {
    int n = 9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // If the current cell is empty (contains 0)
            if (matrix[i][j] == 0) {

                // Try placing values from 1 to 9 at the current cell
                for (int val = 1; val <= 9; val++) {

                    // Check if it is safe to place 'val' at position (i, j)
                    if (isSafe(i, j, matrix, val)) {

                        // If it is safe, place 'val' at position (i, j)
                        matrix[i][j] = val;

                        // Recursively call the function to solve the remaining Sudoku
                        bool flag = isItSudoku(matrix);

                        // If the recursive call returns true, it means the Sudoku is solved
                        if (flag == true)
                            return true;

                        // If the recursive call returns false, backtrack by resetting the current cell to 0
                        else
                            matrix[i][j] = 0;
                    }
                }

                // If all values from 1 to 9 are tried and none of them lead to a solution, backtrack.
                return false;
            }
        }
    }

    // If no empty cell is found, the Sudoku is solved.
    return true;
}
