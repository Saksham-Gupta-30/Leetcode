class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        q.push({1, {0, 0}});
        dist[0][0] = 1;
        while (!q.empty()) {
            int dis = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            if (i == n - 1 && j == n - 1) return dis;

            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    int ni = i + a;
                    int nj = j + b;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                        if (dis + 1 < dist[ni][nj]) {
                            dist[ni][nj] = dis + 1;
                            q.push({dis + 1, {ni, nj}});
                        }
                    }
                    
                }
            }
        }
        return -1;
    }
};
