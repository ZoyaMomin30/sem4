#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the solution
void printSolution(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed safely at board[row][col]
bool isSafe(int **board, int row, int col, int N) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int **board, int col, int N) {
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing a queen in each row of this column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove the queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }

    // If queen can't be placed in any row in this column, return false
    return false;
}

// Function to solve the N-Queens problem and print the solution
void nQueens(int N) {
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        board[i] = (int *)calloc(N, sizeof(int));

    if (solveNQueens(board, 0, N) == false) {
        printf("Solution does not exist");
        return;
    }

    printSolution(board, N);

    // Free allocated memory
    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
}

int main() {
    int N;
    printf("Enter the size of the chessboard: ");
    scanf("%d", &N);
    nQueens(N);
    return 0;
}
