# Sudoku-Game
This C program solves a 9×9 Sudoku puzzle using the Backtracking Algorithm. It finds empty cells, tries numbers (1-9), and checks their validity before placing them. If a number doesn’t work, it backtracks and tries another. The program prints both the original and solved Sudoku.
✅ Key Features:

Uses recursion & backtracking for solving.
Checks row, column, and 3×3 grid constraints.
Fast and efficient solution for Sudoku puzzles.
🔹 Run using GCC:

sh
Copy
Edit
gcc sudoku_solver.c -o sudoku_solver  
./sudoku_solver  
Great for practicing algorithms, recursion, and logical thinking! 🚀
🔹 Algorithm Explanation
Find an empty cell (0) in the grid.
Try placing numbers (1-9) in the empty cell.
Check if the number is valid (not repeated in row, column, or 3×3 subgrid).
If valid, recursively solve the next empty cell.
If no valid number exists, backtrack to the previous cell.
Repeat until the grid is solved.
📝 C Code for Sudoku Solver
c
Copy
Edit
#include <stdio.h>

#define N 9  // Size of Sudoku Grid

// Function to print the Sudoku Grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number is safe to place in a given cell
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) return 0;
    }

    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) return 0;
    }

    // Check 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return 0;
        }
    }
    return 1;
}

// Backtracking function to solve Sudoku
int solveSudoku(int grid[N][N]) {
    int row, col, emptyFound = 0;

    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptyFound = 1;
                break;
            }
        }
        if (emptyFound) break;
    }

    // If no empty cell is found, the Sudoku is solved
    if (!emptyFound) return 1;

    // Try placing numbers 1-9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solveSudoku(grid)) return 1;

            // If solution doesn't work, backtrack
            grid[row][col] = 0;
        }
    }
    return 0;
}

// Main function
int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku Puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists!\n");
    }
    
    return 0;
}
🔹 How to Run the Program?
Save the code as sudoku_solver.c
Compile and run using GCC (Linux/Mac/Windows with MinGW):
sh
Copy
Edit
gcc sudoku_solver.c -o sudoku_solver
./sudoku_solver
It will print the solved Sudoku grid.
📝 Example Output
Input Sudoku:
markdown
Copy
Edit
5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
---------------------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
---------------------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9
Solved Sudoku:
markdown
Copy
Edit
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
---------------------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
---------------------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
🔹 Why This is a Good Project?
✅ Uses Backtracking – A key algorithm in problem-solving.
✅ Real-world application – Useful for puzzle-solving software.
✅ Good for GitHub – Showcases your logic and coding skills.

🚀 Next Steps (Improvements)
🔹 Take user input instead of hardcoded Sudoku.
🔹 Optimize with bitwise operations for faster solving.
🔹 Add a GUI using C & GTK or C++ & OpenGL.

Would you like help improving this project further? 🚀
