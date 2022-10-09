class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int dupRow = row;
        int dupCol = col;

        while (col >= 0 && row >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0 && row <= n - 1) {
            if (board[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }
    void NQueens(int col, vector<vector<string>>& ans, int n, vector<string>& board) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                NQueens(col + 1, ans, n, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) board[i] = s;
        NQueens(0, ans, n, board);
        return ans;
    }
};
