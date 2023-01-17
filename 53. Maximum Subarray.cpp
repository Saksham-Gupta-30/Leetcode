class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + sum <= 0) {
                sum += nums[i];
                ans = max(ans, sum);
                sum = 0;
                continue;
            }
            else {
                sum += nums[i];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
