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
