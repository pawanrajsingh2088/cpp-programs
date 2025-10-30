#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard
void printBoard(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed safely
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: all queens are placed
    if (row == N) {
        printBoard(board, N);
        return true; // print one solution, can continue to find others
    }

    bool foundSolution = false;

    // Try placing queen in all columns of current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // place queen
            foundSolution = solveNQueens(board, row + 1, N) || foundSolution;
            board[row][col] = 0; // backtrack
        }
    }

    return foundSolution;
}

int main() {
    int N;
    cout << "Enter number of queens: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueens(board, 0, N))
        cout << "No solution exists for " << N << " queens.\n";
    else
        cout << "All possible solutions are shown above.\n";

    return 0;
}
