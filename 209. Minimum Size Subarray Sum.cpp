class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e6, j = 0;
        int sum = nums[0], size = 1;
        if (sum >= target) return 1;
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            size += 1;
            if (sum == target) {
                ans = min(ans, size);
            }
            else if (sum > target) {
                ans = min(size, ans);
                while (sum > target) {
                    ans = min(ans, size);
                    sum -= nums[j];
                    j++;
                    size--;
                }
                if (sum == target) ans = min(ans, size);
            }
        }
        return ans == 1e6 ? 0 : ans;
    }
};
