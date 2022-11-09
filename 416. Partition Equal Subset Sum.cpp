class Solution {
public:
    bool helper(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return (nums[0] == target);
        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTaken = helper(ind - 1, nums, target, dp);
        bool taken = false;
        if (nums[ind] <= target) taken = helper(ind - 1, nums, target - nums[ind], dp);

        return dp[ind][target] = (notTaken | taken);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it: nums) sum += it;

        if (sum % 2 == 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return helper(nums.size() - 1, nums, sum / 2, dp);
    }
};
