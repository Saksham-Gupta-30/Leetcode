class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        for (auto &it: nums) sort(it.begin(), it.end());
        vector<vector<int>> res(m, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res[j][i] = nums[i][j];
            }
        }
        int score = 0;
        for (auto &it: res) {
            score += *max_element(it.begin(), it.end());
            cout << score << " ";
        }
        return score;
    }
};
