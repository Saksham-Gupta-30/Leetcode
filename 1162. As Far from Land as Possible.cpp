class Solution {
public:
    int dist = -1;
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, -1, 0, 1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({0, {i, j}});
                }
            }
        }
        while (!q.empty()) {
            dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({dist + 1, {nr, nc}});
                }
            }            
        }
        return dist > 0 ? dist : -1;
    }
};
