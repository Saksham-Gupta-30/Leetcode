class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] >= nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLength = 0;
        for (int len : dp) {
            maxLength = max(maxLength, len);
        }

        return maxLength;
    }
    int minimumOperations(vector<int>& nums) {
        int len = helper(nums);
        return nums.size() - len;
    }
};
