class Solution {
public:
    int helper(vector<vector<int>> &mat, int x1, int y1, int x2, int y2) {
        int totalArea = mat[x2][y2];

        if (x1 - 1 >= 0) totalArea -= mat[x1 - 1][y2];
        if (y1 - 1 >= 0) totalArea -= mat[x2][y1 - 1];
        if (x1 - 1 >= 0 && y1 - 1 >= 0) totalArea += mat[x1 - 1][y1 - 1];
        return totalArea;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m));

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x1 = max(0, i - k);
                int y1 = max(0, j - k);
                int x2 = min(n - 1, i + k);
                int y2 = min(m - 1, j + k);

                int res = helper(mat, x1, y1, x2, y2);
                ans[i][j] = res;
            }
        }
        return ans;
    }
};
