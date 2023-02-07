class Solution {
public:
    int area = 0;
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        for (int a = 0; a < 4; a++) {
            int nr = i + delRow[a];
            int nc = j + delCol[a];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) {
                area += 1;
                dfs(nr, nc, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    area = 1;
                    dfs(i, j, grid);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
