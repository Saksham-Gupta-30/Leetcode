class Solution {
public:
    void dfs(int r, int c, int n, int m, vector<vector<int>>& dup, int x, int color, vector<vector<int>>& image) {
        dup[r][c] = color;
        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                if (abs(delrow) == abs(delcol)) continue;
                int nr = r + delrow;
                int nc = c + delcol;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == x && dup[nr][nc] != color) dfs(nr, nc, n, m, dup, x, color, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int x = image[sr][sc];
        vector<vector<int>> dup = image;
        // for (auto it: image) dup.push_back(it);
        dfs(sr, sc, n, m, dup, x, color, image);
        return dup;
    }
};
