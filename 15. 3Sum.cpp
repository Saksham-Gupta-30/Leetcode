class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int k = nums.size() - 1;
            int j = i + 1;
            int temp = 0 - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == temp) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < nums.size() && nums[j] == nums[j - 1]) j++;
                    while (k > 0 && nums[k] == nums[k + 1]) k--;
                }
                else if (nums[j] + nums[k] > temp) k--;
                else j++;
            }
        }
        return ans;
    }
};
