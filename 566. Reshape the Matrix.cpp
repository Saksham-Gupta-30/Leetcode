class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c, 0));
        if (mat.size() * mat[0].size() != r * c) return mat;
        int i = 0, j = 0;
        for (auto it: mat) {
            for (auto x: it) {
                ans[i][j] = x;
                j++;
                if (j == c) {
                    j = 0;
                    i++;
                }
            }
        }
        return ans;
    }
};
