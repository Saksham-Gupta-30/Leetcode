class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) count++;
            if (board[row][i] == c) count++;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) count++;
        }
        if (count == 3) return true;
        else return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    if (isValid(i, j, board[i][j], board) == false) return false;
                }
            }
        }
        return true;
    }
};
