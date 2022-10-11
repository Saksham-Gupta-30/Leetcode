class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        int dupRow = row;
        int dupCol = col;

        while (col >= 0 && row >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
            row--;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        col = dupCol;
        while (col >= 0 && row < n) {
            if (board[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }
    void NQueens(int col, int n, vector<string>& board, int& ans) {
        if (col == n) {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                NQueens(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) board[i] = s;
        NQueens(0, n, board, ans);
        return ans;
    }
};
