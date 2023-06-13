class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                res[j][i] = grid[i][j];
            }
        }
        int count = 0;
        for (auto &it: grid) {
            for (auto &vec: res) {
                if (it == vec) count++;
            }
        }
        return count;
    }
};
