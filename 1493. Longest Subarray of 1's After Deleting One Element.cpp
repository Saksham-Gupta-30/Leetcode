class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int j = i;
                int len = 0;
                while (i < nums.size() && nums[i] == 1) {
                    len++;
                    i++;
                }
                nums[j] = len;
                nums[i - 1] = len;
            }
        }
        int ans = 0;
        nums.insert(nums.begin(), 0);
        nums.insert(nums.end(), 0);
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                flag = true;
                ans = max(ans, nums[i - 1] + nums[i + 1]);
            }
        }
        if (flag == false) {
            return nums.size() - 3;
        }
        return ans;
    }
};
