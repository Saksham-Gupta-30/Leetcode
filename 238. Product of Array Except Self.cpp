class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 2) return {nums[1], nums[0]};
        int n = nums.size();
        vector<int> prefix(n), suffix(n), ans(n);
        prefix[0] = 1;
        prefix[1] = nums[0];
        suffix[n - 1] = 1;
        suffix[n - 2] = nums[n - 1];
        for (int i = 2; i < n; i++) prefix[i] = nums[i - 1] * prefix[i - 1];
        for (int i = n - 3; i >= 0; i--) suffix[i] = suffix[i + 1] * nums[i + 1];
        for (int i = 0; i < n; i++) ans[i] = prefix[i] * suffix[i];
        return ans;
    }
};
