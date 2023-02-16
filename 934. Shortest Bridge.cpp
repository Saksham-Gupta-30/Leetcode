class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, -1, 0, 1};
    void visit(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int n) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int nr = i + delRow[k];
            int nc = j + delCol[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                visit(grid, vis, nr, nc, n);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = true;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visit(grid, vis, i, j, n);
                    flag = false;
                    break;
                }
            }
            if (flag == false) break;
        }

        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1 && grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nr = i + delRow[k];
                        int nc = j + delCol[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 0) {
                            vis[nr][nc] = 1;
                            q.push({nr, nc, 1});
                        }
                    }
                }
            }
        }

        int ans = 1e9;

        while (!q.empty()) {
            auto vec = q.front();
            int i = vec[0];
            int j = vec[1];
            int dist = vec[2];
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = i + delRow[k];
                int nc = j + delCol[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0) {
                    if (grid[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc, dist + 1});
                    }
                    else if (grid[nr][nc] == 1) {
                        ans = min(ans, dist);
                    }
                }
            }            
        }
        return ans == 1e9 ? 1 : ans;
    }
};
