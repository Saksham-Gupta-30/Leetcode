class Solution {
public:
    int ans = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>> vis;
        vis = grid;
        int count = 0;
        int i, j;
        for (int a = 0; a < vis.size(); a++) {
            for (int b = 0; b < vis[a].size(); b++) {
                if (vis[a][b] == 0) count++;
                if (vis[a][b] == 1) i = a, j = b;
            }
        }
        sol(grid, count + 1, i, j);
        return ans;
    }
    void sol(vector<vector<int>>& grid, int count, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == 2) {
            if (count == 0)
                ans++;
            return;
        }
        if (grid[i][j] == -1) return;

        grid[i][j] = -1;

        sol(grid, count - 1, i - 1, j);

        sol(grid, count - 1, i + 1, j);

        sol(grid, count - 1, i, j - 1);

        sol(grid, count - 1, i, j + 1);

        grid[i][j] = 1;
    }
};
