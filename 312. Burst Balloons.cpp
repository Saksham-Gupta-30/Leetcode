class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> nnums(n + 2, 1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));

        for (int i = 0; i < n; i++) nnums[i + 1] = nums[i];

        for (int length = 1; length <= n; length++) {
            for (int st = 1; st <= n - length + 1; st++) {
                int en = st + length - 1;
                int ans = 0;
                for (int k = st; k <= en; k++) {
                    ans = max(ans, dp[st][k - 1] + dp[k + 1][en] + nnums[st - 1]* nnums[k] * nnums[en + 1]);
                }
                dp[st][en] = ans;;
            }
        }
        return dp[1][n];
    }
};
