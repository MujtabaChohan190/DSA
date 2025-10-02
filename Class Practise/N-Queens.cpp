class Solution {
private:
    // Helper function to check if placing a queen at (row, col) is safe
    bool isSafe(vector<string> &board, int row, int col, int n) {
        // horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // vertical
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // left diagonal (up-left direction)
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // right diagonal (up-right direction)
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // The recursive backtracking function
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        // Base Case: All rows are filled, so a solution is found
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column (j) of the current row
        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                // Place Queen
                board[row][j] = 'Q';

                // Recurse to the next row
                nQueens(board, row + 1, n, ans);

                // Backtrack: Remove Queen to try other possibilities
                board[row][j] = '.';
            }
        }
    }

public:
    // Main function to initiate the N-Queens problem solver
    vector<vector<string>> solveNQueens(int n) {
        // Initialize an empty board
        vector<string> board(n, string(n, '.'));
        
        // Container to store all solutions
        vector<vector<string>> ans;

        // Start the recursive process from the first row (row 0)
        nQueens(board, 0, n, ans);

        return ans;
    }
};
