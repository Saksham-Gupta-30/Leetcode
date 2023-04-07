class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};
    void dfs(int row, int col, vector<vector<int>>& board, vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + x[i];
            int ncol = col + y[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 1) {
                dfs(nrow, ncol, board, vis, n, m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 1 && vis[0][j] == 0) dfs(0, j, board, vis, n, m);
            if (board[n - 1][j] == 1 && vis[n - 1][j] == 0) dfs(n - 1, j, board, vis, n, m);
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 1 && vis[i][0] == 0) dfs(i, 0, board, vis, n, m);
            if (board[i][m - 1] == 1 && vis[i][m - 1] == 0) dfs(i, m - 1, board, vis, n, m);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && board[i][j] == 1) count++;
            }
        }

        return count;
    }
};
