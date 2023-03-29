class Solution {
public:
    int solve(int ind, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if (ind == nums.size()) {
            return 0;
        }
        if (dp[ind][j] != -1) return dp[ind][j];

        int pick = nums[ind] * j + solve(ind + 1, j + 1, nums, dp);
        int notPick = solve(ind + 1, j, nums, dp);
        return dp[ind][j] = max(pick, notPick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(0, 1, satisfaction, dp);
    }
};
